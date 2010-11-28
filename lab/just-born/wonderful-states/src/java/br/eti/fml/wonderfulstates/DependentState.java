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
