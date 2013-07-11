package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesUnknown implements Locus {
    UNKNOWN(0, false);

    private final int position;
    private final boolean deprecated;

    private LocusGenesUnknown(int position, boolean deprecated) {
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
