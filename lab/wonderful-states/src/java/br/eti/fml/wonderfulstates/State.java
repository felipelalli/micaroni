package br.eti.fml.wonderfulstates;

/**
 * A State represents a "snapshot" of anything.
 *
 * A State has the follow characteristics:
 * <ul>
 *  <li>At first it contains history, but the history values can be
 *      {@link #isBroken() broken} or {@link #isFuzzy() fuzzy}.</li>
 *  <li>It is part of an {@link Universe}.</li>
 *  <li>It is mutable until the {@link #setAndFreeze} is called.</li>
 *  <li>It can be broken or fuzzy.</li>
 * </ul>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface State<T, U extends Universe<T>> {
    /**
     * Indicates that it is a invalid state and all functions to get value
     * will return a runtime exception of {@link BrokenStateException}.
     * Every broken states also will return true for {@link #isFuzzy()}.
     * This function guarantees that you cannot retrieve any value: this
     * is not only corrupted, it is also completely inaccessible. If the state
     * is only corrupted but it can guess some value, the state would be
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isBroken();

    /**
     * Indicates that this state has a not accurate value. It can
     * be true or not. This state probably has the true value or at least
     * it do its best to have it. It can happens, e. g., because the value
     * was storedin a non safe place or because it is a calculated or
     * presumed value. All {@link #isBroken() broken} states is also fuzzy.
     */
    boolean isFuzzy();

    /**
     * It is a really weird situation, but it can happens if you create
     * a state and never set any value.
     */
    boolean isBeforeTheFirstValue();

    /**
     * Accesses its {@link History}. It never returns null, even the
     * implementation of this state doesn't have a valid, complete
     * or any history.
     */
    History<State<T, U>> getHistory();

    /**
     * Accesses its {@link Universe}. It never returns null, even the
     * universe is a {@link Any generic universe}.
     */
    U getUniverse();


    /**
     * Get value and don't block.
     */
    T getToSee() throws BrokenStateException;

    /**
     * Get value and block.
     */
    T getToChange() throws BrokenStateException, FreezedException;

    /**
     * Set and unblock if success.
     */
    boolean set(T previousValue, T newValue)
            throws InvalidInitialValueException, InvalidChangeException,
                   SetWithoutGetToChangeFirstException;

    /**
     * Dangerous! It will ignore the {@link #getUniverse() universe}, but
     * it can be faster depending on the implementation. It will unblock
     * if it was previously blocked.
     */
    boolean forceSet(T newValue);

    /**
     * Set and freeze this state. Unblock this state if success.
     *
     * @return if it was really set.
     */
    boolean setAndFreeze(T previousValue, T finalValue)
            throws InvalidInitialValueException, InvalidChangeException,
                   InvalidFinalValueException;

    /**
     * Give up to change this state.
     */
    void giveUpAndUnblock();

    /**
     * Every state has a hashcode.
     */
    long calculateHash() throws BrokenStateException;
}
