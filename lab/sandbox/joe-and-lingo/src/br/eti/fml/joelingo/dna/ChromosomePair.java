package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.dna.locus.Locus;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomePair<L extends Locus> {
    public Chromosome<L> left;
    public Chromosome<L> right;

    public GenePair getPair(L locus) {
        return new GenePair(left.getGene(locus), right.getGene(locus));
    }
}
