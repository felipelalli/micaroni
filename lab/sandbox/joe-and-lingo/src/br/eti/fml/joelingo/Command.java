package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Command extends JsonCapable {
    private final CommandDescription commandDescription;

    public Command(CommandDescription commandDescription) {
        this.commandDescription = commandDescription;
    }

    public CommandDescription getCommandDescription() {
        return commandDescription;
    }
}
