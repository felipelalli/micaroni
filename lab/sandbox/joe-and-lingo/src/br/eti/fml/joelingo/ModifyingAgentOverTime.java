package br.eti.fml.joelingo;

import sisc.interpreter.AppContext;
import sisc.interpreter.Context;
import sisc.interpreter.Interpreter;
import sisc.interpreter.SchemeException;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ModifyingAgentOverTime {
    private boolean attached = false;

    private final String uuid;
    private final String name;
    private final String description;
    private final Long version;
    private final Long randomSeed;

    private final Long secondDuration;

    private Long currentSecondCycle;
    private Long initialCycle;
    private Long lastCycle;

    private final String onAttachCode;
    private final String onCycleCode;
    private final String onRemoveCode;

    private transient Interpreter interpreter;

    /**
     *
     * @param uuid
     * @param name
     * @param description
     * @param version
     * @param secondDuration 0 is infinite or until be removed
     * @param onAttachCode
     * @param onCycleCode
     * @param onRemoveCode
     */
    public ModifyingAgentOverTime(String uuid, String name,
                                  String description, Long version,
                                  Long secondDuration,
                                  String onAttachCode,
                                  String onCycleCode,
                                  String onRemoveCode) {

        this.uuid = uuid;
        this.name = name;
        this.description = description;
        this.version = version;
        this.secondDuration = secondDuration;
        this.onAttachCode = onAttachCode;
        this.onCycleCode = onCycleCode;
        this.onRemoveCode = onRemoveCode;
        this.randomSeed = System.currentTimeMillis() ^ uuid.hashCode();

        AppContext appContext = Context.getDefaultAppContext();
        this.interpreter = Context.enter(appContext);

        // TODO: initialize interpreter before execute
    }

    public void onAttach(Joelingo joelingo) throws BadCodeException, IOException {
        initialCycle = joelingo.getCurrentSecondCycle();

        try {
            interpreter.eval(onAttachCode);
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }

        attached = true;
    }

    public void onRemove(Joelingo joelingo) throws IOException, BadCodeException {
        try {
            interpreter.eval(onRemoveCode);
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }

        onKill(joelingo);
    }

    public void onKill(Joelingo joelingo) {
        lastCycle = joelingo.getCurrentSecondCycle();
        attached = false;
    }

    public void executeCycle(Joelingo joelingo) throws IOException, BadCodeException {
        try {
            interpreter.eval(onCycleCode);
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }
    }

    public String getUuid() {
        return uuid;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public Long getVersion() {
        return version;
    }
}
