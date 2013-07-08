package br.eti.fml.joelingo;

import br.eti.fml.joelingo.agent.ModificationOverFeature;
import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.Feature;
import br.eti.fml.joelingo.dna.Phenotype;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * Used to describe a {@link Joelingo}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Description {
    private final Phenotype initialPhenotype;
    private final List<ModifierAgentOverTime> activeAgents;

    public Description(Phenotype initialPhenotype, List<ModifierAgentOverTime> activeAgents) {
        this.initialPhenotype = initialPhenotype;
        this.activeAgents = new ArrayList<>(activeAgents);
    }

    public Phenotype getPhenotype() throws NeedAppUpdateException {
        Phenotype modifiedPhenotype = initialPhenotype.clone();

        // TODO: think in a way to cache it, saving intermediate states

        for (ModifierAgentOverTime activeAgent : activeAgents) {
            Set<Integer> changes = activeAgent.getFeatureChanges().keySet();

            for (Integer position : changes) {
                List<ModificationOverFeature> modifications = activeAgent.getFeatureChanges().get(position);

                for (ModificationOverFeature modification : modifications) {
                    Feature newFeature = new Feature();
                    newFeature.setValue(modification.apply(modifiedPhenotype.getFeature(position).getValue()));
                    modifiedPhenotype.setFeature(position, newFeature);
                }
            }
        }

        return modifiedPhenotype;
    }
}
