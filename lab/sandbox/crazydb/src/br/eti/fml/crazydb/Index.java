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
        //this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;

        this.indexSizeInBytes = 3 * ADDRESS_SIZE; // TODO: JUST FOR DEBUG

        if (!this.db.preallocate(indexSizeInBytes)) {
            log.debug("Nice! The index already was created before.");
        } else {
            log.debug("Filling with zeros...");
            this.db.fillWithZero(0L, indexSizeInBytes, BUFFER_SIZE);

            log.debug("Filling with zeros done! Thanks for wait.");
        }
    }
    
    protected static byte[] getAHashNode(byte[] key, long size,
                                         long address, long nextAddress) {
        
        long timestamp = System.currentTimeMillis();

        byte[] addressChecksum = ByteUtil.getChecksum(address);
        byte[] nextAddressChecksum = ByteUtil.getChecksum(nextAddress);

        return ByteBuffer.allocate(HASH_NODE_SIZE).put(key).putLong(size)
                .putLong(address).put(addressChecksum).putLong(nextAddress)
                .put(nextAddressChecksum).putLong(timestamp).array();
    }

    public void updateIndex(UUID key, long address, long size) throws IOException {
        final byte[] bytesKey = ByteUtil.UUID2bytes(key);

        long indexPosition = Math.abs(key.getMostSignificantBits()
                ^ key.getLeastSignificantBits())
                % (indexSizeInBytes / ADDRESS_SIZE) * ADDRESS_SIZE;

        if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) { // the slot is free
            log.trace("The slot is free, recording new node at " + indexPosition + " index position.");
            writeNewNodeAtIndex(bytesKey, address, size, indexPosition, 0L);
        } else { // need to find a free position
            log.trace("The slot " + indexPosition + " is used. Trying to find the key or a free slot.");

            byte[] indexNode = this.db.readBytesAt(indexPosition, ADDRESS_SIZE);
            ByteBuffer indexNodeBuffer = ByteBuffer.wrap(indexNode);
            long hashNodeAddress = indexNodeBuffer.getLong();
            byte[] hashNodeChecksumAddress = new byte[2];
            indexNodeBuffer.get(hashNodeChecksumAddress);

            if (!ByteUtil.compare(ByteUtil.getChecksum(hashNodeAddress),
                    hashNodeChecksumAddress)) {

                // TODO: CORRUPTED DATA, WHAT TO DO NOW TO RECOVER?

                log.error("I'm so sorry. Some data is corrupted here, so"
                        + " it's possible you lost some valid keys. I'll just"
                        + " replace this corrupted node with the new one.");

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

                    if (ByteUtil.compare(k, bytesKey)) {
                        log.trace("The key " + key + " was used before and will be updated.");

                        // needs to replace (update) the hashNode
                        byte[] newHashNode = getAHashNode(
                                bytesKey, size, address, nextAddress);

                        this.body.replaceAt(currentPosition, newHashNode);

                        // TODO: need to free the oldAddress

                        end = true;
                    } else if (nextAddress != 0L) { // just go to next
                        log.trace("The key " + key + " was not found yet. Going to next node.");
                        currentPosition = nextAddress;
                    } else {
                        // needs to update the nextAddress of currentHashNode
                        byte[] newHashNode = getAHashNode(
                                bytesKey, size, address, 0L);

                        long newHashNodeAddress
                                = this.body.allocateAndPut(newHashNode);

                        log.trace("The key " + key + " was not found. Creating a new node at "
                                + newHashNodeAddress);

                        byte[] currentHashNode = getAHashNode(
                                k, oldAddress, oldSize, newHashNodeAddress);                                             

                        this.body.replaceAt(currentPosition, currentHashNode);
                        end = true;
                    }
                }
            }
        }
    }

    private void writeNewNodeAtIndex(byte[] bytesKey, long address, long size,
                                     long indexPosition, long nextAddress) throws IOException {

        byte[] hashNode = getAHashNode(bytesKey, size, address, nextAddress);
        long nodeAddress = this.body.allocateAndPut(hashNode);
        this.db.putLongAt(indexPosition, nodeAddress);
        byte[] checkSum = ByteUtil.getChecksum(nodeAddress);
        this.db.putBytesAt(indexPosition + 8, checkSum);
    }
}
