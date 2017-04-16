package br.eti.fml.joelingo.dna.locus;

/**
 * 16 pairs of chromosomes, 32 chromosomes
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum ChromosomePairLocus implements Locus {
    A(0, false, LocusGenesA.class),
    B(1, false, LocusGenesB.class),
    C(2, false, LocusGenesC.class),
    D(3, false, LocusGenesD.class),
    E(4, false, LocusGenesE.class),
    F(5, false, LocusGenesF.class),
    G(6, false, LocusGenesG.class),
    H(7, false, LocusGenesH.class),
    I(8, false, LocusGenesI.class),
    J(9, false, LocusGenesJ.class),
    K(10, false, LocusGenesK.class),
    L(11, false, LocusGenesL.class),
    M(12, false, LocusGenesM.class),
    N(13, false, LocusGenesN.class),
    O(14, false, LocusGenesO.class);

    private final int position;
    private final boolean deprecated;
    private final Class locusGenesClass;

    private <L extends LocusGenes> ChromosomePairLocus(int position, boolean deprecated, Class<L> locusGenesClass) {
        this.position = position;
        this.deprecated = deprecated;
        this.locusGenesClass = locusGenesClass;
    }

    @Override
    public int getPosition() {
        return position;
    }

    @Override
    public boolean isDeprecated() {
        return deprecated;
    }

    @SuppressWarnings("unchecked")
    public <L extends LocusGenes> Class<L> getLocusGenesClass() {
        return (Class<L>) locusGenesClass;
    }
}
