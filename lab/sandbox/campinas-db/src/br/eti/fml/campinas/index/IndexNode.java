package br.eti.fml.campinas.index;

import br.eti.fml.campinas.util.DebugUtil;

import java.nio.ByteBuffer;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class IndexNode extends Node {
    // 96 bits - 12 bytes
    // ______________________________
    // 64 bits - addr          - 8 bytes
    // 32 bits - checksum      - 4 bytes

    public static final int ADDRESS_SIZE = 8;
    public static final int CHECKSUM_SIZE = 4;
    public static final int INDEX_NODE_SIZE = ADDRESS_SIZE + CHECKSUM_SIZE;

    private long hashNodeAddress;
    private int hashNodeChecksumAddress;
    private boolean empty;

    private ByteBuffer indexNode;

    public IndexNode(ByteBuffer indexNode) {
        super(Node.NodeType.INDEX_NODE);

        indexNode.position(0);
        hashNodeAddress = indexNode.getLong();
        hashNodeChecksumAddress = indexNode.getInt();

        this.indexNode = indexNode;
        int realChecksum = getChecksum(hashNodeAddress);

        this.empty = hashNodeChecksumAddress == 0 && hashNodeAddress == 0L;
        this.setCorruptedNode(!this.empty && realChecksum != hashNodeChecksumAddress);
    }

    private int getChecksum(long number) {
        return (int) ((~number) % Integer.MAX_VALUE);
    }

    public IndexNode(ByteBuffer tempBuffer, long hashNodeAddress) {
        super(Node.NodeType.INDEX_NODE);

        this.hashNodeAddress = hashNodeAddress;
        this.hashNodeChecksumAddress = getChecksum(hashNodeAddress);

        tempBuffer.position(0);
        this.indexNode = tempBuffer.putLong(hashNodeAddress)
                .putInt(hashNodeChecksumAddress);
    }

    public long getHashNodeAddress() {
        return hashNodeAddress;
    }

    public int getHashNodeChecksumAddress() {
        return hashNodeChecksumAddress;
    }

    public boolean isEmpty() {
        return empty;
    }

    public ByteBuffer getIndexNode() {
        indexNode.position(0);
        return indexNode;
    }

    @Override
    public String toString() {
        int realChecksum = getChecksum(hashNodeAddress);

        return "IndexNode{" +
                "hashNodeAddress=" + DebugUtil.niceName(hashNodeAddress) +
                ", hashNodeChecksumAddress=" + hashNodeChecksumAddress +
                ", realHashNodeChecksumAddress*=" + realChecksum +
                ", indexNode=" + Arrays.toString(indexNode.array()) +
                '}';
    }
}
