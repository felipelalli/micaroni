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

    private long currentSecondCycle = 0; // age in seconds (94.608.000 = 3 years)
    private final Map<String, ModifierAgentOverTime> activeAgents = new HashMap<>(50);
    private final Set<ModifierAgentOverTime> archivedAgents = new HashSet<>(100);

    public void arises() {
        // TODO: copy genotype characteristics to phenotype

    }

    public void liveOneSecond() throws IOException, BadCodeException {
        for (ModifierAgentOverTime agent : activeAgents.values()) {
            agent.executeCycle(this);
        }

        currentSecondCycle++;
    }

    /**
     * Kill can be called by another agent. The modifier is killed immediately
     * even if it cannot be removed.
     */
    private boolean killModifierAgent(String uuid) {
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
}

