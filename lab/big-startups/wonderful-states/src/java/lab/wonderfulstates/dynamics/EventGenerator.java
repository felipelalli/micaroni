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

package br.eti.fml.wonderfulstates.dynamics;

import br.eti.fml.wonderfulstates.conducting.SecurityGuardOfStates;
import br.eti.fml.wonderfulstates.changing.Event;

/**
 * It can generate {@link br.eti.fml.wonderfulstates.mutable.Event}s.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class EventGenerator {
    /**
     * Receives the information that something happened.
     */
    public abstract void itHappened(Event event);

    /**
     * Process the pending events and finish.
     */
    public abstract void executePendingTasks(
            SecurityGuardOfStates groupOfStatesToManipulate)
                throws InterruptedException;
}
