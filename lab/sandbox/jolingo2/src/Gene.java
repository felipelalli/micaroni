/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Gene {
    enum Allele {
        DOMINANT,
        RECESSIVE
    }

    private Allele a;
    private Allele b;

    public Gene() {
        this.a = Math.random() < .5 ? Gene.Allele.DOMINANT : Gene.Allele.RECESSIVE;
        this.b = Math.random() < .5 ? Gene.Allele.DOMINANT : Gene.Allele.RECESSIVE;
    }

    public Gene(Allele a, Allele b) {
        this.a = a;
        this.b = b;
    }

    public Allele getA() {
        return a;
    }

    public Allele getB() {
        return b;
    }

    public boolean isDominant() {
        return this.a.equals(Gene.Allele.DOMINANT) || this.b.equals(Gene.Allele.DOMINANT); 
    }

    public boolean isRecessive() {
        return this.a.equals(Gene.Allele.RECESSIVE) && this.b.equals(Gene.Allele.RECESSIVE);
    }

    public String toString() {
        if ((this.a.equals(Gene.Allele.RECESSIVE) && this.b.equals(Gene.Allele.DOMINANT))
            || (this.a.equals(Gene.Allele.DOMINANT) && this.b.equals(Gene.Allele.RECESSIVE)))
        {
            return "Aa";
        } else if (this.isRecessive()) {
            return "aa";
        } else {
            return "AA";
        }
    }
}
