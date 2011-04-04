package br.eti.fml.crazydb;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Pair<CAR, CDR> {
    public CAR car;
    public CDR cdr;

    public Pair(CAR car, CDR cdr) {
        this.car = car;
        this.cdr = cdr;
    }
}
