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
        byte[] value = ByteUtil.UUID2bytes(uuid);

        db.put("ola".getBytes(), value);
        db.put("oi tudo bem?".getBytes(), value);
        db.put("como vai voce".getBytes(), value);
        db.put("certinho".getBytes(), value);
        db.put("opa lele".getBytes(), value);
        db.put("non creddo".getBytes(), value);
        db.put("poutz".getBytes(), value);
        db.put("lokkura ne".getBytes(), value);
        db.put("doido".getBytes(), value);
    }
}
