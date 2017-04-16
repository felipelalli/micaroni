package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.dna.Phenotype;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
class IntervalCondition implements Condition {
    private final LocusFeatures locusFeatures;
    private final Goodness goodness;
    private final double min;
    private final double max;
    private final Importance importance;
    private final String[] description;

    public IntervalCondition(LocusFeatures locusFeatures, Goodness goodness,
                             double min, double max, String... description) {

        this.locusFeatures = locusFeatures;
        this.goodness = goodness;
        this.min = min;
        this.max = max;
        this.importance = Importance.LOW;
        this.description = description;
    }

    public IntervalCondition(LocusFeatures locusFeatures, Goodness goodness,
                             double min, double max, Importance importance, String... description) {

        this.locusFeatures = locusFeatures;
        this.goodness = goodness;
        this.min = min;
        this.max = max;
        this.importance = importance;
        this.description = description;
    }

    @Override
    public boolean satisfies(Phenotype phenotype) {
        return isBetween(phenotype, locusFeatures, min, max);
    }

    public static boolean isBetween(Phenotype phenotype, LocusFeatures locusFeatures, double min, double max) {
        double value = phenotype.getFeature(locusFeatures).getDoubleValue();
        return value >= min && value <= max;
    }

    public String[] getDescription() {
        return description;
    }

    public Goodness getGoodness() {
        return goodness;
    }

    public Importance getImportance() {
        return importance;
    }
}
