package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.Locus;

import java.util.BitSet;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Chromosome<L extends Locus> extends JsonCapable<Chromosome<L>> {
    private BitSet genes = new BitSet();

    BitSet getGenes() {
        return genes;
    }

    void setGene(int position, boolean gene) {
        genes.set(position, gene);
    }

    public void setGene(L locus, byte gene) {
        genes.set(locus.getPosition(), gene);
    }

    public boolean getGene(L locus) {
        return genes.get(locus.getPosition());
    }
}
