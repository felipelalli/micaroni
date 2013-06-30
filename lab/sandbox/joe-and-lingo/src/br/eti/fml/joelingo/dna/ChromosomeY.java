package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.LocusGenesX;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomeY extends JsonCapable {
    private Gene[] genes = new Gene[LocusGenesY.values().length];
}
