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

package br.eti.fml.basic;

import java.util.ArrayList;
import java.util.List;

/**
 * A factory can produce something.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Factory<T> {
    public abstract T produce();

    public List<T> produce(int n) {
        List<T> list = new ArrayList<T>();

        for (int i = 0; i < n; i++) {
            list.add(this.produce());
        }

        return list;
    }
}
