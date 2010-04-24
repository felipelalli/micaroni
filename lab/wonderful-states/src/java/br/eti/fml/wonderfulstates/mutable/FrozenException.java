package br.eti.fml.wonderfulstates.mutable;

import br.eti.fml.wonderfulstates.universe.InvalidChangeException;

/**
 * It happens when you try to change some {@link State#isFrozen frozen}
 * {@link State state}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class FrozenException extends InvalidChangeException {

}
