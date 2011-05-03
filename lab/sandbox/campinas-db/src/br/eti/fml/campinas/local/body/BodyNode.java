package br.eti.fml.campinas.local.body;

import java.nio.ByteBuffer;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class BodyNode {
    public static final int FLAGS_SIZE = 1;
    public static final int SIZE_SIZE = 4;
    public static final int CHECKSUM_SIZE = 4;

    // TODO: checksum, flags, size and data
    private int realSize;

    public BodyNode(int realSize) {
        this.realSize = realSize;
    }

    public int getTotalSize() {
        return this.realSize + CHECKSUM_SIZE + SIZE_SIZE + FLAGS_SIZE;
    }

    public ByteBuffer getNewByteBuffer(byte[] data, byte flags) {
        ByteBuffer buffer = ByteBuffer.allocateDirect(getTotalSize());
        int checksum = Arrays.hashCode(data);
        buffer.putInt(checksum).putInt(data.length).put(flags).put(data);
        buffer.position(0);
        return buffer;
    }
}
