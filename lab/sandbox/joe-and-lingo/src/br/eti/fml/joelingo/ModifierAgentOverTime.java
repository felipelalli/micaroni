package br.eti.fml.joelingo;

import sisc.data.ImmutableString;
import sisc.interpreter.SchemeException;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public final class ModifierAgentOverTime {
    private final ModifierAgentType modifierAgentType;

    private boolean attached = false;
    private Long currentSecondCycle;
    private Long initialCycle;
    private Long lastCycle;

    public ModifierAgentOverTime(ModifierAgentType modifierAgentType) {
        assert modifierAgentType != null;
        this.modifierAgentType = modifierAgentType;

        // TODO: initialize interpreter before execute
    }

    public AttachmentResult onAttach(Joelingo joelingo) throws BadCodeException, IOException {
        initialCycle = joelingo.getCurrentSecondCycle();
        AttachmentResult result;

        try {
            ImmutableString value
                    = (ImmutableString) LifeEngine.getDefaultLifeEngine()
                        .eval(modifierAgentType.getOnAttachCode());

            result = AttachmentResult.valueOf(value.asString());
        } catch (SchemeException | ClassCastException e) {
            throw new BadCodeException(e);
        }

        attached = true;
        return result;
    }

    /**
     * Try to remove this agent, but the agent code will decide if it kill itself
     * or not. If not, this modifier cannot be removed. See {@link #isAccessory()}.
     * Accessory generally can be removed.
     */
    public AttachmentResult onRemove(Joelingo joelingo) throws IOException, BadCodeException {
        AttachmentResult result;

        try {
            ImmutableString value = (ImmutableString) LifeEngine
                    .getDefaultLifeEngine().eval(modifierAgentType.getOnRemoveCode());

            result = AttachmentResult.valueOf(value.asString());
        } catch (SchemeException | ClassCastException e) {
            throw new BadCodeException(e);
        }

        return result;
    }

    public void onKill(Joelingo joelingo) {
        lastCycle = joelingo.getCurrentSecondCycle();
        attached = false;
    }

    public void executeCycle(Joelingo joelingo) throws IOException, BadCodeException {
        try {
            LifeEngine.getDefaultLifeEngine().eval(modifierAgentType.getOnCycleCode());
        } catch (SchemeException e) {
            throw new BadCodeException(e);
        }
    }

    public ModifierAgentType getModifierAgentType() {
        return modifierAgentType;
    }

    public boolean isAccessory() {
        return this.getModifierAgentType().isAccessory();
    }
}
