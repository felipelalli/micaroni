package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

import java.math.BigDecimal;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Feature extends JsonCapable<Feature> {
    private BigDecimal value;

    public Feature() {}

    public Feature(BigDecimal value) {
        this.value = value;
    }

    public double getDoubleValue() {
        return value.min(new BigDecimal(1.0)).max(new BigDecimal(0.0)).doubleValue();
    }

    public BigDecimal getValue() {
        return value.min(new BigDecimal(1.0)).max(new BigDecimal(0.0));
    }

    public Feature setValue(BigDecimal value) {
        this.value = value;
        return this;
    }

    public Feature setValue(double value) {
        this.value = new BigDecimal(String.valueOf(value));
        return this;
    }
}
