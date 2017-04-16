package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class NotBornException extends DeathException {
    public NotBornException() {
        super(DeathReason.NOT_BORN);
    }

    public NotBornException(String message) {
        super(DeathReason.NOT_BORN, message);
    }
}
