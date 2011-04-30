package br.eti.fml.campinas.local.index;

import java.nio.ByteBuffer;

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
    private static final long K = 38217372L;

    private long hashNodeAddress;
    private boolean empty;

    private ByteBuffer indexNode;

    public enum From {
        BINARY,
        VALUE
    }

    public IndexNode(ByteBuffer buffer, long address, From from) {
        super(Node.NodeType.INDEX_NODE);

        if (from.equals(From.VALUE)) {
            this.hashNodeAddress = filter(address);
            buffer.position(0);
            this.indexNode = buffer.putLong(hashNodeAddress);
        } else {
            buffer.position(0);
            hashNodeAddress = buffer.getLong();
            this.indexNode = buffer;
    
            if (hashNodeAddress != address) {
                setCorrupted(true);
            }
        }

        this.empty = !isCorrupted() && (hashNodeAddress == NULL);
    }

    public static long filter(long address) {
        return (address == NULL ? NULL : address ^ K);
    }

    public void fixNode(long newAddress) {
        this.hashNodeAddress = filter(newAddress);
        this.indexNode.position(0);
        this.indexNode.putLong(this.hashNodeAddress);
        setCorrupted(false);
    }

    public long getHashNodeAddress() {
        return filter(hashNodeAddress);
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
                "hashNodeAddress=" + hashNodeAddress +
                ",^hashNodeAddress=" + getHashNodeAddress() +
                ", empty=" + empty +
                ", indexNode=" + indexNode +
                ", isCorrupted=" + isCorrupted() +
                '}';
    }
}
