package br.eti.fml.crazydb;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    public static void main(String[] args) throws IOException {
        CrazyDB db = new CrazyDB("my database", "db");

        try {
            db.put("ola".getBytes(), "ola value".getBytes());
            db.put("oi tudo bem?".getBytes(), "tudo value".getBytes());
            db.put("como vai voce".getBytes(), "como value".getBytes());
            db.put("certinho".getBytes(), "certinho value".getBytes());
            db.put("opa lele".getBytes(), "opa lele value".getBytes());
            db.put("non creddo".getBytes(), "non value".getBytes());
            db.put("poutz".getBytes(), "poutz value".getBytes());
            db.put("lokkura ne".getBytes(), "lokkura value".getBytes());
            db.put("doido".getBytes(), "doido value".getBytes());

            System.out.println("como = " + new String(db.get("como vai voce".getBytes())));
            System.out.println("certinho = " + new String(db.get("certinho".getBytes())));
            System.out.println("doido = " + new String(db.get("doido".getBytes())));
            System.out.println("nao existe = " + db.get("nao existe".getBytes()));
            
        } finally {
            db.shutdown();
        }
    }
}
