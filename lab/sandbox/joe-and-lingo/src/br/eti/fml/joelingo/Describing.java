package br.eti.fml.joelingo;

import java.security.SecureRandom;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class Describing<T> {
    private static final Random RANDOM = new SecureRandom();

    public T describe(Joelingo joelingo) {
        return describe(RANDOM, joelingo);
    }

    public abstract T describe(Random random, Joelingo description);
}
