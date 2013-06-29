package br.eti.fml.joelingo;

import sisc.data.Value;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class LifeEngine {
    private static LifeEngine defaultLifeEngine;
    private Interpreter interpreter;

    static {
        defaultLifeEngine = new LifeEngine();
    }

    public static LifeEngine getDefaultLifeEngine() {
        return defaultLifeEngine;
    }

    public LifeEngine() {
        AppContext appContext = Context.getDefaultAppContext();
        this.interpreter = Context.enter(appContext);
    }

    public Value eval(String expression) throws IOException, SchemeException {
        return interpreter.eval(expression);
    }
}
