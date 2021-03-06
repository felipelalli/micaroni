package br.eti.fml.crazydb;

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public final class ByteUtil {
    private ByteUtil() {
    }

    public static final long TB = 1024L * 1024L * 1024L * 1024L;
    public static final int GB = 1024 * 1024 * 1024;
    public static final int MB = 1024 * 1024;
    public static final int KB = 1024;
    public static final int B = 1;

    public static byte[] UUID2bytes(UUID uuid) {
        return ByteBuffer.allocate(16).putLong(
                uuid.getMostSignificantBits()).putLong(
                uuid.getLeastSignificantBits()).array();
    }

    public static UUID bytes2UUID(byte[] bytes) {
        ByteBuffer bb = ByteBuffer.allocate(16).put(bytes);
        bb.position(0);
        long most = bb.getLong();
        long least = bb.getLong();
        return new UUID(most, least);
    }

    public static boolean compare(byte[] a, byte[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    public static byte[] getChecksum(long address) {
        short value = (short) (address % Short.MAX_VALUE);
        return ByteBuffer.allocate(2).putShort(value).array();
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
