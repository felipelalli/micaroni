package br.eti.fml.joelingo.timeagent;

import br.eti.fml.joelingo.JsonCapable;

import java.math.BigDecimal;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ModificationOverFeature extends JsonCapable<ModificationOverFeature> {
    private Operation operation;
    private BigDecimal value;

    public BigDecimal apply(BigDecimal valueSource) {
        BigDecimal result = null;

        switch (operation) {
            case ADD:
                result = valueSource.add(value);
                break;
            case SUB:
                result = valueSource.subtract(value);
                break;
            case MUL:
                result = valueSource.multiply(value);
                break;
            case DIV:
                result = valueSource.divide(value);
                break;
            case SET:
                result = new BigDecimal(value.toPlainString());
                break;
        }

        return result;
    }
}
