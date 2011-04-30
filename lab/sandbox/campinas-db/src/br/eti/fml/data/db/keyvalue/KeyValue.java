package br.eti.fml.data.db.keyvalue;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public interface KeyValue {
    public void put(String key, final byte[] value) throws IOException;
    public byte[] get(String key) throws IOException;
}
