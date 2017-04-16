package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SexException extends Exception {
    public SexException() {
    }

    public SexException(String message) {
        super(message);
    }

    public SexException(String message, Throwable cause) {
        super(message, cause);
    }

    public SexException(Throwable cause) {
        super(cause);
    }
}
