package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class GenePair {
    private boolean left;
    private boolean right;

    public GenePair(boolean left, boolean right) {
        this.left = left;
        this.right = right;
    }

    public boolean isDominant() {
        return left || right;
    }

    public boolean isRecessive() {
        return !left && !right;
    }

    public boolean getLeft() {
        return left;
    }

    public boolean getRight() {
        return right;
    }
}
