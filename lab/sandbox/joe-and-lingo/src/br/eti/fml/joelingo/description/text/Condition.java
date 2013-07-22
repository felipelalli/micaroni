package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.dna.locus.LocusFeatures;

/**
* @author Felipe Micaroni Lalli (micaroni@gmail.com)
*/
class Condition {
    final LocusFeatures locusFeatures;
    final Goodness goodness;
    final double min;
    final double max;
    final Importance importance;
    final String[] description;

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
