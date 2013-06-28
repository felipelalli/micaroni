package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class BadCodeException extends Exception {
    public BadCodeException() {
    }

    public BadCodeException(String message) {
        super(message);
    }

    public BadCodeException(String message, Throwable cause) {
        super(message, cause);
    }

    public BadCodeException(Throwable cause) {
        super(cause);
    }

    public BadCodeException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}