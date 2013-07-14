package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.dna.locus.LocusGenesX;
import br.eti.fml.joelingo.dna.locus.LocusGenesY;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SexualChromosomePair {
    public Chromosome<LocusGenesX> left;

    public Chromosome<LocusGenesX> rightX;
    public Chromosome<LocusGenesY> rightY;

    public GenePair getPairXX(LocusGenesX locus) {
        return new GenePair(left.getGene(locus), rightX.getGene(locus));
    }

    public GenePair getPairXY(LocusGenesX locus) {
        return new GenePair(left.getGene(locus), (byte) 0);
    }

    public GenePair getPairXY(LocusGenesY locus) {
        return new GenePair((byte) 0, rightY.getGene(locus));
    }
}
