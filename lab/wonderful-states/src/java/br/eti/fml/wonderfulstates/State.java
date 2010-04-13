package br.eti.fml.wonderfulstates;

/**
 * <p>
 * A State represents a "snapshot" of anything in a timeline and it
 * can be changed only by a valid {@link Event}.
 * </p>
 *
 * <p>
 * A State has the follow characteristics:
 * <ul>
 *  <li>It is part of an {@link Universe}.</li>
 *  <li>It is mutable until an {@link Event} frozen it.</li>
 *  <li>It can be broken or fuzzy.</li>
 *  <li>It has a universal unique number represented by 160 bits
 *      (or 20 bytes) from its born to its frozen state. This number
 *      doesn't represent its content.</li>
 * </ul>
 * </p>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface State<T extends Object, U extends Universe<T>> {
    /**
     * Indicates that it is a invalid state and all functions to get value
     * will return a runtime exception of {@link BrokenStateException}.
     * All broken states also will return true for {@link #isFuzzy()}.
     * This function guarantees that you cannot retrieve any value: this
     * is not only corrupted, it is also completely inaccessible. If the state
     * is only corrupted but it can guess some value, the state would be
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isBroken();

    /**
     * Indicates that it state has a not accurate value. It can
     * be true or not. This state probably has the true value or at least
     * it do its best to have it. It can happens, e. g., because the value
     * was stored in a non safe place or because it is a calculated or
     * presumed value. All {@link #isBroken() broken} states is also
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isFuzzy();

    /**
     * When this State is frozen, i. e., it is immutable forever.
     */
    boolean isFrozen();

    /**
     * It is a really weird situation, but it can happens if you create
     * a state and never set any value. When the State is in this state
     * not means that it is {@link #isBroken() broken} or fuzzy.
     */
    boolean isBeforeTheFirstValue();

    /**
     * Accesses its {@link Universe}. It never returns null, even the
     * universe is a {@link Any generic universe}.
     */
    U getUniverse();

    /**
     * Get the current value.
     */
    T getValue() throws BrokenStateException;

    /**
     * Get the timestamp of the last change.
     */
    Long getLastTimestampChange() throws CantDetermineLastChangeException;

    /**
     * Get the current value and the timestamp when it was defined.
     */
    Pair<T, Long> getValueInTheTime() throws BrokenStateException;

    /**
     * Try to apply the {@link Event}.
     * 
     * @throws OutdateException if the previousValue is not equals
     *                          {@link #getValue the current value}.
     */
    void apply(T previousValue, Event<T, U> event)
            throws InvalidInitialValueException, InvalidFinalValueException,
                   InvalidChangeException, FrozenException, OutdatedException;

    /**
     * <b>Dangerous!</b> It will ignore the {@link #getUniverse() universe}, but
     * it can be faster depending on the implementation. Notice that this need
     * to be avoided. Use only for a necessary optimization and in cases where
     * the {@link Universe} is flexible enough.
     *
     * @return true only if in case of success
     */
    boolean forceApply(Event<T, U> event);
}
