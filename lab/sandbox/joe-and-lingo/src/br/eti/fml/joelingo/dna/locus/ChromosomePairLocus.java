package br.eti.fml.joelingo.dna.locus;

/**
 * 16 pairs of chromosomes, 32 chromosomes
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum ChromosomePairLocus implements Locus {
    A(0, false),
    B(1, false),
    C(2, false),
    D(3, false),
    E(4, false),
    F(5, false),
    G(6, false),
    H(7, false),
    I(8, false),
    J(9, false),
    K(10, false),
    L(11, false),
    M(12, false),
    N(13, false),
    O(14, false);

    private final int position;
    private final boolean deprecated;

    private ChromosomePairLocus(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }

    @Override
    public int getPosition() {
        return position;
    }

    @Override
    public boolean isDeprecated() {
        return deprecated;
    }
}
