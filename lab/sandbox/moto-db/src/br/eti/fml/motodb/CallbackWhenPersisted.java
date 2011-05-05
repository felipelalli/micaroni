package br.eti.fml.motodb;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public interface CallbackWhenPersisted {
    public void itWasPersisted(boolean success, IOException exception);
}
