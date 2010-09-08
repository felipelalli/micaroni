package br.eti.fml.sinfonia.dynamics;

/**
 * Any condition can be true or false, depeding of the related states.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Condition {
    public abstract boolean isTrue();
    public abstract boolean isFalse();
}
