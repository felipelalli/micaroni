package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesG implements LocusGenes {
    HAIR_VOLUME_P1         (0, false), // g0g0,h0h0 - 1,1 -> no hair, 0,1 -> few, 1,0 -> much, 0,0 -> normal
    GENITALIA_SIZE_P2      (1, false),
    NO_GENITALIA_P1        (2, false), // g2g2,g3g3 -> no genitalia
    NO_GENITALIA_P2        (3, false),
    GENITALIA_EFFICIENCY_P2(4, false),
    CONE_HEAD              (5, false), // g5g5 -> cone head
    INTESTINE_EFFICIENCY_P1(6, false), // g6g6,h6h6 -> 1,1 -> intestine disease, 1,0 -> very good, 0,1 -> bad, 0,0 -> normal
    BLADDER_CAPACITY_P1    (7, false), // g7g7,f7f7 -> 1,1 -> ultra, 1,0 -> very, 0,1 -> few, 0,0 -> normal
    TRUNK_SIZE_P3          (8, false),
    FEET_SIZE_P1           (9, false), // g9g9,h8h8,i8i8 -> 0,0,0 -> very short, 1,1,1 -> very long

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesG(int position, boolean deprecated) {
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
        return ChromosomePairLocus.G;
    }
}
