package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.Locus;

import java.util.BitSet;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Chromosome<L extends Locus> extends JsonCapable<Chromosome<L>> {
    private BitSet genes = new BitSet();
    private BitSet mutations = new BitSet();

    BitSet getGenes() {
        return genes;
    }

    void setGene(int position, boolean gene, boolean mutation) {
        genes.set(position, gene);
        mutations.set(position, mutation);
    }

    public void setGene(L locus, boolean gene, boolean mutation) {
        setGene(locus.getPosition(), gene, mutation);
    }

    public boolean getGene(L locus) {
        return genes.get(locus.getPosition());
    }

    public boolean isMutation(L locus) {
        return mutations.get(locus.getPosition());
    }
}
