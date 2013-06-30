package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.LocusGenesA1;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomeA1 extends JsonCapable {
    private Gene[] genes = new Gene[LocusGenesA1.values().length];
}
