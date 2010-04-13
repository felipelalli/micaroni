package br.eti.fml.wonderfulstates;

/**
 * <p>
 * A mutable state represents a {@link State} that
 * can be changed by an {@link Event}.
 * </p>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface MutableState<T extends Object, U extends Universe<T>>
        extends State<T, U>
{
    /**
     * Try to apply the {@link Event}.
     * 
     * @throws OutdateException if the previousValue is not equals
     *                          {@link #getValue the current value}.
     */
    void apply(T previousValue, Event<T> event)
            throws InvalidInitialValueException, InvalidFinalValueException,
                   InvalidChangingException, FrozenException, OutdatedException,
                   BlockedStateException;

    /**
     * <b>Dangerous!</b> It will ignore the {@link #getUniverse() universe}, but
     * it can be faster depending on the implementation. Notice that this need
     * to be avoided. Use only for a necessary optimization and in cases where
     * the {@link Universe} is flexible enough.
     *
     * @return <code>true</code> if success.
     *          It can returns <code>false</code> if it is blocked.
     */
    boolean forceApply(Event<T> event);
}
