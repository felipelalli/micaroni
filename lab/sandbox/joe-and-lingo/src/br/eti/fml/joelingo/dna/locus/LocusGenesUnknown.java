package br.eti.fml.joelingo.dna.locus;

public enum LocusGenesUnknown {
    UNKNOWN(0, false, "0.0"); // 1.300 average

    private final int position;
    private final boolean deprecated;
    private final String defaultValue; // used if this gene is absent in parent

    private LocusGenesUnknown(int position, boolean deprecated, String defaultValue) {
        this.position = position;
        this.deprecated = deprecated;
        this.defaultValue = defaultValue;
    }
}
