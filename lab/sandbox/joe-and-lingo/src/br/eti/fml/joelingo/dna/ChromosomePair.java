package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.dna.locus.Locus;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomePair<C1 extends Chromosome, C2 extends Chromosome> {
    public C1 left;
    public C2 right;

    @SuppressWarnings("unchecked")
    public GenePair getPair(Locus locus) {
        Gene g1 = left.getGene(locus);
        Gene g2 = right.getGene(locus);

        GenePair result;

        if (g1 == null || g2 == null) {
            result = new UnknownGenePair();
        } else {
            result = new GenePair(g1, g2);
        }

        return result;
    }
}
