package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.LevelDetail;
import org.apache.commons.lang3.StringUtils;

import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class DescriptionGroup {
    private final Random random;
    private final Joelingo joelingo;
    private final LevelDetail levelDetail;
    private final String[] introduction;
    private final List<Description> description = new ArrayList<Description>();

    public DescriptionGroup(Random random, Joelingo joelingo,
                            LevelDetail levelDetail,
                            String ... introduction) {

        this.random = random;
        this.introduction = introduction;
        this.joelingo = joelingo;
        this.levelDetail = levelDetail;
    }

    public DescriptionGroup add(Description d) {
        this.description.add(d);
        return this;
    }

    public String split() {
        StringBuilder result = new StringBuilder();
        boolean firstRelevant = true;

        if (!isIrrelevant()) {
            result.append(SimpleTextDescribing.randomize(random, introduction));
            Description before = null;

            for (Description d : description) {
                if (d.isRelevant()) {
                    if (before != null && before.isRelevant()) {
                        boolean opposite = d.getGoodness() == Goodness.BAD && before.getGoodness() == Goodness.GOOD
                                || d.getGoodness() == Goodness.GOOD && before.getGoodness() == Goodness.BAD;

                        String comma = SimpleTextDescribing.COMMA;

                        if (levelDetail == LevelDetail.SMS_TWITTER) {
                            if (opposite) {
                                result.append(comma).append(" mas");
                            } else {
                                result.append(comma);
                            }
                        } else {
                            if (opposite) {
                                result.append(SimpleTextDescribing.randomize(random,
                                        comma + " mas", comma + " mas", comma + " mas", comma + " mas",
                                        comma + " mas", comma + " mas", comma + " mas", comma + " mas",
                                        comma + " porém", comma + " porém", comma + " todavia", comma + " só que",
                                        StringUtils.trim(MessageFormat.format(comma + " apesar de que {0}",
                                                SimpleTextDescribing.randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". Porém {0} também {1}",
                                                joelingo.getName(), SimpleTextDescribing.randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". Mas {0} ainda {1}",
                                                SimpleTextDescribing.getPronoum(joelingo), SimpleTextDescribing.randomize(random, introduction)))));
                            } else {
                                String separator = SimpleTextDescribing.randomize(random,
                                        comma, comma, comma, comma, comma, comma, comma, comma, comma,
                                        comma, comma, comma, comma, comma, comma, comma, comma, comma,
                                        StringUtils.trim(MessageFormat.format(". E {0} também {1}",
                                                joelingo.getName(), SimpleTextDescribing.randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". E {0}", SimpleTextDescribing.randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". E {0} ainda {1}", joelingo.getName(),
                                                SimpleTextDescribing.randomize(random, introduction))),
                                        StringUtils.trim(MessageFormat.format(". {0} {1}",
                                                StringUtils.capitalize(SimpleTextDescribing.getPronoum(joelingo)), SimpleTextDescribing.randomize(random, introduction)))
                                );

                                result.append(separator);
                            }
                        }
                    }

                    result = new StringBuilder(StringUtils.trim(result.toString()));

                    result.append((introduction.length == 0 && firstRelevant) ? "" : " ").append(d.toString());
                    before = d;

                    firstRelevant = false;
                }
            }
        }

        return result.toString();
    }

    public boolean isIrrelevant() {
        return isIrrelevantSince(0);
    }

    public boolean isIrrelevantSince(int start) {
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
}
