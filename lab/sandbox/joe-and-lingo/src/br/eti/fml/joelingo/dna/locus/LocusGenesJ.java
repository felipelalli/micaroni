package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesJ implements Locus {
    SKIN_SMOOTHNESS_P2   (0, false),
    NO_BRISTLE_P2        (1, false),
    BRISTLE_SIZE_P1      (2, false), // j2j2,n0n0 - 1,1 -> giant, 1,0 -> big, 0,1 -> small, 0,0 -> normal
    BRISTLE_SMOOTHNESS_P2(3, false),
    SKIN_TON_P2          (4, false),
    SKIN_ALBINO_P1       (5, false), // j5j5,j6j6 -> albino
    SKIN_ALBINO_P2       (6, false),
    SUPER_PANCREAS       (7, false), // j7j7 -> super pancreas
    HANDS_SIZE_P1        (8, false), // j8j8,k8k8,l8l8 -> 0,0,0 -> very short, 1,1,1 -> very long

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesJ(int position, boolean deprecated) {
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
