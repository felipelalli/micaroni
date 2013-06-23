package br.eti.fml.joelingo;

import sisc.data.Quantity;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException, SchemeException {
        System.out.println("Hello world!");

        AppContext appContext = Context.getDefaultAppContext();
        Interpreter interpreter = Context.enter(appContext);

        Quantity q = (Quantity) interpreter.eval("(+ 1 1)");
        System.out.println("result: " + q.intValue());

        Context.exit();
    }
}
