package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.Locus;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Chromosome<L extends Locus> extends JsonCapable<Chromosome<L>> {
    private byte[] genes = new byte[Genotype.NUMBER_OF_GENES_PER_CHROMOSOME];

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
