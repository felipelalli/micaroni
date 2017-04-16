package br.eti.fml.joelingo.dna;

import br.eti.fml.joelingo.dna.locus.LocusFeatures;
import br.eti.fml.joelingo.dna.locus.LocusGenes;
import br.eti.fml.joelingo.dna.locus.LocusGenesA;
import br.eti.fml.joelingo.dna.locus.LocusGenesB;
import br.eti.fml.joelingo.dna.locus.LocusGenesC;
import br.eti.fml.joelingo.dna.locus.LocusGenesD;
import br.eti.fml.joelingo.dna.locus.LocusGenesE;
import br.eti.fml.joelingo.dna.locus.LocusGenesF;
import br.eti.fml.joelingo.dna.locus.LocusGenesG;
import br.eti.fml.joelingo.dna.locus.LocusGenesH;
import br.eti.fml.joelingo.dna.locus.LocusGenesI;
import br.eti.fml.joelingo.dna.locus.LocusGenesJ;
import br.eti.fml.joelingo.dna.locus.LocusGenesK;
import br.eti.fml.joelingo.dna.locus.LocusGenesL;
import br.eti.fml.joelingo.dna.locus.LocusGenesM;
import br.eti.fml.joelingo.dna.locus.LocusGenesX;
import br.eti.fml.joelingo.dna.locus.LocusGenesY;

import java.security.SecureRandom;
import java.util.Random;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class DefaultTransformer implements InitialPhenotypeTransformer {
    private static final Random RANDOM = new SecureRandom();

    @Override
    public void transform(Genotype g, Phenotype f) {
        if (g.isRecessive(LocusGenesA.EYE_GLOW_P1, LocusGenesB.EYE_GLOW_P2, LocusGenesC.EYE_GLOW_P3)) {
            f.setFeature(LocusFeatures.EYE_GLOW,
                    makeIntensity(g, 0.3, 0.1, IntensityStyle.LOCUS_AS_BITS,
                            LocusGenesA.GLOW_INTENSITY_P1,
                            LocusGenesB.GLOW_INTENSITY_P2,
                            LocusGenesC.GLOW_INTENSITY_P3));
        } else {
            f.setFeature(LocusFeatures.EYE_GLOW, 0.0);
        }

        boolean clearEyes = g.isRecessive(LocusGenesA.CLEAR_EYE);

        if (g.isRecessive(LocusGenesB.EYE_COLOR_P1, LocusGenesC.EYE_COLOR_P2)) { // b1b1 c1c1
            f.setFeature(LocusFeatures.EYE_REDDISH, standardDeviation(clearEyes ? 0.8 : 0.4, 0.2));
            f.setFeature(LocusFeatures.EYE_GREENISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
            f.setFeature(LocusFeatures.EYE_BLUISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
        } else if (g.isRecessive(LocusGenesC.EYE_COLOR_P2)) { // B1b1 c1c1
            f.setFeature(LocusFeatures.EYE_REDDISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
            f.setFeature(LocusFeatures.EYE_GREENISH, standardDeviation(clearEyes ? 0.8 : 0.4, 0.2));
            f.setFeature(LocusFeatures.EYE_BLUISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
        } else if (g.isRecessive(LocusGenesB.EYE_COLOR_P1)) { // b1b1 C1c1
            f.setFeature(LocusFeatures.EYE_REDDISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
            f.setFeature(LocusFeatures.EYE_GREENISH, standardDeviation(clearEyes ? 0.4 : 0.0, 0.2));
            f.setFeature(LocusFeatures.EYE_BLUISH, standardDeviation(clearEyes ? 0.8 : 0.4, 0.2));
        } else { // B1b1 C1c1
            f.setFeature(LocusFeatures.EYE_REDDISH, standardDeviation(clearEyes ? 0.7 : 0.6, 0.1));
            f.setFeature(LocusFeatures.EYE_GREENISH, standardDeviation(clearEyes ? 0.4 : 0.3, 0.1));
            f.setFeature(LocusFeatures.EYE_BLUISH, standardDeviation(clearEyes ? 0.0 : 0.0, 0.1));
        }

        if (g.isRecessive(LocusGenesD.EYE_SIZE_P1, LocusGenesE.EYE_SIZE_P2, LocusGenesE.EYE_SIZE_P3)) { // d0d0 e0e0 e1e1
            f.setFeature(LocusFeatures.EYE_SIZE, standardDeviation(0.9, 0.2));
        } else if (g.isRecessive(LocusGenesD.EYE_SIZE_P1, LocusGenesE.EYE_SIZE_P2)) { // d0d0 e0e0
            f.setFeature(LocusFeatures.EYE_SIZE, standardDeviation(0.6, 0.1));
        } else if (g.isRecessive(LocusGenesE.EYE_SIZE_P2)) { // D0d0 e0e0
            f.setFeature(LocusFeatures.EYE_SIZE, standardDeviation(0.1, 0.1));
        } else { // D0d0 E0e0 or d0d0 E0e0
            f.setFeature(LocusFeatures.EYE_SIZE, standardDeviation(0.3, 0.05));
        }

        if (g.isRecessive(LocusGenesA.BLINDNESS_P1, LocusGenesA.BLINDNESS_P2)) { // a3a3 a4a4
            f.setFeature(LocusFeatures.EYE_EFFICIENCY, 0.0);
        } else if (g.isRecessive(LocusGenesA.BLINDNESS_P1)) { // a3a3
            f.setFeature(LocusFeatures.EYE_EFFICIENCY, standardDeviation(0.1, 0.1));
        } else if (g.isDominant(LocusGenesA.BLINDNESS_P1, LocusGenesA.BLINDNESS_P2)
                && g.isRecessive(LocusGenesB.BIONIC_VISION)) { // A3a3 A4a4 b3b3
            f.setFeature(LocusFeatures.EYE_EFFICIENCY, standardDeviation(0.9, 0.1));
        } else { // A3a3
            f.setFeature(LocusFeatures.EYE_EFFICIENCY, standardDeviation(0.5, 0.2));
        }

        if (g.getSex() == Sex.FEMALE) {
            if (g.isRecessiveXX(LocusGenesX.EYELASHES_SIZE)) {
                f.setFeature(LocusFeatures.EYELASHES_SIZE, standardDeviation(0.3, 0.1));
            } else {
                f.setFeature(LocusFeatures.EYELASHES_SIZE, standardDeviation(0.6, 0.2));
            }
        } else {
            if (g.isRecessiveXY(LocusGenesX.EYELASHES_SIZE)) {
                f.setFeature(LocusFeatures.EYELASHES_SIZE, standardDeviation(0.3, 0.1));
            } else {
                f.setFeature(LocusFeatures.EYELASHES_SIZE, standardDeviation(0.1, 0.2));
            }
        }

        if (g.isRecessive(LocusGenesB.NO_EYEBROW_P1, LocusGenesC.NO_EYEBROW_P2)) {
            f.setFeature(LocusFeatures.EYEBROW_SIZE, 0.0);
        } else {
            boolean unibrowP1;

            if (g.getSex() == Sex.MALE) {
                unibrowP1 = g.isRecessiveXY(LocusGenesY.UNIBROW_P1);
            } else {
                unibrowP1 = g.isRecessiveXX(LocusGenesX.UNIBROW_P1);
            }

            if (unibrowP1 && g.isRecessive(LocusGenesB.UNIBROW_P2)) {
                f.setFeature(LocusFeatures.EYEBROW_SIZE, standardDeviation(0.9, 0.2));
            } else {
                f.setFeature(LocusFeatures.EYEBROW_SIZE, standardDeviation(0.3, 0.2));
            }
        }

        if (g.isRecessive(LocusGenesI.WINGS_P1, LocusGenesJ.WINGS_P2)) {
            f.setFeature(LocusFeatures.WINGS_SIZE, standardDeviation(0.3, 0.5));
        } else {
            f.setFeature(LocusFeatures.WINGS_SIZE, 0.0);
        }

        if (g.isRecessive(LocusGenesK.FINS_P1, LocusGenesL.FINS_P2)) {
            f.setFeature(LocusFeatures.FINS_SIZE, standardDeviation(0.3, 0.5));
        } else {
            f.setFeature(LocusFeatures.FINS_SIZE, 0.0);
        }

        if (g.isRecessive(LocusGenesM.THORNS)) {
            f.setFeature(LocusFeatures.THORNS_SIZE, standardDeviation(0.3, 0.3));
        }

        f.setFeature(LocusFeatures.TENDENCY_TO_AGE, makeIntensity(g, 0.2, 0.05, IntensityStyle.N_OF_RECESSIVES,
                LocusGenesD.TENDENCY_TO_AGE_P1, LocusGenesD.TENDENCY_TO_AGE_P2, LocusGenesC.TENDENCY_TO_AGE_P3));

        if (g.isRecessive(LocusGenesF.STRAIGHT_HAIR)) {
            f.setFeature(LocusFeatures.HAIR_STRAIGHTNESS, standardDeviation(0.8, 0.1));
        } else {
            f.setFeature(LocusFeatures.HAIR_STRAIGHTNESS, standardDeviation(0.3, 0.2));
        }

        if (g.isRecessive(LocusGenesG.HAIR_VOLUME_P1, LocusGenesH.HAIR_VOLUME_P2)) {
            f.setFeature(LocusFeatures.HAIR_VOLUME, 0.0);
            f.setFeature(LocusFeatures.HAIR_SIZE, 0.0);
            f.setFeature(LocusFeatures.HAIR_GROWTH, 0.0);
        } else {
            f.setFeature(LocusFeatures.HAIR_VOLUME, makeIntensity(g, 0.1, 0.1, IntensityStyle.ZERO_MANY_FEW_NORMAL,
                    LocusGenesG.HAIR_VOLUME_P1, LocusGenesH.HAIR_VOLUME_P2));

            if (g.isRecessive(LocusGenesF.HAIR_SPEED)) {
                f.setFeature(LocusFeatures.HAIR_SIZE, standardDeviation(0.1, 0.1));
                f.setFeature(LocusFeatures.HAIR_GROWTH, standardDeviation(0.8, 0.2));
            } else {
                f.setFeature(LocusFeatures.HAIR_SIZE, standardDeviation(0.0, 0.05));
                f.setFeature(LocusFeatures.HAIR_GROWTH, standardDeviation(0.3, 0.2));
            }
        }

        f.setFeature(LocusFeatures.TENDENCY_TO_JOY, makeIntensity(g, 0.2, 0.1,
                IntensityStyle.MAX_FEW_MANY_NORMAL,
                LocusGenesD.HAPPYNESS_TENDENCY_P1, LocusGenesE.HAPPYNESS_TENDENCY_P2));

        f.setFeature(LocusFeatures.HAPPINESS, standardDeviation(
                f.getFeature(LocusFeatures.TENDENCY_TO_JOY).getDoubleValue(), 0.1));

        f.setFeature(LocusFeatures.MOTIVATION_FEELING, standardDeviation(
                f.getFeature(LocusFeatures.TENDENCY_TO_JOY).getDoubleValue(), 0.1));

        f.setFeature(LocusFeatures.ANGER_FEELING, 1.0 - standardDeviation(
                f.getFeature(LocusFeatures.TENDENCY_TO_JOY).getDoubleValue(), 0.1));

        f.setFeature(LocusFeatures.TENDENCY_TO_FEEL_FEAR, makeIntensity(g, 0.0, 0.1,
                IntensityStyle.MAX_FEW_MANY_NORMAL,
                LocusGenesC.FEAR_TENDENCY_P1, LocusGenesD.FEAR_TENDENCY_P2));

        if (f.getFeature(LocusFeatures.TENDENCY_TO_FEEL_FEAR).getDoubleValue() < 0.5) {
            f.setFeature(LocusFeatures.FEAR, standardDeviation(0.2, 0.1));
        } else {
            f.setFeature(LocusFeatures.FEAR, standardDeviation(0.5, 0.1));
        }

        if (g.isRecessive(LocusGenesD.NOSE_SIZE)) {
            f.setFeature(LocusFeatures.NOSE_SIZE, standardDeviation(0.6, 0.1));
        } else {
            f.setFeature(LocusFeatures.NOSE_SIZE, standardDeviation(0.3, 0.05));
        }

        if (g.isRecessive(LocusGenesE.NOSE_WIDE)) {
            f.setFeature(LocusFeatures.NOSE_WIDTH, standardDeviation(0.6, 0.1));
        } else {
            f.setFeature(LocusFeatures.NOSE_WIDTH, standardDeviation(0.3, 0.05));
        }

        if (g.isRecessive(LocusGenesF.BIG_MOUTH)) {
            f.setFeature(LocusFeatures.MOUTH_SIZE, standardDeviation(0.6, 0.1));
        } else {
            f.setFeature(LocusFeatures.MOUTH_SIZE, standardDeviation(0.3, 0.05));
        }

        if (g.getSex() == Sex.FEMALE) {
            if (g.isDominantXX(LocusGenesX.MOUTH_FEMININITY)) {
                f.setFeature(LocusFeatures.MOUTH_FEMININITY, standardDeviation(1.0, 0.3));
            } else {
                f.setFeature(LocusFeatures.MOUTH_FEMININITY, standardDeviation(0.5, 0.3));
            }
        } else {
            if (g.isRecessiveXY(LocusGenesX.MOUTH_FEMININITY)) {
                f.setFeature(LocusFeatures.MOUTH_FEMININITY, standardDeviation(0.0, 0.2));
            } else {
                f.setFeature(LocusFeatures.MOUTH_FEMININITY, standardDeviation(0.5, 0.2));
            }
        }

        if (g.isRecessive(LocusGenesE.BIG_EAR)) {
            f.setFeature(LocusFeatures.EAR_SIZE, standardDeviation(0.6, 0.1));
        } else {
            f.setFeature(LocusFeatures.EAR_SIZE, standardDeviation(0.3, 0.05));
        }

        if (g.isRecessive(LocusGenesE.SUPER_HEARING)) {
            if (g.getSex() == Sex.MALE && g.isRecessiveXY(LocusGenesY.DEAF_P1)) {
                f.setFeature(LocusFeatures.HEARING_ACCURACY, standardDeviation(0.0, 0.1));
            } else if (g.getSex() == Sex.FEMALE && g.isRecessiveXX(LocusGenesX.DEAF_P1)) {
                f.setFeature(LocusFeatures.HEARING_ACCURACY, standardDeviation(0.0, 0.1));
            } else {
                f.setFeature(LocusFeatures.HEARING_ACCURACY, standardDeviation(1.0, 0.1));
            }
        } else {
            f.setFeature(LocusFeatures.HEARING_ACCURACY, standardDeviation(0.7, 0.1));
        }

        if (g.getSex() == Sex.MALE) {
            f.setFeature(LocusFeatures.GENITALIA_TYPE, 0.0);
        } if (g.getSex() == Sex.FEMALE) {
            f.setFeature(LocusFeatures.GENITALIA_TYPE, 1.0);
        } else {
            f.setFeature(LocusFeatures.GENITALIA_TYPE, 0.5);
        }

        if (g.isRecessive(LocusGenesG.NO_GENITALIA_P1, LocusGenesG.NO_GENITALIA_P2)) {
            f.setFeature(LocusFeatures.GENITALIA_SIZE, 0.0);
        }


    }

    private static double standardDeviation(double normal, double standardDeviation) {
        return normal + (RANDOM.nextGaussian() * standardDeviation);
    }

    /**
     * Given a list of locusGeneses, a style will
     * determine how a intensity value (0 to 1) will be calculated.
     */
    public enum IntensityStyle {
        /**
         * <pre>
         * DDD = 000 = 0
         * DRD = 010 = 2
         * RRD = 110 = 6
         * RRR = 111 = 7
         * </pre>
         */
        LOCUS_AS_BITS,

        /**
         * <pre>
         * DDD = 000 = 0
         * DRD = 010 = 1
         * RRD = 110 = 2
         * RRR = 111 = 3
         * </pre>
         */
        N_OF_RECESSIVES,

        /**
         * <pre>
         * RR = 11 = 0
         * RD = 10 = 3
         * DR = 01 = 1
         * DD = 00 = 2
         * </pre>
         */
        ZERO_MANY_FEW_NORMAL,

        /**
         * <pre>
         * RR = 11 = 4
         * RD = 10 = 1
         * DR = 01 = 3
         * DD = 00 = 2
         * </pre>
         */
        MAX_FEW_MANY_NORMAL
    }

    private static double makeIntensity(
            Genotype g, double min, double standardDeviation,
            IntensityStyle style, LocusGenes... locusGeneses) {

        long result = 0;
        long max = 0;

        switch (style) {
            case LOCUS_AS_BITS:
                int position = 1;

                for (int i = locusGeneses.length - 1; i >= 0; i--) {
                    LocusGenes locus = locusGeneses[i];

                    if (g.isRecessive(locus)) {
                        result += Math.pow(2.0, position);
                    }

                    max += Math.pow(2.0, position);
                    position++;
                }

                break;

            case N_OF_RECESSIVES:
                for (LocusGenes locus : locusGeneses) {
                    max++;

                    if (g.isRecessive(locus)) {
                        result++;
                    }
                }

                break;

            case ZERO_MANY_FEW_NORMAL:
                max = 4;

                if (locusGeneses.length != 2) {
                    throw new IllegalArgumentException("Style ZERO_MANY_FEW_NORMAL you have to send TWO arguments");
                }

                if (g.isRecessive(locusGeneses[0]) && g.isRecessive(locusGeneses[1])) {
                    result = 0;
                } else if (g.isRecessive(locusGeneses[0])) {
                    result = 3;
                } else if (g.isRecessive(locusGeneses[1])) {
                    result = 1;
                } else {
                    result = 2;
                }

                break;

            case MAX_FEW_MANY_NORMAL:
                max = 4;

                if (locusGeneses.length != 2) {
                    throw new IllegalArgumentException("Style MAX_FEW_MANY_NORMAL you have to send TWO arguments");
                }

                if (g.isRecessive(locusGeneses[0]) && g.isRecessive(locusGeneses[1])) {
                    result = 4;
                } else if (g.isRecessive(locusGeneses[0])) {
                    result = 1;
                } else if (g.isRecessive(locusGeneses[1])) {
                    result = 3;
                } else {
                    result = 2;
                }

                break;
        }

        return max == 0 ? 0.0 : standardDeviation(min + ((1.0 - min) * (result / ((double) max))), standardDeviation);
    }
}
