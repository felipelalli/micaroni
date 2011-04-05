package br.eti.fml.crazydb;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CorruptedData extends IOException {
    public CorruptedData() {
    }

    public CorruptedData(String message) {
        super(message);
    }

    public CorruptedData(String message, Throwable cause) {
        super(message, cause);
    }

    public CorruptedData(Throwable cause) {
        super(cause);
    }
}
