package br.eti.fml.campinas;

import br.eti.fml.campinas.index.CorruptedIndex;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException, CorruptedIndex {
        CampinasDB db = new CampinasDB("my database", "db", 1);
        Map<String, byte[]> values = new HashMap<String, byte[]>();

        System.out.println(db.getInfo());
        int tests = 300000;

        try {
            long now = System.currentTimeMillis();

            for (int i = 0; i < tests; i++) {
                String key = "key" + i;
                ByteBuffer buffer = ByteBuffer.allocate(4).putInt(i);
                buffer.position(0);
                byte[] value = buffer.array();

                db.put(key, value);
                values.put(key, value);

                if (i % 10000 == 0) {
                    System.out.print(".");
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
                    if (i % 10000 == 0) {
                        System.out.print(".");
                    }
                } else {
                    System.out.println(
                            "*** ERROR " + Arrays.toString(value)
                                    + " must be " + Arrays.toString(readValue));
                }
            }

            System.out.println("\ntime 2 per key: " +  ((System.currentTimeMillis() - now) / (double) tests) + " ms");

            System.out.println(db.getInfo());
            
        } finally {
            db.shutdown();
        }

    }
}
