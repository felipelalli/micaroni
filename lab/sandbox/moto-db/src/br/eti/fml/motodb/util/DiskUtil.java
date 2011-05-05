package br.eti.fml.motodb.util;

import org.apache.log4j.Logger;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.text.DecimalFormat;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class DiskUtil {
    private static final Logger log = Logger.getLogger(DiskUtil.class);
    public static final int MEGAS_TO_TEST = 1000;

    public static void main(String[] args) throws IOException {
        File[] files = new File[] {
//                File.createTempFile("test", ".tmp"),
//                File.createTempFile("test", ".tmp",
//                        new File("/media/eSataOne")),
//                File.createTempFile("test", ".tmp",
//                        new File("/media/6758e8c7-2151-4388-8148-0626b6634700")),
//                File.createTempFile("test", ".tmp",
//                        new File("/media/NTFS500")),
                File.createTempFile("test", ".tmp",
                        new File("/media/Heyko32"))
        };

        for (File file : files) {
            file.deleteOnExit();
            log.info("File: " + file.getAbsolutePath());

            byte[] mega = new byte[(int) ByteUtil.MB];
            Random random = new Random();
            random.nextBytes(mega);
            ByteBuffer bytes = ByteBuffer.allocateDirect(mega.length);
            bytes.put(mega);

            RandomAccessFile raf = new RandomAccessFile(file, "rw");
            FileChannel channel = raf.getChannel();

            long now = System.currentTimeMillis();

            for (int m = 0; m < MEGAS_TO_TEST; m++) {
                bytes.position(0);
                channel.write(bytes);
            }

            channel.force(true);

            double secs = ((double) (System.currentTimeMillis() - now)) / 1000d;
            double mps = MEGAS_TO_TEST / secs;

            DecimalFormat format = new DecimalFormat("#,##0.00");
            log.info(format.format(mps) + " Mb/s");

            raf.close();
        }
    }
}
