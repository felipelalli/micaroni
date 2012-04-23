package br.eti.fml.android.sigame.util;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public interface DefaultCallback<T> {
    void success(T result);
    void error(Exception e);
}
