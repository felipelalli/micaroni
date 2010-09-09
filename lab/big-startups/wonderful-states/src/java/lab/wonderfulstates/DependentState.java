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

package br.eti.fml.wonderfulstates;

import br.eti.fml.wonderfulstates.universe.Universe;
import java.util.ArrayList;
import java.util.List;

/**
 * It's a {@link State} which its value <b>depends</b>
 * of the value of another states. It can have (but is opcional)
 * cache.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class DependentState<T extends Object, U extends Universe<T>> extends State<T, U> {
    private List<State> states;

    public DependentState() {
        this.states = new ArrayList<State>();
    }

    public void addState(State state) {
        this.states.add(state);
    }

    protected List<State> getStates() {
        return this.states;
    }
}
