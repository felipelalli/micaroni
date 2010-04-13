package br.eti.fml.wonderfulstates;

/**
 * This {@link Universe} accepts all values.
 * Always returns true in a valid object parameter (not null).
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Any extends Universe<Object> {

    /**
     * @return false only if newValue is null
     */
    public boolean checksIfItIsAValidChange(Object previousValue, Object newValue) {
        return newValue != null;
    }

    /**
     * @return false only if value is null
     */
    public boolean checksIfItIsAValidFinalValue(Object value) {
        return value != null;
    }
}
