package br.eti.fml.joelingo;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo {
    private Genotype genotype;
    private Phenotype phenotype;

    private long currentSecondCycle = 0; // age in seconds
    private final Map<String, ModifyingAgentOverTime> activeAgents = new HashMap<>(50);

    public void arises() {
        // TODO: copy genotype characteristics to phenotype

    }

    public void liveOneSecond() throws IOException, BadCodeException {
        for (ModifyingAgentOverTime agent : activeAgents.values()) {
            agent.executeCycle(this);
        }

        currentSecondCycle++;
    }

    public void killModifyingAgent(String uuid) {
        activeAgents.get(uuid).onKill(this);
    }

    public void removeModifyingAgent(String uuid) throws IOException, BadCodeException {
        activeAgents.get(uuid).onRemove(this);
    }

    public void attachModifyingAgent(
            ModifyingAgentOverTime modifyingAgentOverTime) throws IOException, BadCodeException {

        activeAgents.put(modifyingAgentOverTime.getUuid(), modifyingAgentOverTime);
        modifyingAgentOverTime.onAttach(this);
    }

    public long getCurrentSecondCycle() {
        return this.currentSecondCycle;
    }
}

