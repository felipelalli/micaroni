package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.Locus;

import java.util.HashMap;
import java.util.Map;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Chromosome<T extends Chromosome, L extends Locus> extends JsonCapable<T> {
    private Map<Integer, Gene> genes = new HashMap<>();

    public void setGene(L locus, Gene gene) {
        genes.put(locus.getPosition(), gene);
    }

    public Gene getGene(L locus) {
        return genes.get(locus.getPosition());
    }
}
