package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomePair<C1 extends Chromosome, C2 extends Chromosome> {
    public C1 left;
    public C2 right;

    public GenePair getPair(int position) {
        Gene g1 = left.getGene(position);
        Gene g2 = right.getGene(position);

        GenePair result;

        if (g1 == null || g2 == null) {
            result = new UnknownGenePair();
        } else {
            result = new GenePair(g1, g2);
        }

        return result;
    }
}
