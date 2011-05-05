package br.eti.fml.motodb;

import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class MotoDB {
    private static final Logger log = Logger.getLogger(MotoDB.class);

    private AtomicBoolean down = new AtomicBoolean(false);
    private ConcurrentHashMap firstBuffer
            = new ConcurrentHashMap(128, 0.9f, 1);

    public MotoDB(String pathDirectory) throws IOException {
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

        Runtime.getRuntime().addShutdownHook(new Thread() {
            public void run() {
                try {
                    if (!MotoDB.this.down.get()) {
                        log.fatal("CAUTION in shutdownHook: You MUST to call" +
                                " shutdown() or you can LOOSE DATA! Trying to" +
                                " shutdown...");

                        MotoDB.this.shutdown();
                    }
                } catch (Throwable e) {
                    log.error("Error on automatic finalize of CampinasDB", e);
                }
            }
        });
    }

    public void put(final String key, final byte[] value) throws IOException {
        this.put(key, value, new CallbackWhenPersisted() {
            @Override
            public void itWasPersisted(boolean success, IOException exception) {}
        });
    }

    public void put(final String key, final byte[] value,
                    final CallbackWhenPersisted callback) throws IOException {

        // TODO
    }

    public byte[] get(final String key) throws IOException {
        return null; // TODO
    }

    public void shutdown() throws IOException {
        if (this.down.compareAndSet(false, true)) {
            // TODO: do the shutdown
        }
    }

    @Override
    public void finalize() throws Throwable {
        if (!this.down.get()) {
            log.fatal("CAUTION in finalize(): You MUST to call shutdown() or " +
                    "you can LOOSE DATA! Trying to shutdown...");

            this.shutdown();
        }

        super.finalize();
    }
}
