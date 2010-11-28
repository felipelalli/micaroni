package br.eti.fml.ridiculousdb;

import java.io.IOException;
import java.io.Serializable;
import java.io.UnsupportedEncodingException;
import java.util.List;
import tokyocabinet.Util;

/**
 * This is a simple and ridiculous but powerful and very good
 * database system. The interface was based on tokyocabinet.DBM
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class RidiculousDB {
    public abstract void beginTransaction() throws IOException;
    public abstract void abortTransaction() throws IOException;
    public abstract void commitTransaction() throws IOException;

    public abstract void erase() throws IOException;
    public abstract void optimize() throws IOException;
    public abstract String getInfo() throws IOException;
    public abstract void close() throws IOException;    
    public abstract void putOverwrite(
            String key, byte[] value) throws IOException;
    public abstract boolean putFirstTime(
            String key, byte[] value) throws IOException;
    public abstract int addInteger(String key, int value) throws IOException; 
    public abstract double addDouble(
            String key, double value) throws IOException;
    public abstract void remove(String key) throws IOException;

    public abstract byte[] get(String key);
    public abstract List getForwardKeys(String prefix, int max);
    public abstract long getSize();
    public abstract long getSizeInBytes();

    // AUX

    public boolean putFirstTimeObject(
            String key, Object value) throws IOException
    {
        return this.putFirstTime(key, Util.serialize(value));
    }

    public boolean putFirstTime(String key, int value) throws IOException {
        return this.putFirstTime(key, Util.packint(value));
    }

    public boolean putFirstTime(String key, String value) throws IOException {
        return this.putFirstTime(key, value.getBytes("UTF-8"));
    }

    public boolean putFirstTime(String key, double value) throws IOException {
        return this.putFirstTime(key, Util.packdouble(value));
    }

    public void putOverwriteObject(String key, Object value) throws IOException {
        this.putOverwrite(key, Util.serialize(value));
    }
    
    public void putOverwrite(String key, int value) throws IOException {
        this.putOverwrite(key, Util.packint(value));
    }

    public void putOverwrite(String key, double value) throws IOException {
        this.putOverwrite(key, Util.packdouble(value));
    }

    public void putOverwrite(String key, String value) throws IOException {
        this.putOverwrite(key, value.getBytes("UTF-8"));
    }

    public String getString(String key) {
        byte[] value = this.get(key);

        if (value == null) {
            return null;
        } else {
            try {
                return new String(value, "UTF-8");
            } catch (UnsupportedEncodingException e) {
                return "<INTERNAL ERROR " + e + ">";
            }
        }
    }

    public Integer getInteger(String key) {
        byte[] value = this.get(key);

        if (value == null) {
            return null;
        } else {
            return Util.unpackint(value);
        }
    }

    public Double getDouble(String key) {
        byte[] value = this.get(key);

        if (value == null) {
            return null;
        } else {
            return Util.unpackdouble(value);
        }
    }

    @SuppressWarnings ("unchecked")
    public <T> T getObject(String key) {
        byte[] value = this.get(key);

        if (value == null) {
            return null;
        } else {
            return (T) Util.deserialize(value);
        }
    }

    public static byte[] objectToBytes(Serializable obj) {
        return Util.serialize(obj);
    }

    public static Object bytesToObject(byte[] bytes) {
        return Util.deserialize(bytes);
    }

    public static int bytesToInteger(byte[] bytes) {
        return Util.unpackint(bytes);
    }
    
    public static byte[] intToBytes(int obj) {
        return Util.packint(obj);
    }

    public static double bytesToDouble(byte[] bytes) {
        return Util.unpackdouble(bytes);
    }
    
    public static byte[] doubleToBytes(double obj) {
        return Util.packdouble(obj);
    }

    public static byte[] stringToBytes(String string) {
        try {
            return string.getBytes("UTF-8");
        } catch (UnsupportedEncodingException e) {
            return null;
        }
    }

    public static String bytesToString(byte[] bytes) {
        try {
            return new String(bytes, "UTF-8");
        } catch (UnsupportedEncodingException e) {
            return null;
        }        
    }
}
