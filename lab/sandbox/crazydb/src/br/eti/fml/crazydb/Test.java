package br.eti.fml.crazydb;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {
        CrazyDB db = new CrazyDB("my database", "db");
        Map<String, String> values = new HashMap<String, String>();

        try {
            long now = System.currentTimeMillis();

            for (int i = 0; i < 30000; i++) {
                String key = "key" + i;
                String value = "value " + i;

                db.put(key, value.getBytes());
                values.put(key, value);

                if (i % 10000 == 0) {
                    System.out.print(".");
                }
            }

            System.out.println("time 1 per key: " +  ((System.currentTimeMillis() - now) / 30000d));
            System.out.println("\n*** CHECKING... ");

            now = System.currentTimeMillis();

            for (int i = 0; i < 30000; i++) {
                String key = "key" + i;
                String value = new String(db.get(key));
                String readValue = values.get(key);

                if (readValue.equals(value)) {
                    if (i % 10000 == 0) {
                        System.out.print(".");
                    }
                } else {
                    System.out.println("*** ERROR " + value + " must be "
                            + readValue);
                }
            }

            System.out.println("time 2 per key: " +  ((System.currentTimeMillis() - now) / 30000d));

        } finally {
            db.shutdown();
        }
    }
}
