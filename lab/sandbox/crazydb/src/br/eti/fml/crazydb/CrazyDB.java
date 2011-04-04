package br.eti.fml.crazydb;

import br.eti.fml.crazydb.index.Index;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CrazyDB {
    private static final Logger log = Logger.getLogger(CrazyDB.class);

    private static final int DEFAULT_SIZE_IN_MEGABYTES = 512;

    private volatile boolean shutdown = false;
    
    private TheBigFile db;
    private Index index;
    private Body body;

    @SuppressWarnings("unused")
    public CrazyDB(String exclusiveName, String path) throws IOException {
        this(exclusiveName, path, DEFAULT_SIZE_IN_MEGABYTES, false);
    }

    @SuppressWarnings("unused")
    public CrazyDB(String exclusiveName, String path, boolean forceFileSystemSynchronize) throws IOException {
        this(exclusiveName, path, DEFAULT_SIZE_IN_MEGABYTES, forceFileSystemSynchronize);
    }

    @SuppressWarnings("unused")
    public CrazyDB(String exclusiveName, String path, int indexSizeInMegabytes) throws IOException {
        this(exclusiveName, path, indexSizeInMegabytes, false);
    }

    public CrazyDB(String exclusiveName, String path, int indexSizeInMegabytes,
                   boolean forceFileSystemSynchronize) throws IOException {

        this.db = new TheBigFile(exclusiveName, path, forceFileSystemSynchronize);
        this.body = new Body(db);
        this.index = new Index(db, body, indexSizeInMegabytes);

        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                try {
                    if (!CrazyDB.this.shutdown) {
                        log.fatal("CAUTION in shutdownHook: You MUST to call shutdown() or your can LOST DATA! Trying to shutdown...");
                        CrazyDB.this.shutdown();
                    }
                } catch (Throwable e) {
                    log.error("Error on automatic finalize of CrazyDB", e);
                }
            }
        });
    }

    public void put(byte[] key, byte[] value) throws IOException {
        this.put(UUID.nameUUIDFromBytes(key), value);
    }

    public byte[] get(byte[] key) throws IOException {
        return this.get(UUID.nameUUIDFromBytes(key));
    }

    protected byte[] get(UUID key) throws IOException {
        Pair<Long, Long> addressAndSize = this.index.find(key);

        if (addressAndSize != null) {
            return this.body.read(addressAndSize.car, addressAndSize.cdr);
        } else {
            return null;
        }
    }

    protected void put(UUID key, byte[] value) throws IOException {
        long address = this.body.allocateAndPut(value);
        this.index.updateIndex(key, address, value.length);
    }

    public void shutdown() throws IOException {
        if (!this.shutdown) {
            this.shutdown = true;
            log.info("Shutting down...");
            this.index.closeIndex();
            this.db.close();
            System.runFinalization();
            System.gc();
            log.info("Shutdown OK!");
        }
    }

    @Override
    public void finalize() throws Throwable {
        if (!this.shutdown) {
            log.fatal("CAUTION in finalize: You MUST to call shutdown() or your can LOST DATA! Trying to shutdown...");
            this.shutdown();
        }

        super.finalize();
    }
}
