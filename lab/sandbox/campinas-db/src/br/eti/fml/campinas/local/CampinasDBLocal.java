package br.eti.fml.campinas.local;

import br.eti.fml.campinas.local.body.Body;
import br.eti.fml.campinas.local.index.HashNode;
import br.eti.fml.campinas.local.index.Index;
import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.Pair;
import br.eti.fml.data.db.keyvalue.KeyValue;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicLong;
import java.util.concurrent.atomic.AtomicReference;

/**
 * 
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CampinasDBLocal implements KeyValue {
    private static final Logger log = Logger.getLogger(CampinasDBLocal.class);

    private volatile boolean down = false;

    private MetaInfo metaInfo;
    private Index index;
    private Body body;

    private ByteBuffer tempBufferW = ByteBuffer.allocateDirect(8);
    private ByteBuffer tempBufferR = ByteBuffer.allocateDirect(8);

    public CampinasDBLocal(String exclusiveName, String pathDirectory,
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
        this.body = new Body(directory);

        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                try {
                    if (!CampinasDBLocal.this.down) {
                        log.fatal("CAUTION in shutdownHook: You MUST to call shutdown() or you can LOOSE DATA! Trying to shutdown...");
                        CampinasDBLocal.this.shutdown();
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
                assert value.length < ByteUtil.GB;

                flags |= Flag.POINTER.getValue();
                Pair<Byte, Long> address = this.body.allocateAndPut(value);

                address1 = address.car;
                address2.set(address.cdr);
            } else {
                flags |= Flag.N_BYTES.getValue();
                address1 = (byte) value.length;

                tempBufferW.position(0);
                tempBufferW.put(value);
                tempBufferW.position(0);
                address2.set(tempBufferW.getLong());
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
                    result.set(this.body.read(node));
                } else if (Flag.N_BYTES.isInside(flags)) {
                    tempBufferR.position(0);
                    tempBufferR.putLong(node.getAddress2());
                    tempBufferR.position(0);
                    int n = node.getAddress1();
                    byte[] b = new byte[n];
                    tempBufferR.get(b);
                    result.set(b);
                }
            }
        }

        return result.get();
    }

    public void shutdown() throws IOException {
        if (!this.down) {
            this.down = true;
            log.info("Shutting down...");

            this.index.shutdown();
            log.debug("1/5 Index is down...");
            this.metaInfo.setShutdown(true);
            this.metaInfo.shutdown();
            log.debug("2/5 Metainfo is down...");
            this.body.shutdown();
            log.debug("3/5 Body is down...");
            System.runFinalization();
            log.debug("4/5 Finalization was called...");
            System.gc();
            log.debug("5/5 Free memory...");

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
