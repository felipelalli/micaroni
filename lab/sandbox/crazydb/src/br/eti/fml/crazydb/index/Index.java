package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.Body;
import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.DebugUtil;
import br.eti.fml.crazydb.Pair;
import br.eti.fml.crazydb.TheBigFile;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.UUID;

/**
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);
    public static final boolean TRACE_ENABLED = false;

    private static final int KEY_SIZE = 16;
    private static final int SIZE_SIZE = 8;
    private static final int CHECKSUM_SIZE = 2;
    private static final int ADDRESS_SIZE = 8 + CHECKSUM_SIZE;
    private static final int TIMESTAMP_SIZE = 8;
    private static final int HASH_NODE_SIZE = KEY_SIZE + SIZE_SIZE
            + ADDRESS_SIZE + ADDRESS_SIZE + TIMESTAMP_SIZE;

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
            log.debug("Filling with zeros...");
            this.db.fillWithZero(0L, indexSizeInBytes
                    + INDEX_START_POSITION, BUFFER_SIZE);

            metaInfo.writeFirstTime(db.getName(), indexSizeInMegabytes,
                    System.currentTimeMillis());

            log.debug("Filling with zeros done! Thanks for wait.");
        }

        metaInfo.setShutdown(false);

        // Reading all index in memory:
        long free = Runtime.getRuntime().freeMemory();

        if (free < this.indexSizeInBytes) {
            log.warn("Your free memory is TOO low! You need at least "
                    + indexSizeInMegabytes + " MB of free memory. You have "
                    + (free / 1024 / 1024) + " MB free.");
        }
    }

    public String retrieveInfo() {
        long total = (indexSizeInBytes / ADDRESS_SIZE);

        for (long n = 0; n < total; n += ADDRESS_SIZE) {
            long indexPosition = this.getIndexPositionByNumber(n);
        }

        // TODO

        return "";
    }
    
    protected static byte[] getAHashNode(byte[] key, long size,
                                         long address, long nextAddress,
                                         long timestamp) {

        if (timestamp == 0L) {
            timestamp = System.currentTimeMillis();
        }

        byte[] addressChecksum = ByteUtil.getChecksum(address);
        byte[] nextAddressChecksum = ByteUtil.getChecksum(nextAddress);

        return ByteBuffer.allocate(HASH_NODE_SIZE).put(key).putLong(size)
                .putLong(address).put(addressChecksum).putLong(nextAddress)
                .put(nextAddressChecksum).putLong(timestamp).array();
    }

    public void updateIndex(UUID key, long address, long size) throws IOException {
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

            byte[] indexNode = this.db.readBytesAt(indexPosition, ADDRESS_SIZE);
            ByteBuffer indexNodeBuffer = ByteBuffer.wrap(indexNode);
            long hashNodeAddress = indexNodeBuffer.getLong();
            byte[] hashNodeChecksumAddress = new byte[2];
            indexNodeBuffer.get(hashNodeChecksumAddress);

            if (!checkForCorruptedData(hashNodeAddress, hashNodeChecksumAddress, false)) {
                writeNewNodeAtIndex(bytesKey, address, size, indexPosition, 0L);
            } else {
                long currentPosition = hashNodeAddress;
                boolean end = false;

                while (!end) {
                    byte[] hashNode = this.db.readBytesAt(
                            currentPosition, HASH_NODE_SIZE);

                    ByteBuffer byteBuffer = ByteBuffer.wrap(hashNode);
                    byte[] k = new byte[KEY_SIZE];
                    byteBuffer.get(k);
                    long oldSize = byteBuffer.getLong();
                    long oldAddress = byteBuffer.getLong();
                    byte[] oldAddressChecksum = new byte[2];
                    byteBuffer.get(oldAddressChecksum);
                    long nextAddress = byteBuffer.getLong();
                    byte[] nextAddressChecksum = new byte[2];
                    byteBuffer.get(nextAddressChecksum);
                    long oldTimestamp = byteBuffer.getLong();

                    if (ByteUtil.compare(k, bytesKey)) {
                        if (TRACE_ENABLED) {
                            log.trace("The key " + DebugUtil.niceName(key)
                                    + " was used before and will be updated at "
                                    + DebugUtil.niceName(currentPosition));
                        }

                        // needs to replace (update) the hashNode
                        byte[] newHashNode = getAHashNode(
                                bytesKey, size, address, nextAddress, 0L);

                        this.body.replaceAt(currentPosition, newHashNode);

                        // TODO: need to free the oldAddress

                        end = true;
                    } else if (nextAddress != 0L) { // just go to next
                        checkForCorruptedData(nextAddress,
                                nextAddressChecksum, true);

                        if (TRACE_ENABLED) {
                            log.trace("The key " + DebugUtil.niceName(key)
                                    + " was not found yet. Going to next node: "
                                    + DebugUtil.niceName(nextAddress));
                        }

                        currentPosition = nextAddress;
                    } else {
                        // needs to update the nextAddress of currentHashNode
                        byte[] newHashNode = getAHashNode(
                                bytesKey, size, address, 0L, 0L);

                        long newHashNodeAddress
                                = this.allocateAndPut(newHashNode);

                        if (TRACE_ENABLED) {
                            log.trace("The key " + DebugUtil.niceName(key)
                                    + " was not found. Creating a new node at "
                                    + DebugUtil.niceName(newHashNodeAddress));
                        }

                        byte[] currentHashNode = getAHashNode(
                                k, oldAddress, oldSize, newHashNodeAddress,
                                oldTimestamp);

                        this.body.replaceAt(currentPosition, currentHashNode);
                        end = true;
                    }
                }
            }
        }
    }

    private boolean checkForCorruptedData(long address,
                                       byte[] checksumAddress,
                                       boolean throwException) throws IOException {

        if (ByteUtil.compare(ByteUtil.getChecksum(address), checksumAddress)) {
            return true;
        } else {
            // TODO: CORRUPTED DATA, WHAT TO DO NOW TO RECOVER?

            log.error("I'm so sorry. Some data is corrupted here, so"
                    + " it's possible you lost some valid keys. I'll just"
                    + " replace this corrupted node with the new one. address="
                    + address + " : checksumAddress=("
                    + checksumAddress[0] + "," + checksumAddress[1]);

            if (throwException) {
                throw new IOException("Corrupted data. " + address
                        + " seems to be invalid!");
            }

            return false;
        }
    }

    private long getIndexPositionByNumber(long positiveNumber) {
        return INDEX_START_POSITION
                + positiveNumber % (indexSizeInBytes / ADDRESS_SIZE)
                    * ADDRESS_SIZE;
    }

    private long getIndexPositionByKey(UUID key) {
        return getIndexPositionByNumber(
                Math.abs(key.getMostSignificantBits()
                        ^ key.getLeastSignificantBits()));
    }

    private void writeNewNodeAtIndex(byte[] bytesKey, long address, long size,
                                     long indexPosition, long nextAddress) throws IOException {

        byte[] hashNode = getAHashNode(bytesKey, size, address, nextAddress, 0L);
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

    public Pair<Long, Long> find(UUID key) throws IOException {
        Pair<Long, Long> result = null;

        final byte[] bytesKey = ByteUtil.UUID2bytes(key);
        final long indexPosition = getIndexPositionByKey(key);

        byte[] indexNode = this.db.readBytesAt(indexPosition, ADDRESS_SIZE);
        ByteBuffer indexNodeBuffer = ByteBuffer.wrap(indexNode);
        long hashNodeAddress = indexNodeBuffer.getLong();
        byte[] hashNodeChecksumAddress = new byte[2];
        indexNodeBuffer.get(hashNodeChecksumAddress);

        checkForCorruptedData(hashNodeAddress, hashNodeChecksumAddress, true);

        if (hashNodeAddress != 0) {
            long currentPosition = hashNodeAddress;
            boolean end = false;

            while (!end) {
                byte[] hashNode = this.db.readBytesAt(
                        currentPosition, HASH_NODE_SIZE);

                ByteBuffer byteBuffer = ByteBuffer.wrap(hashNode);
                byte[] k = new byte[KEY_SIZE];
                byteBuffer.get(k);
                long size = byteBuffer.getLong();
                long address = byteBuffer.getLong();
                byte[] addressChecksum = new byte[2];
                byteBuffer.get(addressChecksum);
                long nextAddress = byteBuffer.getLong();
                byte[] nextAddressChecksum = new byte[2];
                byteBuffer.get(nextAddressChecksum);
                //long oldTimestamp = byteBuffer.getLong();

                if (ByteUtil.compare(k, bytesKey)) {
                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was found at " + DebugUtil.niceName(currentPosition));
                    }

                    checkForCorruptedData(address, addressChecksum, true);

                    end = true;
                    result = new Pair<Long, Long>(address, size);

                } else if (nextAddress != 0L) { // just go to next
                    checkForCorruptedData(nextAddress,
                            nextAddressChecksum, true);

                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was not found yet. Going to next node: "
                                + DebugUtil.niceName(nextAddress));
                    }

                    currentPosition = nextAddress;
                } else {
                    if (TRACE_ENABLED) {
                        log.trace("The key " + DebugUtil.niceName(key)
                                + " was not found!");
                    }

                    end = true;
                    result = null;
                }
            }
        }

        return result;
    }
}
