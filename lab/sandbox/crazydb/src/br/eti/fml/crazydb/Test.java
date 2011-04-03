package br.eti.fml.crazydb;

import java.io.IOException;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {
        CrazyDB db = new CrazyDB("db");

        UUID uuid = UUID.randomUUID();
        byte[] value = ByteUtils.UUID2bytes(uuid);

        db.put("ola".getBytes(), value);
    }
}
