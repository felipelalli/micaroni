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

/**
 * An {@link Event} represents a
 * {@link br.eti.fml.wonderfulstates.State} <i>delta</i> (its changing).
 * It's an <b>action</b>.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Event {
    /**
     * This value represents the type of the "action"
     * of this Event. <code>"+"</code> is a valid action type, for example.
     */
    public abstract String getActionType();

    /**
     * It's a value that represents the "action" of this Event.
     * An Event <code>"+1"</code> must return the same hash of
     * the Event <code>"+2-1"</code> for example,
     * both do exactly the same thing, but <code>"+1"</code>
     * and <code>"+2"</code> is different, even
     * both are sum operation. It can be <code>null</code> if is impossible
     * to determine.
     */
    public abstract String getActionHash();

    /**
     * Get the UID of the related {@link State}. It can be <code>null</code>
     * if is not related with any state.
     */
    public abstract String getRelatedState();

    /**
     * By default it returns the result of
     * <code>{@link #getActionHash()} + {@link #getRelatedState()}</code>
     */
    public String getGlobalHash() {
        return this.getActionHash() + this.getRelatedState();
    }
}
