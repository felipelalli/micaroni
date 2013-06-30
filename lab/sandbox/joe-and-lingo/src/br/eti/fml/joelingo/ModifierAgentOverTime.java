package br.eti.fml.joelingo;

import sisc.data.ImmutableString;
import sisc.interpreter.SchemeException;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public final class ModifierAgentOverTime extends JsonCapable {
    private final AgentType agentType;

    private boolean attached = false;
    private Long initialCycle;
    private Long lastCycle;

    public ModifierAgentOverTime(AgentType agentType) {
        assert agentType != null;
        this.agentType = agentType;

        // TODO: initialize interpreter before execute
    }

    public AttachmentResult attachOn(Joelingo joelingo) throws BadCodeException, IOException {
        initialCycle = joelingo.getCurrentSecondCycle();
        AttachmentResult result;

        try {
            ImmutableString value
                    = (ImmutableString) LifeEngine.getDefaultLifeEngine()
                        .eval(agentType.getOnAttachCode());

            result = AttachmentResult.valueOf(value.asString());
        } catch (SchemeException | ClassCastException e) {
            throw new BadCodeException(e);
        }

        attached = true;
        return result;
    }

    /**
     * Try to remove this agent, but the agent code will decide if it kill itself
     * or not. If not, this modifier cannot be removed. See {@link #isAccessory()}.
     * Accessory generally can be removed.
     */
    public AttachmentResult removeFrom(Joelingo joelingo) throws IOException, BadCodeException {
        AttachmentResult result;

        try {
            ImmutableString value = (ImmutableString) LifeEngine
                    .getDefaultLifeEngine().eval(agentType.getOnRemoveCode());

            result = AttachmentResult.valueOf(value.asString());
        } catch (SchemeException | ClassCastException e) {
            throw new BadCodeException(e);
        }

        return result;
    }

    public void kill(Joelingo joelingo) {
        lastCycle = joelingo.getCurrentSecondCycle();
        attached = false;
    }

    public void executeCycle(Joelingo joelingo) throws IOException, BadCodeException {
        assert isActive(joelingo);

        try {
            LifeEngine.getDefaultLifeEngine().eval(agentType.getOnCycleCode());
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }
    }

    public boolean isActive(Joelingo joelingo) {
        return joelingo.getCurrentSecondCycle() >= initialCycle
                && joelingo.getCurrentSecondCycle() < lastCycle;
    }

    public AgentType getAgentType() {
        return agentType;
    }

    public boolean isAccessory() {
        return this.getAgentType().isAccessory();
    }
}
