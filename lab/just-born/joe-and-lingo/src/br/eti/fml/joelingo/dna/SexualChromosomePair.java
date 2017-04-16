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
        return new GenePair(left.getGene(locus), left.isMutation(locus), rightX.getGene(locus), rightX.isMutation(locus));
    }

    public GenePair getPairXY(LocusGenesX locus) {
        return new GenePair(left.getGene(locus), left.isMutation(locus), false, false);
    }

    public GenePair getPairXY(LocusGenesY locus) {
        return new GenePair(false, false, rightY.getGene(locus), rightY.isMutation(locus));
    }
}
