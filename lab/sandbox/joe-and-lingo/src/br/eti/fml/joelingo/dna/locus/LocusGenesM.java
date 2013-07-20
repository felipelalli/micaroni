package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesM implements Locus {
    BRISTLE_BLUE_B1  (0, false), // blue 01001101 e.g. is 30% blue
    BRISTLE_BLUE_B2  (1, false),
    BRISTLE_BLUE_B3  (2, false),
    BRISTLE_BLUE_B4  (3, false),
    BRISTLE_BLUE_B5  (4, false),
    BRISTLE_BLUE_B6  (5, false),
    BRISTLE_BLUE_B7  (6, false),
    BRISTLE_BLUE_B8  (7, false),
    POINTED_NAILS    (8, false), // m8m8 -> pointed nails
    THORNS           (9, false), // m9m9 -> has thorns

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesM(int position, boolean deprecated) {
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
