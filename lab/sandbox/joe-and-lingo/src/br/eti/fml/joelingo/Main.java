package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import sisc.data.Quantity;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Main {

    public static void test(String[] args) throws IOException, SchemeException {
        System.out.println("Hello world!");

        AppContext appContext = Context.getDefaultAppContext();
        Interpreter interpreter = Context.enter(appContext);

        Quantity q = (Quantity) interpreter.eval("(+ 1 1)");
        System.out.println("result: " + q.intValue());

        Context.exit();
    }

    public static void main(String[] args) throws Exception {
        Random random = new SecureRandom();

        Joelingo joe = new Joelingo();
        joe.arises(null, null, Genotype.createRandomGenotype(Sex.MALE));
        joe.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);

        Joelingo lingo = new Joelingo();
        lingo.arises(null, null, Genotype.createRandomGenotype(Sex.FEMALE));
        lingo.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);

        List<Joelingo> kids = new ArrayList<Joelingo>();

        for (int i = 0; i < 20; i++) {
            Joelingo kid = joe.crosses(lingo);
            kids.add(kid);

            if (i == 0) {
                kid.die(DeathReason.SUDDEN_UNEXPLAINED_DEATH);
            }

            if (i > 2) {
                kid.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);
            }

            kid.getPhenotype().setFeature(LocusFeatures.SLEEPY, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.HAPPINESS, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.ANGER_FEELING, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.HUNGER_FEELING, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.MOTIVATION_FEELING, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.FEAR, random.nextDouble());
            kid.getPhenotype().setFeature(LocusFeatures.FEELING_COLD, random.nextDouble());
        }

        System.out.println("Joe: " + joe);
        System.out.println("Lingo: " + lingo);

        for (Joelingo kid : kids) {
            kid.liveUntilNow();
            Thread.sleep(500);
            System.out.println("Kid: " + kid);
        }
    }
}
