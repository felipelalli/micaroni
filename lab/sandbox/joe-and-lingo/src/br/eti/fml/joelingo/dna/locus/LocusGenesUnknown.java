package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesUnknown {
    UNKNOWN(0, false); // 1.300 average

    private final int position;
    private final boolean deprecated;

    private LocusGenesUnknown(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
