package br.eti.fml.wonderfulstates;

/**
 * Event represents a {@link State} delta (its changing).
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface Event<T extends Object> {
    T processes(T previousValue);
}
