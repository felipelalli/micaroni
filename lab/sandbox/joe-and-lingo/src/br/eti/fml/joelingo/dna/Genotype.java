package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.HomossexualException;
import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.ChromosomePairLocus;
import br.eti.fml.joelingo.dna.locus.Locus;
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

    private static <T extends Locus> ChromosomePair<T> createRandomPair(Class<T> clazz) {
        ChromosomePair<T> chromosomePair = new ChromosomePair<T>();
        chromosomePair.left = new Chromosome<T>();
        chromosomePair.right = new Chromosome<T>();

        randomize(clazz, chromosomePair.left);
        randomize(clazz, chromosomePair.right);

        return chromosomePair;
    }

    private static <T extends Locus> void randomize(Class<T> locus, Chromosome<T> chromosome) {
        for (int i = 0; i < locus.getEnumConstants().length; i++) {
            chromosome.setGene(i, random.nextBoolean());
        }
    }

    public static Genotype createGenotype(
            Genotype g1, Genotype g2, double mutationProbabilityForEachGene) throws HomossexualException {

        Genotype male = g1.getSex() == Sex.MALE ? g1 : g2;
        Genotype female = g1.getSex() == Sex.FEMALE ? g1 : g2;

        Genotype genotype = new Genotype();

        if (male.getSex() != Sex.MALE || female.getSex() != Sex.FEMALE) {
            throw new HomossexualException("You need a male and female genotype to make a baby");
        }

        if (random.nextDouble() < 0.5) {
            genotype.sexualChromosomePair.left = female.sexualChromosomePair.left.clone();
        } else {
            genotype.sexualChromosomePair.left = female.sexualChromosomePair.rightX.clone();
        }

        if (random.nextDouble() < 0.5) {
            genotype.sexualChromosomePair.rightY = male.sexualChromosomePair.rightY.clone();
        } else {
            genotype.sexualChromosomePair.rightX = male.sexualChromosomePair.left.clone();
        }

        for (ChromosomePairLocus locus : ChromosomePairLocus.values()) {
            ChromosomePair chromosomePair = new ChromosomePair();

            if (random.nextDouble() < 0.5) {
                chromosomePair.left = (Chromosome) female.chromosomes.get(locus.getPosition()).left.clone();
            } else {
                chromosomePair.left = (Chromosome) female.chromosomes.get(locus.getPosition()).right.clone();
            }

            if (random.nextDouble() < 0.5) {
                chromosomePair.right = (Chromosome) male.chromosomes.get(locus.getPosition()).left.clone();
            } else {
                chromosomePair.right = (Chromosome) male.chromosomes.get(locus.getPosition()).right.clone();
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
            }

            chromosome.setGene(position, gene);
        }
    }

    public Sex getSex() {
        Sex sex;

        if (sexualChromosomePair.rightY != null) {
            sex = Sex.MALE;
        } else if (sexualChromosomePair.rightX != null) {
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
    public <T extends Locus> ChromosomePair<T> getChromosomePair(Locus locus) {
        ChromosomePair pair = chromosomes.get(locus.getPosition());

        if (pair == null) {
            pair = Genotype.createRandomPair((Class<T>) locus.getClass());
            chromosomes.put(locus.getPosition(), pair);
        }

        return (ChromosomePair<T>) pair;
    }
}
