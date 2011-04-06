package br.eti.fml.crazydb;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CorruptedDataException extends Exception {
    public CorruptedDataException() {
    }

    public CorruptedDataException(String message) {
        super(message);
    }

    public CorruptedDataException(String message, Throwable cause) {
        super(message, cause);
    }

    public CorruptedDataException(Throwable cause) {
        super(cause);
    }

    public String toString() {
        return "Corrupted data!";
    }
}
