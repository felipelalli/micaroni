package br.eti.fml.crazydb;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {
        CrazyDB db = new CrazyDB("my database", "db", 12);
        Map<String, String> values = new HashMap<String, String>();

        System.out.println(db.getInfo());
        int tests = 50000;

        try {
            long now = System.currentTimeMillis();

            for (int i = 0; i < tests; i++) {
                String key = "key" + i;
                String value = "value " + i;

                db.put(key, value.getBytes());
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
                String value = new String(db.get(key));
                String readValue = values.get(key);

                if (readValue.equals(value)) {
                    if (i % 10000 == 0) {
                        System.out.print(".");
                    }
                } else {
                    System.out.println(
                            "*** ERROR " + value + " must be " + readValue);
                }
            }

            System.out.println("\ntime 2 per key: " +  ((System.currentTimeMillis() - now) / (double) tests) + " ms");

            System.out.println(db.getInfo());

        } finally {
            db.shutdown();
        }
    }
}
