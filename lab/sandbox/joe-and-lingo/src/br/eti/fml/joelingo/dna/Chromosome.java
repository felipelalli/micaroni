package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.Locus;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Chromosome<L extends Locus> extends JsonCapable<Chromosome<L>> {
    private byte[] genes = new byte[Genotype.NUMBER_OF_GENES_PER_CHROMOSOME];

    /**
     * This is the last active gene position, defined on born. Genes
     * in position greater than specified here cannot be used to determine
     * how a {@link br.eti.fml.joelingo.agent.ModifierAgentOverTime} can behavior.
     * This is to avoid a unpredictable behavior after a core update. For example:
     * if the last active gene position is 20, genes in position > 20 cannot be
     * used as input entry in {@link br.eti.fml.joelingo.agent.ModifierAgentOverTime}.
     */
    public int lastActiveGenePosition;

    byte[] getGenes() {
        return genes;
    }

    void setGene(int position, byte gene) {
        genes[position] = gene;
    }

    public void setGene(L locus, byte gene) {
        genes[locus.getPosition()] = gene;
    }

    public byte getGene(L locus) {
        return genes[locus.getPosition()];
    }
}
