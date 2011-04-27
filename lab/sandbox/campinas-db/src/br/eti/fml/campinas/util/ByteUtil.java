package br.eti.fml.campinas.util;

import java.io.IOException;
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
    public static final int GB = 1024 * 1024 * 1024;
    public static final int MB = 1024 * 1024;
    public static final int KB = 1024;
    public static final int B = 1;

    public static byte[] UUID2bytes(final UUID uuid) {
        final byte[] bytes = new byte[16];

        try {
            BufferPool.doWithATemporaryBuffer(
                    16, new BufferPool.Action() {
                        @Override
                        public void doWith(ByteBuffer buffer) {
                            buffer.putLong(uuid.getMostSignificantBits())
                                  .putLong(uuid.getLeastSignificantBits());

                            buffer.position(0);
                            buffer.get(bytes);
                        }
                    }
            );
        } catch (IOException e) {
            // never happens
        }

        return bytes;
    }

    public static UUID bytes2UUID(final byte[] bytes) {

        final AtomicReference<UUID> result = new AtomicReference<UUID>();

        try {
            BufferPool.doWithATemporaryBuffer(
                16, new BufferPool.Action() {
                    @Override
                    public void doWith(ByteBuffer buffer) {
                        buffer.put(bytes);
                        buffer.position(0);
                        long most = buffer.getLong();
                        long least = buffer.getLong();
                        result.set(new UUID(most, least));
                    }
                }
            );
        } catch (IOException e) {
            // never happens
        }

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
}
