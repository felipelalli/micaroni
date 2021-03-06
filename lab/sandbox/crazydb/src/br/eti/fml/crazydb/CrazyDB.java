package br.eti.fml.crazydb;

import br.eti.fml.crazydb.index.CorruptedIndex;
import br.eti.fml.crazydb.index.HashNode;
import br.eti.fml.crazydb.index.Index;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.util.Arrays;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CrazyDB {
    private static final Logger log = Logger.getLogger(CrazyDB.class);

    private volatile boolean shutdown = false;
    
    private TheBigFile db;
    private Index index;
    private Body body;

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
                        log.fatal("CAUTION in shutdownHook: You MUST to call shutdown() or you can LOOSE DATA! Trying to shutdown...");
                        CrazyDB.this.shutdown();
                    }
                } catch (Throwable e) {
                    log.error("Error on automatic finalize of CrazyDB", e);
                }
            }
        });
    }

    public void put(byte[] key, byte[] value) throws IOException, CorruptedIndex {
        this.put(UUID.nameUUIDFromBytes(key), value);
    }

    public void put(String key, byte[] value) throws IOException, CorruptedIndex {
        try {
            this.put(ByteUtil.stringToBytesUTFNIO(key), value);
        } catch (CorruptedIndex e) {
            throw new CorruptedIndex("at " + key, e.getPosition(), e.getNode());
        }
    }    

    public byte[] get(byte[] key)
            throws IOException, CorruptedIndex, CorruptedDataException {

        return this.get(UUID.nameUUIDFromBytes(key));
    }

    public byte[] get(String key)
            throws IOException, CorruptedIndex, CorruptedDataException {

        try {
            return this.get(ByteUtil.stringToBytesUTFNIO(key));
        } catch (CorruptedIndex e) {
            throw new CorruptedIndex("at " + key, e.getPosition(), e.getNode());
        } catch (CorruptedDataException e) {
            throw new CorruptedDataException("at " + key,
                    e.getCorruptedData(), e.getChecksum(), e.getRealChecksum());
        }
    }

    protected byte[] get(UUID key)
            throws IOException, CorruptedIndex, CorruptedDataException {

        HashNode node = this.index.find(key);

        if (node == null) {
            return null;
        } else {
            byte[] data = this.body.read(node.getAddress(), node.getSize());
            int realChecksumData = Arrays.hashCode(data);

            if (realChecksumData != node.getChecksumData()) {
                throw new CorruptedDataException(
                        data, node.getChecksumData(), realChecksumData);
            }

            return data;
        }
    }

    protected void put(UUID key, byte[] value) throws IOException, CorruptedIndex {
        long address = this.index.allocateAndPut(value);
        int checksumData = Arrays.hashCode(value);
        this.index.updateIndex(key, address, checksumData, value.length);
    }

    public void shutdown() throws IOException {
        if (!this.shutdown) {
            this.shutdown = true;
            log.info("1/5 Shutting down...");
            this.index.closeIndex();
            log.debug("2/5 Index closed...");
            this.db.close();
            log.debug("3/5 Big file closed...");
            System.runFinalization();
            log.debug("4/5 Finalization called...");
            System.gc();
            log.info("5/5 Shutdown OK!");
        }
    }

    public String getInfo() throws IOException {
        return this.index.retrieveInfo();
    }

    @Override
    public void finalize() throws Throwable {
        if (!this.shutdown) {
            log.fatal("CAUTION in finalize: You MUST to call shutdown() or you can LOOSE DATA! Trying to shutdown...");
            this.shutdown();
        }

        super.finalize();
    }
}
