package br.eti.fml.joelingo.external;

import br.eti.fml.joelingo.Joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface JoelingoTable {
    void insert(Joelingo data);
    Joelingo get(String uuid);
}
