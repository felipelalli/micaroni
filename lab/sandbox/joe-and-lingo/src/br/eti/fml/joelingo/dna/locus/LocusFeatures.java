package br.eti.fml.joelingo.dna.locus;

public enum LocusFeatures {
    EYE_GREENING(0, false);

    private final int position;
    private final boolean deprecated;

    private LocusFeatures(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
