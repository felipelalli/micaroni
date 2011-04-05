package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.Body;
import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.DebugUtil;
import br.eti.fml.crazydb.TheBigFile;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicInteger;

/**
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);
    public static final boolean TRACE_ENABLED = false;    

    private static final long INDEX_START_POSITION
            = MetaInfo.META_INFO_FIXED_SIZE_IN_BYTES
                + FreeTable.FREE_TABLE_FIXED_SIZE_IN_BYTES;
    
    private static final int BUFFER_SIZE = (int) (512 * ByteUtil.KB);

    private long indexSizeInBytes;

    private TheBigFile db;
    private Body body;
    private MetaInfo metaInfo;

    public Index(TheBigFile db, Body body, int indexSizeInMegabytes) throws IOException {
        this.db = db;
        this.body = body;
        this.metaInfo = new MetaInfo(this.db);
        this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;

        assert this.indexSizeInBytes % 8 == 0;

        log.debug("Starting '" + db.getName() + "' with "
                + indexSizeInMegabytes + " MB index...");

        if (!this.db.preallocate(indexSizeInBytes + INDEX_START_POSITION)) {
            log.debug("Nice! The index already was created before.");

            metaInfo.checkValues(this.db.getName(), indexSizeInMegabytes);

            if (!metaInfo.checkShutdown()) {
                log.error("Shutdown was not called last time. Some data can be corrupted!");
            }
        } else {
            this.db.fillWithZero(0L, indexSizeInBytes
                    + INDEX_START_POSITION, BUFFER_SIZE);

            metaInfo.writeFirstTime(db.getName(), indexSizeInMegabytes,
                    System.currentTimeMillis());
        }

        metaInfo.setShutdown(false);
        log.debug("Ready! Thanks for wait.");
    }

    private String percentage(long part, long total) {
        double number = (((double) part) / ((double) total));
        DecimalFormat format = new DecimalFormat("0.00%");
        return format.format(number);
    }

    public String retrieveInfo() throws IOException {
        StringBuilder info = new StringBuilder();

        long slots = (indexSizeInBytes / IndexNode.ADDRESS_SIZE);
        long freeSlots = 0L;
        final AtomicInteger keys = new AtomicInteger();
        Map<Integer, Integer> sizes = new HashMap<Integer, Integer>();
        boolean seemsCorrupted = false;

        for (long n = 0; n < slots; n++) {
            long indexPosition = this.getIndexPositionByNumber(n);

            if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) {
                freeSlots++;
            } else {
                byte[] indexNodeRaw = this.db.readBytesAt(
                        indexPosition, IndexNode.ADDRESS_SIZE);

                IndexNode indexNode = new IndexNode(indexNodeRaw);

                if (!indexNode.checkIfDataIsOK()) {
                    seemsCorrupted = true;
                } else {
                    final AtomicInteger count = new AtomicInteger();
                    count.incrementAndGet();

                    HashNode.navigateThrough(indexNode.getHashNodeAddress(),
                            null, this.db,

                        new HashNode.HashNodeNavigator() {
                            @Override
                            public void whenTheKeyIsEqual(
                                    long currentPosition,
                                    HashNode currentHashNode)  throws IOException {
                            }

                            @Override
                            public void interceptGoingToNextNode(
                                    long currentPosition, HashNode currentHashNode)
                                        throws IOException {

                                count.incrementAndGet();
                                keys.incrementAndGet();
                            }

                            @Override
                            public void whenTheKeyWasNotFound(long currentPosition,
                                    HashNode currentHashNode) throws IOException {

                                keys.incrementAndGet();
                            }
                       });

                    if (!sizes.containsKey(count.get())) {
                        sizes.put(count.get(), 0);
                    }

                    sizes.put(count.get(), sizes.get(count.get()) + 1);
                }
            }
        }

        info.append("Name: ").append(this.db.getName()).append("\n");
        info.append("Index size: ").append(
                this.indexSizeInBytes / ByteUtil.MB).append(" MB").append("\n");
        
        info.append("Body size: ").append((this.metaInfo.getCurrentSize()
                - this.indexSizeInBytes) / ByteUtil.MB).append(" MB").append("\n");

        info.append("Total size: ").append(this.metaInfo.getCurrentSize() / ByteUtil.MB)
                .append(" MB").append("\n");

        info.append("Seems corrupted? ").append(seemsCorrupted).append("\n");
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
    
    public void updateIndex(final UUID key, final long address, final long size) throws IOException {
        final byte[] bytesKey = ByteUtil.UUID2bytes(key);
        final long indexPosition = getIndexPositionByKey(key);

        if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) {
            if (TRACE_ENABLED) {
                log.trace("The slot is free, recording new node at "
                        + DebugUtil.niceName(indexPosition) + " index position.");
            }

            writeNewNodeAtIndex(bytesKey, address, size, indexPosition, 0L);
        } else {
            if (TRACE_ENABLED) {
                log.trace("The slot " + DebugUtil.niceName(indexPosition)
                        + " is used. Trying to find the key or a free slot.");
            }

            byte[] indexNodeRaw = this.db.readBytesAt(
                    indexPosition, IndexNode.ADDRESS_SIZE);

            IndexNode indexNode = new IndexNode(indexNodeRaw);

            if (!indexNode.checkIfDataIsOK()) {
                writeNewNodeAtIndex(bytesKey, address, size, indexPosition, 0L);
            } else {
                HashNode.navigateThrough(indexNode.getHashNodeAddress(), bytesKey, this.db,
                    new HashNode.HashNodeNavigator() {
                        @Override
                        public void whenTheKeyIsEqual(
                                long currentPosition,
                                HashNode currentHashNode)  throws IOException {

                            if (TRACE_ENABLED) {
                                log.trace("The key " + DebugUtil.niceName(key)
                                        + " was used before and will be updated at "
                                        + DebugUtil.niceName(currentPosition));
                            }

                            // needs to replace (update) the hashNode
                            byte[] newHashNode = new HashNode(
                                    bytesKey, size, address,
                                    currentHashNode.getNextAddress(), 0L)
                                        .getHashNode();

                            body.replaceAt(currentPosition, newHashNode);

                            // TODO: need to free the oldAddress
                        }

                        @Override
                        public void interceptGoingToNextNode(
                                long currentPosition, HashNode currentHashNode)
                                    throws IOException {

                            if (TRACE_ENABLED) {
                                log.trace("The key " + DebugUtil.niceName(key)
                                        + " was not found yet. Going to next node: "
                                        + DebugUtil.niceName(currentHashNode.getNextAddress()));
                            }
                        }

                        @Override
                        public void whenTheKeyWasNotFound(long currentPosition,
                                HashNode currentHashNode) throws IOException {

                            // needs to update the nextAddress of currentHashNode
                            byte[] newHashNode = new HashNode(
                                    bytesKey, size, address, 0L, 0L).getHashNode();

                            long newHashNodeAddress = allocateAndPut(newHashNode);

                            if (TRACE_ENABLED) {
                                log.trace("The key " + DebugUtil.niceName(key)
                                        + " was not found. Creating a new node at "
                                        + DebugUtil.niceName(newHashNodeAddress));
                            }

                            byte[] newCurrentHashNode = new HashNode(
                                    currentHashNode.getKey(), currentHashNode.getSize(),
                                    currentHashNode.getAddress(), newHashNodeAddress,
                                    currentHashNode.getTimestamp()).getHashNode();
    
                            body.replaceAt(currentPosition, newCurrentHashNode);
                        }
                   });
            }
        }
    }

    private long getIndexPositionByNumber(long positiveNumber) {
        return INDEX_START_POSITION
                + positiveNumber % (indexSizeInBytes / IndexNode.ADDRESS_SIZE)
                    * IndexNode.ADDRESS_SIZE;
    }

    private long getIndexPositionByKey(UUID key) {
        return getIndexPositionByNumber(
                Math.abs(key.getMostSignificantBits()
                        ^ key.getLeastSignificantBits()));
    }

    private void writeNewNodeAtIndex(byte[] bytesKey, long address, long size,
                                     long indexPosition, long nextAddress) throws IOException {

        byte[] hashNode = new HashNode(
                bytesKey, size, address, nextAddress, 0L).getHashNode();

        long nodeAddress = this.allocateAndPut(hashNode);
        this.db.putLongAt(indexPosition, nodeAddress);
        byte[] checkSum = ByteUtil.getChecksum(nodeAddress);
        this.db.putBytesAt(indexPosition + 8, checkSum);
    }

    public long allocateAndPut(byte[] data) throws IOException {
        long currentSize = this.metaInfo.getCurrentSize();
        this.metaInfo.setNewSize(currentSize + data.length);
        this.body.replaceAt(currentSize, data);
        return currentSize;
    }

    public void closeIndex() throws IOException {
        this.metaInfo.setShutdown(true);
    }

    public HashNode find(final UUID key) throws IOException {
        final HashNode[] result = new HashNode[1]; // boxing
        result[0] = null;

        final byte[] bytesKey = ByteUtil.UUID2bytes(key);
        final long indexPosition = getIndexPositionByKey(key);

        byte[] indexNodeRaw = this.db.readBytesAt(indexPosition, IndexNode.ADDRESS_SIZE);
        IndexNode indexNode = new IndexNode(indexNodeRaw);

        indexNode.checkForCorruptedData(true);

        HashNode.navigateThrough(indexNode.getHashNodeAddress(),
                bytesKey, this.db, new HashNode.HashNodeNavigator() {

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
            public void interceptGoingToNextNode(long currentPosition,
                             HashNode currentHashNode) throws IOException {

                if (TRACE_ENABLED) {
                    log.trace("The key " + DebugUtil.niceName(key)
                            + " was not found yet. Going to next node: "
                            + DebugUtil.niceName(currentHashNode.getNextAddress()));
                }
            }

            @Override
            public void whenTheKeyWasNotFound(long currentPosition,
                                HashNode currentHashNode) throws IOException {
                
                if (TRACE_ENABLED) {
                    log.trace("The key " + DebugUtil.niceName(key)
                            + " was not found!");
                }

                result[0] = null;
            }
        });

        return result[0];
    }
}
