package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.HomossexualException;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.ChromosomePairLocus;
import br.eti.fml.joelingo.dna.locus.Locus;
import br.eti.fml.joelingo.dna.locus.LocusGenes;
import br.eti.fml.joelingo.dna.locus.LocusGenesA;
import br.eti.fml.joelingo.dna.locus.LocusGenesB;
import br.eti.fml.joelingo.dna.locus.LocusGenesC;
import br.eti.fml.joelingo.dna.locus.LocusGenesD;
import br.eti.fml.joelingo.dna.locus.LocusGenesE;
import br.eti.fml.joelingo.dna.locus.LocusGenesF;
import br.eti.fml.joelingo.dna.locus.LocusGenesG;
import br.eti.fml.joelingo.dna.locus.LocusGenesH;
import br.eti.fml.joelingo.dna.locus.LocusGenesI;
import br.eti.fml.joelingo.dna.locus.LocusGenesJ;
import br.eti.fml.joelingo.dna.locus.LocusGenesK;
import br.eti.fml.joelingo.dna.locus.LocusGenesL;
import br.eti.fml.joelingo.dna.locus.LocusGenesM;
import br.eti.fml.joelingo.dna.locus.LocusGenesN;
import br.eti.fml.joelingo.dna.locus.LocusGenesO;
import br.eti.fml.joelingo.dna.locus.LocusGenesX;
import br.eti.fml.joelingo.dna.locus.LocusGenesY;

import java.security.SecureRandom;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
@SuppressWarnings("UnusedDeclaration")
public class Genotype extends JsonCapable<Genotype> {
    private static final int NUMBER_OF_CHROMOSOMES = 16;
    private static SecureRandom random = new SecureRandom();

    private SexualChromosomePair sexualChromosomePair = new SexualChromosomePair();
    private Map<Integer, ChromosomePair> chromosomes
            = new HashMap<Integer, ChromosomePair>(NUMBER_OF_CHROMOSOMES - 1); // one is the sexual chromosome

    public static Genotype createRandomGenotype(Sex sex) {
        Genotype genotype = new Genotype();

        if (sex == Sex.MALE) {
            genotype.sexualChromosomePair.left = new Chromosome<LocusGenesX>();
            genotype.sexualChromosomePair.rightY = new Chromosome<LocusGenesY>();

            randomize(LocusGenesX.class, genotype.sexualChromosomePair.left);
            randomize(LocusGenesY.class, genotype.sexualChromosomePair.rightY);
        } else if (sex == Sex.FEMALE) {
            genotype.sexualChromosomePair.left = new Chromosome<LocusGenesX>();
            genotype.sexualChromosomePair.rightX = new Chromosome<LocusGenesX>();

            randomize(LocusGenesX.class, genotype.sexualChromosomePair.left);
            randomize(LocusGenesX.class, genotype.sexualChromosomePair.rightX);
        }

        genotype.chromosomes.put(ChromosomePairLocus.A.getPosition(),
                Genotype.<LocusGenesA>createRandomPair(LocusGenesA.class));

        genotype.chromosomes.put(ChromosomePairLocus.B.getPosition(),
                Genotype.<LocusGenesB>createRandomPair(LocusGenesB.class));

        genotype.chromosomes.put(ChromosomePairLocus.C.getPosition(),
                Genotype.<LocusGenesC>createRandomPair(LocusGenesC.class));

        genotype.chromosomes.put(ChromosomePairLocus.D.getPosition(),
                Genotype.<LocusGenesD>createRandomPair(LocusGenesD.class));

        genotype.chromosomes.put(ChromosomePairLocus.E.getPosition(),
                Genotype.<LocusGenesE>createRandomPair(LocusGenesE.class));

        genotype.chromosomes.put(ChromosomePairLocus.F.getPosition(),
                Genotype.<LocusGenesF>createRandomPair(LocusGenesF.class));

        genotype.chromosomes.put(ChromosomePairLocus.G.getPosition(),
                Genotype.<LocusGenesG>createRandomPair(LocusGenesG.class));

        genotype.chromosomes.put(ChromosomePairLocus.H.getPosition(),
                Genotype.<LocusGenesH>createRandomPair(LocusGenesH.class));

        genotype.chromosomes.put(ChromosomePairLocus.I.getPosition(),
                Genotype.<LocusGenesI>createRandomPair(LocusGenesI.class));

        genotype.chromosomes.put(ChromosomePairLocus.J.getPosition(),
                Genotype.<LocusGenesJ>createRandomPair(LocusGenesJ.class));

        genotype.chromosomes.put(ChromosomePairLocus.K.getPosition(),
                Genotype.<LocusGenesK>createRandomPair(LocusGenesK.class));

        genotype.chromosomes.put(ChromosomePairLocus.L.getPosition(),
                Genotype.<LocusGenesL>createRandomPair(LocusGenesL.class));

        genotype.chromosomes.put(ChromosomePairLocus.M.getPosition(),
                Genotype.<LocusGenesM>createRandomPair(LocusGenesM.class));

        genotype.chromosomes.put(ChromosomePairLocus.N.getPosition(),
                Genotype.<LocusGenesN>createRandomPair(LocusGenesN.class));

        genotype.chromosomes.put(ChromosomePairLocus.O.getPosition(),
                Genotype.<LocusGenesO>createRandomPair(LocusGenesO.class));

        return genotype;
    }

    private static <T extends LocusGenes> ChromosomePair<T> createRandomPair(Class<T> clazz) {
        ChromosomePair<T> chromosomePair = new ChromosomePair<T>(clazz);
        chromosomePair.left = new Chromosome<T>();
        chromosomePair.right = new Chromosome<T>();

        randomize(clazz, chromosomePair.left);
        randomize(clazz, chromosomePair.right);

        return chromosomePair;
    }

    private static <T extends Locus> void randomize(Class<T> locus, Chromosome<T> chromosome) {
        for (int i = 0; i < locus.getEnumConstants().length; i++) {
            chromosome.setGene(i, random.nextBoolean(), false);
        }
    }

    @SuppressWarnings("unchecked")
    public static Genotype createGenotype(
            Genotype g1, Genotype g2, double mutationProbabilityForEachGene) throws HomossexualException {

        Genotype male = g1.getSex() == Sex.MALE ? g1 : g2;
        Genotype female = g1.getSex() == Sex.FEMALE ? g1 : g2;

        Genotype genotype = new Genotype();

        if (male.getSex() != Sex.MALE || female.getSex() != Sex.FEMALE) {
            throw new HomossexualException("You need a male and female genotype to make a baby");
        }

        if (random.nextDouble() < 0.5) {
            genotype.sexualChromosomePair.left = female.getSexualChromosomePair().left.clone();
        } else {
            genotype.sexualChromosomePair.left = female.getSexualChromosomePair().rightX.clone();
        }

        if (random.nextDouble() < 0.5) {
            genotype.sexualChromosomePair.rightY = male.getSexualChromosomePair().rightY.clone();
        } else {
            genotype.sexualChromosomePair.rightX = male.getSexualChromosomePair().left.clone();
        }

        for (ChromosomePairLocus locus : ChromosomePairLocus.values()) {
            ChromosomePair chromosomePair = new ChromosomePair(locus.getLocusGenesClass());

            if (random.nextDouble() < 0.5) {
                chromosomePair.left = (Chromosome) female.getChromosomePair(locus).left.clone();
            } else {
                chromosomePair.left = (Chromosome) female.getChromosomePair(locus).right.clone();
            }

            if (random.nextDouble() < 0.5) {
                chromosomePair.right = (Chromosome) male.getChromosomePair(locus).left.clone();
            } else {
                chromosomePair.right = (Chromosome) male.getChromosomePair(locus).right.clone();
            }

            applyMutation(chromosomePair, mutationProbabilityForEachGene);
            genotype.chromosomes.put(locus.getPosition(), chromosomePair);
        }

        return genotype;
    }

    private static void applyMutation(ChromosomePair chromosomePair, double mutationProbabilityForEachGene) {
        applyMutation(chromosomePair.left, mutationProbabilityForEachGene);
        applyMutation(chromosomePair.right, mutationProbabilityForEachGene);
    }

    @SuppressWarnings("unchecked")
    private static void applyMutation(Chromosome chromosome, double mutationProbabilityForEachGene) {
        BitSet genes = chromosome.getGenes();

        for (int position = 0; position < genes.length(); position++) {
            boolean gene = genes.get(position);

            if (random.nextDouble() < mutationProbabilityForEachGene) {
                gene = !gene;
                chromosome.setGene(position, gene, true);
            }
        }
    }

    public Sex getSex() {
        Sex sex;

        if (getSexualChromosomePair().rightY != null) {
            sex = Sex.MALE;
        } else if (getSexualChromosomePair().rightX != null) {
            sex = Sex.FEMALE;
        } else {
            sex = Sex.UNDETERMINED;
        }

        return sex;
    }

    public SexualChromosomePair getSexualChromosomePair() {
        return sexualChromosomePair;
    }

    @SuppressWarnings("unchecked")
    public <T extends LocusGenes> ChromosomePair<T> getChromosomePair(ChromosomePairLocus locus) {
        ChromosomePair pair = chromosomes.get(locus.getPosition());

        if (pair == null) {
            pair = Genotype.createRandomPair((Class<T>) locus.getLocusGenesClass());
            chromosomes.put(locus.getPosition(), pair);
        }

        return (ChromosomePair<T>) pair;
    }

    public GenePair getGenePair(LocusGenes locusGenes) {
        return getChromosomePair(locusGenes.getChromosomePairLocus()).getGenePair(locusGenes);
    }

    public GenePair getGenePairXX(LocusGenesX locusGenesX) {
        return getSexualChromosomePair().getPairXX(locusGenesX);
    }

    public GenePair getGenePairXY(LocusGenesX locusGenesX) {
        return getSexualChromosomePair().getPairXY(locusGenesX);
    }

    public GenePair getGenePairXY(LocusGenesY locusGenesY) {
        return getSexualChromosomePair().getPairXY(locusGenesY);
    }

    public boolean isRecessiveXX(LocusGenesX locusGenes) {
        return getGenePairXX(locusGenes).isRecessive();
    }

    public boolean isRecessiveXY(LocusGenesX locusGenes) {
        return getGenePairXY(locusGenes).isRecessive();
    }

    public boolean isRecessiveXY(LocusGenesY locusGenes) {
        return getGenePairXY(locusGenes).isRecessive();
    }

    public boolean isDominantXX(LocusGenesX locusGenes) {
        return getGenePairXX(locusGenes).isDominant();
    }

    public boolean isDominantXY(LocusGenesX locusGenes) {
        return getGenePairXY(locusGenes).isDominant();
    }

    public boolean isDominantXY(LocusGenesY locusGenes) {
        return getGenePairXY(locusGenes).isDominant();
    }

    public boolean isRecessive(LocusGenes ... locusGenes) {
        boolean isRecessive = true;

        for (LocusGenes gene : locusGenes) {
            if (!getGenePair(gene).isRecessive()) {
                isRecessive = false;
                break;
            }
        }

        return isRecessive;
    }

    public boolean isDominant(LocusGenes ... locusGenes) {
        boolean isDominant = true;

        for (LocusGenes gene : locusGenes) {
            if (!getGenePair(gene).isDominant()) {
                isDominant = false;
                break;
            }
        }

        return isDominant;
    }

    @SuppressWarnings("unchecked")
    public String toString() {
        StringBuilder result = new StringBuilder();

        for (ChromosomePairLocus chromosome : ChromosomePairLocus.values()) {
            result.append(chromosome.name()).append(": ");
            ChromosomePair chromosomePair = getChromosomePair(chromosome);

            for (LocusGenes locus : chromosomePair.getPossibleLocus()) {
                result.append(locus.getPosition())
                        .append("(")
                        .append(chromosomePair.getGenePair(locus).toString(locus.toString()))
                        .append(")\t");
            }

            result.append("\n");
        }

        SexualChromosomePair sexual = getSexualChromosomePair();

        if (getSex() == Sex.MALE) {
            result.append("X").append(": ");

            for (LocusGenesX locus : LocusGenesX.values()) {
                result.append(locus.getPosition())
                        .append("(")
                        .append(sexual.getPairXY(locus).toString("X"))
                        .append(")\t");
            }

            result.append("\n");
            result.append("Y").append(": ");

            for (LocusGenesY locus : LocusGenesY.values()) {
                result.append(locus.getPosition())
                        .append("(")
                        .append(sexual.getPairXY(locus).toString("Y"))
                        .append(")\t");
            }

        } else if (getSex() == Sex.FEMALE) {
            result.append("XX").append(": ");

            for (LocusGenesX locus : LocusGenesX.values()) {
                result.append(locus.getPosition())
                        .append("(")
                        .append(sexual.getPairXX(locus).toString("X"))
                        .append(")\t");
            }
        }

        result.append("\n");

        return result.toString();
    }

    public String toString(LocusGenesX gene) {
        return (getSex() == Sex.FEMALE ? String.valueOf(getGenePairXX(gene)) : getGenePairXY(gene)) + ";";
    }

    public String toString(LocusGenesY gene) {
        return (getSex() == Sex.FEMALE ? "?" : getGenePairXY(gene)) + ";";
    }

    public String toString(LocusGenes ... genes) {
        StringBuilder result = new StringBuilder();

        for (LocusGenes gene : genes) {
            result.append(getGenePair(gene)).append(";");
        }

        return result.toString();
    }
}
