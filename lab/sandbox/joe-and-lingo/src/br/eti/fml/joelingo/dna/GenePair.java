package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class GenePair {
    private Gene left;
    private Gene right;

    public GenePair(Gene left, Gene right) {
        this.left = left;
        this.right = right;
    }

    public boolean isDominant() {
        return left.on || right.on;
    }
}
