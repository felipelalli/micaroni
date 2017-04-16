package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesX implements Locus {
    EYELASHES_SIZE      ( 0, false), // X0x0 -> big, x0x0 or x0y -> normal, X0y -> short
    UNIBROW_P1          ( 1, false), // y0 + b4b4 or x1x1 + b4b4
    MOUTH_FEMININITY    ( 2, false), // X2x2 -> female mouth+, x2x2 female mouth, x2y masc mouth, X2y female mouth-
    DEAF_P1             ( 3, false), // e5e5 -> super hearing, y1 + e5e5 deaf, x3x3 + e5e5 deaf
    BAD_BLOOD           ( 4, false), // x4x4, x4y -> bad blood (see also h7h7)
    SUPER_MAMA          ( 5, false), // x5x5 -> super mama
    TEAT_SIZE_P1        ( 6, false), // x6x6,x7x7 - 1,1 -> very big, 1,0 -> big, 0,1 -> small, 0,0 -> normal
    TEAT_SIZE_P2        ( 7, false),
    CHILLY_P1           ( 8, false), // X8? + O8o8 -> chilly
    ANGER_TREND_P1      ( 9, false), // X9x9 + a9a9 -> zen, x9x9 + a9a9 -> anger
    BOREDOM_TENDENCY_P1 (10, false), // X10x10 or X10y + h9h9

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesX(int position, boolean deprecated) {
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
