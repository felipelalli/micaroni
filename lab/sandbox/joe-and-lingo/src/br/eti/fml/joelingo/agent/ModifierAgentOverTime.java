package br.eti.fml.joelingo.agent;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.engine.LifeEngine;
import sisc.interpreter.SchemeException;

import java.io.IOException;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public final class ModifierAgentOverTime extends JsonCapable<ModifierAgentOverTime> {
    private AgentType agentType;

    private Long initialCycle;
    private Long lastCycle;

    /**
     * Immutable initial params.
     */
    private Map<String, BigDecimal> initialParams;

    /**
     * FeatureLocus position vs Changes
     */
    private transient final Map<Integer, ModificationOverFeature> featureChanges = new HashMap<>();

    public Map<Integer, ModificationOverFeature> getFeatureChanges() {
        return featureChanges;
    }

    public void attach(Joelingo joelingo) {
        initialCycle = joelingo.getCurrentSecondCycle();
    }

    public void detach(Joelingo joelingo) {
        lastCycle = joelingo.getCurrentSecondCycle();
    }

    /**
     * This manipulates {@link #featureChanges}, using {@link #initialParams}.
     */
    public void executeCycle(Joelingo joelingo) throws IOException, BadCodeException {
        assert isActive(joelingo);

        try {
            LifeEngine.getDefaultLifeEngine().eval(agentType.getOnCycleCode());
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }
    }

    public boolean isActive(Joelingo joelingo) {
        return (initialCycle != null && joelingo.getCurrentSecondCycle() >= initialCycle)
                && (lastCycle == null || joelingo.getCurrentSecondCycle() < lastCycle);
    }

    public AgentType getAgentType() {
        return agentType;
    }

    public boolean isAccessory() {
        return this.getAgentType().isAccessory();
    }
}
