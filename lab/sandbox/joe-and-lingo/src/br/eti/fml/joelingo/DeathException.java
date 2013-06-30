package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class DeathException extends Exception {
    private final DeathReason deathReason;

    public DeathException(DeathReason deathReason) {
        this.deathReason = deathReason;
    }

    @Override
    public String toString() {
        return "DeathException{" +
                "deathReason=" + deathReason +
                "} " + super.toString();
    }
}
