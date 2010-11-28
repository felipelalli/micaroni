package br.eti.fml.ridiculousdb;

import java.io.IOException;
import java.io.Serializable;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class TypesFactory {
    private RidiculousDB db;

    public TypesFactory(RidiculousDB db) {
        this.db = db;
    }

    public static String generateRandomKey() {
        return "" + Long.toString(
                (long) (Long.MAX_VALUE * Math.random()), Character.MAX_RADIX);
    }

    public IntegerRDB newInteger(int initialValue) throws IOException {
        return new IntegerRDB(db, generateRandomKey(), initialValue);
    }

    public DoubleRDB newDouble(double initialValue) throws IOException {
        return new DoubleRDB(db, generateRandomKey(), initialValue);
    }

    public StringRDB newString(String initialValue) throws IOException {
        return new StringRDB(db, generateRandomKey(), initialValue);
    }

    public <T extends Serializable> ObjectRDB<T>
            newObject(T initialValue) throws IOException
    {
        return new ObjectRDB<T>(db, generateRandomKey(), initialValue);
    }
}
