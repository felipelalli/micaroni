package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesD implements Locus {
    EYE_SIZE_P1          (0, false), // d0d0,e0e0 - 1,1 -> big, 0,1 -> small, 0,0 ou 1,0 -> normal
    TENDENCY_TO_AGE_P1   (1, false), // d1d1,d2d2,c4c4 - 1,1,1 -> very fast, 0,1,1 or 1,1,0 or 1,0,1 -> fast, 1,0,0 or 0,1,0 or 0,0,1 -> slow, 0,0,0 -> normal
    TENDENCY_TO_AGE_P2   (2, false),
    HAPPYNESS_TENDENCY_P1(3, false), // d3d3,e2e2 - 1,1 -> very happy, 0,0 -> normal, 0,1 -> normal+, 1,0 -> unhappy
    FEAR_TENDENCY_P2     (4, false),
    NOSE_SIZE            (5, false), // d5d5 -> big nose
    LUNG_EFFICIENCY_P1   (6, false), // d6d6,e6e6 - 1,1 -> respiratory disease, 1,0 -> good, 0,1 -> weak, 0,0 -> normal
    TONGUE_EFFICIENCY_P2 (7, false),
    LEGS_SIZE_P3         (8, false),
    NO_TAIL_P1           (9, false), // d9d9,c9c9 -> no tail (override tail size)

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesD(int position, boolean deprecated) {
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
