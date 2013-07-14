package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class GenePair {
    private byte left;
    private byte right;

    public GenePair(byte left, byte right) {
        this.left = (byte) (left == 0 ? 0 : 1);
        this.right = (byte) (right == 0 ? 0 : 1);
    }

    public boolean isDominant() {
        return left != 0 || right != 0;
    }
}
