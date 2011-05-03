package br.eti.fml.campinas.local.index;

import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.DebugUtil;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class HashNode extends Node {
    private static final Logger log = Logger.getLogger(HashNode.class);

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

    public static final long NULL = -1L;
    public static final long NOW = 0L;

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

        final byte[] fullNode = new byte[HASH_NODE_SIZE];
        hashNode.position(0);
        hashNode.get(fullNode);

        hashNode.position(0);

        this.key = new byte[KEY_SIZE];
        hashNode.get(this.key);
        this.flags = hashNode.get();
        this.address1 = hashNode.get();
        this.address2 = hashNode.getLong();
        this.leftNode = hashNode.getLong();
        this.rightNode = hashNode.getLong();
        this.timestamp = hashNode.getLong();
        this.checksum = hashNode.getInt();

        final byte[] hashNodeWithoutChecksum
                = new byte[HASH_NODE_SIZE - CHECKSUM_SIZE];
        
        hashNode.position(0);
        hashNode.get(hashNodeWithoutChecksum);

        int realChecksum = Arrays.hashCode(hashNodeWithoutChecksum);
        this.setCorrupted(realChecksum != checksum);
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

        ByteBuffer newBuffer = ByteBuffer.allocate(HASH_NODE_SIZE);

        newBuffer.put(this.key).put(this.flags).put(this.address1)
                .putLong(this.address2).putLong(this.leftNode).putLong(this
                .rightNode).putLong(this.timestamp);

        newBuffer.position(0);
        final byte[] nodeBuffer = new byte[HASH_NODE_SIZE - CHECKSUM_SIZE];
        newBuffer.get(nodeBuffer);
        this.checksum = Arrays.hashCode(nodeBuffer);

        newBuffer.putInt(this.checksum);
        this.hashNode = newBuffer;
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

    @SuppressWarnings("unused")
    public long getTimestamp() {
        return timestamp;
    }

    public long getLeftNode() {
        return leftNode;
    }

    public long getRightNode() {
        return rightNode;
    }

    @SuppressWarnings("unused")
    public int getChecksum() {
        return checksum;
    }

    public ByteBuffer getHashNode() {
        assert hashNode != null;
        hashNode.position(0);
        return hashNode;
    }

    public interface HashNodeNavigator {
        void whenTheKeyIsEqual(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToLeftNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void interceptGoingToRightNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void whenTheKeyWasNotFound(boolean isLeft, long currentPosition, HashNode currentHashNode) throws IOException;
        void corruptedHashNode(long currentPosition, HashNode currentHashNode, int level) throws IOException;
    }

    public interface HashNodeFullyNavigator {
        void updateCurrentNode(long currentPosition, HashNode currentHashNode) throws IOException;
        void corruptedHashNode(long currentPosition, HashNode currentHashNode, int level) throws IOException;
        void nodeHasLeft(long currentPosition, HashNode currentHashNode) throws IOException;
        void nodeHasRight(long currentPosition, HashNode currentHashNode) throws IOException;
    }

    public static void navigateThroughFully(
            long hashNodeAddress,
            final FileChannel file,
            final HashNodeFullyNavigator navigator) throws IOException {

        final Stack<Long> nextAddress = new Stack<Long>();
        final Set<Long> usedAddresses = new HashSet<Long>();

        long now = System.currentTimeMillis();

        if (hashNodeAddress != HashNode.NULL) {
            nextAddress.push(hashNodeAddress);

            while (nextAddress.size() > 0) {
                final long currentPosition = nextAddress.pop();
                usedAddresses.add(currentPosition);

                if (System.currentTimeMillis() - now > 10000) {
                    log.trace("Navigating yet... stack size: " + nextAddress.size()
                            + " currentPosition=" + currentPosition);

                    now = System.currentTimeMillis();
                }

                ByteBuffer tempBuffer = ByteBuffer.allocate(HASH_NODE_SIZE);
                file.read(tempBuffer, currentPosition);

                final HashNode hashNode = new HashNode(tempBuffer);
                navigator.updateCurrentNode(currentPosition, hashNode);

                if (hashNode.isCorrupted()) {
                    navigator.corruptedHashNode(currentPosition,
                            hashNode, usedAddresses.size());
                } else {
                    long leftNode = hashNode.getLeftNode();

                    if (leftNode != HashNode.NULL) {
                        if (usedAddresses.contains(leftNode)) {
                            log.error("Something is crazy here! The LEFT node "
                                    + DebugUtil.niceName(leftNode)
                                    + " was used before! current hash node: "
                                    + hashNode + ". Level: "
                                    + usedAddresses.size());
                        } else {
                            nextAddress.push(leftNode);
                            navigator.nodeHasLeft(
                                    currentPosition, hashNode);
                        }
                    }

                    long rightNode = hashNode.getRightNode();

                    if (rightNode != HashNode.NULL) {
                        if (usedAddresses.contains(rightNode)) {
                            log.error("Something is crazy here! The RIGHT node "
                                    + DebugUtil.niceName(rightNode)
                                    + " was used before! current hash node: "
                                    + hashNode + ". Level: "
                                    + usedAddresses.size());
                        } else {
                            nextAddress.push(rightNode);
                            navigator.nodeHasRight(
                                    currentPosition, hashNode);
                        }
                    }
                }

                tempBuffer.clear();
            }
        }
    }

    public static void navigateThroughToFindAKey(
            long hashNodeAddress,
            final byte[] bytesKey,
            final FileChannel file,
            final HashNodeNavigator navigator) throws IOException {

        assert bytesKey != null && bytesKey.length == 16;

        final Set<Long> usedAddresses = new HashSet<Long>();

        if (hashNodeAddress != HashNode.NULL) {
            final AtomicInteger level = new AtomicInteger(0);
            final AtomicLong currentPosition = new AtomicLong(hashNodeAddress);
            final AtomicBoolean end = new AtomicBoolean(false);

            while (!end.get()) {
                if (usedAddresses.contains(currentPosition.get())) {
                        log.error("Something is crazy here! The index position "
                                + DebugUtil.niceName(currentPosition.get())
                                + " was used before! Level: " + level.get());
                } else {
                    usedAddresses.add(currentPosition.get());

                    ByteBuffer tempBuffer = ByteBuffer.allocate(HASH_NODE_SIZE);
                    file.read(tempBuffer, currentPosition.get());
                    final HashNode hashNode = new HashNode(tempBuffer);

                    if (hashNode.isCorrupted()) {
                        navigator.corruptedHashNode(
                                currentPosition.get(), hashNode,
                                level.get());

                        end.set(true);
                    } else {
                        int compareResult = ByteUtil.compare(
                                hashNode.getKey(), bytesKey);

                        if (compareResult == 0) {
                            navigator.whenTheKeyIsEqual(
                                    currentPosition.get(), hashNode);

                            end.set(true);
                        } else if (compareResult < 0
                                && hashNode.getLeftNode()
                                != HashNode.NULL) {

                            navigator.interceptGoingToLeftNode(
                                    currentPosition.get(), hashNode);

                            currentPosition.set(
                                    hashNode.getLeftNode());

                            level.incrementAndGet();
                        } else if (compareResult > 0
                                && hashNode.getRightNode()
                                != HashNode.NULL) {

                            navigator.interceptGoingToRightNode(
                                    currentPosition.get(), hashNode);

                            currentPosition.set(
                                    hashNode.getRightNode());

                            level.incrementAndGet();
                        } else {
                            navigator.whenTheKeyWasNotFound(
                                    compareResult < 0,
                                    currentPosition.get(), hashNode);

                            end.set(true);
                        }
                    }

                    tempBuffer.clear();
                }
            }
        }
    }

    @Override
    public String toString() {
        int realChecksum = -1;
        byte[] hashNodeBytes = null;

        if (this.hashNode != null) {
            final byte[] hashNodeWithoutChecksum = new byte[HASH_NODE_SIZE - CHECKSUM_SIZE];
            this.getHashNode().get(hashNodeWithoutChecksum);
            realChecksum = Arrays.hashCode(hashNodeWithoutChecksum);

            hashNodeBytes = new byte[HASH_NODE_SIZE];
            hashNode.position(0);
            hashNode.get(hashNodeBytes);
        }

        return "HashNode{" +
                "hashNode=" + (this.hashNode == null ? null : Arrays.toString
                                (hashNodeBytes)) +
                ", key=" + Arrays.toString(key) +
                ", flags=" + DebugUtil.niceName(flags) +
                ", address1=" + DebugUtil.niceName(address1) +
                ", address2=" + DebugUtil.niceName(address2) +
                ", timestamp=" + timestamp +
                ", leftNode=" + DebugUtil.niceName(leftNode) +
                ", rightNode=" + DebugUtil.niceName(rightNode) +
                ", checksum=" + checksum +
                ", *realChecksum= " + realChecksum +
                '}';
    }
}
