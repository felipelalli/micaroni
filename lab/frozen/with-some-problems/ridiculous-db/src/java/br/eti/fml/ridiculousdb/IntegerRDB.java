package br.eti.fml.ridiculousdb;

import java.io.IOException;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class IntegerRDB extends TypeRDB<Integer> {
    public IntegerRDB(RidiculousDB db, String key) throws IOException {
        this(db, key, 0);
    }

    public IntegerRDB(RidiculousDB db,
            String key, int initialValue) throws IOException
    {
        super(db, key);
        this.db().putFirstTime(key, initialValue);
    }

    public int add(int value) throws IOException {
        return this.db().addInteger(key(), value);
    }

    @Override
    public void set(Integer newValue) throws IOException {
        this.db().putOverwrite(key(), newValue);
    }

    @Override
    public Integer currentValue() {
        return this.db().getInteger(key());
    }
}
