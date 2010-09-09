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
