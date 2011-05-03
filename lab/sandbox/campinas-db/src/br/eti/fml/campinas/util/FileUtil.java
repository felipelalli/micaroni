package br.eti.fml.campinas.util;

import br.eti.fml.campinas.local.index.IndexNode;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public final class FileUtil {
    private static final Logger log = Logger.getLogger(FileUtil.class);

    private FileUtil() {
    }

    public static void fillWith(
            byte whichOne, FileChannel channel,
            long position, long sizeInBytes) throws IOException {

        channel.position(position);

        byte[] b = new byte[(int) (512 * ByteUtil.KB)];
        Arrays.fill(b, whichOne);
        ByteBuffer buffer = ByteBuffer.wrap(b);

        int filled = 0;
        long remaining;

        do {
            remaining = sizeInBytes - filled;

            if (remaining >= b.length) {
                buffer.position(0);
                channel.write(buffer);
                filled += b.length;
            } else {
                assert remaining <= Integer.MAX_VALUE;

                buffer = ByteBuffer.wrap(b, 0, (int) remaining);
                channel.write(buffer);
                filled += remaining;
            }
        } while (remaining > 0L);        
    }

    public static void checkFileSize(
            String fileName, long size,
            RandomAccessFile file, long multiple) throws IOException {

        long currentSize = file.length();

        if (currentSize != size) {
            log.error("Something is really wrong with the file '" + fileName +
                    "' size! Trying to fix it. Resizing from " + currentSize
                    + " to " + size + ". The size must be multiple of "
                    + multiple + ". It's very probable that some"
                    + " data is corrupted!");

            file.setLength(size);
        }
    }
}
