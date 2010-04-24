package br.eti.fml.wonderfulstates.universe;

/**
 * It represents a set (or range) of a valid initials,
 * deltas and finals values.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Universe<T extends Object> {

    /**
     * Check if this changing is part of this universe.
     */
    public abstract boolean checksIfItIsAValidChanging(T previousValue, T newValue);

    /**
     * Check if this value is part of the initial possible values.
     */
    public abstract boolean checksIfItIsAValidInitialValue(T value);

    /**
     * Check if the state related with this Universe
     * can be frozen after the setting of this value.
     */
    public abstract boolean checksIfItIsAValidFinalValue(T value);
}
