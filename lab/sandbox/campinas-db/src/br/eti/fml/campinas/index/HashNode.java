package br.eti.fml.campinas.index;

import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.DebugUtil;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class HashNode extends Node {
    // 432 bits - 54 bytes
    // ______________________________
    // 128 bits - key          - 16 bytes
    //   8 bits - flags        - 1 byte
    //   8 bits - address 1    - 1 byte
    //  64 bits - address 2    - 8 bytes
    //  64 bits - timestamp    - 8 bytes
    //  64 bits - left node    - 8 bytes
    //  64 bits - right node   - 8 bytes
    //  32 bits - checksum     - 4 bytes

    public static final int KEY_SIZE = 16;
    public static final int FLAGS_SIZE = 1;
    public static final int ADDRESS1_SIZE = 1;
    public static final int ADDRESS2_SIZE = 8;
    public static final int TIMESTAMP_SIZE = 8;
    public static final int LEFT_NODE = 8;
    public static final int RIGHT_NODE = 8;
    public static final int CHECKSUM_SIZE = 4;

    public static final int HASH_NODE_SIZE = KEY_SIZE + FLAGS_SIZE
            + ADDRESS1_SIZE + ADDRESS2_SIZE + TIMESTAMP_SIZE + LEFT_NODE
            + RIGHT_NODE + CHECKSUM_SIZE;

    private ByteBuffer hashNode;

    private byte[] key;
    private byte flags;
    private byte address1;
    private long address2;
    private long timestamp;
    private long leftNode;
    private long rightNode;
    private int checksum;       

    public HashNode(ByteBuffer hashNode) {
        super(Node.NodeType.HASH_NODE);

        hashNode.position(0);

        this.key = new byte[KEY_SIZE];
        hashNode.get(this.key);
        this.flags = hashNode.get();
        this.address1 = hashNode.get();
        this.address2 = hashNode.getLong();
        this.timestamp = hashNode.getLong();
        this.leftNode = hashNode.getLong();
        this.rightNode = hashNode.getLong();
        this.checksum = hashNode.getInt();

        ByteBuffer nodeBuffer = getNodeBufferWithoutChecksum(
                key, flags, address1, address2, leftNode, rightNode, timestamp);

        int realChecksum = Arrays.hashCode(nodeBuffer.array());
        this.setCorruptedNode(realChecksum != checksum);
    }

    public HashNode(byte[] key,
                    byte flags, byte address1, long address2,
                    long timestamp, long leftNode, long rightNode) {
        
        super(NodeType.HASH_NODE);

        assert key == null || key.length == 16;

        this.key = key;
        this.flags = flags;
        this.address1 = address1;
        this.address2 = address2;
        this.leftNode = leftNode;
        this.rightNode = rightNode;

        if (timestamp == 0L) {
            this.timestamp = System.currentTimeMillis();
        } else {
            this.timestamp = timestamp;
        }

        ByteBuffer nodeBuffer = getNodeBufferWithoutChecksum(
                key, flags, address1, address2, leftNode, rightNode, timestamp);

        this.checksum = Arrays.hashCode(nodeBuffer.array());

        nodeBuffer.putInt(this.checksum);
        this.hashNode = nodeBuffer;
    }

    private ByteBuffer getNodeBufferWithoutChecksum(
            byte[] key, byte flags, byte address1, long address2,
            long leftNode, long rightNode, long timestamp) {

        return ByteBuffer.allocate(HASH_NODE_SIZE)
                    .put(key).put(flags)
                    .put(address1).putLong(address2)
                    .putLong(leftNode).putLong(rightNode)
                    .putLong(timestamp);
    }

    public byte[] getKey() {
        return key;
    }

    public byte getFlags() {
        return flags;
    }

    public byte getAddress1() {
        return address1;
    }

    public long getAddress2() {
        return address2;
    }

    public long getTimestamp() {
        return timestamp;
    }

    public long getLeftNode() {
        return leftNode;
    }

    public long getRightNode() {
        return rightNode;
    }

    public int getChecksum() {
        return checksum;
    }

    public ByteBuffer getHashNode() {
        hashNode.position(0);
        return hashNode;
    }
    public interface HashNodeNavigator {
        void whenTheKeyIsEqual(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToLeftNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToRightNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void whenTheKeyWasNotFound(boolean isLeft, long currentPosition, HashNode currentHashNode) throws IOException;
        void corruptedHashNode(long currentPosition, HashNode currentHashNode) throws IOException;
    }

    public static void navigateThrough(
            long hashNodeAddress, byte[] bytesKey,
            FileChannel file, HashNodeNavigator navigator) throws IOException {

        assert bytesKey != null && bytesKey.length == 16;

        if (hashNodeAddress != 0L) {
            long currentPosition = hashNodeAddress;
            boolean end = false;

            while (!end) {
                ByteBuffer hashNodeRaw = ByteBuffer.allocate(HASH_NODE_SIZE);
                file.read(hashNodeRaw, currentPosition);

                final HashNode hashNode = new HashNode(hashNodeRaw);

                if (hashNode.isCorruptedNode()) {
                    navigator.corruptedHashNode(currentPosition, hashNode);
                    end = true;
                } else {
                    int compareResult = ByteUtil.compare(
                            hashNode.getKey(), bytesKey);

                    if (compareResult == 0) {
                        navigator.whenTheKeyIsEqual(currentPosition, hashNode);
                        end = true;
                    } else if (compareResult < 0
                            && hashNode.getLeftNode() != 0L) {

                        navigator.interceptGoingToLeftNode(
                                currentPosition, hashNode);

                        currentPosition = hashNode.getLeftNode();
                    } else if (compareResult > 0
                            && hashNode.getRightNode() != 0L) {

                        navigator.interceptGoingToRightNode(
                                currentPosition, hashNode);

                        currentPosition = hashNode.getRightNode();
                    } else {
                        navigator.whenTheKeyWasNotFound(
                                compareResult < 0, currentPosition, hashNode);

                        end = true;
                    }
                }
            }
        }
    }

    @Override
    public String toString() {
        return "HashNode{" +
                "hashNode=" + Arrays.toString(hashNode.array()) +
                ", key=" + Arrays.toString(key) +
                ", flags=" + DebugUtil.niceName(flags) +
                ", address1=" + DebugUtil.niceName(address1) +
                ", address2=" + DebugUtil.niceName(address2) +
                ", timestamp=" + timestamp +
                ", leftNode=" + DebugUtil.niceName(leftNode) +
                ", rightNode=" + DebugUtil.niceName(rightNode) +
                ", checksum=" + DebugUtil.niceName(checksum) +
                '}';
    }
}
