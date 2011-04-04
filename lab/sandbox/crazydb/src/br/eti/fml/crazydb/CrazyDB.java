package br.eti.fml.crazydb;

import java.io.IOException;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CrazyDB {
    private static final int DEFAULT_SIZE_IN_MEGABYTES = 512;
    private TheBigFile db;
    private Index index;
    private Body body;

    public CrazyDB(String path) throws IOException {
        this(path, DEFAULT_SIZE_IN_MEGABYTES, false);
    }

    public CrazyDB(String path, boolean forceFileSystemSynchronize) throws IOException {
        this(path, DEFAULT_SIZE_IN_MEGABYTES, forceFileSystemSynchronize);
    }

    public CrazyDB(String path, int indexSizeInMegabytes) throws IOException {
        this(path, indexSizeInMegabytes, false);
    }

    public CrazyDB(String path, int indexSizeInMegabytes,
                   boolean forceFileSystemSynchronize) throws IOException {

        this.db = new TheBigFile(path, forceFileSystemSynchronize);
        this.body = new Body(db);
        this.index = new Index(db, body, indexSizeInMegabytes);
    }

    public void put(byte[] key, byte[] value) throws IOException {
        this.put(UUID.nameUUIDFromBytes(key), value);
    }

    protected void put(UUID key, byte[] value) throws IOException {
        long address = this.body.allocateAndPut(value);
        this.index.updateIndex(key, address, value.length);
    }    
}
