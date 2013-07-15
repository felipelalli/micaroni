package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesI implements Locus {
    TEETH_SIZE_P2       (0, false),
    NO_TEETH_P2         (1, false),
    SUPER_TEETH_P1      (2, false), // i2i2,i3i3 -> super teeth
    SUPER_TEETH_P2      (3, false),
    SMOOTHNESS_P1       (4, false), // i4i4,j0j0 - 1,1 -> very smooth skin,    1,0 -> smooth, 0,1 -> hard, 0,0 -> normal
                                  // i4i4,j3j3 - 1,1 -> very smooth bristle, 1,0 -> smooth, 0,1 -> hard, 0,0 -> normal
    SKIN_TON_P1         (5, false), // i5i5,j4j4 - 1,1 -> black, 0,1 -> dark, 1,0 -> very light, 0,0 -> white
    BRAIN_P1            (6, false), // i6i6,n5n5,o5o5 - 0,0,0 -> level 0, 1,1,1 -> level 7
    KIDNEY_EFFICIENCY_P1(7, false), // i7i7,o7o7 - 1,1 -> very good, 0,1 -> bad, 1,0 -> good, 0,0 -> normal
    FEET_SIZE_P3        (8, false),

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesI(int position, boolean deprecated) {
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
