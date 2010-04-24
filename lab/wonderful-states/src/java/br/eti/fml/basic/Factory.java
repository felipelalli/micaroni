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
