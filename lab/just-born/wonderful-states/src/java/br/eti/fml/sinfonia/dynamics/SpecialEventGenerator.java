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
