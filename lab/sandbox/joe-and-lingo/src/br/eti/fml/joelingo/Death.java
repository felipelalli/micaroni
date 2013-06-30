package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Death extends Exception {
    private final DeathReason deathReason;

    public Death(DeathReason deathReason) {
        this.deathReason = deathReason;
    }

    @Override
    public String toString() {
        return "Death{" +
                "deathReason=" + deathReason +
                "} " + super.toString();
    }
}
