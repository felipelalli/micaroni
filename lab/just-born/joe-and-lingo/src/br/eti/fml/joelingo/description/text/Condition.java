package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.dna.Phenotype;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface Condition {
    boolean satisfies(Phenotype phenotype);
    String[] getDescription();
    Goodness getGoodness();
    Importance getImportance();
}
