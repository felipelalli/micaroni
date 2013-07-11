package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesX implements Locus {
    EYE_GREENING(0, false); // 1.300 average

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
