package br.eti.fml.joelingo.external;

import br.eti.fml.joelingo.engine.Command;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface HistoryTable {
    void insert(Command command);
}
