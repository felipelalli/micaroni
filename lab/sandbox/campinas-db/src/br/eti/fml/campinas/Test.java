package br.eti.fml.campinas;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {

        CampinasDB db = new CampinasDB("my database", "db", 1);
        Map<String, byte[]> values = new HashMap<String, byte[]>();

        System.out.println(db.getInfo());
        //int tests = 10000000;
        int tests = 300000;

        DecimalFormat format = new DecimalFormat("#,###");
        final ByteBuffer buffer = ByteBuffer.allocate(4);

        try {
            long now = System.currentTimeMillis();

            for (int i = 0; i < tests; i++) {
                String key = "key" + i;

                buffer.position(0);
                buffer.putInt(i);
                byte[] value = buffer.array();

                db.put(key, value);
                values.put(key, value);

                if (i % 100000 == 0) {
                    System.out.println(format.format(i));
                }
            }

            System.out.println("\n\ntime 1 per key: "
                    +  ((System.currentTimeMillis() - now) / (double) tests) + "ms");

            System.out.println("\n*** CHECKING... ");

            now = System.currentTimeMillis();

            for (int i = 0; i < tests; i++) {
                String key = "key" + i;
                byte[] value = db.get(key);
                byte[] readValue = values.get(key);

                if (Arrays.equals(readValue, value)) {
                    if (i % 100000 == 0) {
                        System.out.println(format.format(i));
                    }
                } else {
                    System.out.println(
                            "*** ERROR " + Arrays.toString(value)
                                    + " should be " + Arrays.toString(readValue));
                }
            }

            System.out.println("\ntime 2 per key: " +  ((System.currentTimeMillis() - now) / (double) tests) + " ms");

            System.out.println(db.getInfo());

        } finally {
            db.shutdown();
        }
    }
}
