package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesC implements LocusGenes {
    EYE_GLOW_P3         (0, false),
    EYE_COLOR_P2        (1, false),
    GLOW_INTENSITY_P3   (2, false),
    NO_EYEBROW_P2       (3, false),
    TENDENCY_TO_AGE_P3  (4, false),
    FEAR_TENDENCY_P1    (5, false), // c5c5,d4d4 - 1,1 -> fearful, 0,1 -> fearless, 1,0 or 0,0 -> normal
    HEART_EFFICIENCY_P2 (6, false),
    TONGUE_EFFICIENCY_P1(7, false), // c7c7,d7d7 - 1,1 -> mute, 1,0 -> good, 0,1 -> bad, 0,0 -> normal
    ARMS_SIZE_P3        (8, false),
    TAIL_SIZE           (9, false), // y7 + c9c9 -> long, c9c9 -> normal, C9c9 -> small

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesC(int position, boolean deprecated) {
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
        return ChromosomePairLocus.C;
    }
}
