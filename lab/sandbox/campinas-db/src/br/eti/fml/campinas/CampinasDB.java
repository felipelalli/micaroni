package br.eti.fml.campinas;

import br.eti.fml.campinas.index.HashNode;
import br.eti.fml.campinas.index.Index;
import br.eti.fml.campinas.util.BufferPool;
import br.eti.fml.campinas.util.ByteUtil;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.atomic.AtomicReference;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CampinasDB {
    private static final Logger log = Logger.getLogger(CampinasDB.class);

    private volatile boolean down = false;

    private MetaInfo metaInfo;
    private Index index;
    //private Body body;

    public CampinasDB(String exclusiveName, String pathDirectory,
                      int indexSizeInMegabytes) throws IOException {

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

        this.metaInfo = new MetaInfo(exclusiveName, directory);
        this.index = new Index(directory, metaInfo, indexSizeInMegabytes);
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

    public void put(String key, final byte[] value) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

        byte flags = 0;
        byte address1 = 0;
        final AtomicLong address2 = new AtomicLong(0L);

        if (value == null || value.length == 0) {
            flags |= Flag.DELETED.getValue();
        } else {
            if (value.length > 8) {
                assert value.length <= ByteUtil.GB;
                flags |= Flag.POINTER.getValue();
                address1 = 1; // TODO
                address2.set(0L); // TODO
            } else {
                flags |= Flag.N_BYTES.getValue();
                address1 = (byte) value.length;

                BufferPool.getInstance().doWithATemporaryBuffer(
                        8, new BufferPool.Action() {
                            @Override
                            public void doWith(ByteBuffer buffer) {
                                buffer.put(value);
                                buffer.position(0);
                                address2.set(buffer.getLong());
                            }
                        });
            }
        }

        this.index.updateIndex(k, flags, address1, address2.get());
    }

    public byte[] get(String key) throws IOException {
        UUID k = UUID.nameUUIDFromBytes(
                ByteUtil.stringToBytesUTFNIO(key));

        final HashNode node = this.index.find(k);
        final AtomicReference<byte[]> result = new AtomicReference<byte[]>();

        if (node != null) {
            byte flags = node.getFlags();

            if (!Flag.DELETED.isInside(flags)) {
                if (Flag.POINTER.isInside(flags)) {
                    // TODO: search on Bodies
                } else if (Flag.N_BYTES.isInside(flags)) {
                    BufferPool.getInstance().doWithATemporaryBuffer(
                            8, new BufferPool.Action() {
                                @Override
                                public void doWith(ByteBuffer buffer) {
                                    buffer.putLong(node.getAddress2());
                                    buffer.position(0);
                                    int n = node.getAddress1();
                                    byte[] b = new byte[n];
                                    buffer.get(b);
                                    result.set(b);
                                }
                            });
                }
            }
        }

        return result.get();

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
    }

    public void shutdown() throws IOException {
        if (!this.down) {
            this.down = true;
            log.info("Shutting down...");

            this.index.shutdown();
            log.debug("1/4 Index down...");
            this.metaInfo.setShutdown(true);
            this.metaInfo.shutdown();
            log.debug("2/4 Metainfo down...");
            System.runFinalization();
            log.debug("3/4 Finalization called...");
            System.gc();
            log.debug("4/4 Free memory...");

            log.info("Shutdown OK!");
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

    public String getInfo() throws IOException {
        return this.index.retrieveInfo();
    }
}
