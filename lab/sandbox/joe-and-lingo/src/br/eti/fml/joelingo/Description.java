package br.eti.fml.joelingo;

import br.eti.fml.joelingo.agent.ModificationOverFeature;
import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.Feature;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.env.Environment;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Used to describe a {@link Joelingo}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Description {
    private final Joelingo joelingo;
    private final Environment env;
    private final List<ModifierAgentOverTime> activeAgents = new ArrayList<>();

    public Description(Joelingo joelingo, Environment env) throws NotBornException {
        this.joelingo = joelingo.clone();
        this.env = env.clone();

        long age = this.joelingo.getAgeInSecondCycle(this.env);

        for (ModifierAgentOverTime agent : this.joelingo.getAgents()) {
            if (agent.isActive(age)) {
                activeAgents.add(agent);
            }
        }
    }

    public List<ModifierAgentOverTime> getActiveAgents() {
        return activeAgents;
    }

    /**
     * Get the initial phenotype modified by the modifier agents.
     */
    public Phenotype getFinalPhenotype() throws NotBornException, BadCodeException, IOException, NeedAppUpdateException {
        Phenotype modifiedPhenotype = joelingo.getInitialPhenotype().clone();

        // TODO: think in a way to cache it, saving intermediate states

        for (ModifierAgentOverTime activeAgent : joelingo.getAgents()) {
            Map<Integer,ModificationOverFeature> featureChanges = activeAgent.getFeatureChanges(joelingo, env);
            Set<Integer> changes = featureChanges.keySet();

            for (Integer change : changes) {
                LocusFeatures locus = LocusFeatures.valueByPosition(change);

                if (locus == null) {
                    throw new NeedAppUpdateException();
                } else {
                    ModificationOverFeature modification = featureChanges.get(locus.getPosition());

                    Feature newFeature = new Feature();
                    newFeature.setValue(modification.apply(modifiedPhenotype.getFeature(locus).getValue()));
                    modifiedPhenotype.setFeature(locus, newFeature);
                }
            }
        }

        return modifiedPhenotype;
    }

    public String toString() {
        String result;

        try {
            result = "activeAgents=" + getActiveAgents() + "; finalPhenotype: " + getFinalPhenotype();
        } catch (Exception e) {
            result = "impossible to describe: " + e;
        }

        return result;
    }
}
