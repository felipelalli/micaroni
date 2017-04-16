package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.dna.locus.LocusGenes;
import br.eti.fml.joelingo.dna.locus.LocusGenesC;
import br.eti.fml.joelingo.dna.locus.LocusGenesD;
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

        Joelingo joe = Joelingo.getNewJoe();
        joe.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);

        Joelingo lingo = Joelingo.getNewLingo();
        lingo.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);

        List<Joelingo> children = new ArrayList<Joelingo>();

        for (int i = 0; i < 20; i++) {
            Joelingo child = joe.crossesWith(lingo);
            children.add(child);

//            if (i == 0) {
//                child.die(DeathReason.SUDDEN_UNEXPLAINED_DEATH);
//            }
//
//            if (i > 2) {
//                child.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);
//            }

            child.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0);

            child.getPhenotype().setFeature(LocusFeatures.SLEEPY, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.HAPPINESS, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.ANGER_FEELING, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.HUNGER_FEELING, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.MOTIVATION_FEELING, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.FEAR, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.FEELING_COLD, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.HEALTHY_APPEARANCE, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BOREDOM_FEELING, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.DIRT_LEVEL, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.MUSCLE, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BODY_FAT, random.nextDouble());

//            child.getPhenotype().setFeature(LocusFeatures.EYE_SIZE, Math.abs(random.nextDouble()));
//            child.getPhenotype().setFeature(LocusFeatures.EYE_EFFICIENCY, Math.abs(random.nextDouble()));
//            child.getPhenotype().setFeature(LocusFeatures.EYE_GLOW, Math.abs(random.nextDouble()));
//            child.getPhenotype().setFeature(LocusFeatures.EYE_REDDISH, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.EYE_GREENISH, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.EYE_BLUISH, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.EYELASHES_SIZE, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.EYEBROW_SIZE, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.WINGS_SIZE, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.SKIN_REDDISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.SKIN_GREENISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.SKIN_BLUISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.SKIN_ROUGHNESS, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BRISTLE_REDDISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BRISTLE_GREENISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BRISTLE_BLUISH, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.BRISTLE_SIZE, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.HAIR_SIZE, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.HAIR_VOLUME, random.nextDouble());
//            child.getPhenotype().setFeature(LocusFeatures.HAIR_STRAIGHTNESS, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.TAIL_SIZE, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.TEETH_SIZE, random.nextDouble());
            child.getPhenotype().setFeature(LocusFeatures.TEETH_POINTED, random.nextDouble());
        }

        LocusGenes[] gene = new LocusGenes[] { LocusGenesC.FEAR_TENDENCY_P1, LocusGenesD.FEAR_TENDENCY_P2 };
        //LocusGenesX gene = LocusGenesX.EYELASHES_SIZE;
        LocusFeatures[] feature = new LocusFeatures[] {
                LocusFeatures.TENDENCY_TO_FEEL_FEAR, LocusFeatures.FEAR };

        System.out.println("Joe: " + joe);
//        System.out.println(joe.getGenotype().toString(gene));
//        System.out.println(joe.getPhenotype().toString(feature));
        System.out.println("\nLingo: " + lingo);
//        System.out.println(lingo.getGenotype().toString(gene));
//        System.out.println(lingo.getPhenotype().toString(feature));

        for (int i = 0; i < children.size(); i++) {
            Joelingo child = children.get(i);

            child.liveUntilNow();
            Thread.sleep(50);
            System.out.println("\n" + i + ") " + child);
            //System.out.println(child.getGenotype().toString(gene));
            //System.out.println(child.getPhenotype().toString(feature));
            System.out.println("---");
        }
    }
}
