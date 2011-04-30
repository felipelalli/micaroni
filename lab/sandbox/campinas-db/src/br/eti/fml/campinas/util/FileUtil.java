package br.eti.fml.campinas.util;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public final class FileUtil {
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
}
