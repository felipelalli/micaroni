package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.LocusGenesX;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomeX extends JsonCapable<ChromosomeX> {
    private Gene[] genes = new Gene[LocusGenesX.values().length];
}
