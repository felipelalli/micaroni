package br.eti.fml.data.db.keyvalue;

import java.io.IOException;

/**
 * It is a very simple key-value database.
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public interface KeyValue {
    /**
     * This name will be used for function {@link #put(String, String, byte[])}
     * and {@link #get(String)} in databases that works with columns,
     * like Cassandra. <b>The value is {@value}</b>.
     */
    public static final String DEFAULT_COLUMN = "DEFAULT_COLUMN";

    void put(String key, byte[] data) throws IOException;
    void put(String key, String column, byte[] data) throws IOException;
    void lazyPut(String queueId, String key, byte[] data) throws IOException;
    void lazyPut(String queueId, String key, String column, byte[] data) throws IOException;

    void delete(String key) throws IOException;
    void delete(String key, String column) throws IOException;
    void lazyDelete(String queueId, String key) throws IOException;
    void lazyDelete(String queueId, String key, String column) throws IOException;

    byte[] get(String key) throws IOException;
    byte[] get(String key, String column) throws IOException;

    void commitQueue(String queueId) throws IOException;

    byte[][] getSlice(String key, String startColumn, String endColumn)
            throws IOException, UnsupportedOperationException;

    void shutdown() throws IOException;
}
