package br.eti.fml.wonderfulstates;

/**
 * It represents a set (or range) of a valid initials,
 * deltas and finals values.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface Universe<T extends Object> {

    /**
     * Checks if this change is part of this universe.
     * If the <code>previousValue</code> parameter is null
     * then this function will check if the <code>newValue</code>
     * is a {@link #checksIfItIsAValidInitialValue(java.lang.Object) valid
     * initial value}.
     */
    boolean checksIfItIsAValidChange(T previousValue, T newValue);

    /**
     * It is the same of a
     * {@link #checksIfItIsAValidChange(java.lang.Object, java.lang.Object)
     * checksIfItIsAValidChange(null, T)} call.
     */
    boolean checksIfItIsAValidInitialValue(T value);

    /**
     * Checks if the state related with this Universe
     * can be freezed after the set of this value.
     */
    boolean checksIfItIsAValidFinalValue(T value);
}
