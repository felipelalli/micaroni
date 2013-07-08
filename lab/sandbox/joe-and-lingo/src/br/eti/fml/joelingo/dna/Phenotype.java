package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.NeedAppUpdateException;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.dna.locus.LocusSpots;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Phenotype extends JsonCapable<Phenotype> {
    private Feature[] features = new Feature[LocusFeatures.values().length];
    private SpotToPutAccessory[] accessories = new SpotToPutAccessory[LocusSpots.values().length];

    public Feature getFeature(int position) throws NeedAppUpdateException {
        if (!hasFeature(position)) {
            throw new NeedAppUpdateException("Invalid feature position to get: " + position);
        }

        return features[position];
    }

    private boolean hasFeature(int position) {
        return position < features.length && position >= 0;
    }

    public void setFeature(int position, Feature feature) throws NeedAppUpdateException {
        if (!hasFeature(position)) {
            throw new NeedAppUpdateException("Invalid feature position to set: " + position);
        }

        features[position] = feature;
    }
}
