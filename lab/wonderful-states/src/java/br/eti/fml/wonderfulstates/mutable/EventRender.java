package br.eti.fml.wonderfulstates.mutable;

import  br.eti.fml.wonderfulstates.TimeoutException;

/**
 * It's a more "concrete" kind of {@link Event} that <b>renders</b>
 * the previous value into a new value. It can be bad if the
 * <code>T</code> type is too complex, big or too abstract.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface EventRender<T extends Object> extends Event {
    /**
     * Render this event based on a previous value.
     *
     * @TimeoutException If
     */
    T render(T previousValue) throws TimeoutException;
}
