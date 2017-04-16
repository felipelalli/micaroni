package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.dna.locus.LocusGenes;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomePair<L extends LocusGenes> {
    private final Class<L> locusClass;
    public Chromosome<L> left;
    public Chromosome<L> right;

    public ChromosomePair(Class<L> locusClass) {
        this.locusClass = locusClass;
    }

    public GenePair getGenePair(L locus) {
        return new GenePair(left.getGene(locus), left.isMutation(locus), right.getGene(locus), right.isMutation(locus));
    }

    public L[] getPossibleLocus() {
        return this.locusClass.getEnumConstants();
    }
}
