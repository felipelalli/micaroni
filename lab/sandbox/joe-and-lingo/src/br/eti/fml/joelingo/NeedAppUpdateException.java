package br.eti.fml.joelingo;

/**
 * If the code is trying to access some invalid locus, e.g., an app update is necessary.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class NeedAppUpdateException extends Exception {
    public NeedAppUpdateException() {
    }

    public NeedAppUpdateException(String message) {
        super(message);
    }

    public NeedAppUpdateException(String message, Throwable cause) {
        super(message, cause);
    }

    public NeedAppUpdateException(Throwable cause) {
        super(cause);
    }

}
