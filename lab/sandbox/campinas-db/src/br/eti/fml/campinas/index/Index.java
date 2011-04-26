package br.eti.fml.campinas.index;

import br.eti.fml.campinas.MetaInfo;
import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.DebugUtil;
import br.eti.fml.campinas.util.FileUtil;
import br.eti.fml.campinas.util.Pair;
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
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);
    public static final boolean TRACE_ENABLED = false;

    private RandomAccessFile fileIndex;
    private FileChannel channelIndex;
    private FileLock lockIndex;

    private RandomAccessFile fileHashNode;
    private FileChannel channelHashNode;
    private FileLock lockHashNode;
    private long currentHashNodeFileSize;

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

        this.currentHashNodeFileSize = this.fileHashNode.length();

        if (this.currentHashNodeFileSize % HashNode.HASH_NODE_SIZE != 0) {
            long newSize = this.currentHashNodeFileSize;

            while (newSize % HashNode.HASH_NODE_SIZE != 0) {
                newSize++;
            }

            log.error("Something is really wrong with the hash node file size! Trying"
                    + " to fix it. Resizing from " + this.currentHashNodeFileSize
                    + " to " + newSize + ". The size must be multiple of "
                    + HashNode.HASH_NODE_SIZE + ". It's very probable that some"
                    + " data is corrupted!");

            this.currentHashNodeFileSize = newSize;
            this.fileHashNode.setLength(newSize);
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
        this.lockHashNode.release();
        this.fileIndex.close();
        this.fileHashNode.close();
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

    private int getSlotPositionByKey(UUID key) {
        return this.getSlotPositionByPositiveNumber(getAPositiveNumberByKey(key));
    }

    private long getIndexPositionByKey(UUID key) {
        return getIndexPositionByNumber(getAPositiveNumberByKey(key));
    }

    private long getAPositiveNumberByKey(UUID key) {
        return Math.abs(key.getMostSignificantBits()
                        ^ key.getLeastSignificantBits());
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
                            public void whenTheKeyWasNotFound(
                                    boolean isLeft,
                                    long currentPosition,
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

    private void writeNewNodeAtIndex(
            long indexPosition, byte[] key, byte flags,
            byte address1, long address2, long left, long right) throws IOException {

        HashNode hashNode = new HashNode(key, flags,
                address1, address2, 0L, left, right);

        long nodeAddress = this.allocateAndPut(hashNode);
        IndexNode indexNode = new IndexNode(nodeAddress);

        this.channelIndex.write(indexNode.getIndexNode(), indexPosition);
    }

    private long allocateAndPut(HashNode hashNode) throws IOException {
        long address = this.currentHashNodeFileSize;
        this.channelHashNode.write(hashNode.getHashNode(), address);
        this.currentHashNodeFileSize += HashNode.HASH_NODE_SIZE;
        return address;
    }

    public void updateIndex(
            final UUID key, final byte flags, final byte address1,
            final long address2) throws IOException, CorruptedIndex {

        if (key == null) {
            log.warn("The key can't be null!");
            return;
        }

        final byte[] bytesKey = ByteUtil.UUID2bytes(key);

        final long indexPosition = getIndexPositionByKey(key);
        final int slotPosition = getSlotPositionByKey(key);

        if (this.freeSlots.get(slotPosition) != (byte) 0) {
            if (TRACE_ENABLED) {
                log.trace("The slot is free, recording new node at "
                        + DebugUtil.niceName(indexPosition) + " index position.");
            }

            this.freeSlots.put(slotPosition, (byte) 0);
            writeNewNodeAtIndex(indexPosition, bytesKey, flags,
                    address1, address2, 0L, 0L);
        } else {
            if (TRACE_ENABLED) {
                log.trace("The slot " + DebugUtil.niceName(indexPosition)
                        + " is used. Trying to find the key or a free slot.");
            }

            ByteBuffer indexNodeRaw = ByteBuffer
                    .allocate(IndexNode.INDEX_NODE_SIZE);

            this.channelIndex.read(indexNodeRaw, indexPosition);
            IndexNode indexNode = new IndexNode(indexNodeRaw);

            if (indexNode.isCorruptedNode()) {
                throw new CorruptedIndex(indexPosition, indexNode);
            } else {
                final AtomicBoolean isCorrupted = new AtomicBoolean(false);
                final Pair<Long, HashNode> corruptedHashNode
                        = new Pair<Long, HashNode>(null, null);

                HashNode.navigateThrough(indexNode.getHashNodeAddress(),
                        bytesKey, this.channelHashNode, new HashNode.HashNodeNavigator() {

                            @Override
                            public void whenTheKeyIsEqual(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                if (TRACE_ENABLED) {
                                    log.trace("The key " + DebugUtil.niceName(key)
                                            + " was used before and will be updated at "
                                            + DebugUtil.niceName(currentPosition));
                                }

                                // TODO: need to free address1 & address2 of currentHashNode

                                // needs to replace (update) the hashNode
                                HashNode newHashNode = new HashNode(
                                        bytesKey, flags, address1, address2,
                                        0L, currentHashNode.getLeftNode(),
                                        currentHashNode.getRightNode());

                                Index.this.channelHashNode.write(
                                        newHashNode.getHashNode(),
                                        currentPosition);
                            }

                            @Override
                            public void interceptGoingToLeftNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                if (TRACE_ENABLED) {
                                    log.trace("The key " + DebugUtil.niceName(key)
                                            + " was not found yet. Going to the left node: "
                                            + DebugUtil.niceName(
                                                currentHashNode.getLeftNode()));
                                }
                            }

                            @Override
                            public void interceptGoingToRightNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {
                                
                                if (TRACE_ENABLED) {
                                    log.trace("The key " + DebugUtil.niceName(key)
                                            + " was not found yet. Going to the right node: "
                                            + DebugUtil.niceName(
                                                currentHashNode.getLeftNode()));
                                }
                            }

                            @Override
                            public void whenTheKeyWasNotFound(
                                    boolean isLeft, long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                // needs to update the nextAddress of currentHashNode
                                HashNode newHashNode = new HashNode(
                                        bytesKey, flags, address1, address2,
                                        0L, 0L, 0L);

                                long newHashNodeAddress
                                        = allocateAndPut(newHashNode);

                                if (TRACE_ENABLED) {
                                    log.trace("The key " + DebugUtil.niceName(key)
                                            + " was not found. Creating a new node at "
                                            + DebugUtil.niceName(newHashNodeAddress));
                                }

                                HashNode newCurrentHashNode = new HashNode(
                                        currentHashNode.getKey(),
                                        currentHashNode.getFlags(),
                                        currentHashNode.getAddress1(),
                                        currentHashNode.getAddress2(),
                                        0L, isLeft ? newHashNodeAddress : 0L,
                                        !isLeft ? newHashNodeAddress : 0L);

                                Index.this.channelHashNode.write(
                                        newCurrentHashNode.getHashNode(),
                                        currentPosition);
                            }                                

                            @Override
                            public void corruptedHashNode(
                                    long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                isCorrupted.set(true);
                                corruptedHashNode.car = currentPosition;
                                corruptedHashNode.cdr = currentHashNode;
                            }
                        }
                );

                if (isCorrupted.get()) {
                    throw new CorruptedIndex(
                            corruptedHashNode.car, corruptedHashNode.cdr);
                }
            }
        }
    }

    public HashNode find(final UUID key) throws IOException, CorruptedIndex {
        if (key == null) {
            return null;
        }

        final HashNode[] result = new HashNode[1]; // boxing
        final AtomicBoolean isCorrupted = new AtomicBoolean(false);
        final Pair<Long, HashNode> corruptedHashNode
                = new Pair<Long, HashNode>(null, null);

        result[0] = null;

        final byte[] bytesKey = ByteUtil.UUID2bytes(key);
        final long indexPosition = getIndexPositionByKey(key);

        ByteBuffer indexNodeRaw = ByteBuffer.allocate(IndexNode.INDEX_NODE_SIZE);
        this.channelIndex.read(indexNodeRaw, indexPosition);
        IndexNode indexNode = new IndexNode(indexNodeRaw);

        if (indexNode.isCorruptedNode()) {
            throw new CorruptedIndex(indexPosition, indexNode);
        } else {
            HashNode.navigateThrough(indexNode.getHashNodeAddress(),
                    bytesKey, this.channelHashNode, new HashNode.HashNodeNavigator() {

                @Override
                public void whenTheKeyIsEqual(long currentPosition,
                                HashNode currentHashNode)  throws IOException {

                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was found at " + DebugUtil.niceName(currentPosition));
                    }

                    result[0] = currentHashNode;
                }

                @Override
                public void interceptGoingToLeftNode(
                        long currentPosition,
                        HashNode currentHashNode) throws IOException {

                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was not found yet. Going to the left node: "
                                + DebugUtil.niceName(
                                    currentHashNode.getLeftNode()));
                    }
                }

                @Override
                public void interceptGoingToRightNode(
                        long currentPosition,
                        HashNode currentHashNode) throws IOException {

                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was not found yet. Going to the right node: "
                                + DebugUtil.niceName(
                                    currentHashNode.getLeftNode()));
                    }
                }

                @Override
                public void whenTheKeyWasNotFound(
                        boolean isLeft, long currentPosition,
                        HashNode currentHashNode) throws IOException {

                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was not found!");
                    }

                    result[0] = null;
                }

                @Override
                public void corruptedHashNode(
                        long currentPosition,
                        HashNode currentHashNode) throws IOException {

                    isCorrupted.set(true);
                    corruptedHashNode.car = currentPosition;
                    corruptedHashNode.cdr = currentHashNode;
                }
            });

            if (isCorrupted.get()) {
                throw new CorruptedIndex(
                        corruptedHashNode.car, corruptedHashNode.cdr);
            }

            return result[0];
        }
    }
}
