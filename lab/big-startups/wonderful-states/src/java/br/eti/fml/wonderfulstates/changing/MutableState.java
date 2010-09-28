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
