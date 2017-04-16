package br.eti.fml.joelingo;

import br.eti.fml.joelingo.description.text.SimpleTextDescribing;
import br.eti.fml.joelingo.dna.AppearanceAge;
import br.eti.fml.joelingo.dna.DefaultTransformer;
import br.eti.fml.joelingo.dna.Feature;
import br.eti.fml.joelingo.dna.Genotype;
import br.eti.fml.joelingo.dna.InitialPhenotypeTransformer;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.dna.locus.LocusGenesO;

import java.util.Date;
import java.util.UUID;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Joelingo extends JsonCapable<Joelingo> {
    private String uuid;                 // UUID
    private String uuidFather;
    private String uuidMother;

    private Name name;                   // Generated name
    private Name lastName;               // Generated name

    private Genotype genotype;           // DNA
    private Phenotype phenotype;         // The current phenotype

    private Long birthdayTimestamp;      // when this joelingo has born (Java timestamp)
    private Long deathTimestamp;         // when this joelingo has died (Java timestamp)
    private Long ageInSecondCycle = 0L;  // current age in second cycle

    private DeathReason deathReason;     // if any

    private Joelingo() {}

    public Phenotype getPhenotype() {
        return phenotype;
    }

    public int getLuckyNumber() {
        return uuid.hashCode();
    }

    public InitialPhenotypeTransformer getInitialPhenotypeTransformer() {
        return new DefaultTransformer();
    }

    public static Joelingo getNewJoe() throws HomossexualException, AlreadyBornException {
        Joelingo joe = new Joelingo();
        return joe.arises(null, null, Sex.MALE);
    }

    public static Joelingo getNewLingo() throws HomossexualException, AlreadyBornException {
        Joelingo lingo = new Joelingo();
        return lingo.arises(null, null, Sex.FEMALE);
    }

    private Joelingo arises(Joelingo father, Joelingo mother) throws AlreadyBornException, HomossexualException {
        return arises(father, mother, Sex.UNDETERMINED);
    }

    private Joelingo arises(Joelingo father, Joelingo mother, Sex sex) throws AlreadyBornException, HomossexualException {
        if (isBorn()) {
            throw new AlreadyBornException();
        } else {
            birthdayTimestamp = System.currentTimeMillis();

            // TODO: get mutation probability from Box
            Phenotype phenotype = new Phenotype();

            for (LocusFeatures feature : LocusFeatures.values()) {
                phenotype.setFeature(feature, new Feature(feature.getDefaultValue()));
            }

            Genotype genotype;

            if (father == null || mother == null) {
                genotype = Genotype.createRandomGenotype(sex);
                this.name = genotype.getSex() == Sex.MALE ? Name.JOE_FIRST_NAME : Name.LINGO_FIRST_NAME;
                this.lastName = genotype.getSex() == Sex.MALE ? Name.JOE_LAST_NAME : Name.LINGO_LAST_NAME;
                phenotype.setFeature(LocusFeatures.IN_EGG, 0.0);
            } else {
                genotype = Genotype.createGenotype(father.genotype, mother.genotype, 0.05);

                this.uuidFather = father.uuid;
                this.uuidMother = mother.uuid;
                this.name = Name.generateName();
                this.lastName = Name.generateName(mother.getLastName(), father.getLastName());

                if (father.getGenotype().isRecessive(LocusGenesO.NO_EGG)
                        && mother.getGenotype().isRecessive(LocusGenesO.NO_EGG)) {

                    phenotype.setFeature(LocusFeatures.IN_EGG, 0.0);
                } else {
                    phenotype.setFeature(LocusFeatures.IN_EGG, 1.0);
                }

                phenotype.setFeature(LocusFeatures.IN_EGG, 0.0);
            }

            this.uuid = UUID.randomUUID().toString();
            this.genotype = genotype; // TODO: clone here?
            this.phenotype = phenotype;

            getInitialPhenotypeTransformer().transform(this.genotype, this.phenotype);
        }

        return this;
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

    public Joelingo crossesWith(Joelingo joelingo)
            throws DeathException, SexException, AlreadyBornException {

        assertIsAlive();
        joelingo.assertIsAlive();

        Joelingo son = new Joelingo();

        Joelingo father = this.genotype.getSex() == Sex.MALE ? this : joelingo;
        Joelingo mother = this.genotype.getSex() == Sex.FEMALE ? this : joelingo;

        if (father.getPhenotype().getFeature(LocusFeatures.GENITALIA_EFFICIENCY).getDoubleValue() == 0.0
            || mother.getPhenotype().getFeature(LocusFeatures.GENITALIA_EFFICIENCY).getDoubleValue() == 0.0
            || father.getPhenotype().getFeature(LocusFeatures.GENITALIA_SIZE).getDoubleValue() == 0.0
            || mother.getPhenotype().getFeature(LocusFeatures.GENITALIA_SIZE).getDoubleValue() == 0.0
            || father.getPhenotype().getFeature(LocusFeatures.GENITALIA_TYPE).getDoubleValue() > 0.5
            || mother.getPhenotype().getFeature(LocusFeatures.GENITALIA_TYPE).getDoubleValue() < 0.5)
        {
            throw new SexException("Father or mother is not able to have a child." +
                    " Please check genitalia sizes, type and efficiency. father: "
                    + father.getPhenotype().toString(
                    LocusFeatures.GENITALIA_EFFICIENCY,
                    LocusFeatures.GENITALIA_SIZE,
                    LocusFeatures.GENITALIA_TYPE)
                    + " --- mother: " + mother.getPhenotype().toString(
                    LocusFeatures.GENITALIA_EFFICIENCY,
                    LocusFeatures.GENITALIA_SIZE,
                    LocusFeatures.GENITALIA_TYPE));
        }

        // TODO: check age

        son.arises(father, mother);

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
        //LevelDetail levelDetail = LevelDetail.values()[(int) (Math.random() * LevelDetail.values().length)];
        LevelDetail levelDetail = LevelDetail.FULL;
        String desc = new SimpleTextDescribing(levelDetail).describe(this);
        return levelDetail + ": " + desc + " (" + desc.length() + " chars)"
                    //+ "\n*** Genotype:\n" + getGenotype()
                    //+ "\n*** Phenotype:\n" + getPhenotype()
                    ;
    }

    public AppearanceAge getAppearanceAge() {
        return AppearanceAge.calculateAgeAppearance(getPhenotype()
                .getFeature(LocusFeatures.TENDENCY_TO_AGE).getDoubleValue(), getAgeInSecondCycle());
    }

    public boolean isMale() {
        return getGenotype().getSex() == Sex.MALE;
    }

    public boolean isFemale() {
        return getGenotype().getSex() == Sex.FEMALE;
    }
}

