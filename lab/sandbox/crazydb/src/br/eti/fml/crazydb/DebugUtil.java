package br.eti.fml.crazydb;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public final class DebugUtil {
    private DebugUtil() {}

    private static final String[] codes = new String[] {
        "fa", "ro", "fei", "pu", "ta",
        "ca", "su", "co", "la", "ran",
        "ja", "bu", "ti", "ba", "do",
        "ce", "brei", "fu", "xou", "pe",
        "nha"
    };

    public static String niceName(Object object) {
        StringBuilder sb = new StringBuilder("'");

        if (object instanceof Number) {
            sb.append("#").append(Long.toHexString(((Number) object).longValue()));
        } else {
            String hash = object.hashCode() + "";

            for (byte b : hash.getBytes()) {
                int value = b % codes.length;
                sb.append(codes[value]);

                if (sb.length() > 8) {
                    break;
                }
            }
        }

        sb.append("'");

        return sb.toString();
    }
}
