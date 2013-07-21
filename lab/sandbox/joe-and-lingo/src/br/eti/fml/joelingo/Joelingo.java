package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.AppearanceAge;
import br.eti.fml.joelingo.dna.Feature;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;

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

    private Long birthdayTimestamp; // when this joelingo has born (Java timestamp)
    private Long deathTimestamp;    // when this joelingo has died (Java timestamp)
    private Long ageInSecondCycle = 0L;   // current age in second cycle

    private DeathReason deathReason;      // if any

    public Phenotype getPhenotype() {
        return phenotype;
    }

    public void arises(Joelingo father, Joelingo mother, Genotype genotype) throws AlreadyBornException {

        if (isBorn()) {
            throw new AlreadyBornException();
        } else {
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

    public void die(DeathReason reason) throws DeathException {
        this.getPhenotype().setFeature(LocusFeatures.IN_EGG, 0.0); // crash the egg if is inside one
        assertIsAlive();

        if (reason == DeathReason.NOT_BORN) {
            throw new IllegalArgumentException("You cannot kill a joelingo with reason 'not born'");
        }

        this.deathTimestamp = System.currentTimeMillis();
        this.deathReason = reason;
    }

    public Joelingo crosses(Joelingo joelingo)
            throws DeathException, HomossexualException, AlreadyBornException {

        assertIsAlive();
        joelingo.assertIsAlive();

        Joelingo son = new Joelingo();

        Joelingo father = this.genotype.getSex() == Sex.MALE ? this : joelingo;
        Joelingo mother = this.genotype.getSex() == Sex.FEMALE ? this : joelingo;

        son.arises(father, mother, Genotype.createGenotype(father.genotype, mother.genotype, 0.05));

        // TODO: create a new joelingo, arises it, crosses, make mutation etc.
        // TODO: if gene of parent is absent when crossing, make new genes random
        // TODO: takes into account genitalia size, efficiency etc.

        return son;
    }

    public void liveUntilNow() {
        long nowInSec = System.currentTimeMillis() / 1000;
        long birthday = this.birthdayTimestamp / 1000;
        long diff = Math.max(0, nowInSec - birthday);

        for (int i = 0; i < diff; i++) {
            liveOneSecond();
        }
    }

    private void liveOneSecond() {


        ageInSecondCycle++;
    }

    public boolean isBorn() {
        return birthdayTimestamp != null
                && name != null && lastName != null && genotype != null && phenotype != null
                && getPhenotype().getFeature(LocusFeatures.IN_EGG).getDoubleValue() < .5; // not inside an egg
    }

    public boolean isDead() {
        return deathTimestamp != null && deathReason != null;
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

    /**
     * Age in seconds (94.608.000 = 3 years)
     */
    public long getAgeInSecondCycle() {
        return ageInSecondCycle * 60L * 60L * 24L; // TODO: for test
    }

    public DeathReason getDeathReason() {
        return deathReason;
    }

    public Genotype getGenotype() {
        return genotype;
    }

    public String getUuid() {
        return uuid;
    }

    public String getUuidFather() {
        return uuidFather;
    }

    public String getUuidMother() {
        return uuidMother;
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

    public String toString() {
        LevelDetail levelDetail = LevelDetail.values()[(int) (Math.random() * LevelDetail.values().length)];
        String desc = new SimpleTextDescribing(levelDetail).describe(this);
        return levelDetail + ": " + desc + " (" + desc.length() + " chars)";
    }

    public AppearanceAge getAppearanceAge() {
        return AppearanceAge.calculateAgeAppearance(getPhenotype()
                .getFeature(LocusFeatures.TENDENCY_TO_AGE).getDoubleValue(), getAgeInSecondCycle());
    }
}

