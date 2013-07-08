package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.JsonCapable;
import br.eti.fml.joelingo.dna.locus.LocusGenesUnknown;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class ChromosomeUnknown extends JsonCapable<ChromosomeUnknown> {
    private Gene[] genes = new Gene[LocusGenesUnknown.values().length];
}
