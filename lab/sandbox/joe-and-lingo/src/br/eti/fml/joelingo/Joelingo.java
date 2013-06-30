package br.eti.fml.joelingo;

import br.eti.fml.joelingo.agent.AttachmentResult;
import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.env.Environment;

import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

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

    private transient Random random;

    /**
     * This list is like a history, always increasing and never decrease in size.
     */
    private final List<ModifierAgentOverTime> agents = new LinkedList<>();

    /**
     * This is a cache built on demand. It keeps the
     * actives agent to fast access.
     */
    private transient List<ModifierAgentOverTime> activeAgentsCache;

    private Random getRandom() {
        assert genotype != null;

        if (random == null) {
            random = new Random(genotype.getLuckyNumber());
        }

        return random;
    }

    private List<ModifierAgentOverTime> getActiveAgentsCache() {
        if (activeAgentsCache == null) {
            List<ModifierAgentOverTime> newCache = new LinkedList<>();

            for (ModifierAgentOverTime agent : agents) {
                if (agent.isActive(this)) {
                    newCache.add(agent);
                }
            }

            activeAgentsCache = newCache;
        }

        return activeAgentsCache;
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

    public Joelingo crosses(Environment environment, Joelingo joelingo) throws DeathException {
        assertIsAlive();
        joelingo.assertIsAlive();

        // TODO: create a new joelingo, arises it, crosses, make mutation etc.

        return null;
    }

    public void liveOneSecond(Environment environment) throws IOException, BadCodeException, DeathException {
        // TODO: use env
        assertIsAlive();

        try {
            Iterator<ModifierAgentOverTime> agents = getActiveAgentsCache().iterator();

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
                getActiveAgentsCache().add(agent);
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
        return new Description(initialPhenotype, getActiveAgentsCache());
    }

    public void assertIsAlive() throws DeathException {
        assert name != null && lastName != null && genotype != null && initialPhenotype != null;

        if (!isBorn()) {
            throw new DeathException(DeathReason.NOT_BORN);
        }

        if (isDead()) {
            assert deathReason != null;
            throw new DeathException(deathReason);
        }
    }
}

