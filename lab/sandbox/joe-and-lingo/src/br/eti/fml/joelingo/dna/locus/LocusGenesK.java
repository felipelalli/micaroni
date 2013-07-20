package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesK implements Locus {
    BRISTLE_GREEN_B1  (0, false), // green 01001101 e.g. is 30% green
    BRISTLE_GREEN_B2  (1, false),
    BRISTLE_GREEN_B3  (2, false),
    BRISTLE_GREEN_B4  (3, false),
    BRISTLE_GREEN_B5  (4, false),
    BRISTLE_GREEN_B6  (5, false),
    BRISTLE_GREEN_B7  (6, false),
    BRISTLE_GREEN_B8  (7, false),
    HANDS_SIZE_P2     (8, false),
    FINS_P1           (9, false), // k9k9,l9l9 -> has fins

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesK(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }

    public int getPosition() {
        return position;
    }

    public boolean isDeprecated() {
        return deprecated;
    }
}
