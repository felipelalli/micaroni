package br.eti.fml.joelingo;

import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.engine.BadCodeException;
import br.eti.fml.joelingo.env.Environment;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo extends JsonCapable<Joelingo> {
    private String uuid;                  // UUID

    private String name;                  // Generated name
    private String lastName;              // Generated name

    private Genotype genotype;            // DNA
    private Phenotype initialPhenotype;   // The initial phenotype is immutable.

    private Long birthdayDateSecondCycle; // when this joelingo has born
    private Long deathDateSecondCycle;    // when this joelingo has died
    private DeathReason deathReason;      // if any

    private transient Random random;

    /**
     * This list is like a history, always increasing and never decrease in size.
     */
    private final List<ModifierAgentOverTime> agents = new LinkedList<>();

    public List<ModifierAgentOverTime> getAgents() {
        return agents;
    }

    /**
     * This is not useful to describe Joelingo. See {@link #describe(br.eti.fml.joelingo.env.Environment)} instead.
     */
    public Phenotype getInitialPhenotype() {
        return initialPhenotype;
    }

    private Random getRandom() throws NotBornException {
        assertIsBorn();

        if (random == null) {
            random = new Random(genotype.getLuckyNumber());
        }

        return random;
    }

    /**
     * Age in seconds (94.608.000 = 3 years)
     */
    public long getAgeInSecondCycle(Environment environment) throws NotBornException {
        assertIsBorn();
        long age;

        if (isDead()) {
            age = this.deathDateSecondCycle - this.birthdayDateSecondCycle;
        } else {
            age = environment.getGlobalSecondCycle() - this.birthdayDateSecondCycle;
        }

        return age;
    }

    public void arises(Environment environment, String name,
                       String lastName, Genotype genotype) throws AlreadyBornException {

        if (isBorn()) {
            throw new AlreadyBornException();
        } else {
            birthdayDateSecondCycle = environment.getGlobalSecondCycle();
            this.name = name;
            this.lastName = lastName;
            this.genotype = genotype;

            // environment.getInitialAgents() TODO
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
        // TODO: if gene of parent is absent when crossing, make new genes random

        return null;
    }

    public void attachModifierAgent(ModifierAgentOverTime agent, Environment env)
            throws IOException, BadCodeException, DeathException {

        agent.attach(this, env);
        agents.add(agent);
    }

    public void removeModifierAgent(ModifierAgentOverTime agent, Environment env)
            throws IOException, BadCodeException, DeathException {

        agent.detach(this, env);
    }

    public long getBirthdayDateSecondCycle() throws NotBornException {
        assertIsBorn();
        return birthdayDateSecondCycle;
    }

    public boolean isBorn() {
        return birthdayDateSecondCycle != null
                && name != null && lastName != null && genotype != null && initialPhenotype != null;
    }

    public boolean isDead() {
        return deathDateSecondCycle != null && deathReason != null;
    }

    public boolean isAlive() {
        return isBorn() && !isDead();
    }

    public Description describe(Environment env) throws DeathException {
        return new Description(this, env);
    }

    public void assertIsBorn() throws NotBornException {
        if (!isBorn()) {
            throw new NotBornException();
        }
    }

    public void assertIsAlive() throws DeathException {
        assertIsBorn();

        if (isDead()) {
            throw new DeathException(deathReason);
        }
    }
}

