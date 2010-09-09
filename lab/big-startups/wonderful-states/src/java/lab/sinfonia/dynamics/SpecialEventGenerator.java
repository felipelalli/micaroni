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

import br.eti.fml.wonderfulstates.conducting.SecurityGuardOfStates;
import br.eti.fml.wonderfulstates.dynamics.EventGenerator;
import br.eti.fml.wonderfulstates.changing.Event;

/**
 * Free implementation of a {@link EventGenerator}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class SpecialEventGenerator extends EventGenerator {

    @Override
    /**
     * Do nothing by default, but the children of this class can
     * use this information to something.
     */
    public void itHappened(Event event) {
        
    }

    public abstract void executePendingTasks(SecurityGuardOfStates
            groupOfStatesToManipulate) throws InterruptedException;

}
