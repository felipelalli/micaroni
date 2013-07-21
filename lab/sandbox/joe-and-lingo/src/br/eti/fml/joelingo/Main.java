package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.env.Environment;
import sisc.data.Quantity;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

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
        Environment env = new Environment();

        Joelingo joe = new Joelingo();
        joe.arises(env, null, null, Genotype.createRandomGenotype(Sex.MALE));

        Joelingo lingo = new Joelingo();
        lingo.arises(env, null, null, Genotype.createRandomGenotype(Sex.FEMALE));

        List<Joelingo> kids = new ArrayList<Joelingo>();

        for (int i = 0; i < 10; i++) {
            kids.add(joe.crosses(env, lingo));
        }

        System.out.println("Joe: " + joe);
        System.out.println("Lingo: " + lingo);

        for (Joelingo kid : kids) {
            System.out.println("Kid: " + kid);
        }
    }

}
