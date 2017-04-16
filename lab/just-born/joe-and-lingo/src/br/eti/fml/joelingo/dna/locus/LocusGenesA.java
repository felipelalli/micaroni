package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesA implements LocusGenes {
    EYE_GLOW_P1       (0, false), // a0a0,b0b0,c0c0 -> has glow
    CLEAR_EYE         (1, false), // a1a1 -> clear, A1a1 dark
    GLOW_INTENSITY_P1 (2, false), // a2a2,b2b2,c2c2 -> glow intensity
    BLINDNESS_P1      (3, false), // a3a3,a4a4 - 1,0 -> partial, 1,1 -> total, 0,1 or 0,0 -> normal
    BLINDNESS_P2      (4, false),
    EYELASHES_PRESENCE(5, false), // a5a5 -> no eyelashes
    STRONG_TENDENCY_P3(6, false),
    ARMS_SIZE_P1      (7, false), // a7a7,b7b7,c8c8 -> 0,0,0 -> very short, 1,1,1 -> very long
    LEGS_SIZE_P1      (8, false), // a8a8,b8b8,d8d8 -> 0,0,0 -> very short, 1,1,1 -> very long
    ANGER_TREND_P2    (9, false),

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesA(int position, boolean deprecated) {
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
        return ChromosomePairLocus.A;
    }
}
