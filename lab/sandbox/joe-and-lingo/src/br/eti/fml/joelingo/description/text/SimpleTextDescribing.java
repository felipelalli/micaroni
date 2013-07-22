package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.LevelDetail;
import br.eti.fml.joelingo.description.Describing;
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
            String states = describeStates(random, joelingo);
            String appearence = describeAppearence(random, joelingo);

            finalText.append(life);

            if (life.length() > 0 && (states.length() > 0 || appearence.length() > 0)) {
                finalText.append(" e");
            }

            finalText.append(states);

            if (states.length() > 0 && appearence.length() > 0) {
                finalText.append(randomize(random,
                        MessageFormat.format(" E {0}", joelingo.getName()),
                        MessageFormat.format(" E {0}", getPronoum(joelingo))));
            }

            finalText.append(appearence);

            if (life.length() == 0 && states.length() == 0 && appearence.length() == 0) {
                finalText.append(" está normal");
            }
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
            finalText.append(gender(joelingo, " é um bebê", " é uma bebê"));
        } else if (joelingo.getAppearanceAge() == AppearanceAge.CHILD
                && levelDetail.ordinal() >= LevelDetail.NORMAL.ordinal()) {
            finalText.append(gender(joelingo, " é um filhote", " é uma filhote"));
        } else if (joelingo.getAppearanceAge() == AppearanceAge.TEEN
                && levelDetail.ordinal() >= LevelDetail.NORMAL.ordinal()) {
            finalText.append(" é adolescente");
        } else if (joelingo.getAppearanceAge() == AppearanceAge.ADULT && levelDetail == LevelDetail.FULL) {
            finalText.append(gender(joelingo, " é adulto", " é adulta"));
        } else if (joelingo.getAppearanceAge() == AppearanceAge.OLD) {
            finalText.append(" está bem ").append(gender(joelingo, "velhinho", "velhinha"));
        }

        if (levelDetail == LevelDetail.FULL && joelingo.getAgeInSecondCycle() > 1) {
            finalText.append(", tem ");
            finalText.append(age(joelingo.getAgeInSecondCycle()));
            finalText.append(" de vida,");
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
                finalText.append(" está ").append(gender(joelingo, "morto", "morta"));
            } else {
                finalText.append(" morreu com ").append(age(joelingo.getAgeInSecondCycle()));
                finalText.append(" em ").append(DATE_FORMAT.format(joelingo.getDeath()));

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

    private String describeAppearence(Random random, Joelingo joelingo) {
        StringBuilder result = new StringBuilder();
        List<Description> description = new ArrayList<Description>(20);

        description.add(new ConditionalDescription(random, levelDetail, joelingo,
                new Condition(LocusFeatures.EYE_SIZE, Goodness.BAD, 0.0, 0.0, Importance.SEVERE,
                        "não tem olho"),
                new Condition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.0, 0.15, Importance.SEVERE,
                        "tem olhos pequenos"),
                new Condition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.3, 0.5, Importance.LOW,
                        "tem olhos grandes"),
                new Condition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.5, 1.0, Importance.HIGH,
                        "tem olhos gigantes")
        ));

        description.add(new ConditionalDescription(random, levelDetail, joelingo,
                new Condition(LocusFeatures.EYE_EFFICIENCY, Goodness.BAD, 0.0, 0.0, Importance.SEVERE,
                        gender(joelingo, "é cego", "é cega")),
                new Condition(LocusFeatures.EYE_EFFICIENCY, Goodness.BAD, 0.0, 0.3, Importance.HIGH,
                        gender(joelingo, "é quase cego", "é quase cega"),
                        "enxerga muito mal"),
                new Condition(LocusFeatures.EYE_EFFICIENCY, Goodness.GOOD, 0.8, 1.0, Importance.LOW,
                        "enxerga absurdamente bem",
                        "tem uma super visão",
                        "tem uma visão biônica")
        ));

        description.add(new ConditionalDescription(random, levelDetail, joelingo,
                new Condition(LocusFeatures.EYE_GLOW, Goodness.NEUTRAL, 0.3, 0.5, Importance.LOW,
                        "tem os olhos um pouco brilhantes"),
                new Condition(LocusFeatures.EYE_GLOW, Goodness.NEUTRAL, 0.5, 0.8, Importance.LOW,
                        "tem os olhos brilhantes"),
                new Condition(LocusFeatures.EYE_GLOW, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                        "tem os olhos muito brilhantes",
                        "tem os olhos super brilhantes",
                        "tem os olhos brilhantes demais")
        ));

        description.add(new ColorDescription(levelDetail, Importance.HIGH, "tem o olho {0}",
                joelingo.getPhenotype().getFeature(LocusFeatures.EYE_REDDISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.EYE_GREENISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.EYE_BLUISH).getDoubleValue()
        ));

        description.add(new ColorDescription(levelDetail, Importance.LOW, "tem uma pele de couro {0}",
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_REDDISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_GREENISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_BLUISH).getDoubleValue()
        ));

        description.add(new ColorDescription(levelDetail, Importance.HIGH, "tem pêlos {0}",
                joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_REDDISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_GREENISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_BLUISH).getDoubleValue()
        ));

        description.add(new ConditionalDescription(random, levelDetail, joelingo,
                new Condition(LocusFeatures.MUSCLE, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                        "tem fraqueza muscular",
                        gender(joelingo, "é fraco como uma borboleta", "é fraca como uma borboleta"),
                        gender(joelingo, "é totalmente sedentário", "é totalmente sedentária")),
                new Condition(LocusFeatures.MUSCLE, Goodness.GOOD, 0.5, 0.8, Importance.LOW,
                        "é forte",
                        gender(joelingo, "é fortinho", "é fortinha")),
                new Condition(LocusFeatures.MUSCLE, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                        gender(joelingo, "é forte como um touro", "é forte como uma gorila"),
                        "é ridiculamente forte",
                        "é absurdamente forte",
                        "é um trator de forte",
                        gender(joelingo, "é musculoso", "é musculosa"))
        ));

        result.append(split(random, joelingo, levelDetail, description));

        return result.toString();
    }

    private String describeStates(Random random, Joelingo joelingo) {
        StringBuilder result = new StringBuilder();
        List<Description> description = new ArrayList<Description>(20);

        // TODO: if twitter, randomize X descriptions only

        description.add(new ConditionalDescription(random, levelDetail, joelingo,
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

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HAPPINESS, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                            "com depressão",
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

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.BOREDOM_FEELING, Goodness.BAD, 0.8, 1.0, Importance.HIGH,
                            gender(joelingo, "muito entediado", "muito entediada"),
                            "de bode",
                            gender(joelingo, "muito chato", "muito chata"),
                            "com um tédio infernal"),
                    new Condition(LocusFeatures.BOREDOM_FEELING, Goodness.BAD, 0.6, 0.8, Importance.LOW,
                            gender(joelingo, "entediado", "entediada"),
                            gender(joelingo, "chato", "chata"),
                            "com tédio")
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                            "zen",
                            gender(joelingo, "bem calmo", "bem calma"),
                            gender(joelingo, "super tranquilo", "super tranquila")),
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com raiva",
                            gender(joelingo, "raivoso", "raivosa"),
                            gender(joelingo, "irritado", "irritada")),
                    new Condition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "louco de raiva", "louca de raiva"),
                            gender(joelingo, "insanamente raivoso", "insanamente irritada"),
                            "bufando de raiva")
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HUNGER_FEELING, Goodness.GOOD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "totalmente saciado", "totalmente saciada"),
                            gender(joelingo, "lotado de comida", "lotada de comida"),
                            "com a barriga cheia"),
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

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "muito desmotivado", "muito desmotivada"),
                            "muito carente",
                            "totalmente sem forças",
                            "totalmente sem ânimo",
                            gender(joelingo, "muito desanimado", "muito desanimada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.3, 0.4, Importance.LOW,
                            gender(joelingo, "desmotivado", "desmotivada"),
                            "carente",
                            "sem forças",
                            "sem ânimo",
                            gender(joelingo, "desanimado", "desanimada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.6, 0.8, Importance.LOW,
                            gender(joelingo, "animado", "amimada"),
                            gender(joelingo, "empolgado", "empolgada"),
                            gender(joelingo, "motivado", "motivada")),
                    new Condition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                            gender(joelingo, "super animado", "super amimada"),
                            gender(joelingo, "super empolgado", "super empolgada"),
                            gender(joelingo, "muito motivado", "muito motivada"))
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.FEAR, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                            gender(joelingo, "muito corajoso", "muito corajosa"),
                            "sem medo nenhum"),
                    new Condition(LocusFeatures.FEAR, Goodness.BAD, 0.7, 0.8, Importance.LOW,
                            "com medo"),
                    new Condition(LocusFeatures.FEAR, Goodness.BAD, 0.8, 1.0, Importance.HIGH,
                            "com muito medo",
                            "morrendo de medo",
                            gender(joelingo, "apavorado", "apavorada"),
                            "em pânico")
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                            "morrendo de calor",
                            "derretendo de calor",
                            "passando mal de calor",
                            "com muito calor",
                            "sentindo muito calor"),
                    new Condition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.2, 0.4, Importance.HIGH,
                            "com calor",
                            "sentindo calor"),
                    new Condition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com frio",
                            "sentindo frio"),
                    new Condition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            "morrendo de frio",
                            "congelando",
                            "sentindo muito frio",
                            "tremendo de frio",
                            "batendo os dentes de frio")
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.GOOD, 0.8, 1.0, Importance.LOW,
                            "super saudável",
                            "muito saudável"),
                    new Condition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.GOOD, 0.5, 0.8, Importance.LOW,
                            "saudável"),
                    new Condition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.BAD, 0.3, 0.5, Importance.LOW,
                            gender(joelingo, "fisicamente acabado", "fisicamente acabada"),
                            "com a aparência meio acabada",
                            "um pouco doente"),
                    new Condition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.BAD, 0.0, 0.3, Importance.SEVERE,
                            "muito doente",
                            gender(joelingo, "destruído fisicamente", "destruída fisicamente"),
                            gender(joelingo, "debilitado", "debilitada"),
                            gender(joelingo, "fraquinho e de cama", "fraquinha e de cama"),
                            "com a aparência horrível",
                            "com profundas olheiras")
            ));

            description.add(new ConditionalDescription(random, levelDetail, joelingo,
                    new Condition(LocusFeatures.DIRT_LEVEL, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW,
                            gender(joelingo, "super limpo", "super limpa"),
                            gender(joelingo, "limpíssimo", "limpíssima"),
                            gender(joelingo, "brilhante de limpo", "brilhante de limpa"),
                            gender(joelingo, "impecavelmente limpo", "impecavelmente limpa")),
                    new Condition(LocusFeatures.DIRT_LEVEL, Goodness.BAD, 0.7, 0.9, Importance.HIGH,
                            gender(joelingo, "fedido", "fedida"),
                            gender(joelingo, "sujo", "suja")),
                    new Condition(LocusFeatures.DIRT_LEVEL, Goodness.BAD, 0.9, 1.0, Importance.SEVERE,
                            gender(joelingo, "sujismundo", "sujismunda"),
                            gender(joelingo, "muito fedido", "muito fedida"),
                            "cheirando podre",
                            "cheirando esgoto",
                            gender(joelingo, "imundo", "imunda"),
                            gender(joelingo, "sujo e nojento", "suja e nojenta"),
                            gender(joelingo, "completamente sujo", "completamente suja"))
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

            for (Description d : description) {
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
                                        COMMA + " mas", COMMA + " mas", COMMA + " mas", COMMA + " mas",
                                        COMMA + " porém", COMMA + " porém", COMMA + " todavia", COMMA + " só que",
                                        COMMA + " apesar de",
                                        StringUtils.trim(MessageFormat.format(". Porém {0} também {1}",
                                                joelingo.getName(), randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". Mas {0} ainda {1}",
                                                getPronoum(joelingo), randomize(random, introduction)))));
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

                    result.append(" ").append(d.toString());
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

    public static boolean isBetween(Phenotype phenotype, LocusFeatures locusFeatures, double min, double max) {
        double value = phenotype.getFeature(locusFeatures).getDoubleValue();
        return value >= min && value <= max;
    }

    public static String randomize(Random random, String ... what) {
        if (what.length == 0) {
            return "";
        } else {
            return what[random.nextInt(what.length)];
        }
    }

}
