package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesL implements LocusGenes {
    BRISTLE_RED_B1  (0, false), // red 01001101 e.g. is 30% red
    BRISTLE_RED_B2  (1, false),
    BRISTLE_RED_B3  (2, false),
    BRISTLE_RED_B4  (3, false),
    BRISTLE_RED_B5  (4, false),
    BRISTLE_RED_B6  (5, false),
    BRISTLE_RED_B7  (6, false),
    BRISTLE_RED_B8  (7, false),
    HANDS_SIZE_P3   (8, false),
    FINS_P2         (9, false),

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesL(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }

    public int getPosition() {
        return position;
    }

    public boolean isDeprecated() {
        return deprecated;
    }

    public ChromosomePairLocus getChromosomePairLocus() {
        return ChromosomePairLocus.L;
    }
}
