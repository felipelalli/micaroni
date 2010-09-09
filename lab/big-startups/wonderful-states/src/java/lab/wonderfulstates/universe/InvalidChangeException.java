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

package br.eti.fml.wonderfulstates.universe;

import br.eti.fml.wonderfulstates.*;

/**
 * It happens when a {@link br.eti.fml.wonderfulstates.mutable.MutableState}
 * try to do some inconsistent change according to some {@link Universe}.
 * When it happens you need to make another choice.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 * @see Universe
 * @see State
 */
public class InvalidChangeException extends InvalidStateException {

}
