package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

import java.math.BigDecimal;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Feature extends JsonCapable<Feature> {
    private BigDecimal value;

    public BigDecimal getValue() {
        return value;
    }

    public void setValue(BigDecimal value) {
        this.value = value;
    }
}
