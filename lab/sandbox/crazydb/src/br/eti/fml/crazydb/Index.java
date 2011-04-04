package br.eti.fml.crazydb;

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
    private static final int KEY_SIZE = 16;
    private static final int SIZE_SIZE = 8;
    private static final int CHECKSUM_SIZE = 2;
    private static final int ADDRESS_SIZE = 8 + CHECKSUM_SIZE;
    private static final int TIMESTAMP_SIZE = 8;
    private static final int HASH_NODE_SIZE = KEY_SIZE + SIZE_SIZE
            + ADDRESS_SIZE + ADDRESS_SIZE + TIMESTAMP_SIZE;
    
    private static final int BUFFER_SIZE = (int) (512 * ByteUtil.KB);

    private long indexSizeInBytes;

    private TheBigFile db;
    private Body body;

    public Index(TheBigFile db, Body body, int indexSizeInMegabytes) throws IOException {
        this.db = db;
        this.body = body;
        this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;

        if (!this.db.preallocate(indexSizeInBytes)) {
            log.debug("Nice! The index already was created before.");
        } else {
            log.debug("Filling with zeros...");
            this.db.fillWithZero(0L, indexSizeInBytes, BUFFER_SIZE);

            log.debug("Filling with zeros done! Thanks for wait.");
        }
    }
    
    protected static byte[] getHashNode(byte[] key, long size,
                                        long address, long nextAddress) {
        
        long timestamp = System.currentTimeMillis();

        byte[] addressChecksum = ByteUtil.getChecksum(address);
        byte[] nextAddressChecksum = ByteUtil.getChecksum(nextAddress);

        return ByteBuffer.allocate(HASH_NODE_SIZE).put(key).putLong(size)
                .putLong(address).put(addressChecksum).putLong(nextAddress)
                .put(nextAddressChecksum).putLong(timestamp).array();
    }

    public void updateIndex(UUID key, byte[] bytesKey, long address, long size) throws IOException {
        long indexPosition = Math.abs(key.getMostSignificantBits()
                ^ key.getLeastSignificantBits())
                % (indexSizeInBytes / ADDRESS_SIZE) * ADDRESS_SIZE;

        if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) { // the slot is free
            writeNode(bytesKey, address, size, indexPosition, 0L);
        } else { // need to find a free position
            long currentPosition = indexPosition;
            // while { ?

            boolean found = false;
            boolean end = false;

            while (!found && !end) {
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

                if (ByteUtil.compare(k, bytesKey)) {
                    writeNode(bytesKey, address, size,
                            currentPosition, nextAddress);

                    // TODO must free the old address

                    

                } else {
                    // TODO has next?
                }
            }
        }
    }

    private void writeNode(byte[] bytesKey, long address, long size,
                           long indexPosition, long nextAddress) throws IOException {

        byte[] hashNode = getHashNode(bytesKey, size, address, nextAddress);
        long nodeAddress = body.allocateAndPut(hashNode);
        this.db.putLongAt(indexPosition, nodeAddress);
        byte[] checkSum = ByteUtil.getChecksum(nodeAddress);
        this.db.putBytesAt(indexPosition + 8, checkSum);
    }
}
