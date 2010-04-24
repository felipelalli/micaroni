package br.eti.fml.wonderfulstates.dynamics;

import br.eti.fml.wonderfulstates.changing.*;
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
