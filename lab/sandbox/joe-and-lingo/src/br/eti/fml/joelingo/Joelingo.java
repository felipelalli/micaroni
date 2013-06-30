package br.eti.fml.joelingo;

import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo extends JsonCapable {
    private String name;                  // Generated name
    private String lastName;              // Generated name

    private Genotype genotype;            // DNA
    private Phenotype initialPhenotype;   // The initial phenotype is immutable.

    private Long birthdayDateSecondCycle; // when this joelingo has born
    private Long deathDateSecondCycle;    // when this joelingo has died
    private DeathReason deathReason;      // if any

    private long currentSecondCycle = 0;  // age in seconds (94.608.000 = 3 years)

    /**
     * This list is like a history, always increasing and never decrease in size.
     */
    private final List<ModifierAgentOverTime> agents = new LinkedList<>();

    /**
     * This is a cache built on Joelingo default constructor. It keeps the
     * actives agents to fast access.
     */
    private transient final List<ModifierAgentOverTime> activeAgentsCache = new LinkedList<>();

    public Joelingo() {
        for (ModifierAgentOverTime agent : agents) {
            if (agent.isActive(this)) {
                activeAgentsCache.add(agent);
            }
        }
    }

    public void arises(Environment environment) throws AlreadyBornException {
        if (isBorn()) {
            throw new AlreadyBornException();
        } else {
            birthdayDateSecondCycle = environment.getGlobalSecondCycle();

            // TODO: copy genotype characteristics to phenotype
        }
    }

    public void die(Environment environment, DeathReason reason) throws DeathException {
        assertIsAlive();

        this.deathDateSecondCycle = environment.getGlobalSecondCycle();
        this.deathReason = reason;
    }

    public void liveOneSecond() throws IOException, BadCodeException, DeathException {
        assertIsAlive();

        try {
            Iterator<ModifierAgentOverTime> agents = activeAgentsCache.iterator();

            while (agents.hasNext()) {
                ModifierAgentOverTime agent = agents.next();

                if (agent.isActive(this)) {
                    agent.executeCycle(this);
                } else {
                    agents.remove();
                }
            }
        } finally {
            currentSecondCycle++;
        }
    }

    public AttachmentResult tryToAttachModifierAgent(
            ModifierAgentOverTime agent) throws IOException, BadCodeException {

        AttachmentResult result = agent.attachOn(this);

        if (result == AttachmentResult.SUCCESS) {
            agents.add(agent);

            if (agent.isActive(this)) {
                activeAgentsCache.add(agent);
            }
        }

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

    public boolean isDead() {
        return deathDateSecondCycle != null;
    }

    public boolean isAlive() {
        return isBorn() && !isDead();
    }

    public Description describe() {
        return new Description(initialPhenotype, activeAgentsCache);
    }

    public void assertIsAlive() throws DeathException {
        if (!isBorn()) {
            throw new DeathException(DeathReason.NOT_BORN);
        }

        if (isDead()) {
            assert deathReason != null;
            throw new DeathException(deathReason);
        }
    }
}

