package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

import java.math.BigDecimal;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Feature extends JsonCapable<Feature> {
    private BigDecimal value;

    public BigDecimal getValue() {
        return value.min(new BigDecimal(1.0)).max(new BigDecimal(0.0));
    }

    public void setValue(BigDecimal value) {
        this.value = value;
    }
}
