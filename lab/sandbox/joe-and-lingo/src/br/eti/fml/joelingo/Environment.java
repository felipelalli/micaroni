package br.eti.fml.joelingo;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Environment {
    // private double temperatureInCelsius = 23; TODO: think about it, modifiers of env

    private long globalSecondCycle = 0; // seconds since begin

    public ModifierAgentOverTime[] getInitialAgents(Genotype genotype) {
        // TODO: read it from jsons initial agents

        return null;
    }

    public void liveUntilNow(Joelingo joelingo) throws Death {
        if (!joelingo.isBorn()) {
            throw new Death(DeathReason.NOT_BORN);
        } else {
            long joelingoTime = joelingo.getBirthdayDateSecondCycle()
                    + joelingo.getCurrentSecondCycle();

            for (long i = joelingoTime; i < globalSecondCycle; i++) {
                try {
                    joelingo.liveOneSecond();
                } catch (IOException | BadCodeException e) {
                    joelingo.die(this, DeathReason.SUDDEN_UNEXPLAINED_DEATH);
                    throw new Death(DeathReason.SUDDEN_UNEXPLAINED_DEATH);
                }
            }
        }
    }

    public long getGlobalSecondCycle() {
        return globalSecondCycle;
    }
}
