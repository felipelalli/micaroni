package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.LevelDetail;
import br.eti.fml.joelingo.description.Describing;
import br.eti.fml.joelingo.dna.AppearanceAge;
import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.Sex;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import org.apache.commons.lang3.StringUtils;

import java.security.SecureRandom;
import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
@SuppressWarnings("SpellCheckingInspection")
public class SimpleTextDescribing extends Describing<String> {
    public static final Random RANDOM = new SecureRandom();

    public static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("d MMM, yyyy");
    public static final String COMMA = ",";
    public static final String FINAL_POINT = ".";
    public static final int MAX_WIDTH_TWITTER_SMS = 140;
    private final LevelDetail levelDetail;

    public SimpleTextDescribing(LevelDetail levelDetail) {
        this.levelDetail = levelDetail;
    }

    @Override
    public String describe(Joelingo joelingo) {
        Random random = RANDOM;
        StringBuilder finalText = new StringBuilder();

        if (levelDetail == LevelDetail.SMS_TWITTER && joelingo.getName().size() > 9) {
            finalText.append(joelingo.getName().getFirstSyllable());
        } else {
            finalText.append(joelingo.getName());
        }

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
                        MessageFormat.format(". — E {0}", joelingo.getName()),
                        MessageFormat.format(". — E {0}", getPronoum(joelingo))));
            }

            finalText.append(appearence);

            if (life.length() == 0 && states.length() == 0 && appearence.length() == 0) {
                finalText.append(" está normal");
            }
        }

        if (finalText.length() > 0) {
            finalText.append(FINAL_POINT);
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
            finalText.append(gender(joelingo, " é um filhotinho recém nascido", " é uma filhotinha recém nascida"));
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

        } else {
            dead = false;
        }

        return dead;
    }

    private String describeAppearence(Random random, Joelingo joelingo) {
        StringBuilder result = new StringBuilder();

        DescriptionGroup is = new DescriptionGroup(random, joelingo, levelDetail, "é");

        is.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.MUSCLE, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                        gender(joelingo, "absurdamente fraco", "absurdamente fraca"),
                        gender(joelingo, "fraco como uma borboleta", "fraca como uma borboleta"),
                        gender(joelingo, "muito fraquinho", "muito fraquinha")),
                new IntervalCondition(LocusFeatures.MUSCLE, Goodness.GOOD, 0.5, 0.8, Importance.LOW,
                        "forte",
                        gender(joelingo, "fortinho", "fortinha")),
                new IntervalCondition(LocusFeatures.MUSCLE, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                        gender(joelingo, "forte como um touro", "forte como uma gorila"),
                        "ridiculamente forte",
                        "absurdamente forte",
                        "um trator de tão forte",
                        gender(joelingo, "musculoso", "musculosa"))
        ));

        // if isn't strong, so it can be fat
        if (joelingo.getPhenotype().getFeature(LocusFeatures.MUSCLE).getDoubleValue() < 0.5) {
            is.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.BODY_FAT, Goodness.NEUTRAL, 0.5, 0.6, Importance.LOW,
                            gender(joelingo, "gordinho", "gordinha"),
                            gender(joelingo, "fofinho", "fofinha")),
                    new IntervalCondition(LocusFeatures.BODY_FAT, Goodness.NEUTRAL, 0.6, 0.7, Importance.HIGH,
                            gender(joelingo, "gordo", "gorda"),
                            gender(joelingo, "obeso", "obesa")),
                    new IntervalCondition(LocusFeatures.BODY_FAT, Goodness.BAD, 0.7, 1.0, Importance.SEVERE,
                            gender(joelingo, "absurdamente gordo", "absurdamente gorda"),
                            gender(joelingo, "muito gordo", "muito gorda"),
                            gender(joelingo, "muito pesado", "muito pesada"))
            ));
        }

        is.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.BODY_FAT, Goodness.BAD, 0.0, 0.1, Importance.HIGH,
                        gender(joelingo, "muito magro", "muito magra"),
                        gender(joelingo, "magro demais", "magra demais")),
                new IntervalCondition(LocusFeatures.BODY_FAT, Goodness.NEUTRAL, 0.1, 0.2, Importance.LOW,
                        gender(joelingo, "magro", "magra"))
        ));

        if (!is.isIrrelevant()) {
            result.append(", ").append(is.split());
        }

        DescriptionGroup eyes1 = new DescriptionGroup(random, joelingo, levelDetail);

        eyes1.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.BAD, 0.0, 0.0, Importance.SEVERE,
                        "não tem olho"),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.HIGH,
                        "tem olhos pequenos"),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.GOOD, 0.4, 0.6, Importance.LOW,
                        "tem olhos grandes"),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.GOOD, 0.6, 1.0, Importance.HIGH,
                        "tem olhos gigantes")
        ));

        eyes1.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new OrCondition(new IntervalCondition(LocusFeatures.EYE_EFFICIENCY, Goodness.BAD, 0.0, 0.0, Importance.SEVERE),
                                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.BAD, 0.0, 0.0, Importance.SEVERE),
                        gender(joelingo, "é cego", "é cega")),
                new IntervalCondition(LocusFeatures.EYE_EFFICIENCY, Goodness.BAD, 0.0, 0.3, Importance.HIGH,
                        gender(joelingo, "é quase cego", "é quase cega"),
                        "enxerga muito mal"),
                new IntervalCondition(LocusFeatures.EYE_EFFICIENCY, Goodness.GOOD, 0.8, 1.0, Importance.LOW,
                        "enxerga absurdamente bem",
                        "com uma super visão",
                        "com uma visão biônica")
        ));

        if (!eyes1.isIrrelevant()) {
            result.append(", ").append(eyes1.split());
        }

        if (joelingo.getPhenotype().getFeature(LocusFeatures.EYE_SIZE).getDoubleValue() > 0.0) {
            DescriptionGroup eyes2 = new DescriptionGroup(random, joelingo, levelDetail, "tem os olhos", "possui olhos");

            eyes2.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.EYE_GLOW, Goodness.NEUTRAL, 0.3, 0.5, Importance.LOW,
                            "um pouco brilhantes"),
                    new IntervalCondition(LocusFeatures.EYE_GLOW, Goodness.NEUTRAL, 0.5, 0.8, Importance.LOW,
                            "brilhantes"),
                    new IntervalCondition(LocusFeatures.EYE_GLOW, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                            "muito brilhantes",
                            "super brilhantes",
                            "brilhantes demais")
            ));

            eyes2.add(new ColorDescription(levelDetail, Importance.HIGH, randomize(random, "bem {0}", "{0}"),
                    joelingo.getPhenotype().getFeature(LocusFeatures.EYE_REDDISH).getDoubleValue(),
                    joelingo.getPhenotype().getFeature(LocusFeatures.EYE_GREENISH).getDoubleValue(),
                    joelingo.getPhenotype().getFeature(LocusFeatures.EYE_BLUISH).getDoubleValue()
            ));

            if (!eyes2.isIrrelevant()) {
                result.append(", ").append(eyes2.split());
            }

            DescriptionGroup eyelashes = new DescriptionGroup(random, joelingo, levelDetail);

            eyelashes.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.EYELASHES_SIZE, Goodness.BAD, 0.0, 0.01, Importance.HIGH,
                            "não tem cílios", "sem cílios"),
                    new IntervalCondition(LocusFeatures.EYELASHES_SIZE, Goodness.NEUTRAL, 0.01, 0.2, Importance.LOW,
                            "cílios bem pequenos",
                            "cílios curtos",
                            "cílios curtinhos"),
                    new IntervalCondition(LocusFeatures.EYELASHES_SIZE, Goodness.NEUTRAL, 0.4, 0.7, Importance.LOW,
                            "cílios grandes",
                            "cílios longos"),
                    new IntervalCondition(LocusFeatures.EYELASHES_SIZE, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                            "cílios enormes",
                            "cílios muito longos",
                            "cílios compridos")
            ));

            if (!eyelashes.isIrrelevant()) {
                result.append(", ").append(eyelashes.split());
            }

            DescriptionGroup eyebrow = new DescriptionGroup(random, joelingo, levelDetail);

            eyebrow.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.EYEBROW_SIZE, Goodness.BAD, 0.0, 0.01, Importance.HIGH,
                            "não tem sobrancelhas", "sem sobrancelhas"),
                    new IntervalCondition(LocusFeatures.EYEBROW_SIZE, Goodness.NEUTRAL, 0.01, 0.2, Importance.LOW,
                            "sobrancelhas bem pequenas",
                            "sobrancelhas pequenas"),
                    new IntervalCondition(LocusFeatures.EYEBROW_SIZE, Goodness.NEUTRAL, 0.7, 0.9, Importance.LOW,
                            "monocelha"),
                    new IntervalCondition(LocusFeatures.EYEBROW_SIZE, Goodness.NEUTRAL, 0.9, 1.0, Importance.HIGH,
                            "monocelha enorme",
                            "monocelha gigante",
                            "tem uma monocelha tão grande como uma taturana")
            ));

            if (!eyebrow.isIrrelevant()) {
                result.append(", ").append(eyebrow.split());
            }
        }

        DescriptionGroup ear = new DescriptionGroup(random, joelingo, levelDetail);

        ear.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.BAD, 0.0, 0.0, Importance.SEVERE,
                        "não tem orelha"),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                        "tem orelhas pequenas"),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.NEUTRAL, 0.4, 0.6, Importance.LOW,
                        "tem orelhas grandes",
                        gender(joelingo, "é orelhudo", "é orelhuda")),
                new IntervalCondition(LocusFeatures.EYE_SIZE, Goodness.GOOD, 0.6, 1.0, Importance.LOW,
                        "tem orelhas muito grandes",
                        "tem orelhas bem longas",
                        "tem um orelhão",
                        gender(joelingo, "é muito orelhudo", "é muito orelhuda"))
        ));

        ear.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.HEARING_ACCURACY, Goodness.BAD, 0.0, 0.1, Importance.SEVERE,
                        gender(joelingo, "é surdo", "é surda"),
                        "não pode ouvir nada",
                        "é incapaz de ouvir"),
                new IntervalCondition(LocusFeatures.HEARING_ACCURACY, Goodness.BAD, 0.1, 0.5, Importance.HIGH,
                        gender(joelingo, "é quase surdo", "é quase surda"),
                        "tem dificuldade pra ouvir",
                        "tem problema de audição",
                        "ouve muito mal",
                        "ouve mal"),
                new IntervalCondition(LocusFeatures.HEARING_ACCURACY, Goodness.GOOD, 0.5, 0.7, Importance.LOW,
                        "ouve normalmente",
                        "tem a audição perfeita"),
                new IntervalCondition(LocusFeatures.EYE_EFFICIENCY, Goodness.GOOD, 0.7, 1.0, Importance.HIGH,
                        "ouve absurdamente bem",
                        "tem uma super audição",
                        "com uma adição ultra-sensível")
        ));

        if (!ear.isIrrelevant()) {
            result.append(", ").append(ear.split());
        }

        DescriptionGroup skin = new DescriptionGroup(random, joelingo, levelDetail,
                "tem uma pele de couro", "possui uma pele de couro", "com uma pele de couro");

        skin.add(new ColorDescription(levelDetail, Importance.LOW, "{0}",
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_REDDISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_GREENISH).getDoubleValue(),
                joelingo.getPhenotype().getFeature(LocusFeatures.SKIN_BLUISH).getDoubleValue()
        ));

        skin.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.SKIN_ROUGHNESS, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW,
                        "bem macia",
                        "fofinha"),
                new IntervalCondition(LocusFeatures.SKIN_ROUGHNESS, Goodness.NEUTRAL, 0.3, 0.4, Importance.LOW,
                        "macia"),
                new IntervalCondition(LocusFeatures.SKIN_ROUGHNESS, Goodness.NEUTRAL, 0.7, 1.0, Importance.LOW,
                        "áspera",
                        "dura",
                        "grosseira",
                        "rugosa")
        ));

        if (!skin.isIrrelevant()) {
            result.append(", ").append(skin.split());
        }

        DescriptionGroup bristle1 = new DescriptionGroup(random, joelingo, levelDetail);

        bristle1.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.0, 0.0, Importance.HIGH,
                        gender(joelingo,
                                "é totalmente liso, sem pêlos",
                                "é totalmente lisa, sem pêlos"),
                                "sem pêlo nenhum",
                                "não tem pêlo nenhum"),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                        gender(joelingo, "coberto de pêlos bem curtos", "coberta de pêlos bem curtos"),
                        "com pêlos curtinhos"),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.2, 0.4, Importance.LOW,
                        gender(joelingo, "coberto de pêlos", "coberta de pêlos"),
                        "com pêlos",
                        gender(joelingo, "peludo", "peluda")),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.4, 0.7, Importance.LOW,
                        gender(joelingo, "coberto de pêlos grandes", "coberta de pêlos grandes"),
                        gender(joelingo, "bem peludo", "bem peluda"),
                        "com bastante pêlos",
                        "com muitos pêlos"),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                        gender(joelingo, "coberto de pêlos grandes", "coberta de pêlos grandes"),
                        gender(joelingo, "bem peludo", "bem peluda"),
                        "com pêlos tão longos que arrastam no chão",
                        gender(joelingo, "muito peludo, cheio de pêlos", "muito peluda, cheia de pêlos"))
        ));

        if (!bristle1.isIrrelevant()) {
            result.append(", ").append(bristle1.split());
        }

        if (joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_SIZE).getDoubleValue() > 0.0) {
            DescriptionGroup bristle2 = new DescriptionGroup(random, joelingo, levelDetail, "possui os pêlos");

            bristle2.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.BRISTLE_SMOOTHNESS, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                            "bem macios",
                            "muito fofos",
                            gender(joelingo, "super fofão", "super fofona")),
                    new IntervalCondition(LocusFeatures.SKIN_ROUGHNESS, Goodness.NEUTRAL, 0.3, 0.4, Importance.LOW,
                            "macios",
                            "macios"),
                    new IntervalCondition(LocusFeatures.SKIN_ROUGHNESS, Goodness.NEUTRAL, 0.7, 1.0, Importance.LOW,
                            "ásperos",
                            "duros",
                            "grosseiros")
            ));

            bristle2.add(new ColorDescription(levelDetail, Importance.HIGH, "{0}",
                    joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_REDDISH).getDoubleValue(),
                    joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_GREENISH).getDoubleValue(),
                    joelingo.getPhenotype().getFeature(LocusFeatures.BRISTLE_BLUISH).getDoubleValue()));

            if (!bristle2.isIrrelevant()) {
                result.append(", ").append(bristle2.split());
            }
        }

        DescriptionGroup hair1 = new DescriptionGroup(random, joelingo, levelDetail);

        hair1.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new OrCondition(new IntervalCondition(LocusFeatures.HAIR_VOLUME, Goodness.BAD, 0.0, 0.0, Importance.HIGH),
                                new IntervalCondition(LocusFeatures.HAIR_SIZE, Goodness.BAD, 0.0, 0.0, Importance.HIGH),
                        "careca",
                        "sem cabelo"),
                new IntervalCondition(LocusFeatures.HAIR_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                        "tem cabelo curto"),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.4, 0.7, Importance.LOW,
                        "tem cabelo grande",
                        "tem cabelo longo"),
                new IntervalCondition(LocusFeatures.BRISTLE_SIZE, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                        "com cabelos muito longos")
        ));

        if (!hair1.isIrrelevant()) {
            result.append(", ").append(hair1.split());
        }

        if (joelingo.getPhenotype().getFeature(LocusFeatures.HAIR_SIZE).getDoubleValue() > 0.0
                && joelingo.getPhenotype().getFeature(LocusFeatures.HAIR_VOLUME).getDoubleValue() > 0.0) {

            DescriptionGroup hair2 = new DescriptionGroup(random, joelingo, levelDetail, "tem cabelos");

            hair2.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.HAIR_STRAIGHTNESS, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                            "muito lisos",
                            "super lisos"),
                    new IntervalCondition(LocusFeatures.HAIR_STRAIGHTNESS, Goodness.NEUTRAL, 0.5, 0.7, Importance.LOW,
                            "lisos"),
                    new IntervalCondition(LocusFeatures.HAIR_STRAIGHTNESS, Goodness.NEUTRAL, 0.0, 0.5, Importance.HIGH,
                            "crespos",
                            "enroladinhos")
            ));

            hair2.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.HAIR_VOLUME, Goodness.NEUTRAL, 0.0, 0.3, Importance.HIGH,
                            "muito ralinhos",
                            "super ralos",
                            "com pouco volume",
                            "meio espaçado"),
                    new IntervalCondition(LocusFeatures.HAIR_VOLUME, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                            "bastante volumosos",
                            joelingo.getPhenotype().getFeature(LocusFeatures.HAIR_STRAIGHTNESS).getDoubleValue() < 0.5
                                    ? "tipo black power" : "bastante armados")
            ));

            if (!hair2.isIrrelevant()) {
                result.append(", ").append(hair2.split());
            }
        }

        DescriptionGroup has = new DescriptionGroup(random, joelingo, levelDetail, "tem", "tem", "possui");

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.WINGS_SIZE, Goodness.GOOD, 0.01, 0.2, Importance.HIGH,
                        "uma asinha",
                        "uma asa pequena",
                        "um belo par de asinhas"),
                new IntervalCondition(LocusFeatures.WINGS_SIZE, Goodness.GOOD, 0.2, 0.5, Importance.HIGH,
                        "uma bela asa",
                        "uma asa muito show",
                        "uma asa linda"),
                new IntervalCondition(LocusFeatures.WINGS_SIZE, Goodness.GOOD, 0.5, 1.0, Importance.HIGH,
                        "uma asa enorme, magnífica",
                        "uma asa ridiculamente linda",
                        "um tremendo par de asas")
        ));

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new NotCondition(new IntervalCondition(LocusFeatures.FINS_SIZE, Goodness.NEUTRAL,
                        0.0, 0.0, Importance.LOW), "nadadeiras"))
        );

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new NotCondition(new IntervalCondition(LocusFeatures.THORNS_SIZE, Goodness.NEUTRAL,
                        0.0, 0.0, Importance.LOW), "espinhos"))
        );

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.TAIL_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                        "um rabinho bem pequeno"),
                new IntervalCondition(LocusFeatures.TAIL_SIZE, Goodness.NEUTRAL, 0.6, 0.7, Importance.LOW,
                        "um rabo longo",
                        "um rabão"),
                new IntervalCondition(LocusFeatures.TAIL_SIZE, Goodness.NEUTRAL, 0.7, 1.0, Importance.HIGH,
                        "um rabo muito, mas muito comprido",
                        "um rabo gigantesco, muito longo")
        ));

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.NOSE_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.HIGH),
                        new IntervalCondition(LocusFeatures.NOSE_WIDTH, Goodness.NEUTRAL, 0.0, 0.2, Importance.HIGH),
                        "um nariz bem pequenininho e fino",
                        "um narizinho delicado",
                        "um belo dum narizinho"),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.NOSE_SIZE, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW),
                        new IntervalCondition(LocusFeatures.NOSE_WIDTH, Goodness.NEUTRAL, 0.4, 1.0, Importance.LOW),
                        "um nariz curto e gordinho",
                        "um nariz tipo batata",
                        "um nariz tipo bolinha"),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.NOSE_SIZE, Goodness.NEUTRAL, 0.5, 1.0, Importance.LOW),
                        new IntervalCondition(LocusFeatures.NOSE_WIDTH, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW),
                        "um nariz bem fino e comprido",
                        "um nariz bem pontudo e longo"),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.NOSE_SIZE, Goodness.NEUTRAL, 0.4, 1.0, Importance.HIGH),
                        new IntervalCondition(LocusFeatures.NOSE_WIDTH, Goodness.NEUTRAL, 0.3, 1.0, Importance.HIGH),
                        "um narizão",
                        "um nariz bem grandão",
                        "um nariz grandão",
                        "um napa gigante")
        ));

        DescriptionGroup mouth = new DescriptionGroup(random, joelingo, levelDetail,
                "tem uma boca", "possui uma boca", "com uma boca");

        mouth.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.MOUTH_SIZE, Goodness.GOOD, 0.6, 1.0, Importance.HIGH,
                        "bem grande",
                        "gigante",
                        "grandona"),
                new IntervalCondition(LocusFeatures.MOUTH_SIZE, Goodness.GOOD, 0.4, 0.6, Importance.LOW,
                        "grande"),
                new IntervalCondition(LocusFeatures.MOUTH_SIZE, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                        "pequena",
                        "pequenininha")
        ));

        mouth.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.MOUTH_FEMININITY,
                                joelingo.isFemale() ? Goodness.BAD : Goodness.GOOD,
                                0.0, 0.2,
                                joelingo.isFemale() ? Importance.HIGH : Importance.LOW,
                        "masculina",
                        "com traços masculinos"),
                new IntervalCondition(LocusFeatures.MOUTH_FEMININITY,
                                joelingo.isMale() ? Goodness.BAD : Goodness.GOOD,
                                0.8, 1.0,
                                joelingo.isMale() ? Importance.HIGH : Importance.LOW,
                        "feminina",
                        "bem feminina",
                        "com traços femininos")
        ));

        if (!mouth.isIrrelevant()) {
            result.append(", ").append(mouth.split());
        }

        has.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.TEETH_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.HIGH),
                        new IntervalCondition(LocusFeatures.TEETH_POINTED, Goodness.NEUTRAL, 0.5, 1.0, Importance.HIGH),
                        "dentes bem pequenininhos e pontudos, tipo uma serrinha",
                        "dentes pequenos e afiados"),
                new AndCondition(
                        new IntervalCondition(LocusFeatures.TEETH_SIZE, Goodness.NEUTRAL, 0.3, 1.0, Importance.HIGH),
                        new IntervalCondition(LocusFeatures.TEETH_POINTED, Goodness.NEUTRAL, 0.5, 1.0, Importance.HIGH),
                        "dentes grandes e bem pontudo",
                        "dentes longos e afiados",
                        gender(joelingo, "dentes bem afiados, parecendo um vampiro", "dentes bem afiados, parecendo uma vampira")),
                new IntervalCondition(LocusFeatures.TEETH_SIZE, Goodness.NEUTRAL, 0.0, 0.2, Importance.LOW,
                        "dentes pequenos"),
                new IntervalCondition(LocusFeatures.TEETH_SIZE, Goodness.NEUTRAL, 0.5, 1.0, Importance.LOW,
                        "dentes grandes, porém não tão afiados")
        ));

        if (!has.isIrrelevant()) {
            result.append(", ").append(has.split());
        }

        return result.toString();
    }

    private String describeStates(Random random, Joelingo joelingo) {
        DescriptionGroup states = new DescriptionGroup(random, joelingo, levelDetail, "está", "parece estar");

        states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                new IntervalCondition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW,
                        gender(joelingo, "bem acordado", "bem acordada"),
                        gender(joelingo, "ligadão", "ligadona"),
                        gender(joelingo, "acordadão", "acordadona")),
                new IntervalCondition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.3, 0.5, Importance.LOW,
                        gender(joelingo, "acordado", "acordada"),
                        "de olho aberto"),
                new IntervalCondition(LocusFeatures.SLEEPY, Goodness.BAD, 0.5, 0.8, Importance.HIGH,
                        "com muito sono", gender(joelingo, "sonolento", "sonolenta"), "caindo de sono"),
                new IntervalCondition(LocusFeatures.SLEEPY, Goodness.NEUTRAL, 0.8, 1.0, Importance.SEVERE, "dormindo", "cochilando")
        ));

        if (joelingo.getPhenotype().getFeature(LocusFeatures.SLEEPY).getDoubleValue() < 0.8) {
            // do not describe others emotional states if is sleeping

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.HAPPINESS, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                            "com depressão",
                            gender(joelingo, "deprimido", "deprimida"),
                            "muito triste",
                            gender(joelingo, "acabado emocionalmente", "acabada emocionalmente")),
                    new IntervalCondition(LocusFeatures.HAPPINESS, Goodness.BAD, 0.2, 0.4, Importance.HIGH,
                            "triste",
                            gender(joelingo, "tristinho", "tristinha"),
                            gender(joelingo, "chateado", "chateada"),
                            gender(joelingo, "cabisbaixo", "cabisbaixa")),
                    new IntervalCondition(LocusFeatures.HAPPINESS, Goodness.GOOD, 0.4, 0.7, Importance.LOW, "feliz", "alegre", "contente"),
                    new IntervalCondition(LocusFeatures.HAPPINESS, Goodness.GOOD, 0.7, 1.0, Importance.HIGH,
                            "muito feliz", "radiante", "ultra feliz", gender(joelingo, "felicíssimo", "felicíssima"),
                            "muito alegre", "muito contente")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.BOREDOM_FEELING, Goodness.BAD, 0.8, 1.0, Importance.HIGH,
                            gender(joelingo, "muito entediado", "muito entediada"),
                            "de bode",
                            gender(joelingo, "muito chato", "muito chata"),
                            "com um tédio infernal"),
                    new IntervalCondition(LocusFeatures.BOREDOM_FEELING, Goodness.BAD, 0.6, 0.8, Importance.LOW,
                            gender(joelingo, "entediado", "entediada"),
                            gender(joelingo, "chato", "chata"),
                            "com tédio")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.ANGER_FEELING, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                            "zen",
                            gender(joelingo, "bem calmo", "bem calma"),
                            gender(joelingo, "super tranquilo", "super tranquila")),
                    new IntervalCondition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com raiva",
                            gender(joelingo, "raivoso", "raivosa"),
                            gender(joelingo, "irritado", "irritada")),
                    new IntervalCondition(LocusFeatures.ANGER_FEELING, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "louco de raiva", "louca de raiva"),
                            gender(joelingo, "insanamente raivoso", "insanamente irritada"),
                            "bufando de raiva")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.HUNGER_FEELING, Goodness.GOOD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "totalmente saciado", "totalmente saciada"),
                            gender(joelingo, "lotado de tanto comer", "lotada de tanto comer"),
                            "com a barriga cheia"),
                    new IntervalCondition(LocusFeatures.HUNGER_FEELING, Goodness.GOOD, 0.3, 0.6, Importance.LOW,
                            "sem fome"),
                    new IntervalCondition(LocusFeatures.HUNGER_FEELING, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com fome",
                            gender(joelingo, "faminto", "faminta"),
                            "com a barriga roncando"),
                    new IntervalCondition(LocusFeatures.HUNGER_FEELING, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            gender(joelingo, "morto de fome", "morta de fome"),
                            gender(joelingo, "desnutrido", "desnutrida"),
                            "morrendo de fome", "azul de fome")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.0, 0.3, Importance.HIGH,
                            gender(joelingo, "muito desmotivado", "muito desmotivada"),
                            "muito carente",
                            "totalmente sem forças",
                            "totalmente sem ânimo",
                            gender(joelingo, "muito desanimado", "muito desanimada")),
                    new IntervalCondition(LocusFeatures.MOTIVATION_FEELING, Goodness.BAD, 0.3, 0.4, Importance.LOW,
                            gender(joelingo, "desmotivado", "desmotivada"),
                            "carente",
                            "sem forças",
                            "sem ânimo",
                            gender(joelingo, "desanimado", "desanimada")),
                    new IntervalCondition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.6, 0.8, Importance.LOW,
                            gender(joelingo, "agitado", "agitada"),
                            gender(joelingo, "empolgado", "empolgada"),
                            gender(joelingo, "motivado", "motivada")),
                    new IntervalCondition(LocusFeatures.MOTIVATION_FEELING, Goodness.GOOD, 0.8, 1.0, Importance.HIGH,
                            gender(joelingo, "super agitado", "super agitada"),
                            gender(joelingo, "super empolgado", "super empolgada"),
                            gender(joelingo, "muito motivado", "muito motivada"))
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.FEAR, Goodness.GOOD, 0.0, 0.2, Importance.LOW,
                            gender(joelingo, "muito corajoso", "muito corajosa"),
                            "sem medo nenhum"),
                    new IntervalCondition(LocusFeatures.FEAR, Goodness.BAD, 0.5, 0.7, Importance.LOW,
                            "com medo"),
                    new IntervalCondition(LocusFeatures.FEAR, Goodness.BAD, 0.7, 1.0, Importance.HIGH,
                            "com muito medo",
                            "morrendo de medo",
                            gender(joelingo, "apavorado", "apavorada"),
                            "em pânico")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.0, 0.2, Importance.SEVERE,
                            "morrendo de calor",
                            "derretendo de calor",
                            "passando mal de calor",
                            "com muito calor",
                            "sentindo muito calor"),
                    new IntervalCondition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.2, 0.4, Importance.HIGH,
                            "com calor",
                            "sentindo calor"),
                    new IntervalCondition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.6, 0.8, Importance.HIGH,
                            "com frio",
                            "sentindo frio"),
                    new IntervalCondition(LocusFeatures.FEELING_COLD, Goodness.BAD, 0.8, 1.0, Importance.SEVERE,
                            "morrendo de frio",
                            "congelando",
                            "sentindo muito frio",
                            "tremendo de frio",
                            "batendo os dentes de frio")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.GOOD, 0.8, 1.0, Importance.LOW,
                            "super saudável",
                            "muito saudável"),
                    new IntervalCondition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.GOOD, 0.5, 0.8, Importance.LOW,
                            "saudável"),
                    new IntervalCondition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.BAD, 0.3, 0.5, Importance.LOW,
                            gender(joelingo, "fisicamente acabado", "fisicamente acabada"),
                            "com a aparência meio acabada",
                            "um pouco doente"),
                    new IntervalCondition(LocusFeatures.HEALTHY_APPEARANCE, Goodness.BAD, 0.0, 0.3, Importance.SEVERE,
                            "muito doente",
                            gender(joelingo, "destruído fisicamente", "destruída fisicamente"),
                            gender(joelingo, "debilitado", "debilitada"),
                            gender(joelingo, "fraquinho e de cama", "fraquinha e de cama"),
                            "com a aparência horrível",
                            "com profundas olheiras")
            ));

            states.add(new ConditionalDescription(levelDetail, random, joelingo.getPhenotype(),
                    new IntervalCondition(LocusFeatures.DIRT_LEVEL, Goodness.NEUTRAL, 0.0, 0.3, Importance.LOW,
                            gender(joelingo, "super limpo", "super limpa"),
                            gender(joelingo, "limpíssimo", "limpíssima"),
                            gender(joelingo, "brilhante de limpo", "brilhante de limpa"),
                            gender(joelingo, "impecavelmente limpo", "impecavelmente limpa")),
                    new IntervalCondition(LocusFeatures.DIRT_LEVEL, Goodness.BAD, 0.7, 0.9, Importance.HIGH,
                            gender(joelingo, "fedido", "fedida"),
                            gender(joelingo, "sujo", "suja")),
                    new IntervalCondition(LocusFeatures.DIRT_LEVEL, Goodness.BAD, 0.9, 1.0, Importance.SEVERE,
                            gender(joelingo, "sujismundo", "sujismunda"),
                            gender(joelingo, "muito fedido", "muito fedida"),
                            "cheirando podre",
                            "cheirando esgoto",
                            gender(joelingo, "imundo", "imunda"),
                            gender(joelingo, "sujo e nojento", "suja e nojenta"),
                            gender(joelingo, "completamente sujo", "completamente suja"))
            ));
        }

        StringBuilder result = new StringBuilder();

        if (!states.isIrrelevant()) {
            result.append(" ").append(states.split());
        }

        return result.toString();
    }

    // Utils:

    public static <T extends Number> String plural(String format, T value, String singular, String plural) {
        long v = Math.abs(Math.round(value.doubleValue()));
        return String.format(format, value, v < 2 ? singular : plural);
    }

    public static String gender(Joelingo joelingo, String male, String female) {
        return joelingo.getGenotype().getSex() == Sex.MALE ? male : female;
    }

    public static String getPronoum(Joelingo joelingo) {
        String pronoun;

        if (joelingo.getGenotype().getSex() == Sex.FEMALE) {
            pronoun = "ela";
        } else {
            pronoun = "ele";
        }

        return pronoun;
    }

    public static String randomize(Random random, String ... what) {
        if (what.length == 0) {
            return "";
        } else {
            return what[random.nextInt(what.length)];
        }
    }
}
