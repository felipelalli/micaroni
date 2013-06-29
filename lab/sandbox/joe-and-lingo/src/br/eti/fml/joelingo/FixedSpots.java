package br.eti.fml.joelingo;

/**
 * Places to put accessories.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum FixedSpots {
    HEAD(0, false),
    LEFT_HAND(1, false),
    RIGHT_HAND(2, false),
    EYES(3, false);

    private final int position;
    private final boolean deprecated;

    private FixedSpots(int position, boolean deprecated) {
        this.position = position;
        this.deprecated = deprecated;
    }
}
