package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.ByteUtil;

import java.nio.ByteBuffer;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class IndexNode extends Node {
    //64 bits - addr - 8 bytes
    //16 bits - checksum - 2 bytes

    public static final int CHECKSUM_SIZE = 2;
    public static final int ADDRESS_SIZE = 8;
    public static final int INDEX_NODE_SIZE
            = ADDRESS_SIZE + CHECKSUM_SIZE;

    private long hashNodeAddress;
    private byte[] hashNodeChecksumAddress;

    private byte[] indexNode;

    public IndexNode(byte[] indexNode) {
        super(Node.NodeType.INDEX_NODE);

        ByteBuffer indexNodeBuffer = ByteBuffer.wrap(indexNode);
        hashNodeAddress = indexNodeBuffer.getLong();
        hashNodeChecksumAddress = new byte[2];
        indexNodeBuffer.get(hashNodeChecksumAddress);

        this.indexNode = indexNode;

        byte[] realChecksum = ByteUtil.getChecksum(hashNodeAddress);
        this.setCorruptedNode(!ByteUtil.compare(
                realChecksum, this.hashNodeChecksumAddress));
    }

    public IndexNode(long hashNodeAddress) {
        super(Node.NodeType.INDEX_NODE);

        this.hashNodeAddress = hashNodeAddress;
        this.hashNodeChecksumAddress = ByteUtil.getChecksum(hashNodeAddress);

        this.indexNode = ByteBuffer
                .allocate(INDEX_NODE_SIZE).putLong(hashNodeAddress)
                .put(hashNodeChecksumAddress).array();
    }

    public long getHashNodeAddress() {
        return hashNodeAddress;
    }

    public byte[] getIndexNode() {
        return indexNode;
    }

    @Override
    public String toString() {
        return "IndexNode{" +
                "hashNodeAddress=" + hashNodeAddress +
                ", hashNodeChecksumAddress="
                        + Arrays.toString(hashNodeChecksumAddress) +
                ", hashNodeChecksumAddress should be="
                        + Arrays.toString(ByteUtil.getChecksum(hashNodeAddress)) +
                ", *indexNode=" + Arrays.toString(indexNode) +
                '}';
    }
}
