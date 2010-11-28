package br.eti.fml.ridiculousdb;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * A big and sorted list.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class BigList {
    private static final String SIZE = "~s";
    private static final String SIZE_DELETED = "~sd";
    private static final String ROOT = "~r";
    private static final String LEFT = "~0";
    private static final String RIGHT = "~1";
    private static final String VALUE = "~v";
    private static final String DELETED = "~d";
    private static final String INDEX = "~i";
    private static final String INDEXES = "^-^";

    private String key;
    private RidiculousDB db;
    private CustomComparator[] comparators;
    private IntegerRDB size;
    private IntegerRDB deleted;

    public BigList(RidiculousDB db, String key) throws IOException {
        this(db, key, (CustomComparator[]) null);
    }

    public BigList(RidiculousDB db, String key, CustomComparator comparator)
        throws IOException
    {
        this(db, key, (CustomComparator[]) null);
        this.comparators = new CustomComparator[1];
        this.comparators[0] = comparator;
        this.fixIndexes();
    }

    /**
     * 
     * @param comparators It's a map where the key is the index name
     *                    and the value is the correspondent comparator.
     */
    public BigList(RidiculousDB db,
            String key, CustomComparator[] comparators)
        throws IOException
    {
        this.db = db;
        this.key = key;
        this.comparators = comparators;
        this.size = new IntegerRDB(this.db, key + SIZE, 0);
        this.deleted = new IntegerRDB(this.db, key + SIZE_DELETED, 0);
        this.fixIndexes();
    }

    private void fixIndexes() throws IOException {
        String oldHash = this.db.getString(indexesHash());
        String newHash = getHash(this.comparators);

        if (oldHash == null) {
            this.db.putOverwrite(indexesHash(), newHash);
        } else if (!oldHash.equals(newHash)) {
            System.err.println("You changed the index! Recalculating...");

            List<String> all = this.getAll();

            for (String s : all) {
                this.remove(s);
            }

            for (String s : all) {
                this.insert(s);
            }

            this.db.putOverwrite(indexesHash(), newHash);
            System.err.println("New index OK!");
        }
    }

    public synchronized void clean() throws IOException {
        List<String> all = this.getAll();

        for (String s : all) {
            this.remove(s);
        }
    }

    private String getHash(CustomComparator[] comparators) {
        String hash = "";

        if (comparators == null) {
            hash = "null";
        } else {
            for (CustomComparator cc : comparators) {
                hash += cc.name() + ":";
            }
        }

        return hash;
    }

    public synchronized int size() {
        return this.size.currentValue() - this.deleted.currentValue();
    }

    public synchronized void insert(String elementKey) throws IOException {
        try {
            this.db.beginTransaction();
            int currentSize = this.size.currentValue();

            this.db.putOverwrite(elementKey(currentSize), elementKey);
            
            this.db.putOverwrite(deletedKey(currentSize), 0);
            this.db.putOverwrite(indexKey(elementKey), currentSize);

            this.size.add(1);

            if (this.comparators != null) {
                for (CustomComparator cc : this.comparators) {
                    this.recursiveInsert(elementKey, root(cc.name()), cc);
                }
            }

            this.db.commitTransaction();
        } catch (IOException e) {
            this.db.abortTransaction();
            throw e;
        } catch (Throwable e) {
            this.db.abortTransaction();
        }
    }

    private String indexesHash() {
        return key + INDEXES;
    }
    
    private String indexKey(String elementKey) {
        return key + "." + elementKey + INDEX;
    }

    private String elementKey(int index) {
        return key + "." + index;
    }

    private String deletedKey(int index) {
        return key + "." + index + DELETED;
    }

    private String root(String indexName) {
        return key + "<" + indexName + ">" + ROOT;
    }
    
    private String valueTreeKey(String key) {
        return key + VALUE;
    }

    private String leftTreeKey(String key) {
        return key + LEFT;
    }

    private String rightTreeKey(String key) {
        return key + RIGHT;
    }

    private boolean isDeleted(int index) {
        Integer isDeleted = this.db.getInteger(deletedKey(index));

        if (isDeleted == null) {
            System.err.println("Missing " + deletedKey(index)
                    + " index(" + index + ") key!");

            return true;
        } else {
            return (isDeleted != 0);
        }
    }

    private Integer getIndex(String keyElement) {
        Integer index = this.db.getInteger(indexKey(keyElement));
        return index;
    }

    public synchronized void remove(String elementKeyToDelete)
            throws IOException
    {
        try {
            this.db.beginTransaction();

            Integer index = this.getIndex(elementKeyToDelete);

            if (index != null) {
                this.db.putOverwrite(deletedKey(index), 1);                
                this.deleted.add(1);

                if (this.comparators != null) {
                    for (CustomComparator cc : this.comparators) {
                        this.recursiveDelete(
                                elementKeyToDelete, root(cc.name()), cc);
                    }
                }
            }
            
            this.db.commitTransaction();
        } catch (IOException e) {
            this.db.abortTransaction();
            throw e;
        } catch (Throwable e) {
            this.db.abortTransaction();
        }
    }

    private void recursiveInsert(
            String elementKey, String newKey,
            Comparator<byte[]> comparator) throws IOException
    {
        byte[] element = this.db.get(elementKey);

        if (element != null) {
            String storedKey = this.db.getString(valueTreeKey(newKey));

            if (storedKey == null) {
                this.db.putOverwrite(valueTreeKey(newKey), elementKey);
            } else {
                byte[] obj = this.db.get(storedKey);

                if (comparator.compare(element, obj) < 0) {
                    this.recursiveInsert(elementKey,
                            leftTreeKey(newKey), comparator);
                } else {
                    this.recursiveInsert(elementKey,
                            rightTreeKey(newKey), comparator);
                }
            }
        }
    }

    private void recursiveDelete(
            String elementKey, String newKey,
            Comparator<byte[]> comparator) throws IOException
    {
        byte[] element = this.db.get(elementKey);

        if (element != null) {
            String storedKey = this.db.getString(valueTreeKey(newKey));

            if (storedKey != null) {
                if (elementKey.equals(storedKey)) {
                    Integer index = this.getIndex(elementKey);

                    if (index != null) {
                        this.db.putOverwrite(deletedKey(index), 1);
                    }
                }
                
                byte[] obj = this.db.get(storedKey);

                if (obj != null) {
                    if (comparator.compare(element, obj) < 0) {
                        this.recursiveDelete(elementKey,
                                leftTreeKey(newKey), comparator);
                    } else {
                        this.recursiveDelete(elementKey,
                                rightTreeKey(newKey), comparator);
                    }
                }
            }
        }
    }

    private void recursiveFirsts(List<String> list, String key, int max)
            throws IOException
    {
        if (list.size() >= max) {
            return;
        } else {
            String storedKey = this.db.getString(valueTreeKey(key));            

            if (storedKey == null) {
                return;
            } else {
                recursiveFirsts(list, leftTreeKey(key), max);
                boolean isDeleted = this.isDeleted(getIndex(storedKey));
                
                if (!isDeleted) {
                    if (list.size() < max) {
                        list.add(storedKey);
                    }
                }

                recursiveFirsts(list, rightTreeKey(key), max);
            }
        }
    }

    public synchronized List<String> getFirsts(int max) throws IOException {
        List<String> result = new ArrayList<String>();

        try {
            this.db.beginTransaction();

            int currentSize = this.size.currentValue();

            for (int i = 0; i < currentSize && result.size() < max; i++) {               
                if (!isDeleted(i)) {
                    result.add(this.db.getString(elementKey(i)));
                }
            }
            
            this.db.commitTransaction();
        } catch (IOException e) {
            this.db.abortTransaction();
            throw e;
        } catch (Throwable e) {
            this.db.abortTransaction();
        }

        return result;
    }
    
    public synchronized List<String> getAll() throws IOException {
        return this.getFirsts(Integer.MAX_VALUE);
    }

    /**
     * Get the firts <code>max</code> elements sorted.
     */
    public synchronized List<String> getSortedFirsts(String indexName, int max)
            throws IOException
    {
        List<String> result = new ArrayList<String>();

        try {
            this.db.beginTransaction();
            this.recursiveFirsts(result, root(indexName), max);
            this.db.commitTransaction();
        } catch (IOException e) {
            this.db.abortTransaction();
            throw e;
        } catch (Throwable e) {
            this.db.abortTransaction();
        }

        return result;
    }

    public synchronized List<String> getSortedAll(String indexName) throws IOException {
        return this.getSortedFirsts(indexName, Integer.MAX_VALUE);
    }
}
