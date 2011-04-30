package br.eti.fml.campinas.local.index;

import br.eti.fml.campinas.local.MetaInfo;
import br.eti.fml.campinas.local.NotEnoughSpaceInDiskException;
import br.eti.fml.campinas.util.BufferPool;
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
import java.util.TreeSet;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);

    private static final byte FREE = (byte) 1;
    private static final byte BUSY = (byte) 0;

    private RandomAccessFile fileIndex;
    private RandomAccessFile fileLazyIndex;
    private FileChannel channelIndex;
    private FileChannel channelLazyIndex;
    private AtomicReference<FileLock> lockIndex = new AtomicReference<FileLock>();
    private AtomicReference<FileLock> lockLazyIndex = new AtomicReference<FileLock>();

    private RandomAccessFile fileHashNode;
    private FileChannel channelHashNode;
    private AtomicReference<FileLock> lockHashNode = new AtomicReference<FileLock>();
    private long currentHashNodeFileSize;

    private MetaInfo metaInfo;
    private long indexSizeInBytes;

    // cache
    private ByteBuffer freeSlots;

    public Index(File directoryPath, MetaInfo metaInfo,
                 int indexSizeInMegabytes) throws IOException {

        this.checkFreeDiskSpace(directoryPath);

        this.metaInfo = metaInfo;
        this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;
        this.indexSizeInBytes = ByteUtil.getNextMultiple(
                this.indexSizeInBytes, IndexNode.INDEX_NODE_SIZE);

        assert this.indexSizeInBytes % IndexNode.INDEX_NODE_SIZE == 0;

        log.info("Starting '" + metaInfo.getName() + "' with "
                + indexSizeInMegabytes + " MB index...");

        File fIndex = new File(directoryPath.getAbsolutePath()
                + File.separator + "index");

        File fIndexBackup = new File(directoryPath.getAbsolutePath()
                + File.separator + "lazy-index");

        File fHashNode = new File(directoryPath.getAbsolutePath()
                + File.separator + "hash-node");

        this.fileIndex = new RandomAccessFile(fIndex, "rw");
        this.fileLazyIndex = new RandomAccessFile(fIndexBackup, "rw");
        this.fileHashNode = new RandomAccessFile(fHashNode, "rw");
        this.channelIndex = this.fileIndex.getChannel();
        this.channelLazyIndex = this.fileLazyIndex.getChannel();
        this.channelHashNode = this.fileHashNode.getChannel();

        this.lock(this.lockIndex, this.channelIndex, directoryPath);
        this.lock(this.lockHashNode, this.channelHashNode, directoryPath);
        this.lock(this.lockLazyIndex, this.channelLazyIndex, directoryPath);

        this.checkFileSize("index", this.indexSizeInBytes, this.fileIndex);
        this.checkFileSize("lazy index", this.indexSizeInBytes,
                this.fileLazyIndex);

        this.currentHashNodeFileSize = this.fileHashNode.length();

        long rightHashNodeFileSize = ByteUtil.getNextMultiple(
                this.currentHashNodeFileSize, HashNode.HASH_NODE_SIZE);

        if (rightHashNodeFileSize != currentHashNodeFileSize) {
            this.checkFileSize("hash node", rightHashNodeFileSize, this.fileHashNode);
            this.currentHashNodeFileSize = rightHashNodeFileSize;
        }

        if (this.metaInfo.isFirstTime()) {
            this.fileIndex.setLength(this.indexSizeInBytes);
            this.fileLazyIndex.setLength(this.indexSizeInBytes);

            FileUtil.fillWith((byte) 0xFF, this.channelIndex, 0L,
                    indexSizeInBytes);

            FileUtil.fillWith((byte) 0xFF, this.channelLazyIndex, 0L,
                    indexSizeInBytes);

            metaInfo.writeFirstTime(indexSizeInMegabytes,
                    System.currentTimeMillis());
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

            Arrays.fill(freeSlotsTemp, FREE);
            this.freeSlots.put(freeSlotsTemp);
        } else {
            log.info("Caching index up to " + slots + " slots...");
            Arrays.fill(freeSlotsTemp, BUSY);
            this.freeSlots.put(freeSlotsTemp);

            long now = System.currentTimeMillis();

            for (int n = 0; n < slots; n++) {
                final int finalPosition = n;

                if (System.currentTimeMillis() - now > 5000) {
                    log.info("Caching index yet... "
                            + percentage(n, slots) + " done");

                    now = System.currentTimeMillis();
                }

                final long indexPosition = this.getIndexPositionByNumber(n);

                BufferPool.getInstance().doWithATemporaryBuffer(
                    IndexNode.INDEX_NODE_SIZE, new BufferPool.Action() {
                        @Override
                        public void doWith(ByteBuffer buffer) throws IOException {
                            channelIndex.read(buffer, indexPosition);
                            IndexNode indexNode = new IndexNode(buffer);

                            if (indexNode.isEmpty()) {
                                freeSlots.put(finalPosition, FREE);
                            } else if (indexNode.isCorruptedNode()) {
                                log.error("The node '" + indexNode + "' is corrupted "
                                        + " at " + DebugUtil.niceName(indexPosition));
                            }
                        }
                    }
                );
            }
        }

        this.metaInfo.clearFirstTimeFlag();
        log.info("Ok! The database is ready!");
    }

    private void checkFreeDiskSpace(File directoryPath)
            throws NotEnoughSpaceInDiskException {

        long min = this.indexSizeInBytes * 3;

        if (directoryPath.getUsableSpace() < min) {
            throw new NotEnoughSpaceInDiskException("The partition where " +
                    "" + directoryPath.getAbsolutePath() + " is has no " +
                    "enough disk space! You need at least " + (min /
                    ByteUtil.MB) + " MB (index * 3).");
        }
    }

    private void lock(AtomicReference<FileLock> lock,
                      FileChannel fileChannel,
                      File directoryPath) throws IOException {

        lock.set(fileChannel.tryLock());

        if (lock.get() == null) {
            throw new IOException(fileChannel + " in '"
                    + directoryPath.getAbsolutePath()
                    + "' is locked! Unlock it first.");
        }
    }

    private void checkFileSize(String fileName, long size,
                               RandomAccessFile file) throws IOException {

        long currentIndexSize = file.length();

        if (currentIndexSize != size) {
            log.error("Something is really wrong with the file " + fileName +
                    "size! Trying to fix it. Resizing from " + currentIndexSize
                    + " to " + size + ". The size must be multiple of "
                    + IndexNode.INDEX_NODE_SIZE + ". It's very probable that some"
                    + " data is corrupted!");

            file.setLength(size);
        }
    }

    public void shutdown() throws IOException {
        this.lockIndex.get().release();
        this.lockHashNode.get().release();
        this.lockLazyIndex.get().release();
        this.fileIndex.close();
        this.fileHashNode.close();
        this.fileLazyIndex.close();
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
        final DecimalFormat format = new DecimalFormat("#,###");
        log.debug("Retrieving database info...");

        StringBuilder info = new StringBuilder();

        long slots = (indexSizeInBytes / IndexNode.INDEX_NODE_SIZE);
        long freeSlots = 0L;
        final AtomicInteger keys = new AtomicInteger();
        final Map<Integer, Integer> sizes = new HashMap<Integer, Integer>();
        final AtomicInteger corruptedNodes = new AtomicInteger();
        final AtomicInteger corruptedHashNodes = new AtomicInteger();

        long now = System.currentTimeMillis();

        for (int n = 0; n < slots; n++) {
            if (System.currentTimeMillis() - now > 5000) {
                log.info("Retrieving info yet... "
                        + percentage(n, slots) + " done");
                
                now = System.currentTimeMillis();
            }

            final long indexPosition = this.getIndexPositionByNumber(n);

            if (this.freeSlots.get(n) != BUSY) {
                freeSlots++;
            } else {
                BufferPool.getInstance().doWithATemporaryBuffer(
                    IndexNode.INDEX_NODE_SIZE, new BufferPool.Action() {
                        @Override
                        public void doWith(ByteBuffer nodeBuffer) throws IOException {
                            channelIndex.read(nodeBuffer, indexPosition);
                            IndexNode indexNode = new IndexNode(nodeBuffer);

                            if (indexNode.isCorruptedNode()) {
                                log.error("The index node '" + indexNode
                                        + "' is corrupted at "
                                        + DebugUtil.niceName(indexPosition));

                                corruptedNodes.incrementAndGet();
                            } else {
                                final AtomicInteger count = new AtomicInteger();
                                count.incrementAndGet();

                                HashNode.navigateThroughFully(
                                        indexNode.getHashNodeAddress(),
                                        channelHashNode,
                                        getInfoNavigator(
                                                count, keys, corruptedHashNodes)
                                );

                                if (!sizes.containsKey(count.get())) {
                                    sizes.put(count.get(), 0);
                                }

                                sizes.put(count.get(), sizes.get(count.get()) + 1);
                            }
                        }
                    }
                );
            }
        }

        info.append("Name: ").append(this.metaInfo.getName()).append("\n");
        info.append("Index size: ").append(
                format.format(this.indexSizeInBytes / ByteUtil.MB)).append(" MB").append("\n");

        info.append("Hash node size: ").append(
                format.format(this.fileHashNode.length() / ByteUtil.MB))
                    .append(" MB").append("\n");

        info.append("Corrupted index nodes: ")
                .append(format.format(corruptedNodes.get())).append("\n");

        info.append("Corrupted hash nodes: ")
                .append(format.format(corruptedHashNodes.get())).append("\n");

        info.append("Keys: ").append(format.format(keys.get())).append("\n");
        info.append("Total slots: ").append(format.format(slots)).append("\n");
        info.append("Free slots: ").append(format.format(freeSlots)).append(" ")
                .append(percentage(freeSlots, slots)).append("\n");

        info.append("Used slots: ").append(format.format(slots - freeSlots)).append(" ")
                .append(percentage(slots - freeSlots, slots)).append("\n");

        TreeSet<Integer> orderedSizes = new TreeSet<Integer>(sizes.keySet());
        
        for (Integer n : orderedSizes) {
            info.append("Level ").append(n).append(": ")
                    .append(format.format(sizes.get(n))).append(" ")
                .append(percentage(sizes.get(n), slots)).append("\n");
        }

        return info.toString();
    }

    private HashNode.HashNodeFullyNavigator getInfoNavigator(
            final AtomicInteger count,
            final AtomicInteger keys, final AtomicInteger corruptedHashNodes) {

        return new HashNode.HashNodeFullyNavigator() {

            @Override
            public void updateCurrentNode(
                    long currentPosition, HashNode currentHashNode)
                        throws IOException {

                keys.incrementAndGet();
            }

            @Override
            public void nodeHasLeft(
                    long currentPosition, HashNode currentHashNode)
                    throws IOException {

                count.incrementAndGet();
            }

            @Override
            public void nodeHasRight(
                    long currentPosition, HashNode currentHashNode)
                        throws IOException {

                count.incrementAndGet();
            }

            @Override
            public void corruptedHashNode(
                    long currentPosition,
                    HashNode currentHashNode, int level)
                        throws IOException {

                log.error("The hash node '" + currentHashNode
                        + "' is corrupted " + " at "
                        + DebugUtil.niceName(currentPosition)
                        + " in level " + level);

                corruptedHashNodes.incrementAndGet();
            }
        };
    }

    private void writeNewNodeAtIndex(
            final long indexPosition, final byte[] key, final byte flags,
            final byte address1, final long address2,
            final long left, final long right) throws IOException {

        BufferPool.getInstance().doWithATemporaryBuffer(
                HashNode.HASH_NODE_SIZE, new BufferPool.Action() {
                    @Override
                    public void doWith(ByteBuffer buffer) throws IOException {
                        HashNode hashNode = new HashNode(buffer, key, flags,
                                address1, address2, HashNode.NOW, left, right);

                        final long nodeAddress = allocateAndPut(hashNode);

                        BufferPool.getInstance().doWithATemporaryBuffer(
                                IndexNode.INDEX_NODE_SIZE, new BufferPool.Action() {
                                    @Override
                                    public void doWith(
                                            ByteBuffer temp) throws IOException {

                                        IndexNode indexNode = new IndexNode(
                                                temp, nodeAddress);

                                        channelIndex.write(
                                                indexNode.getIndexNode(),
                                                indexPosition);
                                    }
                                }
                        );
                    }
                }
        );
    }

    private long allocateAndPut(HashNode hashNode) throws IOException {
        long address = this.currentHashNodeFileSize;
        this.channelHashNode.write(hashNode.getHashNode(), address);
        this.currentHashNodeFileSize += HashNode.HASH_NODE_SIZE;
        return address;
    }

    public void updateIndex(
            final UUID key, final byte flags, final byte address1,
            final long address2) throws IOException {

        if (key == null) {
            log.warn("The key can't be null!");
            return;
        }

        final byte[] bytesKey = ByteUtil.UUID2bytes(key);

        final long indexPosition = getIndexPositionByKey(key);
        final int slotPosition = getSlotPositionByKey(key);

        if (this.freeSlots.get(slotPosition) != BUSY) {
//            log.trace("The slot is free, recording new node at "
//                    + DebugUtil.niceName(indexPosition) + " index position.");

            this.freeSlots.put(slotPosition, BUSY);
            writeNewNodeAtIndex(indexPosition, bytesKey, flags,
                    address1, address2, HashNode.NULL, HashNode.NULL);
        } else {
//            log.trace("The slot " + DebugUtil.niceName(indexPosition)
//                    + " is used. Trying to find the key or a free slot.");

            BufferPool.getInstance().doWithATemporaryBuffer(
                IndexNode.INDEX_NODE_SIZE, new BufferPool.Action() {
                    @Override
                    public void doWith(ByteBuffer nodeBuffer)
                            throws IOException {

                        channelIndex.read(nodeBuffer, indexPosition);
                        IndexNode indexNode = new IndexNode(nodeBuffer);

                        if (indexNode.isCorruptedNode()) {
                            throw new CorruptedIndexException(indexPosition, indexNode);
                        } else {
                            final AtomicBoolean isCorrupted
                                    = new AtomicBoolean(false);
                            
                            final Pair<Long, HashNode> corruptedHashNode
                                    = new Pair<Long, HashNode>(null, null);

                            HashNode.navigateThroughToFindAKey(
                                    indexNode.getHashNodeAddress(),
                                    bytesKey, channelHashNode,
                                    getUpdateIndexNavigator(isCorrupted,
                                            corruptedHashNode, bytesKey,
                                            flags, address1, address2)
                            );

                            if (isCorrupted.get()) {
                                throw new CorruptedIndexException(
                                        corruptedHashNode.car, corruptedHashNode.cdr);
                            }
                        }
                    }
                }
            );                        
        }
    }

    private HashNode.HashNodeNavigator getUpdateIndexNavigator(
            final AtomicBoolean corrupted,
            final Pair<Long, HashNode> corruptedHashNode,
            final byte[] bytesKey, final byte flags, final byte address1,
            final long address2) {
        
        return new HashNode.HashNodeNavigator() {

            @Override
            public void whenTheKeyIsEqual(
                    final long currentPosition, final HashNode currentHashNode)
                        throws IOException {

//                log.trace("The key "
//                        + DebugUtil.niceName(key)
//                        + " was used before and will be updated at "
//                        + DebugUtil.niceName(currentPosition));

                // TODO: need to free address1 & address2 of currentHashNode

                BufferPool.getInstance().doWithATemporaryBuffer(
                    HashNode.HASH_NODE_SIZE, new BufferPool.Action() {
                        @Override
                        public void doWith(
                                ByteBuffer buffer)
                                    throws IOException {

                            // needs to replace (update) the hashNode
                            HashNode newHashNode = new HashNode(
                                    buffer, bytesKey, flags,
                                    address1, address2,
                                    HashNode.NOW,
                                    currentHashNode.getLeftNode(),
                                    currentHashNode.getRightNode());

                            Index.this.channelHashNode.write(
                                    newHashNode.getHashNode(),
                                    currentPosition);
                        }
                    }
                );
            }

            @Override
            public void interceptGoingToLeftNode(
                    long currentPosition,
                    HashNode currentHashNode) throws IOException {

//                log.trace("The key "
//                        + DebugUtil.niceName(key)
//                        + " was not found yet. Going to the left node: "
//                        + DebugUtil.niceName(currentHashNode.getLeftNode()));
            }

            @Override
            public void interceptGoingToRightNode(
                    long currentPosition,
                    HashNode currentHashNode) throws IOException {

//                    log.trace("The key " + DebugUtil.niceName(key)
//                            + " was not found yet. Going to the right node: "
//                            + DebugUtil.niceName(currentHashNode.getLeftNode()));
            }

            @Override
            public void whenTheKeyWasNotFound(
                    final boolean isLeft,
                    final long currentPosition,
                    final HashNode currentHashNode) throws IOException {

                    BufferPool.getInstance().doWithATemporaryBuffer(
                        HashNode.HASH_NODE_SIZE, new BufferPool.Action() {
                            @Override
                            public void doWith(
                                    ByteBuffer tempBuffer) throws IOException {

                                // needs to update the left or right of currentHashNode
                                HashNode newHashNode
                                        = new HashNode(
                                        tempBuffer, bytesKey,
                                        flags, address1, address2,
                                        HashNode.NOW, HashNode.NULL,
                                        HashNode.NULL);

                                final long newHashNodeAddress
                                        = allocateAndPut(newHashNode);

//                                log.trace("The key " + DebugUtil.niceName(key)
//                                        + " was not found. Creating a new node at "
//                                        + DebugUtil.niceName(newHashNodeAddress));

                                BufferPool.getInstance().doWithATemporaryBuffer(
                                    HashNode.HASH_NODE_SIZE, new BufferPool.Action() {
                                        @Override
                                        public void doWith(
                                                ByteBuffer tempBufferNewCurrentHashNode) throws IOException {
                                            HashNode newCurrentHashNode = new HashNode(
                                                    tempBufferNewCurrentHashNode,
                                                    currentHashNode.getKey(),
                                                    currentHashNode.getFlags(),
                                                    currentHashNode.getAddress1(),
                                                    currentHashNode.getAddress2(),
                                                    HashNode.NOW,
                                                    isLeft ? newHashNodeAddress
                                                            : currentHashNode.getLeftNode(),
                                                    !isLeft ? newHashNodeAddress
                                                            : currentHashNode.getRightNode());

                                            Index.this.channelHashNode.write(
                                                    newCurrentHashNode.getHashNode(),
                                                    currentPosition);
                                        }
                                    }
                                );
                            }
                        }
                    );
            }

            @Override
            public void corruptedHashNode(
                    long currentPosition,
                    HashNode currentHashNode, int level) throws IOException {

                corrupted.set(true);
                corruptedHashNode.car = currentPosition;
                corruptedHashNode.cdr = currentHashNode;
            }
        };
    }

    public HashNode find(final UUID key) throws IOException {
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

        BufferPool.getInstance().doWithATemporaryBuffer(
            IndexNode.INDEX_NODE_SIZE, new BufferPool.Action() {
                @Override
                public void doWith(ByteBuffer nodeBuffer) throws IOException {

                    channelIndex.read(nodeBuffer, indexPosition);
                    IndexNode indexNode = new IndexNode(nodeBuffer);

                    if (indexNode.isEmpty()) {
                        // returns null
                    } else if (indexNode.isCorruptedNode()) {
                        throw new CorruptedIndexException(indexPosition, indexNode);
                    } else {
                        HashNode.navigateThroughToFindAKey(indexNode.getHashNodeAddress(),
                                bytesKey, channelHashNode,
                                getSearchNavigator(result,
                                        isCorrupted, corruptedHashNode));

                        if (isCorrupted.get()) {
                            throw new CorruptedIndexException(
                                    corruptedHashNode.car, corruptedHashNode.cdr);
                        }
                    }
                }
            }
        );

        return result[0];
    }

    private HashNode.HashNodeNavigator getSearchNavigator(
            final HashNode[] result,
            final AtomicBoolean corrupted,
            final Pair<Long, HashNode> corruptedHashNode) {

        return new HashNode.HashNodeNavigator() {
            @Override
            public void whenTheKeyIsEqual(long currentPosition,
                            HashNode currentHashNode)  throws IOException {

//                log.trace("The key " + DebugUtil.niceName(key)
//                        + " was found at " + DebugUtil.niceName(currentPosition));

                result[0] = currentHashNode;
            }

            @Override
            public void interceptGoingToLeftNode(
                    long currentPosition,
                    HashNode currentHashNode) throws IOException {

//                log.trace("The key " + DebugUtil.niceName(key)
//                        + " was not found yet. Going to the left node: "
//                        + DebugUtil.niceName(currentHashNode.getLeftNode()));
            }

            @Override
            public void interceptGoingToRightNode(
                    long currentPosition,
                    HashNode currentHashNode) throws IOException {

//                log.trace("The key " + DebugUtil.niceName(key)
//                        + " was not found yet. Going to the right node: "
//                        + DebugUtil.niceName(currentHashNode.getLeftNode()));
            }

            @Override
            public void whenTheKeyWasNotFound(
                    boolean isLeft, long currentPosition,
                    HashNode currentHashNode) throws IOException {

//                log.trace("The key " + DebugUtil.niceName(key) + " was not found!");
                result[0] = null;
            }

            @Override
            public void corruptedHashNode(
                    long currentPosition,
                    HashNode currentHashNode, int level) throws IOException {

                corrupted.set(true);
                corruptedHashNode.car = currentPosition;
                corruptedHashNode.cdr = currentHashNode;
            }
        };
    }
}
