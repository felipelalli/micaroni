package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.CorruptedData;
import br.eti.fml.crazydb.TheBigFile;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.nio.ByteBuffer;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class HashNode {
    private static final Logger log = Logger.getLogger(HashNode.class);

    //128 bits - key - 16 bytes
    //64 bits - size - 8 bytes
    //64 bits - address - 8 bytes
    //16 bits - checksum address - 2 bytes
    //64 bits - next addr - 8 bytes
    //16 bits - checksum next address - 2 bytes
    //64 bits - timestamp - 8 bytes

    public static final int KEY_SIZE = 16;
    public static final int SIZE_SIZE = 8;
    public static final int TIMESTAMP_SIZE = 8;
    public static final int HASH_NODE_SIZE = KEY_SIZE + SIZE_SIZE
            + IndexNode.ADDRESS_SIZE + IndexNode.ADDRESS_SIZE + TIMESTAMP_SIZE;

    private byte[] hashNode;
    private byte[] key;
    private long size;
    private long address;
    private byte[] addressChecksum;
    private long nextAddress;
    private byte[] nextAddressChecksum;
    private long timestamp;

    public HashNode(byte[] key, long size, long address,
                    long nextAddress, long timestamp) {

        this.key = key;
        this.size = size;
        this.address = address;
        this.nextAddress = nextAddress;
        this.timestamp = timestamp;

        if (timestamp == 0L) {
            timestamp = System.currentTimeMillis();
        }

        this.addressChecksum = ByteUtil.getChecksum(address);
        this.nextAddressChecksum = ByteUtil.getChecksum(nextAddress);

        this.hashNode = ByteBuffer.allocate(HASH_NODE_SIZE).put(key).putLong(size)
                .putLong(address).put(addressChecksum).putLong(nextAddress)
                .put(nextAddressChecksum).putLong(timestamp).array();
    }

    public HashNode(byte[] hashNode) {
        this.hashNode = hashNode;

        ByteBuffer byteBuffer = ByteBuffer.wrap(hashNode);
        this.key = new byte[KEY_SIZE];
        byteBuffer.get(this.key);
        this.size = byteBuffer.getLong();
        this.address = byteBuffer.getLong();
        this.addressChecksum = new byte[2];
        byteBuffer.get(addressChecksum);
        this.nextAddress = byteBuffer.getLong();
        this.nextAddressChecksum = new byte[2];
        byteBuffer.get(nextAddressChecksum);
        this.timestamp = byteBuffer.getLong();
    }

    public byte[] getHashNode() {
        return hashNode;
    }

    public byte[] getKey() {
        return key;
    }

    public long getSize() {
        return size;
    }

    public long getAddress() {
        return address;
    }

    public long getNextAddress() {
        return nextAddress;
    }

    public long getTimestamp() {
        return timestamp;
    }

    public void checkForCorruptedDataInNextAddress() throws CorruptedData {
        byte[] realChecksum = ByteUtil.getChecksum(nextAddress);

        if (!ByteUtil.compare(realChecksum, this.nextAddressChecksum)) {
            // TODO: CORRUPTED DATA, WHAT TO DO NOW TO RECOVER?

            log.fatal("I'm so sorry! Next address is corrupted here. address="
                    + nextAddress + " : nextAddressChecksum=("
                    + nextAddressChecksum[0] + "," + nextAddressChecksum[1]
                    + " and should be (" + realChecksum[0] + "," + realChecksum[1] + ")");

            log.fatal("NEXT ADDRESS IS CORRUPTED! WHAT NOW?");

            throw new CorruptedData("Corrupted data. " + nextAddress
                    + " seems to be invalid!");
        }
    }

    public void checkForCorruptedDataInAddress() throws CorruptedData {
        byte[] realChecksum = ByteUtil.getChecksum(address);

        if (!ByteUtil.compare(realChecksum, this.addressChecksum)) {
            // TODO: CORRUPTED DATA, WHAT TO DO NOW TO RECOVER?

            log.fatal("The address is corrupted here. address="
                    + address + " : checksumAddress=("
                    + addressChecksum[0] + "," + addressChecksum[1]
                    + " and should be (" + realChecksum[0] + "," + realChecksum[1] + ")");

            log.fatal("ADDRESS IS CORRUPTED! WHAT NOW?");

            throw new CorruptedData("Corrupted data. " + address + " seems to be invalid!");
        }
    }

    public interface HashNodeNavigator {
        void whenTheKeyIsEqual(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToNextNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void whenTheKeyWasNotFound(long currentPosition, HashNode currentHashNode) throws IOException;
    }

    public static void navigateThrough(long hashNodeAddress, byte[] bytesKey,
                                       TheBigFile db, HashNodeNavigator navigator) throws IOException {

        if (hashNodeAddress != 0L) {
            long currentPosition = hashNodeAddress;
            boolean end = false;

            while (!end) {
                final byte[] hashNodeRaw = db.readBytesAt(
                        currentPosition, HashNode.HASH_NODE_SIZE);

                final HashNode hashNode = new HashNode(hashNodeRaw);

                if (bytesKey != null && ByteUtil.compare(hashNode.getKey(), bytesKey)) {
                    hashNode.checkForCorruptedDataInAddress();
                    navigator.whenTheKeyIsEqual(currentPosition, hashNode);
                    end = true;
                } else if (hashNode.getNextAddress() != 0L) { // just go to next
                    hashNode.checkForCorruptedDataInNextAddress();
                    navigator.interceptGoingToNextNode(currentPosition, hashNode);
                    currentPosition = hashNode.getNextAddress();
                } else {
                    end = true;
                    navigator.whenTheKeyWasNotFound(currentPosition, hashNode);
                }
            }
        }
    }
}
