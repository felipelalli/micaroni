package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesN implements Locus {
    BRISTLE_SIZE_P2      (0, false),
    GROWTH_TREND_P1      (1, false), // n1n1,o0o0 - 1,1 -> dwarfism, 1,0 -> grown fast, 0,1 -> grown slow, 0,0 -> normal
    FATTEN_TENDENCY_P1   (2, false), // n2n2,o1o1 - 1,1 -> lose fast, 1,0 -> fatten fast, 0,1 or 0,0 -> normal
    STRONG_TENDENCY_P1   (3, false), // n3n3,o3o3,a6a6 - 0,0,0 -> level 0, 0,0,1 -> level 1, 0,1,0 -> level 2 etc.
    BONES_HARDNESS_P1    (4, false), // n4n4,o4o4 -> 1,1 -> osteoporosis, 1,0 -> very hard, 0,1 -> weak, 0,0 -> normal
    BRAIN_P2             (5, false),
    STOMACH_EFFICIENCY_P1(6, false), // n6n6,o6o6 -> 1,1 super stomach, 0,1 -> bad, 1,0 -> good, 0,0 -> normal
    SUPER_SPLEEN         (7, false), // n7n7 -> super spleen
    BIG_NAILS            (8, false), // n8n8 -> big nails
    VERY_HUNGRY          (9, false), // n9n9 -> very hungry, n9n9,o9o9 -> starving

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesN(int position, boolean deprecated) {
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
