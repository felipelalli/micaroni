package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import org.apache.commons.lang3.StringUtils;

import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
@SuppressWarnings("SpellCheckingInspection")
public class SimpleTextDescribing extends Describing<String> {
    public static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("d MMM, yyyy");
    public static final String COMMA = ",";
    public static final String FINAL_POINT = ".";
    private final LevelDetail levelDetail;

    public SimpleTextDescribing(LevelDetail levelDetail) {
        this.levelDetail = levelDetail;
    }

    @Override
    public String describe(Random random, Joelingo joelingo) {
        StringBuilder finalText = new StringBuilder();

        finalText.append(joelingo.getName());

        if (levelDetail.ordinal() > LevelDetail.SMS_TWITTER.ordinal()) {
            finalText.append(" ").append(joelingo.getLastName());
        }

        if (!describeDeath(joelingo, finalText)) {
            if (levelDetail == LevelDetail.FULL) {
                finalText.append(" está ");
                finalText.append(randomize(random, gender(joelingo, "vivo", "viva"),
                        gender(joelingo, "vivinho da silva", "vivinha da silva"), "respirando"));
                finalText.append(",");
            }

            if (levelDetail == LevelDetail.FULL) {
                finalText.append(" tem ");
                finalText.append(joelingo.getAgeInSecondCycle());
                finalText.append(" segundos de vida e");
            } else if (levelDetail == LevelDetail.NORMAL) {
                if (joelingo.getAgeInSecondCycle() < 10) {
                    finalText.append(" acabou de nascer e");
                } else if (joelingo.getAgeInSecondCycle() > 20) {
                    finalText.append(" está bem " + gender(joelingo, "novinho", "novinha") + " e");
                } else if (joelingo.getAgeInSecondCycle() > 40) { // TODO fix value
                    finalText.append(" está bem " + gender(joelingo, "velhinho", "velhinha") + " e");
                }
            } else if (levelDetail == LevelDetail.SMS_TWITTER) {
                if (joelingo.getAgeInSecondCycle() > 40) { // TODO fix value - Randomize if will show it
                    finalText.append(" está bem " + gender(joelingo, "velhinho", "velhinha") + " e");
                }
            }

            // TODO: age

            finalText.append(describeStates(random, joelingo));
        }

        return finalText.toString();
    }

    private boolean describeDeath(Joelingo joelingo, StringBuilder finalText) {
        boolean dead;
        Phenotype phenotype = joelingo.getPhenotype();

        if (!joelingo.isBorn()) {
            dead = true;

            if (phenotype.getFeature(LocusFeatures.IN_EGG).getDoubleValue() > .5) {
                finalText.append(" está dentro de um ovo");
            } else {
                finalText.append(" não nasceu ainda");
            }

            finalText.append(FINAL_POINT);
        } else if (joelingo.isDead()) {
            dead = true;
            finalText.append(" está " + gender(joelingo, "morto", "morta"));

            if (levelDetail.ordinal() > LevelDetail.SMS_TWITTER.ordinal()) {
                finalText.append(" desde " + DATE_FORMAT.format(joelingo.getDeath())); // TODO: say the age

                switch (joelingo.getDeathReason()) {
                    case NOT_BORN:
                        finalText.append(" porque ainda não nasceu");
                        break;
                    case SUDDEN_UNEXPLAINED_DEATH:
                        finalText.append(" porque teve uma morte súbita");
                        break;
                }
            }

            finalText.append(FINAL_POINT);
        } else {
            dead = false;
        }

        return dead;
    }

    private String describeStates(Random random, Joelingo joelingo) {
        StringBuilder result = new StringBuilder();

        List<Description> description = new ArrayList<Description>(100);

        // TODO: if twitter, randomize X descriptions only

        description.add(new Description(random, levelDetail, joelingo,
                new Condition(LocusFeatures.SLEEPY, 0.0, 0.3, Importance.LOW,
                        gender(joelingo, "bem acordado", "bem acordada"),
                        gender(joelingo, "ligadão", "ligadona"),
                        gender(joelingo, "acordadão", "acordadona")),
                new Condition(LocusFeatures.SLEEPY, 0.3, 0.5, Importance.LOW,
                        gender(joelingo, "acordado", "acordada"),
                        "de olho aberto"),
                new Condition(LocusFeatures.SLEEPY, 0.5, 0.8, Importance.HIGH,
                        "com muito sono", gender(joelingo, "sonolento", "sonolenta"), "caindo de sono"),
                new Condition(LocusFeatures.SLEEPY, 0.8, 1.0, Importance.SEVERE, "dormindo", "num sono profundo")
        ));

        if (joelingo.getPhenotype().getFeature(LocusFeatures.SLEEPY).getDoubleValue() < 0.8) {
            // do not describe others emotional states if is sleeping

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HAPPINESS, 0.0, 0.3, Importance.SEVERE, "com depressão",
                            gender(joelingo, "deprimido", "deprimida"),
                            "muito triste",
                            gender(joelingo, "acabado emocionalmente", "acabada emocionalmente")),
                    new Condition(LocusFeatures.HAPPINESS, 0.3, 0.5, Importance.HIGH,
                            "triste",
                            gender(joelingo, "tristinho", "tristinha"),
                            gender(joelingo, "chateado", "chateada"),
                            gender(joelingo, "cabisbaixo", "cabisbaixa")),
                    new Condition(LocusFeatures.HAPPINESS, 0.5, 0.7, Importance.LOW, "feliz", "alegre", "contente"),
                    new Condition(LocusFeatures.HAPPINESS, 0.7, 1.0, Importance.HIGH,
                            "muito feliz", "radiante", "ultra feliz",  gender(joelingo, "felicíssimo", "felicíssima"),
                            "muito alegre", "muito contente")
            ));

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.ANGER_FEELING, 0.0, 0.2, Importance.LOW, "zen",
                            gender(joelingo, "bem calmo", "bem calma"),
                            gender(joelingo, "super tranquilo", "super tranquila")),
                    new Condition(LocusFeatures.ANGER_FEELING, 0.2, 0.6, Importance.LOW,
                            gender(joelingo, "calmo", "calma"),
                            gender(joelingo, "tranquilo", "tranquila")),
                    new Condition(LocusFeatures.ANGER_FEELING, 0.6, 0.8, Importance.HIGH,
                            "com raiva",
                            gender(joelingo, "raivoso", "raivosa"),
                            gender(joelingo, "irritado", "irritada")),
                    new Condition(LocusFeatures.ANGER_FEELING, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "louco de raiva", "louca de raiva"),
                            gender(joelingo, "insanamente raivoso", "insanamente irritada"),
                            gender(joelingo, "bufando de raiva", "com TPM a mil"))
            ));
        }

        if (!isAllEmpty(description)) {
            result.append(" ");
        }

        result.append(split(random, joelingo, levelDetail, description, "está", "parece estar"));

        return result.toString();
    }

    private String gender(Joelingo joelingo, String male, String female) {
        return joelingo.getGenotype().getSex() == Sex.MALE ? male : female;
    }

    private String split(Random random, Joelingo joelingo, LevelDetail levelDetail,
                         List<Description> description, String ... introduction) {

        StringBuilder result = new StringBuilder();

        if (!isAllEmpty(description)) {
            result.append(randomize(random, introduction));

            for (int i = 0; i < description.size(); i++) {
                Description d = description.get(i);

                if (d.isRelevant()) {
                    result.append(" ")
                          .append(d.toString());

                    if (!isAllEmpty(description, i + 1)) {
                        if (levelDetail == LevelDetail.SMS_TWITTER) {
                            result.append(COMMA);
                        } else {
                            result.append(randomize(random,
                                    COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA,
                                    COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA, COMMA,
                                    StringUtils.trim(MessageFormat.format(". E {0} também {1}",
                                            joelingo.getName(), randomize(random, introduction))),
                                    StringUtils.trim(MessageFormat.format(". E {0}", randomize(random, introduction))),
                                    StringUtils.trim(MessageFormat.format(". E {0} ainda {1}", joelingo.getName(),
                                            randomize(random, introduction))),
                                    StringUtils.trim(MessageFormat.format(". {0} {1}",
                                            StringUtils.capitalize(getPronoum(joelingo)), randomize(random, introduction)))
                            ));
                        }
                    }
                }
            }

            result.append(FINAL_POINT);
        }

        return result.toString();
    }

    private String getPronoum(Joelingo joelingo) {
        String pronoum;

        if (joelingo.getGenotype().getSex() == Sex.FEMALE) {
            pronoum = "ela";
        } else {
            pronoum = "ele";
        }

        return pronoum;
    }

    private boolean isAllEmpty(List<Description> description) {
        return isAllEmpty(description, 0);
    }

    private boolean isAllEmpty(List<Description> description, int start) {
        boolean isEmpty = true;

        for (int i = start; i < description.size(); i++) {
            Description d = description.get(i);
            if (d.isRelevant()) {
                isEmpty = false;
                break;
            }
        }

        return isEmpty;
    }

    private boolean isBetween(Phenotype phenotype, LocusFeatures locusFeatures, double min, double max) {
        double value = phenotype.getFeature(locusFeatures).getDoubleValue();
        return value >= min && value <= max;
    }

    private String randomize(Random random, String ... what) {
        if (what.length == 0) {
            return "";
        } else {
            return what[random.nextInt(what.length)];
        }
    }

    enum Importance {
        SEVERE, HIGH, LOW
    }

    class Condition {
        private final LocusFeatures locusFeatures;
        private final double min;
        private final double max;
        private final Importance importance;
        private final String[] description;

        Condition(LocusFeatures locusFeatures, double min, double max, Importance importance, String... description) {
            this.locusFeatures = locusFeatures;
            this.min = min;
            this.max = max;
            this.importance = importance;
            this.description = description;
        }
    }

    class Description {
        private final Random random;
        private final LevelDetail levelDetail;
        private final Joelingo joelingo;
        private final Condition[] conditions;

        Description(Random random, LevelDetail levelDetail, Joelingo joelingo, Condition... conditions) {
            this.random = random;
            this.levelDetail = levelDetail;
            this.joelingo = joelingo;
            this.conditions = conditions;
        }

        public boolean isRelevant() {
            Phenotype phenotype = joelingo.getPhenotype();
            boolean relevant = false;

            for (Condition condition : conditions) {
                if (isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
                    if (condition.importance == Importance.SEVERE) {
                        relevant = true;
                    } else if (condition.importance == Importance.HIGH && levelDetail.ordinal() > LevelDetail.SMS_TWITTER.ordinal()) {
                        relevant = true;
                    } else if (levelDetail == LevelDetail.FULL) {
                        relevant = true;
                    }

                    break;
                }
            }

            return relevant;
        }

        @Override
        public String toString() {
            String result = "";
            Phenotype phenotype = joelingo.getPhenotype();

            for (Condition condition : conditions) {
                if (isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
                    result = randomize(random, condition.description);
                    break;
                }
            }

            return result;
        }
    }
}
