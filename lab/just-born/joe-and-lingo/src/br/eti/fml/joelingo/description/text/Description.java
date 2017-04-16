package br.eti.fml.joelingo.description.text;

/**
* @author Felipe Micaroni Lalli (micaroni@gmail.com)
*/
interface Description {
    Goodness getGoodness();
    boolean isRelevant();
    String toString();
}
