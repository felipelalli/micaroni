package br.eti.fml.campinas.local;

import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class MetaInfo {
    private static final Logger log = Logger.getLogger(MetaInfo.class);

    // 4232 bits - 529 bytes
    // ______________________________
    //     8 bits - closed          - 1 byte
    //  4096 bits - name            - 512 bytes
    //    32 bits - index size MB   - 4 bytes
    //    64 bits - creation time   - 8 bytes
    //    32 bits - version (float) - 4 bytes

    private static final float VERSION = 0.1f;
    private static final int META_INFO_SIZE = 1 + 512 + 4 + 8 + 4;

    private boolean firstTime;

    private RandomAccessFile file;
    private FileChannel channel;
    private FileLock lock;
    
    private String name;

    // cache
    private static ByteBuffer buffer
            = ByteBuffer.allocateDirect(META_INFO_SIZE);

    public MetaInfo(String name, File directoryPath) throws IOException {
        assert name.length() > 0;
        assert name.length() < 512;

        this.name = name;

        File f = new File(directoryPath.getAbsolutePath()
                + File.separator + "meta-info");

        this.file = new RandomAccessFile(f, "rw");
        this.channel = this.file.getChannel();
        this.lock = this.channel.tryLock();

        if (this.lock == null) {
            throw new IOException("MetaInfo in '"
                    + directoryPath.getAbsolutePath()
                    + "' is locked! Unlock it first.");
        }

        this.firstTime = this.file.length() == 0;
    }

    public void shutdown() throws IOException {
        this.lock.release();
        this.file.close();
    }

    public boolean isFirstTime() {
        return firstTime;
    }

    public void clearFirstTimeFlag() {
        this.firstTime = false;
    }

    public boolean checkShutdown() throws IOException {
        this.file.seek(0);
        return this.file.readByte() != ((byte) 0);
    }

    public void setShutdown(boolean shutdown) throws IOException {
        this.file.seek(0);
        this.file.writeByte(shutdown ? (byte) 0xFF : (byte) 0);
        this.channel.force(true);
    }

    public void writeFirstTime(final int indexSizeInMegabytes,
                          final long creationTimestamp) throws IOException {

        StringBuilder sb = new StringBuilder(name);
        sb.setLength(512);
        byte[] nameBytes = new byte[512];

        try {
            nameBytes = sb.toString().getBytes("ASCII");
            assert nameBytes.length == 512;
        } catch (UnsupportedEncodingException e) {
            log.error(null, e);
        }

        final byte[] finalName = nameBytes;

        buffer.position(0);
        buffer.put((byte) 0) // not closeIndex
                .put(finalName)
                .putInt(indexSizeInMegabytes)
                .putLong(creationTimestamp)
                .putFloat(VERSION);

        buffer.position(0);

        file.setLength(META_INFO_SIZE);
        channel.write(buffer, 0);
        channel.force(true);
    }

    public void checkValues(final String name, final int indexSizeInMegabytes)
            throws RuntimeException, IOException {

            buffer.position(0);
            channel.read(buffer, 0);

            buffer.position(0);
            buffer.get(); // discard first byte
            byte[] nameBytes = new byte[512];
            buffer.get(nameBytes);
            String oldName = new String(nameBytes, "ASCII");

            if (!oldName.trim().equals(name.trim())) {
                throw new RuntimeException(
                        "The database name cannot change! The original name is '"
                        + oldName.trim() + "' and the new one is '"
                        + name.trim() + "'");
            }

            int oldIndexSizeInMegabytes = buffer.getInt();

            if (oldIndexSizeInMegabytes != indexSizeInMegabytes) {
                throw new RuntimeException(
                        "The database index size cannot change! The original size is "
                        + oldIndexSizeInMegabytes
                        + " and the new one is "
                        + indexSizeInMegabytes);
            }
    }

    public String getName() {
        return name;
    }
}
