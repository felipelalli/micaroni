package br.eti.fml.ridiculousdb;

import java.io.IOException;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class StringRDB extends TypeRDB<String> {

    public StringRDB(RidiculousDB db, String key) throws IOException {
        this(db, key, "");
    }
    
    public StringRDB(RidiculousDB db, String key, String initialValue)
            throws IOException
    {
        super(db, key);
        this.db().putFirstTime(key, initialValue.getBytes());
    }

    @Override
    public void set(String newValue) throws IOException {
        this.db().putOverwrite(key(), newValue);
    }

    @Override
    public String currentValue() {
        return this.db().getString(key());
    }
}
