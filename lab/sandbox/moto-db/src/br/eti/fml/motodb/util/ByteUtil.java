package br.eti.fml.motodb.util;

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicReference;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public final class ByteUtil {
    private ByteUtil() {
    }

    public static final long TB = 1024L * 1024L * 1024L * 1024L;
    public static final long GB = 1024L * 1024L * 1024L;
    public static final long MB = 1024L * 1024L;
    public static final long KB = 1024L;
    public static final long B = 1L;

    private static ByteBuffer bufferA = ByteBuffer.allocateDirect(16);
    private static ByteBuffer bufferB = ByteBuffer.allocateDirect(16);

    public static byte[] UUID2bytes(final UUID uuid) {
        final byte[] bytes = new byte[16];

        bufferA.position(0);
        bufferA.putLong(uuid.getMostSignificantBits())
              .putLong(uuid.getLeastSignificantBits());

        bufferA.position(0);
        bufferA.get(bytes);

        return bytes;
    }

    public static UUID bytes2UUID(final byte[] bytes) {

        final AtomicReference<UUID> result = new AtomicReference<UUID>();

        bufferB.position(0);
        bufferB.put(bytes);
        bufferB.position(0);
        long most = bufferB.getLong();
        long least = bufferB.getLong();
        result.set(new UUID(most, least));

        return result.get();
    }

    /**
     * The basic difference between
     * <code>java.util.Arrays.equals()</code> is that
     * this function expected a.length == b.length
     * and a != null and b != null.
     * @param a an array of bytes
     * @param b an array of bytes
     * @return -1 if minor, 1 if major and 0 if equal
     */
    public static int compare(byte[] a, byte[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] < b[i]) {
                return -1;
            } else if (a[i] > b[i]) {
                return 1;
            }
        }

        return 0;
    }

    public static byte[] stringToBytesUTFNIO(String str) {
        char[] buffer = str.toCharArray();
        byte[] b = new byte[buffer.length << 1];
        CharBuffer cBuffer = ByteBuffer.wrap(b).asCharBuffer();

        for (char aBuffer : buffer) {
            cBuffer.put(aBuffer);
        }

        return b;
    }

    public static String bytesToStringUTFNIO(byte[] bytes) {
        CharBuffer cBuffer = ByteBuffer.wrap(bytes).asCharBuffer();
        return cBuffer.toString();
    }

    public static long getNextMultiple(long number, long multiple) {
        if (number % multiple == 0) {
            return number;
        } else {
            return number + (multiple - number % multiple);
        }
    }
}
