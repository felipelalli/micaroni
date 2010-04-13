package br.eti.fml.wonderfulstates;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class SecurityGuardOfStates {

    /**
     * Get the state to read only.
     */
    public abstract State getState(String stateUID);

    /**
     * Get and try to change the state, if you can!
     *
     * @see #getAndBlockStateToChangingForAWhile(java.lang.String)
     */
    public abstract MutableState getStateToChange(String stateUID);

    /**
     * Use this only if you are having some difficulty to change
     * some state with {@link #getStateToChange}.
     * It guarantees (for a undetermined but probably enough time)
     * that you will have always the right previous value
     * to change the state. Don't forget to call {@link #unblockState} as soon
     * as possible after you change the state, otherwise everybody can
     * be angry with you. When you will use this to change a state, don't
     * forget that is similar to use a busy toilet: return the key!
     *
     * @see #unblockState(br.eti.fml.wonderfulstates.Key)
     * @see #getStateToChange(java.lang.String) 
     */
    public abstract Pair<Key, MutableState>
            getAndBlockStateToChangingForAWhile(String stateUID);

    /**
     * It is to be nice with the others even before your
     * "time to changing" expires.
     */
    public abstract void unblockState(Key keyToUnblock);
}
