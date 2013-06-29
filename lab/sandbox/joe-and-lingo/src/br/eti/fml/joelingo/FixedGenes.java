package br.eti.fml.joelingo;

public enum FixedGenes {
    EYE_GREENING(0, false);

    private final int position;
    private final boolean deprecated;

    private FixedGenes(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
