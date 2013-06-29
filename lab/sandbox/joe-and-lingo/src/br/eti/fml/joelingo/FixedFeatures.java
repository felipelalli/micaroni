package br.eti.fml.joelingo;

public enum FixedFeatures {
    EYE_GREENING(0, false);

    private final int position;
    private final boolean deprecated;

    private FixedFeatures(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
