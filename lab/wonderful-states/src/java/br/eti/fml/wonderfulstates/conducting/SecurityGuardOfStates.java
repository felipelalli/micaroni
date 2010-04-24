package br.eti.fml.wonderfulstates.conducting;

import br.eti.fml.wonderfulstates.*;
import br.eti.fml.wonderfulstates.mutable.MutableState;

/**
 * The first layer between the {@link State}s and the world.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class SecurityGuardOfStates {

    /**
     * Get the {@link State} to read only.
     */
    public abstract State getState(String stateUID);

    /**
     * Get the {@link State} to try to change. It just if you can because
     * you will only get a change if you have the <b>right</b>
     * <i>previous value</i>.
     *
     * @see #getAndBlockStateToChangeForAWhile(java.lang.String)
     */
    public abstract MutableState getStateToChange(String stateUID);

    /**
     * <p>
     * Use this only if you are having some difficulty to change
     * some {@link State} with {@link #getStateToChange}.
     * It guarantees (for a undetermined but probably <i>enough time</i>)
     * that you will have always the <i>right previous value</i>
     * to change the <code>State</code>.
     * </p>
     * <p>
     * Don't forget to call {@link #unblockState} as soon
     * as possible after you change the <code>State</code>, otherwise
     * everybody else can be very angry with you.
     * </p>
     * <p>
     * When you will use this to change a <code>State</code>, don't
     * forget that is similar to use a busy toilet: you must return the key!
     * </p>
     * <p>
     * The <i>enough time</i> depends of the implementation, but don't
     * expect so much.
     * </p>
     * 
     * @see #unblockState(br.eti.fml.wonderfulstates.Key)
     * @see #getStateToChange(java.lang.String) 
     */
    public abstract Pair<Key, MutableState>
            getAndBlockStateToChange(String stateUID);

    /**
     * It's nice to be nice with the others even before your
     * "time to changing" expires.
     */
    public abstract void unblockState(Key keyToUnblock);
}
