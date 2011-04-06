package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.TheBigFile;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class HashNode extends Node {
    // 464 bits - 56 bytes
    // ______________________________
    // 128 bits - key - 16 bytes
    //  64 bits - size - 8 bytes
    //  64 bits - address - 8 bytes
    //  32 bits - checksum data - 4 bytes
    //  64 bits - next addr - 8 bytes
    //  64 bits - timestamp - 8 bytes
    //  32 bits - checksum node - 4 bytes

    public static final int KEY_SIZE = 16;
    public static final int SIZE_SIZE = 8;
    public static final int CHECKSUM_DATA_SIZE = 4;
    public static final int TIMESTAMP_SIZE = 8;
    public static final int CHECKSUM_NODE_SIZE = 4;
    public static final int HASH_NODE_SIZE = KEY_SIZE + SIZE_SIZE
            + IndexNode.ADDRESS_SIZE + CHECKSUM_DATA_SIZE
            + IndexNode.ADDRESS_SIZE + TIMESTAMP_SIZE + CHECKSUM_NODE_SIZE;

    private byte[] hashNode;

    private byte[] key;
    private long size;
    private long address;
    private int checksumData;
    private long nextAddress;
    private long timestamp;
    private int checksumNode;

    public HashNode(byte[] key, long size, long address, int checksumData,
                    long nextAddress, long timestamp) {

        super(Node.NodeType.HASH_NODE);

        this.key = key;
        this.size = size;
        this.address = address;
        this.checksumData = checksumData;
        this.nextAddress = nextAddress;

        if (timestamp == 0L) {
            this.timestamp = System.currentTimeMillis();
        } else {
            this.timestamp = timestamp;
        }

        ByteBuffer nodeBuffer = ByteBuffer.allocate(HASH_NODE_SIZE)
                .put(key).putLong(size)
                .putLong(address).putInt(checksumData).putLong(nextAddress)
                .putLong(timestamp);

        this.checksumNode = Arrays.hashCode(nodeBuffer.array());

        nodeBuffer.putInt(this.checksumNode);
        this.hashNode = nodeBuffer.array();
    }

    public HashNode(byte[] hashNode) {
        super(Node.NodeType.HASH_NODE);

        this.hashNode = hashNode;

        ByteBuffer byteBuffer = ByteBuffer.wrap(hashNode);
        this.key = new byte[KEY_SIZE];
        byteBuffer.get(this.key);
        this.size = byteBuffer.getLong();
        this.address = byteBuffer.getLong();
        this.checksumData = byteBuffer.getInt();
        this.nextAddress = byteBuffer.getLong();
        this.timestamp = byteBuffer.getLong();
        this.checksumNode = byteBuffer.getInt();

        ByteBuffer nodeBuffer = ByteBuffer.allocate(HASH_NODE_SIZE)
                .put(key).putLong(size)
                .putLong(address).putInt(checksumData).putLong(nextAddress)
                .putLong(timestamp);

        int realChecksum = Arrays.hashCode(nodeBuffer.array());
        this.setCorruptedNode(realChecksum != checksumNode);
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

    public int getChecksumData() {
        return checksumData;
    }

    public long getNextAddress() {
        return nextAddress;
    }

    public long getTimestamp() {
        return timestamp;
    }

    public interface HashNodeNavigator {
        void whenTheKeyIsEqual(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToNextNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void whenTheKeyWasNotFound(long currentPosition, HashNode currentHashNode) throws IOException;
        void corruptedHashNode(long currentPosition, HashNode currentHashNode) throws IOException;
    }

    public static void navigateThrough(
            long hashNodeAddress, byte[] bytesKey,
            TheBigFile db, HashNodeNavigator navigator) throws IOException {

        if (hashNodeAddress != 0L) {
            long currentPosition = hashNodeAddress;
            boolean end = false;

            while (!end) {
                final byte[] hashNodeRaw = db.readBytesAt(
                        currentPosition, HashNode.HASH_NODE_SIZE);

                final HashNode hashNode = new HashNode(hashNodeRaw);

                if (hashNode.isCorruptedNode()) {
                    navigator.corruptedHashNode(currentPosition, hashNode);
                    end = true;
                } if (bytesKey != null
                        && ByteUtil.compare(hashNode.getKey(), bytesKey)) {

                    navigator.whenTheKeyIsEqual(currentPosition, hashNode);
                    end = true;
                } else if (hashNode.getNextAddress() != 0L) { // just go to next
                    navigator.interceptGoingToNextNode(currentPosition, hashNode);
                    currentPosition = hashNode.getNextAddress();
                } else {
                    navigator.whenTheKeyWasNotFound(currentPosition, hashNode);
                    end = true;
                }
            }
        }
    }

    @Override
    public String toString() {
        ByteBuffer nodeBuffer = ByteBuffer.allocate(HASH_NODE_SIZE)
                .put(key).putLong(size)
                .putLong(address).putInt(checksumData).putLong(nextAddress)
                .putLong(timestamp);

        int realChecksum = Arrays.hashCode(nodeBuffer.array());

        return "HashNode{" +
                "key=" + Arrays.toString(key) +
                ", size=" + size +
                ", address=" + address +
                ", checksumData=" + checksumData +
                ", nextAddress=" + nextAddress +
                ", timestamp=" + timestamp +
                ", checksumNode=" + checksumNode +
                ", checksumNode should be=" + realChecksum +
                ", *hashNode=" + Arrays.toString(hashNode) +
                "}";
    }
}
