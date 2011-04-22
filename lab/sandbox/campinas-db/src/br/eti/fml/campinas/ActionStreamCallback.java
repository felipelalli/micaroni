package br.eti.fml.campinas;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public interface ActionStreamCallback {
    public void finishedAction(boolean success, IOException exception);
}
