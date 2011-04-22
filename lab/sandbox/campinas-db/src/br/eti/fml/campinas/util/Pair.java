package br.eti.fml.campinas.util;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class Pair<CAR, CDR> {
    public CAR car;
    public CDR cdr;

    public Pair(CAR car, CDR cdr) {
        this.car = car;
        this.cdr = cdr;
    }
}

