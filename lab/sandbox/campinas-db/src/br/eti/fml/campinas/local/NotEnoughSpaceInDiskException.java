package br.eti.fml.campinas.local;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class NotEnoughSpaceInDiskException extends IOException {
    public NotEnoughSpaceInDiskException() {
    }

    public NotEnoughSpaceInDiskException(String message) {
        super(message);
    }

    public NotEnoughSpaceInDiskException(String message, Throwable cause) {
        super(message, cause);
    }

    public NotEnoughSpaceInDiskException(Throwable cause) {
        super(cause);
    }
}
