package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SpotToPutAccessory extends JsonCapable {
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
