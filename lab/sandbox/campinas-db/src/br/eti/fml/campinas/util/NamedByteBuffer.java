package br.eti.fml.campinas.util;

import java.nio.ByteBuffer;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class NamedByteBuffer implements Comparable<NamedByteBuffer> {
    private static final Random random = new Random();

    private long name;
    private int size;
    private ByteBuffer byteBuffer;

    public NamedByteBuffer(int size) {
        this.name = random.nextLong();
        this.size = size;
        this.byteBuffer = ByteBuffer.allocateDirect(size);
    }

    @Override
    public void finalize() throws Throwable {
        this.byteBuffer.clear();
        super.finalize();
    }

    public ByteBuffer getByteBufferAndResetPosition() {
        this.byteBuffer.position(0);
        return this.byteBuffer;
    }

    public int getSize() {
        return size;
    }

    @Override
    public int compareTo(NamedByteBuffer o) {
        return this.name < o.name ? -1
                : this.name > o.name ? 1
                : 0;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        NamedByteBuffer that = (NamedByteBuffer) o;
        return name == that.name;
    }

    @Override
    public int hashCode() {
        return (int) (name ^ (name >>> 32));
    }

    public long getName() {
        return name;
    }
}
