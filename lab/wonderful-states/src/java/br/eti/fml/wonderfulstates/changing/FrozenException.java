package br.eti.fml.wonderfulstates.changing;

import br.eti.fml.wonderfulstates.universe.InvalidChangeException;

/**
 * It happens when you try to change some
 * {@link br.eti.fml.wonderfulstates.State#isFrozen frozen}
 * {@link br.eti.fml.wonderfulstates.State state}.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class FrozenException extends InvalidChangeException {

}
