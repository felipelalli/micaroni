package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum OneSecondLifeResultStatus {
    LIVED_ONE_SECOND(true),
    EXPIRED(false),
    TOO_EARLY(false);

    private final boolean success;

    private OneSecondLifeResultStatus(boolean success) {
        this.success = success;
    }

    public boolean isSuccess() {
        return success;
    }
}
