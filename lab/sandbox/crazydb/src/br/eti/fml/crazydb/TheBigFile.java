package br.eti.fml.crazydb;

import org.apache.log4j.Logger;

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
    private static final Logger log = Logger.getLogger(TheBigFile.class);

    private RandomAccessFile file;
    private String name;

    /**
     * @param exclusiveName The exclusiveName of database
     * @param path          The filesystem path
     * @param synchronize   Forces a hard synchronization with the filesystem. It
     *                      can let the database ~ 300 times slower.
     */
    public TheBigFile(String exclusiveName, String path, boolean synchronize) {
        assert exclusiveName.length() > 0;
        assert exclusiveName.length() < 512;

        this.name = exclusiveName;

        String mode;
        if (synchronize) {
            mode = "rws";
        } else {
            mode = "rw";
        }

        try {
            this.file = new RandomAccessFile(path, mode);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void flush() throws IOException {
        log.trace("Flushing file to disk...");
        this.file.getChannel().force(true);
    }

    public void close() throws IOException {
        this.flush();
        this.file.close();
    }

    public boolean preallocate(long size) throws IOException {
        if (this.file.length() >= size) {
            return false;
        } else {
            log.debug("Allocating " + (size / 1024 / 1024) + " MB...");
            this.file.setLength(size);
            return true;
        }
    }

    /**
     * @param index             where the zeros must start
     * @param size              the length of zeros
     * @param bufferSizeInBytes 1024 * 512 is a good value for big sizes
     * @throws IOException if something goes wrong with the disk
     */
    public void fillWithZero(long index, long size, int bufferSizeInBytes) throws IOException {
        this.file.seek(index);

        byte[] buffer = new byte[bufferSizeInBytes];
        Arrays.fill(buffer, (byte) 0);

        int filled = 0;
        long remaining;

        do {
            remaining = size - filled;

            if (remaining >= buffer.length) {
                this.file.write(buffer);
                filled += buffer.length;
            } else {
                assert remaining < Integer.MAX_VALUE;

                this.file.write(buffer, 0, (int) remaining);
                filled += remaining;
            }
        } while (remaining > 0L);
    }

    public boolean checkIfPositionIsEqualTo(long indexPosition, long value) throws IOException {
        this.file.seek(indexPosition);
        long realValue = this.file.readLong();
        return realValue == value;
    }

    public byte[] readBytesAt(long position, int size) throws IOException {
        this.file.seek(position);
        byte[] read = new byte[size];
        this.file.read(read);
        return read;
    }

    public void putLongAt(long position, long value) throws IOException {
        this.file.seek(position);
        this.file.writeLong(value);
    }

    public void putBytesAt(long position, byte[] bytes) throws IOException {
        this.file.seek(position);
        this.file.write(bytes);
    }

    public String getName() {
        return name;
    }

    public long length() throws IOException {
        return this.file.length();
    }

    public void setLength(long bigSize) throws IOException {
        this.file.setLength(bigSize);
    }

    public long readLongAt(long position) throws IOException {
        this.file.seek(position);
        return this.file.readLong();
    }
}
