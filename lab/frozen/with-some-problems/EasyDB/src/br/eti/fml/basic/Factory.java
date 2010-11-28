package br.eti.fml.basic;

import java.util.Collection;
import java.util.Vector;

/**
 * Subclasses of this class is able to generate new elements. It is
 * possible the child class has specific functions to customize the
 * creation.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Factory<Product> {
    /**
     * Create a new element.
     */
    public abstract Product createNew() throws CreationError;

    /**
     * Create N new elements. <i>The default implementation
     * is a <code>for</code> witch uses the function {@link #createNew()},
     * however the child class may reimplement in a different way
     * to be more optimized.</i>
     */
    public Collection<Product> createNew(int quantosElementos) throws CreationError {
        Vector<Product> v = new Vector<Product>();

        for (int i = 0; i < quantosElementos; i++) {
            v.add(this.createNew());
        }

        return v;
    }
}