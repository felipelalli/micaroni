package br.eti.fml.wonderfulstates.universe;

import br.eti.fml.wonderfulstates.*;

/**
 * It happens when a {@link MutableState} try to do some
 * inconsistent change according to some {@link Universe}.
 * When it happens you need to make another choice.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 * @see Universe
 * @see State
 */
public class InvalidChangeException extends InvalidStateException {

}
