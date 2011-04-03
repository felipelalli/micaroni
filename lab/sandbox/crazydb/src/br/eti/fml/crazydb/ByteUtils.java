package br.eti.fml.crazydb;

import java.nio.ByteBuffer;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class ByteUtils {
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
}
