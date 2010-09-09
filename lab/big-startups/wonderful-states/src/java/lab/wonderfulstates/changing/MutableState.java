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

package br.eti.fml.wonderfulstates.changing;

import br.eti.fml.wonderfulstates.State;
import br.eti.fml.wonderfulstates.TimeoutException;
import br.eti.fml.wonderfulstates.universe.Universe;
import br.eti.fml.wonderfulstates.universe.InvalidInitialValueException;
import br.eti.fml.wonderfulstates.universe.InvalidFinalValueException;
import br.eti.fml.wonderfulstates.universe.InvalidChangeException;

/**
 * <p>
 * A mutable state represents a {@link State} that
 * can be changed by an {@link EventRender}.
 * </p>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class MutableState<T extends Object, U extends Universe<T>>
        extends State<T, U>
{
    /**
     * It calls {@link #apply(java.lang.Object,
     * br.eti.fml.wonderfulstates.mutable.EventRender, long)}
     * with {@link State#getDefaultTimeout() the default timeout}.
     */
    public void apply(T previousValue, Event event)
            throws InvalidInitialValueException, InvalidFinalValueException,
                   InvalidChangeException, FrozenException, OutdatedException,
                   TimeoutException, NotSupportedEventException
    {
        this.apply(previousValue, event, this.getDefaultTimeout());
    }

    /**
     * Try to apply the {@link EventRender} in this {@link State}. It can be
     * {@link #isBlocked() blocked} if somebody is <i>using</i> this
     * <code>State</code>. Remember the {@link Event#getRelatedState()}
     * must be exactly the same of {@link State#getUID()} or the
     * {@link NotSupportedEventException} will be thrown.
     *
     * @throws OutdateException if the previousValue is not equals
     *                          {@link #getValue the current value}.
     */
    public abstract void apply(T previousValue, Event event, long timeoutInMillis)
            throws InvalidInitialValueException, InvalidFinalValueException,
                   InvalidChangeException, FrozenException, OutdatedException,
                   TimeoutException, NotSupportedEventException;
}
