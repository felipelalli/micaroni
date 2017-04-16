package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.dna.Phenotype;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class NotCondition implements Condition {
    private final String[] description;
    private final List<Condition> conditions = new ArrayList<Condition>();

    public NotCondition(Condition condition, String... description) {
        conditions.add(condition);
        this.description = description;
    }

    public NotCondition add(Condition condition) {
        conditions.add(condition);
        return this;
    }

    @Override
    public boolean satisfies(Phenotype phenotype) {
        boolean satisfies = false;

        for (Condition condition : conditions) {
            if (!condition.satisfies(phenotype)) {
                satisfies = true;
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
