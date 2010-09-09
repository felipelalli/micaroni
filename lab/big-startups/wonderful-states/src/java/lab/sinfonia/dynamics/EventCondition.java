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

package br.eti.fml.sinfonia.dynamics;

import br.eti.fml.wonderfulstates.changing.Event;

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class EventCondition {
    public enum Level {
        ACTION_TYPE,
        ACTION_HASH,
        THE_SAME
    }

    private Event eventToConsider;
    private Level levelToConsider;

    public EventCondition(Event eventToConsider) {
        this(eventToConsider, Level.THE_SAME);
    }

    public EventCondition(Event eventToConsider, Level levelToConsider) {
        this.eventToConsider = eventToConsider;
        this.levelToConsider = levelToConsider;
    }

    public String getHash() {
        return
            levelToConsider.equals(Level.ACTION_HASH) ?
                    eventToConsider.getActionHash()
                    :
            levelToConsider.equals(Level.ACTION_TYPE) ?
                    eventToConsider.getActionType()
                    :
                    eventToConsider.getGlobalHash();
    }

    @Override
    public boolean equals(Object anotherEvent) {
        if (anotherEvent != null) {
            if (anotherEvent instanceof Event) {
                return this.equivalent((Event) anotherEvent);
            }
        }
        
        return false;
    }

    @Override
    public int hashCode() {
        return this.getHash().hashCode();
    }

    public boolean equivalent(Event anotherEvent) {
        return this.getHash().equals(new EventCondition(
                anotherEvent, this.levelToConsider).getHash());
    }
}
