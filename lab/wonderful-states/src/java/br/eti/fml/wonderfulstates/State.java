package br.eti.fml.wonderfulstates;

import java.util.concurrent.TimeoutException;

/**
 * <p>
 * A State represents a "snapshot" of anything in a timeline.
 * </p>
 *
 * <p>
 * A State has the follow characteristics:
 * <ul>
 *  <li>It is part of an {@link Universe}.</li>
 *  <li>It can be {@link #isBroken() broken} or {@link #isFuzzy() fuzzy}.</li>
 *  <li>It has a universal ID.</li>
 * </ul>
 * </p>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface State<T extends Object, U extends Universe<T>> {
    /**
     * Means that this state is not ready to be read yet, but could
     * be transformed soon into a valid, fuzzy or broken value.
     */
    boolean isUnreacheableYet();

    /**
     * The default-default timeout is 0L, and 0L means no timeout.
     * By default any read-function needs to wait the value
     * become {@link #isUnreacheableYet() reacheable}. The methods
     * {@link #isBroken()}, {@link #isFrozen()}, {@link #isFuzzy()},
     * {@link #getValue()}, {@link #getValueInTheTime()} and
     * {@link #isBeforeTheFirstValue()} can block for a undetermined
     * time if the timeout is not defined (or defined to 0L).
     * 
     * @param timeout in millis
     */
    void setDefaultTimeout(long timeout);

    /**
     * Indicates that it is a invalid state and all functions to get value
     * will return a runtime exception of {@link BrokenStateException}.
     * All broken states also will return true for {@link #isFuzzy()}.
     * This function guarantees that you cannot retrieve any value: this
     * is not only corrupted, it is also completely inaccessible. If the state
     * is only corrupted but it can guess some value, the state would be
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isBroken() throws TimeoutException;

    /**
     * Indicates that it state has a not accurate value. It can
     * be true or not. This state probably has the true value or at least
     * it do its best to have it. It can happens, e. g., because the value
     * was stored in a non safe place or because it is a calculated or
     * presumed value. All {@link #isBroken() broken} states is also
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isFuzzy() throws TimeoutException;

    /**
     * When this State is frozen, i. e., it is immutable forever.
     */
    boolean isFrozen() throws TimeoutException;

    /**
     * It is a really weird situation, but it can happens if you create
     * a state and never set any value. When the State is in this state
     * not means that it is {@link #isBroken() broken} or
     * {@link #isFuzzy() fuzzy}.
     */
    boolean isBeforeTheFirstValue() throws TimeoutException;

    /**
     * Accesses its {@link Universe}. It never returns <code>null</code>, even the
     * universe is a {@link Any generic universe}.
     */
    U getUniverse();

    /**
     * Get the current value.
     */
    T getValue() throws BrokenStateException, TimeoutException;

    /**
     * Get the current value and the timestamp when it was defined.
     */
    Pair<T, Long> getValueInTheTime() throws BrokenStateException, TimeoutException;

    /**
     * Get the timestamp of the last changing.
     */
    Long getLastChangingTimestamp() throws CantDetermineLastChangingException;

    /**
     * Unique ID number to indentify this state in all world.
     */
    String getUID();
}
