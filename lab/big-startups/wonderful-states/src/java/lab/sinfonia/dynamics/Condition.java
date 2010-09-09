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
