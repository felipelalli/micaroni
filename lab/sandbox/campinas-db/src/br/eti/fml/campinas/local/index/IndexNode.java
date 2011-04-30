package br.eti.fml.campinas.local.index;

import java.nio.ByteBuffer;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class IndexNode extends Node {
    // 64 bits - 8 bytes
    // ______________________________
    // 64 bits - address          - 8 bytes
    // 64 bits - lazy address     - 8 bytes

    public static final int ADDRESS_SIZE = 8;
    public static final int INDEX_NODE_SIZE = ADDRESS_SIZE * 2;
    public static final long NULL = -1L;
    private static final long K = 38217372L;

    private long hashNodeAddress;
    private long lazyHashNodeAddress;
    private boolean empty;

    private ByteBuffer indexNode;

    public IndexNode(ByteBuffer buffer) {
        super(Node.NodeType.INDEX_NODE);

        buffer.position(0);
        hashNodeAddress = buffer.getLong();
        lazyHashNodeAddress = buffer.getLong();
        this.indexNode = buffer;

        if (hashNodeAddress != lazyHashNodeAddress) {
            setCorrupted(true);
        }

        this.empty = !isCorrupted() && (hashNodeAddress == NULL);
    }

    public IndexNode(ByteBuffer buffer, long address) {
        super(Node.NodeType.INDEX_NODE);

        this.hashNodeAddress = filter(address);
        this.lazyHashNodeAddress = this.hashNodeAddress;
        buffer.position(0);
        this.indexNode = buffer.putLong(hashNodeAddress).putLong(hashNodeAddress);

        this.empty = !isCorrupted() && (hashNodeAddress == NULL);
    }

    public static long filter(long address) {
        return (address == NULL ? NULL : address ^ K);
    }

    public void fixNode(long newAddress) {
        this.hashNodeAddress = filter(newAddress);
        this.lazyHashNodeAddress = this.hashNodeAddress;
        this.indexNode.position(0);
        this.indexNode.putLong(this.hashNodeAddress).putLong(this.hashNodeAddress);
        setCorrupted(false);
    }

    public long getHashNodeAddress() {
        return filter(hashNodeAddress);
    }

    public long getLazyHashNodeAddress() {
        return filter(lazyHashNodeAddress);
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
                ",lazyHashNodeAddress=" + lazyHashNodeAddress +
                ",^lazyHashNodeAddress=" + getLazyHashNodeAddress() +
                ", empty=" + empty +
                ", indexNode=" + indexNode +
                ", isCorrupted=" + isCorrupted() +
                '}';
    }
}
