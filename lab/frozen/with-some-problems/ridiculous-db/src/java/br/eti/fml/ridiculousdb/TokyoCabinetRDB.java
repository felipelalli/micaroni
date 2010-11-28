package br.eti.fml.ridiculousdb;

import java.io.File;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.List;
import tokyocabinet.HDB;
import tokyocabinet.Util;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class TokyoCabinetRDB extends RidiculousDB {
    private String path;
    private HDB hdb = null;
    private String ENCODE = "UTF-8";

    private void throwIOException() throws IOException {
        int ecode = this.hdb.ecode();
        throw new IOException(HDB.errmsg(ecode));
    }

    /**
     * Avoid to use it!
     */
    public HDB getSourceTokyoHDB() {
        return this.hdb;
    }

    private void loadLibrary() throws IOException {
        if (hdb == null) {
            try {
                hdb = new HDB();
            } catch (UnsatisfiedLinkError e) {
                throw new IOException("java.library.path=\""
                        + System.getProperty("java.library.path") + "\"", e);
            }
        }
    }

    public TokyoCabinetRDB(File dirPath) throws IOException {
        if (!dirPath.isDirectory()) {
            throw new IllegalArgumentException(
                    dirPath + " is not a directory!");
        } else {
            this.path = dirPath.getAbsolutePath();

            if (!this.path.endsWith("/") && !this.path.endsWith("\\")) {
                this.path += "/";
            }

            new File(this.path).mkdirs();
            this.path += "tokyo.tch";

            this.loadLibrary();

            this.hdb.setdfunit(256);
            this.hdb.setcache(1000);

            if (!this.hdb.open(this.path, HDB.OWRITER | HDB.OCREAT)) {
                throwIOException();
            }
        }
    }

    public void optimize() throws IOException {
        if (!this.hdb.optimize()) {
            throwIOException();
        }
    }

    public void close() throws IOException {
        if (!this.hdb.close()) {
            throwIOException();
        }
    }

    public void putOverwrite(String key, byte[] value) throws IOException {
        if (!this.hdb.put(key.getBytes(ENCODE), value)) {
            throwIOException();
        }
    }

    public boolean putFirstTime(String key, byte[] value) throws IOException {
        return this.hdb.putkeep(key.getBytes(ENCODE), value);
    }

    public int addInteger(String key, int value) throws IOException {
        int i = this.hdb.addint(key.getBytes(ENCODE), value);

        if (Integer.MIN_VALUE == i)  {
            throwIOException();
        }

        return i;
    }

    public double addDouble(String key, double value) throws IOException {
        double d = this.hdb.adddouble(key.getBytes(ENCODE), value);

        if (Double.isNaN(d))  {
            throwIOException();
        }

        return d;
    }

    public void remove(String key) throws IOException {
        if (!this.hdb.out(key)) {
            throwIOException();
        }
    }

    public List getForwardKeys(String prefix, int max) {
        return this.hdb.fwmkeys(path, max);
    }

    public long getSize() {
        return this.hdb.rnum();
    }

    public long getSizeInBytes() {
        return this.hdb.fsiz();
    }

    public void beginTransaction() throws IOException {
        if (!this.hdb.tranbegin()) {
            throwIOException();
        }
    }

    public void abortTransaction() throws IOException {
        if (!this.hdb.tranabort()) {
            throwIOException();
        }
    }

    public void commitTransaction() throws IOException {
        if (!this.hdb.trancommit()) {
            throwIOException();
        }
    }

    public byte[] get(String key) {
        try {
            return this.hdb.get(key.getBytes(ENCODE));
        } catch (UnsupportedEncodingException e) {
            return null;
        }
    }

    public String getInfo() {
        return (this.getSizeInBytes() / 1000000) + " MB"
                + " / " + this.getSize() + " / "
                + Util.version();
    }

    public void printInfo() {
        System.out.println(this.getInfo());
        System.out.flush();
    }

    public void erase() throws IOException {
        if (!this.hdb.vanish()) {
            throwIOException();
        }
    }
}
