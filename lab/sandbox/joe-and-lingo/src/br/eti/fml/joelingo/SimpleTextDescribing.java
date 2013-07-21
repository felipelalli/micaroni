package br.eti.fml.joelingo;

import br.eti.fml.joelingo.dna.AppearanceAge;
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
    public static final int MAX_WIDTH_TWITTER_SMS = 140;
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
            String life = describeLife(random, joelingo);

            if (life.length() == 0) {
                life += " e";
            }

            finalText.append(life);
            String states = describeStates(random, joelingo);

            if (states.length() == 0) {
                finalText.append(" só.");
            }

            finalText.append(states);
        }

        String text = finalText.toString();
        return levelDetail == LevelDetail.SMS_TWITTER ? StringUtils.abbreviate(text, MAX_WIDTH_TWITTER_SMS) : text;
    }

    private String describeLife(Random random, Joelingo joelingo) {
        StringBuilder finalText = new StringBuilder();

        if (levelDetail == LevelDetail.FULL) {
            finalText.append(" está ");
            finalText.append(randomize(random, gender(joelingo, "vivo", "viva"),
                    gender(joelingo, "vivinho da silva", "vivinha da silva"), "respirando"));
            finalText.append(",");
        }

        if (joelingo.getAppearanceAge() == AppearanceAge.BABY) {
            finalText.append(" é um bebê e");
        } else if (joelingo.getAppearanceAge() == AppearanceAge.CHILD
                && levelDetail.ordinal() >= LevelDetail.NORMAL.ordinal()) {
            finalText.append(" é um filhote e");
        } else if (joelingo.getAppearanceAge() == AppearanceAge.TEEN
                && levelDetail.ordinal() >= LevelDetail.NORMAL.ordinal()) {
            finalText.append(" é adolescente e");
        } else if (joelingo.getAppearanceAge() == AppearanceAge.ADULT && levelDetail == LevelDetail.FULL) {
            finalText.append(" é adulto e");
        } else if (joelingo.getAppearanceAge() == AppearanceAge.OLD) {
            finalText.append(" está bem " + gender(joelingo, "velhinho", "velhinha") + " e");
        }

        if (levelDetail == LevelDetail.FULL && joelingo.getAgeInSecondCycle() > 1) {
            finalText.append(" tem ");
            finalText.append(age(joelingo.getAgeInSecondCycle()));
            finalText.append(" de vida. E " + getPronoum(joelingo));
        }

        return finalText.toString();
    }

    private String age(long seconds) {
        String result = "";

        if (seconds < 60L) {
            result += plural("%d %s", seconds, "segundo", "segundos");
        } else if (seconds < (60L * 60L)) {
            result += plural("%d %s", seconds / 60L, "minuto", "minutos");
        } else if (seconds < (60L * 60L * 24L)) {
            result += plural("%d %s", seconds / (60L * 60L), "hora", "horas");
        } else if (seconds < (60L * 60L * 24L * 30L)) {
            result += plural("%d %s", seconds / (60L * 60L * 24L), "dia", "dias");
        } else if (seconds < (60L * 60L * 24L * 365L)) {
            result += plural("%d %s", seconds / (60L * 60L * 24L * 30L), "mês", "meses");
        } else {
            result += plural("%d %s", (seconds / (60L * 60L * 24L * 30L * 365L)) + 1, "ano", "anos");
        }

        return result;
    }

    private <T extends Number> String plural(String format, T value, String singular, String plural) {
        long v = Math.abs(Math.round(value.doubleValue()));
        return String.format(format, value, v < 2 ? singular : plural);
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

            if (levelDetail == LevelDetail.SMS_TWITTER) {
                finalText.append(" está " + gender(joelingo, "morto", "morta"));
            } else {
                finalText.append(" morreu com " + age(joelingo.getAgeInSecondCycle()));

                finalText.append(" em " + DATE_FORMAT.format(joelingo.getDeath()));

                switch (joelingo.getDeathReason()) {
                    case NOT_BORN:
                        finalText.append(" porque ainda não nasceu");
                        break;
                    case SUDDEN_UNEXPLAINED_DEATH:
                        finalText.append(" de morte súbita");
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
                new Condition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW,
                        gender(joelingo, "bem acordado", "bem acordada"),
                        gender(joelingo, "ligadão", "ligadona"),
                        gender(joelingo, "acordadão", "acordadona")),
                new Condition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.3, 0.5, Importance.LOW,
                        gender(joelingo, "acordado", "acordada"),
                        "de olho aberto"),
                new Condition(LocusFeatures.SLEEPY, Goodness.BAD, 0.5, 0.8, Importance.HIGH,
                        "com muito sono", gender(joelingo, "sonolento", "sonolenta"), "caindo de sono"),
                new Condition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.8, 1.0, Importance.SEVERE, "dormindo", "cochilando")
        ));

        if (joelingo.getPhenotype().getFeature(LocusFeatures.SLEEPY).getDoubleValue() < 0.8) {
            // do not describe others emotional states if is sleeping

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HAPPINESS, Goodness.BAD, 0.0, 0.2, Importance.SEVERE, "com depressão",
                            gender(joelingo, "deprimido", "deprimida"),
                            "muito triste",
                            gender(joelingo, "acabado emocionalmente", "acabada emocionalmente")),
                    new Condition(LocusFeatures.HAPPINESS, Goodness.BAD, 0.2, 0.4, Importance.HIGH,
                            "triste",
                            gender(joelingo, "tristinho", "tristinha"),
                            gender(joelingo, "chateado", "chateada"),
                            gender(joelingo, "cabisbaixo", "cabisbaixa")),
                    new Condition(LocusFeatures.HAPPINESS, Goodness.GOOD, 0.4, 0.7, Importance.LOW, "feliz", "alegre", "contente"),
                    new Condition(LocusFeatures.HAPPINESS, Goodness.GOOD, 0.7, 1.0, Importance.HIGH,
                            "muito feliz", "radiante", "ultra feliz",  gender(joelingo, "felicíssimo", "felicíssima"),
                            "muito alegre", "muito contente")
            ));

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                            "zen",
                            gender(joelingo, "bem calmo", "bem calma"),
                            gender(joelingo, "super tranquilo", "super tranquila")),
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.GOOD, 0.2, 0.6, Importance.LOW,
                            gender(joelingo, "calmo", "calma"),
                            gender(joelingo, "tranquilo", "tranquila")),
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com raiva",
                            gender(joelingo, "raivoso", "raivosa"),
                            gender(joelingo, "irritado", "irritada")),
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "louco de raiva", "louca de raiva"),
                            gender(joelingo, "insanamente raivoso", "insanamente irritada"),
                            "bufando de raiva")
            ));

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HUNGER_FEELING, Goodness.GOOD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "totalmente cheio", "totalmente cheia"),
                            gender(joelingo, "lotado de comida", "lotada de comida"),
                            gender(joelingo, "super satisfeito", "super satisfeita")),
                    new Condition(LocusFeatures.HUNGER_FEELING, Goodness.GOOD, 0.3, 0.6, Importance.LOW,
                            "sem fome"),
                    new Condition(LocusFeatures.HUNGER_FEELING, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com fome",
                            gender(joelingo, "faminto", "faminta"),
                            "barriga roncando"),
                    new Condition(LocusFeatures.HUNGER_FEELING, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "morto de fome", "morta de fome"),
                            gender(joelingo, "desnutrido", "desnutrida"),
                            "morrendo de fome", "azul de fome")
            ));

            description.add(new Description(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "muito desmotivado", "muito desmotivada"),
                            "muito carente",
                            "totalmente sem forças",
                            "totalmente sem ânimo",
                            gender(joelingo, "muito desanimado", "muito desanimada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.3, 0.5, Importance.LOW,
                            gender(joelingo, "desmotivado", "desmotivada"),
                            "carente",
                            "sem forças",
                            "sem ânimo",
                            gender(joelingo, "desanimado", "desanimada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.5, 0.8, Importance.LOW,
                            gender(joelingo, "animado", "amimada"),
                            gender(joelingo, "empolgado", "empolgada"),
                            gender(joelingo, "motivado", "motivada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                            gender(joelingo, "super animado", "super amimada"),
                            gender(joelingo, "super empolgado", "super empolgada"),
                            gender(joelingo, "muito motivado", "muito motivada"))
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
            Description before = null;

            for (int i = 0; i < description.size(); i++) {
                Description d = description.get(i);

                if (d.isRelevant()) {
                    if (before != null && before.isRelevant()) {
                        boolean opposite = d.getGoodness() == Goodness.BAD && before.getGoodness() == Goodness.GOOD
                                        || d.getGoodness() == Goodness.GOOD && before.getGoodness() == Goodness.BAD;

                        if (levelDetail == LevelDetail.SMS_TWITTER) {
                            if (opposite) {
                                result.append(COMMA).append(" mas");
                            } else {
                                result.append(COMMA);
                            }
                        } else {
                            if (opposite) {
                                result.append(randomize(random,
                                        COMMA + " mas", COMMA + " mas", COMMA + " mas", COMMA + " mas",
                                        COMMA + " porém", COMMA + " porém", COMMA + " todavia", COMMA + " só que",
                                        COMMA + " apesar de"));
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

                    result.append(" ")
                          .append(d.toString());

                    before = d;
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

    enum Goodness {
        GOOD, BAD, NEUTRAL
    }

    class Condition {
        private final LocusFeatures locusFeatures;
        private final Goodness goodness;
        private final double min;
        private final double max;
        private final Importance importance;
        private final String[] description;

        Condition(LocusFeatures locusFeatures, Goodness goodness,
                  double min, double max, Importance importance, String... description) {

            this.locusFeatures = locusFeatures;
            this.goodness = goodness;
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

        public Goodness getGoodness() {
            Phenotype phenotype = joelingo.getPhenotype();
            Goodness goodness = Goodness.NEUTRAL;

            for (Condition condition : conditions) {
                if (isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
                    goodness = condition.goodness;
                    break;
                }
            }

            return goodness;
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
