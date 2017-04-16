package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public interface InitialPhenotypeTransformer {
    /**
     * @param genotype the genetics
     * @param phenotype is modified
     */
    void transform(Genotype genotype, Phenotype phenotype);
}
