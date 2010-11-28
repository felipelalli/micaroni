package br.eti.fml.ridiculousdb;

import java.io.IOException;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class DoubleRDB extends TypeRDB<Double> {
    public DoubleRDB(RidiculousDB db, String key) throws IOException {
        this(db, key, 0d);
    }

    public DoubleRDB(RidiculousDB db,
            String key, double initialValue) throws IOException
    {
        super(db, key);
        this.db().putFirstTime(key, initialValue);
    }

    public double add(double value) throws IOException {
        return this.db().addDouble(key(), value);
    }

    @Override
    public void set(Double newValue) throws IOException {
        this.db().putOverwrite(key(), newValue);
    }

    @Override
    public Double currentValue() {
        return this.db().getDouble(key());
    }
}
