package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesY implements Locus {
    UNIBROW_P1          (0, false), // y0 + b4b4 or x1x1 + b4b4
    DEAF_P1             (1, false), // e5e5 -> super hearing, y1 + e5e5 deaf, x3x3 + e5e5 deaf
    NO_BRISTLE_P1       (2, false), // y2 + j1j1 -> no bristle
    BONES_MORE_HARD     (3, false), // y3 -> harder
    GOOD_LIVER          (4, false), // y4 + f6f6 -> very good liver
    CHILLY_P1           (5, false), // y5 + o8o8 -> chilly
    ANGER_TREND_P1      (6, false), // y6 + A9a9 -> anger, Y6 + a9a9 -> zen
    TAIL_SIZE           (7, false), // y7 + c9c9 -> long, c9c9 -> normal, C9c9 -> small

    ;

    private final int position;
    private final boolean deprecated;

    private LocusGenesY(int position, boolean deprecated) {
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
