package br.eti.fml.wonderfulstates;

import java.util.Iterator;

/**
 * Represents a state history.
 * 
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface History<S extends State> {
    boolean itCanBeAccessedFromBegin();
    boolean itCanBeAccessedFromEnd();
    boolean itCanBeRandomlyAccessedByDate();
    boolean itCanBeRandomlyAccessedByIndex();
    boolean itCanBeRandomlyAccessedByHash();
    boolean isComplete();

    /**
     * @return the MINIMUM historical entries. Notice that this history
     *         can have MORE than the number returned on this funcion.
     *         It can't be exact when the history implementation
     *         can have some difficulty to determine or access
     *         some kind of entries depending of the optimizations.
     */
    int howManyEntriesAtLeast();

    boolean hasDateInformation();

    Pair<Long, S> findByData(long timestamp)
            throws StateNotFoundException,
                   java.lang.UnsupportedOperationException;

    Pair<Long, S> findByHash(long stateHash)
            throws StateNotFoundException,
                   java.lang.UnsupportedOperationException;

    Pair<Long, S> findByIndex(int index) 
            throws StateNotFoundException,
                   java.lang.UnsupportedOperationException;

    Iterator<S> getFromBegin() throws java.lang.UnsupportedOperationException;
    Iterator<S> getFromEnd() throws java.lang.UnsupportedOperationException;
}
