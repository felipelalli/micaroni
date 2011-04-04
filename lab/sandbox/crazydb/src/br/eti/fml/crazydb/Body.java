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

    public long allocateAndPut(byte[] data) throws IOException {
        return this.db.putAtTheEnd(data);
    }

    public void replaceAt(long position, byte[] data) throws IOException {
        this.db.putBytesAt(position, data);
    }

    public byte[] read(Long address, Long size) throws IOException {
        return this.db.readBytesAt(address, size.intValue());
    }
}
