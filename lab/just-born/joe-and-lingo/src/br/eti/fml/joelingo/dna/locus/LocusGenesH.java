package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesH implements LocusGenes {
    HAIR_VOLUME_P2         (0, false),
    FAT_HEAD               (1, false), // h1h1 -> fat head
    BIG_FOREHEAD           (2, false), // h2h2 -> big forehead
    TEETH_SIZE_P1          (3, false), // h3h3,i0i0 - 1,1 -> giant, 1,0 -> big, 0,1 -> small, 0,0 -> normal
    POINTED_TEETH          (4, false), // h4h4 -> pointed teeth
    NO_TEETH_P1            (5, false), // h5h5,i1i1 -> no teeth
    INTESTINE_EFFICIENCY_P2(6, false),
    GOOD_BLOOD             (7, false), // h7h7 -> good blood, it makes x4 no value
    FEET_SIZE_P2           (8, false),
    BOREDOM_TENDENCY_P2    (9, false),

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesH(int position, boolean deprecated) {
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
        return ChromosomePairLocus.H;
    }
}
