package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.LevelDetail;
import br.eti.fml.joelingo.dna.Phenotype;

import java.util.Random;

/**
* @author Felipe Micaroni Lalli (micaroni@gmail.com)
*/
class ConditionalDescription implements Description {
    private final Phenotype phenotype;
    private final Random random;
    private final LevelDetail levelDetail;
    private final Condition[] conditions;

    ConditionalDescription(LevelDetail levelDetail, Random random, Phenotype phenotype, Condition... conditions) {
        this.phenotype = phenotype;
        this.random = random;
        this.levelDetail = levelDetail;
        this.conditions = conditions;
    }

    public Goodness getGoodness() {
        Goodness goodness = Goodness.NEUTRAL;

        for (Condition condition : conditions) {
            if (condition.satisfies(phenotype)) {
                goodness = condition.getGoodness();
                break;
            }
        }

        return goodness;
    }

    public boolean isRelevant() {
        boolean relevant = false;

        for (Condition condition : conditions) {
            if (condition.satisfies(phenotype)) {
                if (condition.getImportance() == Importance.SEVERE) {
                    relevant = true;
                } else if (condition.getImportance() == Importance.HIGH && levelDetail.ordinal() > LevelDetail.SMS_TWITTER.ordinal()) {
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

        for (Condition condition : conditions) {
            if (condition.satisfies(phenotype)) {
                result = SimpleTextDescribing.randomize(random, condition.getDescription());
                break;
            }
        }

        return result;
    }
}
