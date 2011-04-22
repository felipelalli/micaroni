package br.eti.fml.campinas.index;

import br.eti.fml.campinas.MetaInfo;
import br.eti.fml.campinas.util.ByteUtil;
import br.eti.fml.campinas.util.FileUtil;
import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Index {
    private static final Logger log = Logger.getLogger(Index.class);
    public static final boolean TRACE_ENABLED = true;

    private RandomAccessFile file;
    private FileChannel channel;
    private FileLock lock;

    private MetaInfo metaInfo;

    private long indexSizeInBytes;

    // cache
    private ByteBuffer freeSlots;

    public Index(File directoryPath, MetaInfo metaInfo,
                 int indexSizeInMegabytes) throws IOException {

        this.metaInfo = metaInfo;
        this.indexSizeInBytes = indexSizeInMegabytes * ByteUtil.MB;

        assert this.indexSizeInBytes % 8 == 0;

        log.info("Starting '" + metaInfo.getName() + "' with "
                + indexSizeInMegabytes + " MB index...");

        File f = new File(directoryPath.getAbsolutePath()
                + File.separator + "index");

        this.file = new RandomAccessFile(f, "rw");
        this.channel = this.file.getChannel();
        this.lock = this.channel.tryLock();

        if (this.lock == null) {
            throw new IOException("Index in '"
                    + directoryPath.getAbsolutePath()
                    + "' is locked! Unlock it first.");
        }

        if (this.metaInfo.isFirstTime()) {
            FileUtil.fillWithZero(this.channel, 0L, indexSizeInBytes);

            metaInfo.writeFirstTime(indexSizeInMegabytes,
                    System.currentTimeMillis());

            this.file.setLength(this.indexSizeInBytes);
        } else {
            metaInfo.checkValues(this.metaInfo.getName(), indexSizeInMegabytes);

            this.channel.position(indexSizeInBytes);
            log.debug("Nice! The index already was created before.");

            if (!metaInfo.checkShutdown()) {
                log.error("Shutdown was not called last time. Some data can be corrupted!");
            }
        }

        metaInfo.setShutdown(false);
        
//        int slots = (int) (indexSizeInBytes / IndexNode.INDEX_NODE_SIZE);
//        long maximum = Runtime.getRuntime().maxMemory();
//        long needMB = ((slots * 3) / ByteUtil.MB);
//
//        if (maximum < slots * 3) {
//            log.fatal("You have " + (maximum / ByteUtil.MB)
//                    + " MB of maximum memory and need at least " + needMB + " MB");
//
//            throw new OutOfMemoryError("You need at least " + needMB + " MB maximum");
//        } else {
//            this.freeSlots = ByteBuffer.allocateDirect(slots);
//            byte[] freeSlotsTemp = new byte[slots];
//
//            if (this.metaInfo.isFirstTime()) {
//                log.info("Your first time with this database. All "
//                        + slots + " slots are free.");
//
//                Arrays.fill(freeSlotsTemp, (byte) 1);
//                this.freeSlots.put(freeSlotsTemp);
//            } else {
//                log.info("Caching index up to " + slots + " slots...");
//                Arrays.fill(freeSlotsTemp, (byte) 0);
//                this.freeSlots.put(freeSlotsTemp);
//
//                long now = System.currentTimeMillis();
//
//                for (int n = 0; n < slots; n++) {
//                    if (System.currentTimeMillis() - now > 5000) {
//                        log.info("Caching index yet... "
//                                + percentage(n, slots) + " done");
//
//                        now = System.currentTimeMillis();
//                    }
//
//                    long indexPosition = this.getIndexPositionByNumber(n);
//
//                    // TODO FIXME: improve this reading with buffer
//                    if (this.db.checkIfPositionIsEqualTo(indexPosition, 0L)) {
//                        this.freeSlots.put(n, (byte) 1);
//                    }
//                }
//            }
//
//            this.metaInfo.clearFirstTimeFlag();
//            log.info("Ok! The database is ready!");
//        }
    }

    public void shutdown() throws IOException {
        this.lock.release();
        this.file.close();
    }    
}
