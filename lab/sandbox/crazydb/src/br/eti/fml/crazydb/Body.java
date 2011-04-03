package br.eti.fml.crazydb;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Body {
    private TheBigFile db;

    public Body(TheBigFile db) {
        this.db = db;
    }

    public long allocate(byte[] data) throws IOException {
        return this.db.putAtTheEnd(data);
    }
}
