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
            for (int i = 0; i < 30000; i++) {
                String key = "key" + i;
                String value = "value " + i;

                db.put(key, value.getBytes());
                values.put(key, value);

                if (i % 10000 == 0) {
                    System.out.print(".");
                }
            }

            System.out.println("*** CHECKING...");

            for (int i = 0; i < 30000; i++) {
                String key = "key" + i;
                System.out.println(key);
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

        } finally {
            db.shutdown();
        }
    }
}
