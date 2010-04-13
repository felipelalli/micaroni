package br.eti.fml.wonderfulstates;

/**
 * This {@link Universe} accepts all values.
 * Always returns true in a valid object parameter (not <code>null</code>).
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Any extends Universe<Object> {

    /**
     * @return false only if newValue is <code>null</code>
     */
    public boolean checksIfItIsAValidChanging(Object previousValue, Object newValue) {
        return newValue != null;
    }

    /**
     * @return false only if value is <code>null</code>
     */
    public boolean checksIfItIsAValidFinalValue(Object value) {
        return value != null;
    }
}
