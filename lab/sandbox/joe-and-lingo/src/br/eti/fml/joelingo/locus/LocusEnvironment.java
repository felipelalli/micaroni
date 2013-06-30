package br.eti.fml.joelingo.locus;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum LocusEnvironment {
    TEMPERATURE(0, false);

    private final int position;
    private final boolean deprecated;

    private LocusEnvironment(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
