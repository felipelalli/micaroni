package br.eti.fml.campinas.index;

import br.eti.fml.campinas.MetaInfo;
import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.DebugUtil;
import br.eti.fml.campinas.util.FileUtil;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);
    public static final boolean TRACE_ENABLED = true;

    private RandomAccessFile fileIndex;
    private FileChannel channelIndex;
    private FileLock lockIndex;

    private RandomAccessFile fileHashNode;
    private FileChannel channelHashNode;
    private FileLock lockHashNode;    

    private MetaInfo metaInfo;

    private long indexSizeInBytes;

    // cache
    private ByteBuffer freeSlots;

    public Index(File directoryPath, MetaInfo metaInfo,
                 int indexSizeInMegabytes) throws IOException {

        this.metaInfo = metaInfo;
        this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;

        assert this.indexSizeInBytes % 8 == 0;

        log.info("Starting '" + metaInfo.getName() + "' with "
                + indexSizeInMegabytes + " MB index...");

        File fIndex = new File(directoryPath.getAbsolutePath()
                + File.separator + "index");

        File fHashNode = new File(directoryPath.getAbsolutePath()
                + File.separator + "hashnode");

        this.fileIndex = new RandomAccessFile(fIndex, "rw");
        this.fileHashNode = new RandomAccessFile(fHashNode, "rw");
        this.channelIndex = this.fileIndex.getChannel();
        this.channelHashNode = this.fileHashNode.getChannel();
        this.lockIndex = this.channelIndex.tryLock();
        this.lockHashNode = this.channelHashNode.tryLock();

        if (this.lockIndex == null) {
            throw new IOException("Index in '"
                    + directoryPath.getAbsolutePath()
                    + "' is locked! Unlock it first.");
        }

        if (this.lockHashNode == null) {
            throw new IOException("Hashnode index in '"
                    + directoryPath.getAbsolutePath()
                    + "' is locked! Unlock it first.");
        }

        if (this.metaInfo.isFirstTime()) {
            FileUtil.fillWithZero(this.channelIndex, 0L, indexSizeInBytes);

            metaInfo.writeFirstTime(indexSizeInMegabytes,
                    System.currentTimeMillis());

            this.fileIndex.setLength(this.indexSizeInBytes);
        } else {
            metaInfo.checkValues(this.metaInfo.getName(), indexSizeInMegabytes);

            this.channelIndex.position(indexSizeInBytes);
            log.debug("Nice! The index already was created before.");

            if (!metaInfo.checkShutdown()) {
                log.error("Shutdown was not called last time. Some data can be corrupted!");
            }
        }

        metaInfo.setShutdown(false);

        int slots = (int) (indexSizeInBytes / IndexNode.INDEX_NODE_SIZE);
        log.debug("Using " + slots + " slots.");

        this.freeSlots = ByteBuffer.allocateDirect(slots);
        byte[] freeSlotsTemp = new byte[slots];

        if (this.metaInfo.isFirstTime()) {
            log.info("Your first time with this database. All "
                    + slots + " slots are free.");

            Arrays.fill(freeSlotsTemp, (byte) 1);
            this.freeSlots.put(freeSlotsTemp);
        } else {
            log.info("Caching index up to " + slots + " slots...");
            Arrays.fill(freeSlotsTemp, (byte) 0);
            this.freeSlots.put(freeSlotsTemp);

            long now = System.currentTimeMillis();

            for (int n = 0; n < slots; n++) {
                if (System.currentTimeMillis() - now > 5000) {
                    log.info("Caching index yet... "
                            + percentage(n, slots) + " done");

                    now = System.currentTimeMillis();
                }

                long indexPosition = this.getIndexPositionByNumber(n);

                ByteBuffer node = ByteBuffer.allocate(IndexNode.INDEX_NODE_SIZE);
                this.channelIndex.read(node, indexPosition);
                IndexNode indexNode = new IndexNode(node);

                if (indexNode.isCorruptedNode()) {
                    log.error("The node '" + indexNode + "' is corrupted "
                            + " at " + DebugUtil.niceName(indexPosition));
                } else {
                    this.freeSlots.put(n, (byte) 1);
                }
            }
        }

        this.metaInfo.clearFirstTimeFlag();
        log.info("Ok! The database is ready!");
    }

    public void shutdown() throws IOException {
        this.lockIndex.release();
        this.fileIndex.close();
    }
    
    private String percentage(long part, long total) {
        double number = (((double) part) / ((double) total));
        DecimalFormat format = new DecimalFormat("0.00%");
        return format.format(number);
    }

    private long getIndexPositionByNumber(long positiveNumber) {
        return getSlotPositionByPositiveNumber(positiveNumber)
                    * IndexNode.INDEX_NODE_SIZE;
    }

    private int getSlotPositionByPositiveNumber(long positiveNumber) {
        return (int) (positiveNumber
                % (indexSizeInBytes / IndexNode.INDEX_NODE_SIZE));
    }

    public String retrieveInfo() throws IOException {
        log.debug("Retrieving database info...");

        StringBuilder info = new StringBuilder();

        long slots = (indexSizeInBytes / IndexNode.INDEX_NODE_SIZE);
        long freeSlots = 0L;
        final AtomicInteger keys = new AtomicInteger();
        Map<Integer, Integer> sizes = new HashMap<Integer, Integer>();
        final AtomicInteger corruptedNodes = new AtomicInteger();
        final AtomicInteger corruptedHashNodes = new AtomicInteger();

        long now = System.currentTimeMillis();

        for (int n = 0; n < slots; n++) {
            if (System.currentTimeMillis() - now > 5000) {
                log.info("Retrieving info yet... "
                        + percentage(n, slots) + " done");
                
                now = System.currentTimeMillis();
            }

            long indexPosition = this.getIndexPositionByNumber(n);

            if (this.freeSlots.get(n) != (byte) 0) {
                freeSlots++;
            } else {
                ByteBuffer indexNodeRaw = ByteBuffer.allocate(
                        IndexNode.INDEX_NODE_SIZE);

                this.channelIndex.read(indexNodeRaw, indexPosition);
                IndexNode indexNode = new IndexNode(indexNodeRaw);

                if (indexNode.isCorruptedNode()) {
                    log.error("The index node '" + indexNode
                            + "' is corrupted at "
                            + DebugUtil.niceName(indexPosition));

                    corruptedNodes.incrementAndGet();
                } else {
                    final AtomicInteger count = new AtomicInteger();
                    count.incrementAndGet();

                    HashNode.navigateThrough(indexNode.getHashNodeAddress(),
                            null, this.channelHashNode,

                        new HashNode.HashNodeNavigator() {
                            @Override
                            public void whenTheKeyIsEqual(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {
                            }

                            @Override
                            public void interceptGoingToLeftNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                count.incrementAndGet();
                                keys.incrementAndGet();
                            }

                            @Override
                            public void interceptGoingToRightNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {
                                
                                count.incrementAndGet();
                                keys.incrementAndGet();
                            }

                            @Override
                            public void whenTheKeyWasNotFound(long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                keys.incrementAndGet();
                            }

                            @Override
                            public void corruptedHashNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                log.error("The hash node '"
                                        + currentHashNode + "' is corrupted "
                                        + " at " + DebugUtil.niceName(
                                            currentPosition));

                                corruptedHashNodes.incrementAndGet();
                            }
                        });

                    if (!sizes.containsKey(count.get())) {
                        sizes.put(count.get(), 0);
                    }

                    sizes.put(count.get(), sizes.get(count.get()) + 1);
                }
            }
        }

        info.append("Name: ").append(this.metaInfo.getName()).append("\n");
        info.append("Index size: ").append(
                this.indexSizeInBytes / ByteUtil.MB).append(" MB").append("\n");

        info.append("Hash node size: ").append(
                this.fileHashNode.length() / ByteUtil.MB)
                    .append(" MB").append("\n");

        info.append("Corrupted index nodes: ")
                .append(corruptedNodes.get()).append("\n");

        info.append("Corrupted hash nodes: ")
                .append(corruptedHashNodes.get()).append("\n");

        info.append("Keys: ").append(keys.get()).append("\n");
        info.append("Total slots: ").append(slots).append("\n");
        info.append("Free slots: ").append(freeSlots).append(" ")
                .append(percentage(freeSlots, slots)).append("\n");

        info.append("Used slots: ").append(slots - freeSlots).append(" ")
                .append(percentage(slots - freeSlots, slots)).append("\n");

        for (Integer n : sizes.keySet()) {
            info.append("With: ").append(n).append(" keys: ")
                    .append(sizes.get(n)).append(" ")
                .append(percentage(sizes.get(n), slots)).append("\n");
        }

        return info.toString();
    }


    public void updateIndex(UUID key, byte flags, byte address1, long address2) {
        // TODO
    }
}
