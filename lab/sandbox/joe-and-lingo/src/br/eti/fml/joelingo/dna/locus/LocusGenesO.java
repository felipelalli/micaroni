package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesO implements Locus {
    GROWTH_TREND_P2      (0, false),
    FATTEN_TENDENCY_P2   (1, false),
    NO_EGG               (2, false), // o2o2 -> no egg, O2o2 -> egg
    STRONG_TENDENCY_P2   (3, false),
    BONES_HARDNESS_P2    (4, false),
    BRAIN_P3             (5, false),
    STOMACH_EFFICIENCY_P2(6, false),
    KIDNEY_EFFICIENCY_P2 (7, false),
    CHILLY_P2            (8, false),
    FEW_HUNGRY           (9, false), // o9o9 -> few hungry, n9n9,o9o9 -> starving

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesO(int position, boolean deprecated) {
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
