package br.eti.fml.crazydb;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CrazyDB {
    private TheBigFile db;
    private Index512 index;
    private Body body;

    public CrazyDB(String path) throws IOException {
        this(path, false);
    }

    public CrazyDB(String path, boolean forceFileSystemSynchronize) throws IOException {
        this.db = new TheBigFile(path, forceFileSystemSynchronize);
        this.body = new Body(db);
        this.index = new Index512(db, body);
    }

    public void put(byte[] key, byte[] value) throws IOException {
        this.put(UUID.nameUUIDFromBytes(key), key, value);
    }

    protected void put(UUID key, byte[] bytesKey, byte[] value) throws IOException {
        long address = 0L;

        this.index.updateIndex(key, bytesKey, address, value.length);





        //this.db.
    }    
}
