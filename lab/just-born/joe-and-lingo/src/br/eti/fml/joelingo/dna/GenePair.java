package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class GenePair {
    private boolean left;
    private boolean mutationLeft;
    private boolean right;
    private boolean mutationRight;

    public GenePair(boolean left, boolean mutationLeft, boolean right, boolean mutationRight) {
        this.left = left;
        this.mutationLeft = mutationLeft;
        this.right = right;
        this.mutationRight = mutationRight;
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

    public boolean isMutationLeft() {
        return mutationLeft;
    }

    public boolean isMutationRight() {
        return mutationRight;
    }

    public String toString() {
        return toString("a");
    }

    public String toString(String letter) {
        String l = letter.substring(0, 1);
        StringBuilder string = new StringBuilder();

        if (left) {
            string.append(l.toUpperCase());
        } else {
            string.append(l.toLowerCase());
        }

        if (isMutationLeft()) {
            string.append("*");
        }

        if (right) {
            string.append(l.toUpperCase());
        } else {
            string.append(l.toLowerCase());
        }

        if (isMutationRight()) {
            string.append("*");
        }

        return string.toString();
    }
}
