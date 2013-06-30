package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Genotype extends JsonCapable {
    private Long luckyNumber; // used to random seed

    private Sex sex;
    private Chromosome[] chromosomes;
}
