package br.eti.fml.campinas;

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
    public static final int META_INFO_FIXED_SIZE_IN_BYTES = 1474560;

    private static final int META_INFO_SIZE = 1 + 512 + 4 + 8 + 4;

    private boolean firstTime;

    private RandomAccessFile file;
    private FileChannel channel;
    private FileLock lock;

    public MetaInfo(File directoryPath) throws IOException {
        File f = new File(directoryPath.getAbsolutePath()
                + File.pathSeparator + "metainfo");

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
    }

    public void writeFirstTime(String name, int indexSizeInMegabytes,
                          long creationTimestamp) throws IOException {

        StringBuilder sb = new StringBuilder(name);
        sb.setLength(512);
        byte[] nameBytes = new byte[512];

        try {
            nameBytes = sb.toString().getBytes("ASCII");
            assert nameBytes.length == 512;
        } catch (UnsupportedEncodingException e) {
            log.error(null, e);
        }

        ByteBuffer metaInfoBytes = ByteBuffer.allocate(META_INFO_SIZE)
                .put((byte) 0) // not closeIndex
                .put(nameBytes)
                .putInt(indexSizeInMegabytes)
                .putLong(creationTimestamp)
                .putFloat(VERSION);

        this.channel.write(metaInfoBytes, 0);
    }

    public void checkValues(String name, int indexSizeInMegabytes)
            throws RuntimeException, IOException {

        ByteBuffer metaInfoBytes = ByteBuffer.allocate(META_INFO_SIZE);
        this.channel.read(metaInfoBytes, 0);

        metaInfoBytes.get(); // discard first byte
        byte[] nameBytes = new byte[512];
        metaInfoBytes.get(nameBytes);
        String oldName = new String(nameBytes, "ASCII");

        if (!oldName.trim().equals(name.trim())) {
            throw new RuntimeException("The database name cannot change! The original name is '"
                    + oldName.trim() + "' and the new one is " + name.trim());
        }

        int oldIndexSizeInMegabytes = metaInfoBytes.getInt();

        if (oldIndexSizeInMegabytes != indexSizeInMegabytes) {
            throw new RuntimeException(
                    "The database index size cannot change! The original size is "
                    + oldIndexSizeInMegabytes
                            + " and the new one is " + indexSizeInMegabytes);
        }
    }
}
