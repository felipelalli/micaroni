package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.Feature;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.env.Environment;

import java.util.Date;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo extends JsonCapable<Joelingo> {
    private String uuid;                  // UUID
    private String uuidFather;
    private String uuidMother;

    private Name name;                  // Generated name
    private Name lastName;              // Generated name

    private Genotype genotype;            // DNA
    private Phenotype phenotype;          // The current phenotype

    private Long birthdayDateSecondCycle; // when this joelingo has born
    private Long deathDateSecondCycle;    // when this joelingo has died
    private Long ageInSecondCycle = 0L;   // current age in second cycle

    private Long birthdayTimestamp; // when this joelingo has born (Java timestamp)
    private Long deathTimestamp;    // when this joelingo has died (Java timestamp)

    private DeathReason deathReason;      // if any

    public Phenotype getPhenotype() {
        return phenotype;
    }

    /**
     * Age in seconds (94.608.000 = 3 years)
     */
    public long getAgeInSecondCycle() {
        return ageInSecondCycle;
    }

    public Date getBirthday() {
        return new Date(birthdayTimestamp);
    }

    public Date getDeath() {
        return new Date(deathTimestamp);
    }

    public Name getName() {
        return name;
    }

    public Name getLastName() {
        return lastName;
    }

    public void arises(Environment environment, Joelingo father,
                       Joelingo mother, Genotype genotype) throws AlreadyBornException {

        if (isBorn()) {
            throw new AlreadyBornException();
        } else {
            birthdayDateSecondCycle = environment.getGlobalSecondCycle();
            birthdayTimestamp = System.currentTimeMillis();

            if (father == null || mother == null) {
                this.name = genotype.getSex() == Sex.MALE ? Name.JOE : Name.LINGO;
                this.lastName = Name.generateName();
            } else {
                this.uuidFather = father.uuid;
                this.uuidMother = mother.uuid;
                this.name = Name.generateName();
                this.lastName = Name.generateName(mother.getLastName(), father.getLastName());
            }

            this.uuid = UUID.randomUUID().toString();
            this.genotype = genotype.clone();

            Phenotype phenotype = new Phenotype();

            for (LocusFeatures feature : LocusFeatures.values()) {
                phenotype.setFeature(feature, new Feature(feature.getDefaultValue()));
            }

            this.phenotype = phenotype;

            // TODO: copy genotype characteristics to phenotype
        }
    }

    public void die(Environment environment, DeathReason reason) throws DeathException {
        this.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0); // crash the egg if is inside one
        assertIsAlive();

        if (reason == DeathReason.NOT_BORN) {
            throw new IllegalArgumentException("You cannot kill a joelingo with reason 'not born'");
        }

        this.deathDateSecondCycle = environment.getGlobalSecondCycle();
        this.deathTimestamp = System.currentTimeMillis();
        this.deathReason = reason;
    }

    public Joelingo crosses(Environment environment, Joelingo joelingo)
            throws DeathException, HomossexualException, AlreadyBornException {

        assertIsAlive();
        joelingo.assertIsAlive();

        Joelingo son = new Joelingo();

        Joelingo father = this.genotype.getSex() == Sex.MALE ? this : joelingo;
        Joelingo mother = this.genotype.getSex() == Sex.FEMALE ? this : joelingo;

        son.arises(environment, father, mother, Genotype.createGenotype(father.genotype, mother.genotype, 0.05));

        // TODO: create a new joelingo, arises it, crosses, make mutation etc.
        // TODO: if gene of parent is absent when crossing, make new genes random
        // TODO: takes into account genitalia size, efficiency etc.

        return son;
    }

    public long getBirthdayDateSecondCycle() throws NotBornException {
        assertIsBorn();
        return birthdayDateSecondCycle;
    }

    public boolean isBorn() {
        return birthdayDateSecondCycle != null
                && name != null && lastName != null && genotype != null && phenotype != null
                && getPhenotype().getFeature(LocusFeatures.IN_EGG).getDoubleValue() < .5; // not inside an egg
    }

    public boolean isDead() {
        return deathDateSecondCycle != null && deathReason != null;
    }

    public boolean isAlive() {
        return isBorn() && !isDead();
    }

    public void assertIsBorn() throws NotBornException {
        if (!isBorn()) {
            throw new NotBornException(this.getName() + " is not born!");
        }
    }

    public void assertIsAlive() throws DeathException {
        assertIsBorn();

        if (isDead()) {
            throw new DeathException(deathReason, this.getName() + " is not alive!");
        }
    }

    public DeathReason getDeathReason() {
        return deathReason;
    }

    public String toString() {
        return new SimpleTextDescribing(LevelDetail.NORMAL).describe(this);
    }

    public Genotype getGenotype() {
        return genotype;
    }

    // TODO: back to add here LIVE ONE SECOND
}

