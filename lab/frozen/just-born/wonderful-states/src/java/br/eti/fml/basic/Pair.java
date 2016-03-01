package br.eti.fml.basic;

/**
 * Just a pair.
 * 
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Pair<CAR, CDR> {
    public Pair(CAR car, CDR cdr) {
        this.car = car;
        this.cdr = cdr;
    }

    public CAR car;
    public CDR cdr;
}