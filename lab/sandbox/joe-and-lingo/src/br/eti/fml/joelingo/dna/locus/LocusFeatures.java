package br.eti.fml.joelingo.dna.locus;

import java.math.BigDecimal;

public enum LocusFeatures {
    EYE_GREENING(0, false, new BigDecimal(0.0), new BigDecimal(1.0), new BigDecimal(0.0));

    private final int position;
    private final boolean deprecated;
    private final BigDecimal defaultValue; // used if this gene is absent

    private LocusFeatures(int position, boolean deprecated, BigDecimal minValue, BigDecimal maxValue, BigDecimal defaultValue) {
        this.position = position;
        this.deprecated = deprecated;
        this.defaultValue = defaultValue;
    }
}
