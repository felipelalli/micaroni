package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesF implements LocusGenes {
    STRAIGHT_HAIR          (0, false), // f0f0 -> straight
    HAIR_SPEED             (1, false), // f1f1 -> hair increase fast
    BIG_MOUTH(2, false), // f2f2 -> big mouth
    GENITALIA_SIZE_P1      (3, false), // f3f3,g1g1 - 1,1 -> monster, 1,0 -> big, 0,1 -> small, 0,0 -> normal
    GENITALIA_EFFICIENCY_P1(4, false), // f4f4,g4g4 - 1,1 -> very eff, 1,0 -> eff, 0,1 -> less eff, 0,0 -> normal
    HEADSTRONG             (5, false), // f5f5 -> big head
    BAD_LIVER              (6, false), // f6f6 -> bad liver, y4 + f6f6 -> very good liver
    BLADDER_CAPACITY_P2    (7, false),
    TRUNK_SIZE_P2          (8, false),
    IMMUNE_SYSTEM_P2       (9, false),

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesF(int position, boolean deprecated) {
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
        return ChromosomePairLocus.F;
    }
}
