package br.eti.fml.crazydb;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {
        CrazyDB db = new CrazyDB("my database", "db");

        try {
            for (int i = 0; i < 5000; i++) {
                byte[] value = ("value " + i).getBytes();
                db.put("key" + i, value);
            }

        } finally {
            db.shutdown();
        }
    }
}
