package br.eti.fml.crazydb.index;

import br.eti.fml.crazydb.ByteUtil;
import br.eti.fml.crazydb.TheBigFile;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
class MetaInfo {
    private static final Logger log = Logger.getLogger(MetaInfo.class);

    public static final int META_INFO_FIXED_SIZE_IN_BYTES
            = (int) (5 * ByteUtil.MB);

    private static final int META_INFO_SIZE = 1 + 512 + 4 + 8 + 8;
    private static final long SIZE_POSITION = 1 + 512 + 4 + 8;

    private TheBigFile db;
    private long currentSize;
    private boolean firstTime = false;

    MetaInfo(TheBigFile db) throws IOException {
        this.db = db;

        if (this.db.length() < SIZE_POSITION) {
            this.currentSize = 0L;
            this.firstTime = true;
            this.db.putLongAt(SIZE_POSITION, 0L);
        } else {
            this.currentSize = this.db.readLongAt(SIZE_POSITION);
        }
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

        this.currentSize = META_INFO_FIXED_SIZE_IN_BYTES
                        + FreeTable.FREE_TABLE_FIXED_SIZE_IN_BYTES
                        + (indexSizeInMegabytes * ByteUtil.MB);

        this.db.putLongAt(SIZE_POSITION, this.currentSize);
        
        byte[] metaInfoBytes = ByteBuffer.allocate(META_INFO_SIZE)
                .put((byte) 0) // not closeIndex
                .put(nameBytes)
                .putInt(indexSizeInMegabytes)
                .putLong(creationTimestamp)
                .putLong(currentSize) // current size
                .array();

        this.db.putBytesAt(0, metaInfoBytes);
    }

    public void checkValues(String name, int indexSizeInMegabytes)
            throws RuntimeException, IOException {

        byte[] metaInfoBytes = db.readBytesAt(0, META_INFO_SIZE);
        ByteBuffer buffer = ByteBuffer.wrap(metaInfoBytes);
        buffer.get(); // discard first byte
        byte[] nameBytes = new byte[512];
        buffer.get(nameBytes);
        String oldName = new String(nameBytes, "ASCII");

        if (!oldName.trim().equals(name.trim())) {
            throw new RuntimeException("The database name cannot change! The original name is '"
                    + oldName.trim() + "' and the new one is " + name.trim());
        }

        int oldIndexSizeInMegabytes = buffer.getInt();

        if (oldIndexSizeInMegabytes != indexSizeInMegabytes) {
            throw new RuntimeException(
                    "The database index size cannot change! The original size is "
                    + oldIndexSizeInMegabytes
                            + " and the new one is " + indexSizeInMegabytes);
        }
    }

    public boolean checkShutdown() throws IOException {
        return this.db.readBytesAt(0, 1)[0] != ((byte) 0);
    }

    public void setShutdown(boolean shutdown) throws IOException {
        this.db.putBytesAt(0L, new byte[] { shutdown ? (byte) 1 : (byte) 0 });

        if (shutdown) {
            this.db.putLongAt(SIZE_POSITION, this.currentSize);
        }
    }

    public long getCurrentSize() throws IOException {
        return currentSize;
    }

    public void setNewSize(long newSize) throws IOException {
        this.currentSize = newSize;
        long realSize = this.db.length();

        if (newSize > realSize) {
            long bigSize = realSize + (16 * ByteUtil.MB);
            this.db.setLength(bigSize);
            this.db.putLongAt(SIZE_POSITION, bigSize);
            this.db.flush();
        }
    }

    public boolean isFirstTime() {
        return firstTime;
    }

    public void clearFirstTimeFlag() {
        this.firstTime = false;
    }
}
