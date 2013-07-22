package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.Joelingo;
import br.eti.fml.joelingo.LevelDetail;
import br.eti.fml.joelingo.dna.Phenotype;

import java.util.Random;

/**
* @author Felipe Micaroni Lalli (micaroni@gmail.com)
*/
class ConditionalDescription implements Description {
    private final Random random;
    private final LevelDetail levelDetail;
    private final Joelingo joelingo;
    private final Condition[] conditions;

    ConditionalDescription(Random random, LevelDetail levelDetail, Joelingo joelingo, Condition... conditions) {
        this.random = random;
        this.levelDetail = levelDetail;
        this.joelingo = joelingo;
        this.conditions = conditions;
    }

    public Goodness getGoodness() {
        Phenotype phenotype = joelingo.getPhenotype();
        Goodness goodness = Goodness.NEUTRAL;

        for (Condition condition : conditions) {
            if (SimpleTextDescribing.isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
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
            if (SimpleTextDescribing.isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
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
            if (SimpleTextDescribing.isBetween(phenotype, condition.locusFeatures, condition.min, condition.max)) {
                result = SimpleTextDescribing.randomize(random, condition.description);
                break;
            }
        }

        return result;
    }
}
