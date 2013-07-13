package br.eti.fml.joelingo;

import br.eti.fml.joelingo.env.Environment;
import sisc.data.Quantity;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;

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

        Joelingo joelingo = new Joelingo();
        joelingo.arises(env, "Joe", "Campobelo", null);

        Description description = joelingo.describe(env);

        System.out.println("Description: " + description);
    }

}
