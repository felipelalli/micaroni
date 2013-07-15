package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesE implements Locus {
    EYE_SIZE_P2          (0, false),
    EYE_SIZE_P3          (1, false), // d0d0,e0e0,e1e1 -> very big eyes
    HAPPYNESS_TENDENCY_P2(2, false),
    NOSE_WIDE            (3, false), // e3e3 -> wide nose
    EAR_SIZE             (4, false), // e4e4 -> eared
    SUPER_HEARING        (5, false), // e5e5 -> super hearing, y1 + e5e5 deaf, x3x3 + e5e5 deaf
    LUNG_EFFICIENCY_P2   (6, false),
    LONG_TONGUED         (7, false), // e7e7 -> long tongued
    TRUNK_SIZE_P1        (8, false), // e8e8,f8f8,g8g8 -> 0,0,0 -> very short, 1,1,1 -> very long
    IMMUNE_SYSTEM_P1     (9, false), // e9e9,f9f9 -> 1,1 -> low, 0,1 or 0,0 -> normal, 1,0 -> high

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesE(int position, boolean deprecated) {
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
