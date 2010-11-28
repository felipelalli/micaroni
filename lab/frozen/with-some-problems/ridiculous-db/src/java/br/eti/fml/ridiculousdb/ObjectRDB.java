package br.eti.fml.ridiculousdb;

import java.io.IOException;
import java.io.Serializable;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ObjectRDB<T extends Serializable> extends TypeRDB<T> {
    public ObjectRDB(RidiculousDB db, String key) throws IOException {
        super(db, key);
    }

    public ObjectRDB(RidiculousDB db,
            String key, Object initialValue) throws IOException
    {
        super(db, key);
        this.db().putFirstTimeObject(key, initialValue);
    }

    @Override
    public void set(T newValue) throws IOException {
        this.db().putOverwriteObject(key(), newValue);
    }

    @Override
    public T currentValue() {
        return (T) this.db().<T>getObject(key());
    }
}
