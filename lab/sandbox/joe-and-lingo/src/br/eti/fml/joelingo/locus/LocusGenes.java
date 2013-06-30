package br.eti.fml.joelingo.locus;

public enum LocusGenes {
    EYE_GREENING(0, false);

    private final int position;
    private final boolean deprecated;

    private LocusGenes(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
