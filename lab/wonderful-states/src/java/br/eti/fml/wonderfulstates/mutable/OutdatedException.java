package br.eti.fml.wonderfulstates.mutable;

import br.eti.fml.wonderfulstates.*;

/**
 * <p>
 * It happens when somebody try to do some
 * inconsistent change, i. e., its doesn't know
 * the real <b>previous value</b> because someone else
 * did a change between you got the value and you
 * have tried to change.
 * </p>
 *
 * <p>
 * When it happens you just can try again or give up.
 * </p>
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class OutdatedException extends StateException {

}
