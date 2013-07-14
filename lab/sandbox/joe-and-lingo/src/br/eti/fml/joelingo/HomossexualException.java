package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class HomossexualException extends Exception {
    public HomossexualException() {
    }

    public HomossexualException(String message) {
        super(message);
    }

    public HomossexualException(String message, Throwable cause) {
        super(message, cause);
    }

    public HomossexualException(Throwable cause) {
        super(cause);
    }

    public HomossexualException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}
