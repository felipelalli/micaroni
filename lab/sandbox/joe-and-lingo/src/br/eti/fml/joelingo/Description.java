package br.eti.fml.joelingo;

import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.Phenotype;

import java.util.ArrayList;
import java.util.List;

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
}
