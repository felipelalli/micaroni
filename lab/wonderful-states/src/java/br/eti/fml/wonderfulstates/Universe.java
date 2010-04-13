package br.eti.fml.wonderfulstates;

/**
 * It represents a set (or range) of a valid initials,
 * deltas and finals values.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Universe<T extends Object> {

    /**
     * Checks if this changing is part of this universe.
     * If the <code>previousValue</code> parameter is <code>null</code>
     * then this function will check if the <code>newValue</code>
     * is a {@link #checksIfItIsAValidInitialValue(java.lang.Object) valid
     * initial value}.
     */
    public abstract boolean checksIfItIsAValidChanging(T previousValue, T newValue);

    /**
     * It is the same of a
     * {@link #checksIfItIsAValidChanging(java.lang.Object, java.lang.Object)
     * checksIfItIsAValidChanging(<code>null</code>, T)} call. The default implementation
     * is exactly this.
     */
    public boolean checksIfItIsAValidInitialValue(T value) {
        return checksIfItIsAValidChanging(null, value);
    }

    /**
     * Checks if the state related with this Universe
     * can be freezed after the set of this value.
     */
    public abstract boolean checksIfItIsAValidFinalValue(T value);
}
