package br.eti.fml.joelingo.engine;

import br.eti.fml.joelingo.external.HistoryTable;
import sisc.data.Value;
import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class LifeEngine {
    private static LifeEngine defaultLifeEngine;

    private final HistoryTable historyTable;
    private final Interpreter interpreter;
    private final BlockingQueue<Command> pendentCommands = new LinkedBlockingQueue<Command>();

    public static void setDefaultLifeEngine(LifeEngine lifeEngine) {
        defaultLifeEngine = lifeEngine;
    }

    public static LifeEngine getDefaultLifeEngine() {
        if (defaultLifeEngine == null) {
            throw new IllegalStateException("You must call setDefaultLifeEngine first.");
        }

        return defaultLifeEngine;
    }

    public LifeEngine(HistoryTable historyTable) {
        this.historyTable = historyTable;
        AppContext appContext = Context.getDefaultAppContext();
        this.interpreter = Context.enter(appContext);
    }

    public Value eval(String expression) throws IOException, SchemeException {
        return interpreter.eval(expression);
    }

    public void interact(Command command) {
        this.pendentCommands.offer(command);
    }

    public void mainLoop() {
        boolean exit = false;

        Runtime.getRuntime().addShutdownHook(new Thread(new Runnable() {
            @Override
            public void run() {
                interact(new Command(CommandDescription.SYSTEM_SHUTDOWN));
            }
        }));

        // TODO: define here default functions on default app context
        // TODO: example: (get-initial-param "key" "default_value")

        while (!exit) {
            Command command = pendentCommands.poll();
            historyTable.insert(command);

            if (command.getCommandDescription() == CommandDescription.SYSTEM_SHUTDOWN) {
                exit = true;
            }

            // TODO: apply command here
        }
    }
}
