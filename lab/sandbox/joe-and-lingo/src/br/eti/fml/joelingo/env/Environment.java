package br.eti.fml.joelingo.env;

import br.eti.fml.joelingo.DeathException;
import br.eti.fml.joelingo.DeathReason;
import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.data.genesis.Genesis;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.engine.BadCodeException;

import java.io.IOException;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Environment extends JsonCapable<Environment> {
    private FeatureEnv[] featureEnvs = new FeatureEnv[LocusEnvironment.values().length];

    private static final Random random = new Random(Genesis.GENESIS_LUCKY_NUMBER);

    private long globalSecondCycle = 0; // seconds since begin

    public ModifierAgentOverTime[] getInitialAgents(Genotype genotype) {
        // TODO: read it from jsons initial agent

        // TODO: will use something like "tendency to aging" to generate a specific agent

        return null;
    }

    public void liveUntilNow(Joelingo joelingo) throws DeathException {
        if (!joelingo.isBorn()) {
            throw new DeathException(DeathReason.NOT_BORN);
        } else {
            long joelingoTime = joelingo.getBirthdayDateSecondCycle()
                    + joelingo.getCurrentSecondCycle();

            for (long i = joelingoTime; i < globalSecondCycle; i++) {
                try {
                    joelingo.liveOneSecond(this);
                } catch (IOException | BadCodeException e) {
                    joelingo.die(this, DeathReason.SUDDEN_UNEXPLAINED_DEATH);
                    throw new DeathException(DeathReason.SUDDEN_UNEXPLAINED_DEATH);
                }
            }
        }
    }

    public long getGlobalSecondCycle() {
        return globalSecondCycle;
    }
}
