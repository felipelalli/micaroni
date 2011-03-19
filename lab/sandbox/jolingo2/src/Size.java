/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Size {
    private Gene[] dna = new Gene[100];

    public Size() {
        for (int i = 0; i < dna.length; i++) {
            dna[i] = new Gene();
        }
    }

    public long getSize() {
        return this.sum();
    }

    private long sum() {
        int sum = 0;

        for (int i = 0; i < dna.length; i++) {
            if (dna[i].isDominant()) {
                //sum += (i+1);
                sum += (i * Math.random());
            }
        }

        return sum;
    }

    public String toString() {
        String result = this.getSize() + " ";

        for (Gene aDna : dna) {
            result += aDna.toString() + " ";
        }

        return result;
    }
}
