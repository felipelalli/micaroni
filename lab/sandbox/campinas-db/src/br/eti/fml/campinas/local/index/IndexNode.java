package br.eti.fml.campinas.local.index;

import br.eti.fml.campinas.util.DebugUtil;

import java.nio.ByteBuffer;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class IndexNode extends Node {
    // 64 bits - 8 bytes
    // ______________________________
    // 64 bits - address          - 8 bytes

    public static final int ADDRESS_SIZE = 8;
    public static final int INDEX_NODE_SIZE = ADDRESS_SIZE;
    public static final long NULL = -1L;

    private long hashNodeAddress;
    private boolean empty;

    private ByteBuffer indexNode;

    public IndexNode(ByteBuffer indexNode) {
        super(Node.NodeType.INDEX_NODE);

        indexNode.position(0);
        hashNodeAddress = indexNode.getLong();
        this.indexNode = indexNode;
        this.empty = (hashNodeAddress == NULL);
    }

    public IndexNode(ByteBuffer tempBuffer, long hashNodeAddress) {
        super(Node.NodeType.INDEX_NODE);

        this.hashNodeAddress = hashNodeAddress;
        tempBuffer.position(0);
        this.indexNode = tempBuffer.putLong(hashNodeAddress);
    }

    public long getHashNodeAddress() {
        return hashNodeAddress;
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
        return "IndexNode{" +
                "hashNodeAddress=" + DebugUtil.niceName(hashNodeAddress) +
                ", indexNode=" + Arrays.toString(indexNode.array()) +
                '}';
    }
}
