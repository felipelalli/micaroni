package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Genotype extends JsonCapable<Genotype> {
    private Long luckyNumber; // used to random seed

    // 16 pairs of chromosomes, 32 chromosomes

    private ChromosomePair<ChromosomeX, ChromosomeY> xy;
    private ChromosomePair<ChromosomeX, ChromosomeX> xx;

    private ChromosomePair<ChromosomeA1, ChromosomeA2> a;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> b;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> c;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> d;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> e;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> f;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> g;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> h;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> i;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> j;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> k;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> l;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> m;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> n;
    private ChromosomePair<ChromosomeUnknown, ChromosomeUnknown> o;

    public ChromosomePair<ChromosomeX, ChromosomeY> getXY() {
        assert getSex() == Sex.MALE;
        return xy;
    }

    public ChromosomePair<ChromosomeX, ChromosomeX> getXX() {
        assert getSex() == Sex.FEMALE;
        return xx;
    }

    public Sex getSex() {
        Sex sex;

        if (xy != null) {
            sex = Sex.MALE;
        } else {
            sex = Sex.FEMALE;
        }

        return sex;
    }

    public Long getLuckyNumber() {
        return luckyNumber;
    }
}
