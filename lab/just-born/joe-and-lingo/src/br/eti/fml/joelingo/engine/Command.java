package br.eti.fml.joelingo.engine;

import br.eti.fml.joelingo.JsonCapable;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Command extends JsonCapable<Command> {
    private final CommandDescription commandDescription;

    public Command(CommandDescription commandDescription) {
        this.commandDescription = commandDescription;
    }

    public CommandDescription getCommandDescription() {
        return commandDescription;
    }
}
