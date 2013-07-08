package br.eti.fml.joelingo.agent;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.engine.LifeEngine;
import sisc.data.ImmutableString;
import sisc.interpreter.SchemeException;

import java.io.IOException;
import java.util.List;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public final class ModifierAgentOverTime extends JsonCapable<ModifierAgentOverTime> {
    private AgentType agentType;

    private boolean attached = false;
    private Long initialCycle;
    private Long lastCycle;

    /**
     * FeatureLocus position vs Changes
     */
    private transient Map<Integer, List<ModificationOverFeature>> featureChanges; // TODO: think in how this will be persisted or mounted
    //private transient Map<Integer, List<ModificationOverFeature>> accessoriesChanges; // TODO: THINK ON IT

    /**
     * Immutable initial params.
     */
    private Map<String, String> initialParams;

    public Map<Integer, List<ModificationOverFeature>> getFeatureChanges() {
        return featureChanges;
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
