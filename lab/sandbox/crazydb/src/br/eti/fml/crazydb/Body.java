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

    public void replaceAt(long position, byte[] data) throws IOException {
        this.db.putBytesAt(position, data);
    }

    public byte[] read(long address, int size) throws IOException {
        return this.db.readBytesAt(address, size);
    }
}
