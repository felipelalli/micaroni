package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesB implements Locus {
    EYE_GLOW_P2        (0, false),
    EYE_COLOR_P1       (1, false), // b1b1,c1c1 - 0,0 -> brown, 0,1 -> green, 1,0 -> blue, 1,1 -> red
    GLOW_INTENSITY_P2  (2, false),
    BIONIC_VISION      (3, false), // A3a3,A4a4,b3b3 - 1,1,0
    UNIBROW_P2         (4, false), // y0 + b4b4 or x1x1 + b4b4
    NO_EYEBROW_P1      (5, false), // b5b5,c3c3
    HEART_EFFICIENCY_P1(6, false), // b6b6,c6c6 - 1,1 -> cardiac disease, 1,0 -> good, 0,1 -> weak, 0,0 -> normal
    ARMS_SIZE_P2       (7, false),
    LEGS_SIZE_P2       (8, false),
    SUPER_MOTIVATED    (9, false), // b9b9 -> super motivated

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesB(int position, boolean deprecated) {
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
