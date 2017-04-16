package br.eti.fml.joelingo.env;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.timeagent.ModifierAgentOverTime;
import br.eti.fml.joelingo.data.genesis.Genesis;
import br.eti.fml.joelingo.dna.Genotype;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 *
 * RETHINK ON IT: MAYBE EACH JOELINGO MUST HAVE YOUR OWN ENV
 *
 * TODO -  This is the whole "world" - Make sub environments
 */
public class Environment extends JsonCapable<Environment> {
    private FeatureEnv[] featureEnvs = new FeatureEnv[LocusEnvironment.values().length];

    private static final Random random = new Random(Genesis.GENESIS_LUCKY_NUMBER);

    private long globalSecondCycle = 0; // seconds since begin

    public List<ModifierAgentOverTime> getInitialAgents(Genotype genotype) {
        // TODO: read it from jsons initial agent

        // TODO: will use something like "tendency to aging" gene to generate a specific agent

        return new ArrayList<ModifierAgentOverTime>(0);
    }

    public long getGlobalSecondCycle() {
        return globalSecondCycle;
    }
}
