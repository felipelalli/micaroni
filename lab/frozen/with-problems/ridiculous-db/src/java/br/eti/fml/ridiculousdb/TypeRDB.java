package br.eti.fml.ridiculousdb;

import java.io.IOException;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class TypeRDB<T> {
    private RidiculousDB database;
    private String key;

    protected TypeRDB(RidiculousDB database, String key) {
        this.database = database;
        this.key = key;
    }

    protected RidiculousDB db() {
        return this.database;
    }

    public String key() {
        return this.key;
    }

    public abstract void set(T newValue) throws IOException;
    public abstract T currentValue();

    public void beginTransaction() throws IOException {
        this.db().beginTransaction();
    }

    public void abortTransaction() throws IOException {
        this.db().abortTransaction();
    }
    
    public void commitTransaction() throws IOException {
        this.db().commitTransaction();
    }

    @Override
    public String toString() {
        return key() + "(" + this.currentValue().toString() + ")";
    }
}
