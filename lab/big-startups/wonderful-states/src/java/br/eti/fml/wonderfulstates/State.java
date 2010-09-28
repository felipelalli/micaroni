package br.eti.fml.wonderfulstates;

import br.eti.fml.basic.Pair;
import br.eti.fml.wonderfulstates.universe.Universe;

/**
 * <p>
 * A State represents a "snapshot" of anything in a timeline.
 * A State is "live", i. e., its value can be changed internally
 * unless the {@link #isFrozen()} is set. If you need to change a state,
 * please have a look at {@link br.eti.fml.wonderfulstates.mutable.MutableState}.
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
public abstract class State<T extends Object, U extends Universe<T>> {
    /**
     * Means that this state is not ready to be read yet, but could
     * be transformed soon into a valid, fuzzy or broken value.
     */
    public abstract boolean isUnreacheableYet();

    /**
     * By default any read-function needs to wait the value
     * become {@link #isUnreacheableYet() reacheable}. The methods
     * {@link #isBroken()}, {@link #isFrozen()}, {@link #isFuzzy()},
     * {@link #getValue()}, {@link #getValueInTheTime()} and
     * {@link #isBeforeTheFirstValue()} can block for a undetermined
     * time if the timeout is defined to zero. This value doesn't need to be
     * very accurate and it means the maximum time in milis that you'll have
     * to wait to retrieve some value.
     */
    public abstract long getDefaultTimeout();

    /**
     * Indicates that it is a invalid state and all functions to get value
     * will return a runtime exception of {@link BrokenStateException}.
     * All broken states also will return true for {@link #isFuzzy()}.
     * This function guarantees that you cannot retrieve any value: this
     * is not only corrupted, it is also completely inaccessible. If the state
     * is only corrupted but it can guess some value, the state would be
     * {@link #isFuzzy() fuzzy}.
     */
    public abstract boolean isBroken() throws TimeoutException, InterruptedException;

    /**
     * Block until it becomes unblocked.
     */
    public abstract void waitUntilBeUnblocked() throws TimeoutException, InterruptedException;

    /**
     * Indicates that it state has a not accurate value. It can
     * be true or not. This state probably has the true value or at least
     * it do its best to have it. It can happens, e. g., because the value
     * was stored in a non safe place or because it is a calculated or
     * presumed value. All {@link #isBroken() broken} states is also
     * {@link #isFuzzy() fuzzy}.
     */
    public abstract boolean isFuzzy() throws TimeoutException, InterruptedException;

    /**
     * When this State is frozen, i. e., it is immutable forever.
     */
    public abstract boolean isFrozen() throws TimeoutException, InterruptedException;

    /**
     * If somebody is <i>using</i> this state now. When the {@link State} is in
     * this <i>state</i> means the value will not change until it becomes
     * unblocked again.
     */
    public abstract boolean isBlocked();

    /**
     * It is a really weird situation, but it can happens if you create
     * a state and never set any value. When the State is in this state
     * not means that it is {@link #isBroken() broken} or
     * {@link #isFuzzy() fuzzy}.
     */
    public abstract boolean isBeforeTheFirstValue() throws TimeoutException, InterruptedException;

    /**
     * Accesses its {@link Universe}. It <b>never</b> returns <code>null</code>,
     * even the universe is {@link br.eti.fml.wonderfulstates.universe.Any}.
     */
    public abstract U getUniverse();

    /**
     * Get the current value. The value returned is immutable.
     */
    public abstract T getValue() throws BrokenStateException, TimeoutException,
                        InterruptedException;

    /**
     * Get the current value and the timestamp when it was defined.
     */
    public abstract Pair<T, Long> getValueInTheTime() throws BrokenStateException,
            TimeoutException, CantDetermineTimeException,
            InterruptedException;

    /**
     * Get the timestamp of the last change.
     */
    public abstract Long getLastChangeTimestamp() throws CantDetermineTimeException;

    /**
     * Unique ID number to indentify this state in all world.
     */
    public abstract String getUID();
}
