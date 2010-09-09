/*
 * Copyright (c) 2010.
 * Wonderful States
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0
 * Unported License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 171 Second Street, Suite 300,
 * San Francisco, California, 94105, USA.
 */

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
