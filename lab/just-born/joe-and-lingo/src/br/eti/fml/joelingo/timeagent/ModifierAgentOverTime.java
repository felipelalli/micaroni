package br.eti.fml.joelingo.timeagent;

import br.eti.fml.joelingo.DeathException;
import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.NotBornException;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.engine.LifeEngine;
import br.eti.fml.joelingo.env.Environment;
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

    // TODO: think in how to cache intermediate states
    // TODO: this simulates whole life!
    public Map<Integer, ModificationOverFeature> getFeatureChanges(Joelingo joelingo, Environment environment)
            throws IOException, BadCodeException, NotBornException {

        Map<Integer, ModificationOverFeature> featureChanges = new HashMap<Integer, ModificationOverFeature>();

        long last = lastCycle != null ? lastCycle : joelingo.getAgeInSecondCycle();

        for (long i = initialCycle; i < last; i++) {
            try {
                // TODO: set SISC variables here
                // TODO: the code should manipulate featureChanges

                LifeEngine.getDefaultLifeEngine().eval(agentType.getOnCycleCode());
            } catch (SchemeException e) {
                throw new BadCodeException(e);
            }
        }

        return featureChanges;
    }

    public void attach(Joelingo joelingo, Environment environment) throws DeathException {
        joelingo.assertIsAlive();
        initialCycle = joelingo.getAgeInSecondCycle();
    }

    public void detach(Joelingo joelingo, Environment environment) throws DeathException {
        joelingo.assertIsAlive();
        lastCycle = joelingo.getAgeInSecondCycle();
    }

    public boolean isActive(long ageInSeconds) {
        return (initialCycle != null && ageInSeconds >= initialCycle)
                && (lastCycle == null || ageInSeconds < lastCycle);
    }

    public AgentType getAgentType() {
        return agentType;
    }

    public boolean isAccessory() {
        return this.getAgentType().isAccessory();
    }
}
