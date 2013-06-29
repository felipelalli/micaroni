package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SpotToPutAccessory {
    private String uuidModifier;

    public void take(String uuidModifier) {
        this.uuidModifier = uuidModifier;
    }

    public boolean isTaken() {
        return this.uuidModifier != null;
    }

    public void free() {
        this.uuidModifier = null;
    }
}
