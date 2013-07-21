package br.eti.fml.joelingo.dna;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public enum AppearanceAge {
    BABY (60L * 60L, 60L * 60L * 24L),                         // 1h - 1 day          - 5.6 h
    CHILD(60L * 60L * 24L, 60L * 60L * 24L * 3L),              // 1 day - 3 days      - 1.4 day
    TEEN (60L * 60L * 24L * 3L, 60L * 60L * 24L * 12L),        // 3 days - 12 days    - 4.8 days
    ADULT(60L * 60L * 24L * 7L, 60L * 60L * 24L * 30L * 6L),   // 7 days - 6 months   - 41.6 days (1.4 months)
    OLD  (60L * 60L * 24L * 12L, 60L * 60L * 24L * 365L);      // 12 days - 1 year    - 82.6 days (2.75 months)

    private final long min;
    private final long max;

    AppearanceAge(long min, long max) {
        this.min = min;
        this.max = max;
    }

    public static AppearanceAge calculateAgeAppearance(double tendencyToAge, long ageInSec) {
        AppearanceAge result;

        if (ageInSec < calculate(BABY, tendencyToAge)) {
            result = BABY;
        } else if (ageInSec < calculate(CHILD, tendencyToAge)) {
            result = CHILD;
        } else if (ageInSec < calculate(TEEN, tendencyToAge)) {
            result = TEEN;
        } else if (ageInSec < calculate(ADULT, tendencyToAge)) {
            result = ADULT;
        } else {
            result = OLD;
        }

        return result;
    }

    private static double calculate(AppearanceAge appearanceAge, double tendencyToAge) {
        return appearanceAge.min + ((appearanceAge.max - appearanceAge.min) * tendencyToAge);
    }
}
