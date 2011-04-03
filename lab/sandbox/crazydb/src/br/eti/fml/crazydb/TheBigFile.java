package br.eti.fml.crazydb;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Arrays;

/**
 * A big file where the database will be stored.
 * <b>CAUTION: This class IS NOT thread safe.</b>
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class TheBigFile {
    private RandomAccessFile file;
    private String path;
    private String mode;

    /**
     * @param path The filesystem path
     * @param synchronize Forces a hard synchronization with the filesystem. It
     *                    can let the database ~ 300 times slower.
     *
     */
    public TheBigFile(String path, boolean synchronize) {
        this.path = path;

        if (synchronize) {
            this.mode = "rws";
        } else {
            this.mode = "rw";
        }

        try {
            this.file = new RandomAccessFile(this.path, this.mode);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() throws IOException {
        this.file.close();
        this.file = new RandomAccessFile(this.path, this.mode);
    }

    public boolean preallocate(long size) throws IOException {
        if (this.file.length() >= size) {
            return false;
        } else {
            this.file.setLength(size);
            return true;
        }
    }

    /**
     * 
     * @param index where the zeros must start
     * @param size the length of zeros
     * @param bufferSizeInBytes 1024 * 512 is a good value for big sizes
     * @throws IOException if something goes wrong with the disk
     */
    public void fillWithZero(long index, long size, int bufferSizeInBytes) throws IOException {
        this.file.seek(index);

        byte[] buffer = new byte[bufferSizeInBytes];
        Arrays.fill(buffer, (byte) 0);

        long filled = 0L;
        long remaining;

        do {
            remaining = size - filled;

            if (remaining >= buffer.length) {
                this.file.write(buffer);
                filled += buffer.length;
            } else {
                for (int i = 0; i < remaining; i++) {
                    filled++;
                    this.file.writeByte(0);
                }
            }
        } while (remaining > 0L);
    }

    public boolean checkIfPositionIsEqualTo(long indexPosition, long value) throws IOException {
        this.file.seek(indexPosition);
        long realValue = this.file.readLong();
        return realValue == value;
    }

    public long putAtTheEnd(byte[] data) throws IOException {
        long address = this.file.length();
        this.file.seek(address);
        this.file.write(data);
        return address;
    }

    public void putLongAt(long position, long value) throws IOException {
        this.file.seek(position);
        this.file.writeLong(value);
    }
}
