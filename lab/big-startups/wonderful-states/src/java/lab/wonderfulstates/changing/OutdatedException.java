/*
 * Copyright (c) 2010.
 * Wonderful States
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0
 * Unported License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 171 Second Street, Suite 300,
 * San Francisco, California, 94105, USA.
 */

package br.eti.fml.wonderfulstates.changing;

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
