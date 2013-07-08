package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SpotToPutAccessory extends JsonCapable<SpotToPutAccessory> {
    private String uuidAgent;

    public void take(String uuidModifier) {
        this.uuidAgent = uuidModifier;
    }

    public boolean isTaken() {
        return this.uuidAgent != null;
    }

    public void free() {
        this.uuidAgent = null;
    }
}
