package br.eti.fml.campinas;

import br.eti.fml.campinas.util.ByteUtil;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CampinasDB {
    private static final Logger log = Logger.getLogger(CampinasDB.class);

    private volatile boolean down = false;

    private MetaInfo metaInfo;
    //private Index index;
    //private Body body;

    public CampinasDB(String exclusiveName, String pathDirectory,
                      int indexSizeInMegabytes) throws IOException {

        assert exclusiveName.length() > 0;
        assert exclusiveName.length() < 512;

        File directory = new File(pathDirectory);

        if (!directory.exists()) {
            if (!directory.mkdirs()) {
                throw new IOException("It was not possible to create '"
                        + pathDirectory + "' directory.");
            }
        } else if (!directory.isDirectory()) {
                throw new IOException("The path '"
                        + pathDirectory + "' is not a directory.");
        }

        this.metaInfo = new MetaInfo(directory);
        // TODO

        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                try {
                    if (!CampinasDB.this.down) {
                        log.fatal("CAUTION in shutdownHook: You MUST to call shutdown() or you can LOOSE DATA! Trying to shutdown...");
                        CampinasDB.this.shutdown();
                    }
                } catch (Throwable e) {
                    log.error("Error on automatic finalize of CampinasDB", e);
                }
            }
        });
    }

    public void put(String key, byte[] value) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

//        long address = this.index.allocateAndPut(value);
//        int checksumData = Arrays.hashCode(value);
//        this.index.updateIndex(key, address, checksumData, value.length);
        // TODO
    }

    public byte[] get(String key) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

//        HashNode node = this.index.find(key);
//
//        if (node == null) {
//            return null;
//        } else {
//            byte[] data = this.body.read(node.getAddress(), node.getSize());
//            int realChecksumData = Arrays.hashCode(data);
//
//            if (realChecksumData != node.getChecksumData()) {
//                throw new CorruptedDataException(
//                        data, node.getChecksumData(), realChecksumData);
//            }
//
//            return data;
//        }
        return null; // TODO
    }

    public void shutdown() throws IOException {
        if (!this.down) {
            this.down = true;
            log.info("Shutting down...");

            log.debug("1/X Shutting down... [ ] metainfo, [ ] index, [ ] body, [ ] finalization, [ ] gc");
            this.metaInfo.shutdown();
            log.debug("2/X Shutting down... [X] metainfo ");

            log.info("Shutdown OK!");

//            log.info("1/5 Shutting down...");
//            this.index.closeIndex();
//            log.debug("2/5 Index closed...");
//            this.db.close();
//            log.debug("3/5 Big file closed...");
//            System.runFinalization();
//            log.debug("4/5 Finalization called...");
//            System.gc();
//            log.info("5/5 Shutdown OK!");
        }
    }

    @Override
    public void finalize() throws Throwable {
        if (!this.down) {
            log.fatal("CAUTION in finalize: You MUST to call shutdown() or you can LOOSE DATA! Trying to shutdown...");
            this.shutdown();
        }

        super.finalize();
    }
}
