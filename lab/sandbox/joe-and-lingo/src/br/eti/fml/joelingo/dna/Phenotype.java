package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.agent.ModifierAgentOverTime;
import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.dna.locus.LocusSpots;

import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Phenotype extends JsonCapable<Phenotype> {
    private Map<Integer, Feature> features = new HashMap<>();
    private Map<Integer, ModifierAgentOverTime> accessories = new HashMap<>();

    public void setFeature(LocusFeatures locus, Feature feature) {
        features.put(locus.getPosition(), feature);
    }

    public Feature getFeature(LocusFeatures locus) {
        return features.get(locus.getPosition());
    }

    private boolean hasFeature(LocusFeatures locus) {
        return features.containsKey(locus.getPosition());
    }

    public void clearAccessory(LocusSpots locus) {
        accessories.put(locus.getPosition(), null);
    }

    public void setAccessory(LocusSpots locus, ModifierAgentOverTime modifierAgentOverTime) {
        accessories.put(locus.getPosition(), modifierAgentOverTime);
    }

    public ModifierAgentOverTime getAccessory(LocusSpots locus) {
        return accessories.get(locus.getPosition());
    }

    private boolean isFree(LocusSpots locus) {
        return !features.containsKey(locus.getPosition());
    }
}
