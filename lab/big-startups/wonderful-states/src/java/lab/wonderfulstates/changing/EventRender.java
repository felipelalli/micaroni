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

import  br.eti.fml.wonderfulstates.TimeoutException;

/**
 * It's a more "concrete" kind of {@link Event} that <b>renders</b>
 * the previous value into a new value. It can be bad if the
 * <code>T</code> type is too complex, big or too abstract.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class EventRender<T extends Object> extends Event {
    /**
     * Render this event based on a previous value.
     *
     * @throws TimeoutException If it takes too long to render.
     */
    public abstract T render(T previousValue) throws TimeoutException;
}
