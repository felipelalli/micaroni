package br.eti.fml.joelingo;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo {
    private Genotype genotype;
    private Phenotype initialPhenotype;

    private Long birthdayDateSecondCycle; // when this joelingo has born
    private Long deathDateSecondCycle; // when this joelingo has died
    private long currentSecondCycle = 0; // age in seconds (94.608.000 = 3 years)

    private final Map<String, ModifierAgentOverTime> activeAgents = new HashMap<>(50);
    private final Set<ModifierAgentOverTime> archivedAgents = new HashSet<>(100);

    void arises(Environment environment) throws AlreadyAliveException {
        if (isBorn()) {
            throw new AlreadyAliveException();
        } else {
            birthdayDateSecondCycle = environment.getGlobalSecondCycle();

            // TODO: copy genotype characteristics to phenotype
        }
    }

    void die(Environment environment, DeathReason reason) {
        deathDateSecondCycle = environment.getGlobalSecondCycle();
    }

    void liveOneSecond() throws IOException, BadCodeException {
        try {
            for (ModifierAgentOverTime agent : activeAgents.values()) {
                agent.executeCycle(this);
            }
        } finally {
            currentSecondCycle++;
        }
    }

    /**
     * Kill can be called by another agent. The modifier is killed immediately
     * even if it cannot be removed.
     */
    boolean killModifierAgent(String uuid) {
        boolean removed;

        if (!activeAgents.containsKey(uuid)) {
            removed = false;
        } else {
            ModifierAgentOverTime agentOverTime = activeAgents.get(uuid);
            agentOverTime.onKill(this);
            archivedAgents.add(agentOverTime);
            activeAgents.remove(uuid);
            removed = true;
        }

        return removed;
    }

    // Public

    /**
     * An external action can remove this specific agent.
     */
    public AttachmentResult tryRemoveModifierAgent(String uuid) throws IOException, BadCodeException {
        AttachmentResult result;

        if (!activeAgents.containsKey(uuid)) {
            result = AttachmentResult.NOT_FOUND;
        } else {
            result = activeAgents.get(uuid).onRemove(this);
        }

        return result;
    }

    /**
     * Current known limitation: it is possible to add only one type of an modifier agent at once.
     */
    public AttachmentResult tryAttachModifierAgent(
            ModifierAgentOverTime agent) throws IOException, BadCodeException {

        AttachmentResult result;

        if (activeAgents.containsKey(agent.getModifierAgentType().getUuid())) {
            result = AttachmentResult.ALREADY_ATTACHED;
        } else {
            result = agent.onAttach(this);
        }

        activeAgents.put(agent.getModifierAgentType().getUuid(), agent);
        return result;
    }

    public long getCurrentSecondCycle() {
        return this.currentSecondCycle;
    }

    public long getBirthdayDateSecondCycle() {
        assert birthdayDateSecondCycle != null;
        return birthdayDateSecondCycle;
    }

    public boolean isBorn() {
        return birthdayDateSecondCycle != null;
    }
}

