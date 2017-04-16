package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.dna.Phenotype;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class AndCondition implements Condition {
    private final String[] description;
    private final List<Condition> conditions = new ArrayList<Condition>();

    public AndCondition(Condition condition1, Condition condition2, String... description) {
        conditions.add(condition1);
        conditions.add(condition2);
        this.description = description;
    }

    public AndCondition add(Condition condition) {
        conditions.add(condition);
        return this;
    }

    @Override
    public boolean satisfies(Phenotype phenotype) {
        boolean satisfies = true;

        for (Condition condition : conditions) {
            if (!condition.satisfies(phenotype)) {
                satisfies = false;
                break;
            }
        }

        return satisfies;
    }

    @Override
    public String[] getDescription() {
        return description;
    }

    @Override
    public Goodness getGoodness() {
        return conditions.iterator().next().getGoodness();
    }

    @Override
    public Importance getImportance() {
        return conditions.iterator().next().getImportance();
    }
}
