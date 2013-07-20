package br.eti.fml.joelingo.dna.locus;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

@SuppressWarnings("UnusedDeclaration")
public enum LocusFeatures implements Locus {
    EYE_REDDISH             ( 0, false, new BigDecimal("0.19921875")),  // 0.0 is no red and 1.0 is very red
    EYE_GREENISH            ( 1, false, new BigDecimal("0.098039216")), // 0.0 is no green and 1.0 is very green
    EYE_BLUISH              (31, false, new BigDecimal("0.0")), // 0.0 is no blue and 1.0 is very blue
    EYE_GLOW                (26, false, new BigDecimal("0.0")), // 0.0 is normal and 1.0 is very glow
    EYE_SIZE                ( 8, false, new BigDecimal("0.3")), // 0.0 is no eyes, 0.3 = normal, 1.0 = is so big eyes
    EYE_EFFICIENCY          (55, false, new BigDecimal("0.8")), // 0.0 is blind, 0.5 = normal, 0.8 = very healthy
    EYELASHES_SIZE          (12, false, new BigDecimal("0.3")), // 0.0 is no eyelashes, 0.3 = normal, 1.0 = is so big eyelashes
    EYEBROW_SIZE            (13, false, new BigDecimal("0.3")), // 0.0 is no eyebrow, 0.3 = normal, 0.7 = is unibrow, 1.0 is huge unibrow
    TENDENCY_TO_AGE         ( 2, false, new BigDecimal("0.5")), // 1.0 die very soon
    HAIR_STRAIGHTNESS       ( 3, false, new BigDecimal("1.0")), // 1.0 is totally straight
    HAIR_SIZE               ( 4, false, new BigDecimal("0.3")), // 0.0 is without hair, 0.3 is normal, 1.0 is max long
    HAIR_VOLUME             (70, false, new BigDecimal("0.5")), // 0.0 no hair, 1.0 very bulky
    HAPPINESS               ( 5, false, new BigDecimal("0.6")), // 0.0 is in depression, so sad and 1.0 is so happy, heaven. 0.6 is normal, happy enough
    FEAR                    ( 6, false, new BigDecimal("0.2")), // 1.0 is scarred, 0.0 is so fearless. 0.2 is normal
    NOSE_SIZE               ( 7, false, new BigDecimal("0.3")), // 0.0 is no nose, 0.3 = normal,1.0 = is so big nose
    NOSE_WIDTH              ( 9, false, new BigDecimal("0.3")), // 0.0 is no nose, 0.3 = normal, 1.0 = is so wide
    MOUTH_SIZE              (10, false, new BigDecimal("0.3")), // 0.0 is no mouth, 0.3 = normal, 1.0 = is so big mouth
    MOUTH_FEMININITY        (11, false, new BigDecimal("0.5")), // 0.0 is male mouth, 1.0 is very delicate female mouth
    EAR_SIZE                (14, false, new BigDecimal("0.3")), // 0.0 is no ear, 0.3 = normal, 1.0 is so big ear
    HEARING_ACCURACY        (15, false, new BigDecimal("0.7")), // 1.0 is very accurate, 0.7 is normal
    GENITALIA_TYPE          (16, false, new BigDecimal("0.0")), // 0.0 is male and 1.0 is female; 0.5 is both
    GENITALIA_SIZE          (17, false, new BigDecimal("0.3")), // 0.0 is no genitalia, 0.3 = normal, and 1.0 is too big
    GENITALIA_EFFICIENCY    (25, false, new BigDecimal("0.5")), // 0.0 do not work, 0.5 = normal, and 1.0 works very well
    HEAD_SIZE               (18, false, new BigDecimal("0.3")), // 0.0 is no head, 0.3 = normal, and 1.0 is too big
    HEAD_FAT                (19, false, new BigDecimal("0.3")), // 0.0 is no fat, 0.3 = normal, and 1.0 is too fat
    HEAD_FINENESS           (20, false, new BigDecimal("0.5")), // 0.0 is wide, 1.0 is very thin
    FOREHEAD_SIZE           (21, false, new BigDecimal("0.5")), // 0.0 is very short, 0.5 = normal, 1.0 is very large
    TEETH_SIZE              (22, false, new BigDecimal("0.3")), // 0.0 is no teeth, 0.3 = normal, 1.0 is very big
    TEETH_POINTED           (23, false, new BigDecimal("0.3")), // 0.0 is no pointed, 0.3 = normal, 1.0 is very pointed
    TEETH_EFFICIENCY        (24, false, new BigDecimal("0.5")), // 0.0 does not work, 0.5 = normal, 1.0 very efficient
    SKIN_ROUGHNESS          (27, false, new BigDecimal("0.5")), // 0.0 is totally smooth, 0.5 is normal, 1.0 is very roughness
    SKIN_GREENISH           (28, false, new BigDecimal("0.8125")), // 0.0 is no green, 1.0 is totally green
    SKIN_BLUISH             (29, false, new BigDecimal("0.80859375")), // 0.0 is no blue, 1.0 is totally blue
    SKIN_REDDISH            (30, false, new BigDecimal("0.93359375")), // 0.0 is no red, 1.0 is totally red
    BRISTLE_SIZE            (80, false, new BigDecimal("0.1")), // 0.0 is no bristle, 0.1 = short, 1.0 is very long bristle
    BRISTLE_SMOOTHNESS      (32, false, new BigDecimal("0.3")), // 0.0 is so hard, 1.0 is totally smooth
    BRISTLE_REDDISH         (76, false, new BigDecimal("0.6")), // color R
    BRISTLE_GREENISH        (77, false, new BigDecimal("0.6")), // color G
    BRISTLE_BLUISH          (78, false, new BigDecimal("0.6")), // color B
    BODY_HEIGHT             (33, false, new BigDecimal("0.0")), // 0.0 just born, 0.2 = child, 0.3 = adult, 0.4 = towering
    BODY_WIDTH              (34, false, new BigDecimal("0.0")), // 0.0 just born, 0.2 = child, 0.3 = adult, 0.4 = large
    BODY_FAT                (35, false, new BigDecimal("0.3")), // 0.0 is no fat, 0.3 = normal, 1.0 max fat
    IN_EGG                  (36, false, new BigDecimal("1.0")), // 0.0 is no egg, 1.0 is inside an egg
    MUSCLE                  (37, false, new BigDecimal("0.3")), // 0.0 is no muscle, 0.3 is normal
    BONES_HARDNESS          (39, false, new BigDecimal("0.8")), // 0.8 is normal, less than 0.7 is sickness
    HEART_EFFICIENCY        (40, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    LUNG_EFFICIENCY         (41, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    LIVER_EFFICIENCY        (42, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    INTESTINE_EFFICIENCY    (43, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    BRAIN_EFFICIENCY        (44, false, new BigDecimal("0.5")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    STOMACH_EFFICIENCY      (45, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    STOMACH_FILLING         (52, false, new BigDecimal("0.0")), // 0.0 is empty and 0.8 is full, 1.0 is dead
    KIDNEY_EFFICIENCY       (46, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    PANCREAS_EFFICIENCY     (47, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    SPLEEN_EFFICIENCY       (48, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    BLOOD_EFFICIENCY        (49, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    BLADDER_EFFICIENCY      (50, false, new BigDecimal("0.8")), // 0.0 is dead, 0.5 is normal, 0.8 very healthy
    BLADDER_FILLING         (51, false, new BigDecimal("0.0")), // 0.0 is empty and 0.8 is full, 1.0 is dead
    TONGUE_SIZE             (53, false, new BigDecimal("0.3")), // 0.0 is no tongue, and 0.3 is normal
    TONGUE_EFFICIENCY       (54, false, new BigDecimal("0.5")), // 0.0 is mute
    MAMMARY_GLAND_EFFICIENCY(81, false, new BigDecimal("0.0")), // 0.0 no gland, 0.5 = normal female, 0.8 healthy female
    TEAT_SIZE               (56, false, new BigDecimal("0.2")), // 0.0 no teat, 0.2 male, 0.2 female born, 0.3 female yong, 0.4 female adult (size = 1,2.5)
    ARMS_SIZE               (57, false, new BigDecimal("0.3")), // 0.0 is no arms, and 0.3 is normal
    ARMS_STRENGTH           (38, false, new BigDecimal("0.3")), // 0.0 is no useful, 0.3 is normal
    LEGS_SIZE               (58, false, new BigDecimal("0.3")), // 0.0 is no legs, and 0.3 is normal
    LEGS_STRENGTH           (59, false, new BigDecimal("0.3")), // 0.0 is no useful, 0.3 is normal
    TRUNK_STRENGTH          (60, false, new BigDecimal("0.3")), // 0.0 is dead, 0.3 is normal
    FEET_SIZE               (61, false, new BigDecimal("0.3")), // 0.0 is no feet, and 0.3 is normal
    FEET_STRENGTH           (62, false, new BigDecimal("0.3")), // 0.0 is no useful, 0.3 is normal
    HANDS_SIZE              (63, false, new BigDecimal("0.3")), // 0.0 is no hands, and 0.3 is normal
    HANDS_STRENGTH          (64, false, new BigDecimal("0.3")), // 0.0 is no useful, 0.3 is normal
    NAILS_SIZE              (65, false, new BigDecimal("0.3")), // 0.0 is no nails, and 0.3 is normal
    NAILS_POINTED           (66, false, new BigDecimal("0.5")), // 0.0 is rounded, 1.0 is very pointed
    DIRT_LEVEL              (67, false, new BigDecimal("0.3")), // 0.0 totally clean, 0.3 normal
    FEELING_COLD            (68, false, new BigDecimal("0.5")), // 0.0 very hot, 0.5 normal, 1.0 very cold
    HEALTHY_APPEARANCE      (69, false, new BigDecimal("0.8")), // 0.0 very sick, 0.5 normal, 0.8 healthy
    ANGER_FEELING           (71, false, new BigDecimal("0.3")), // 0.0 zen, 0.3 normal, 0.5 anger, 1.0 crazy
    MOTIVATION_FEELING      (72, false, new BigDecimal("0.3")), // 0.0 zero motivation, 0.3 normal, 0.5 motivated, 1.0 amazing
    HUNGER_FEELING          (73, false, new BigDecimal("0.0")), // 0.0 no hunger, 1.0 starving
    BOREDOM_FEELING         (74, false, new BigDecimal("0.0")), // 0.0 no hunger, 1.0 starving
    TAIL_SIZE               (75, false, new BigDecimal("0.3")), // 0.0 no tail, 0.3 normal
    IMMUNE_EFFICIENCY       (79, false, new BigDecimal("0.8")), // 0.0 is aids, 0.5 is normal, 0.8 very healthy
    ACCUMULATED_KNOWLEDGE   (82, false, new BigDecimal("0.0")), // 0.0 when born, 0.3 smart, 0.6 very smart, 1.0 genius
    SLEEPY                  (83, false, new BigDecimal("0.0")), // 0.0 is no sleepy, 0.3 is normal, 0.5 is sleepy, 1.0 is sleeping

    ;

    private static final Map<Integer, LocusFeatures> LOCUS_CACHE = new HashMap<Integer, LocusFeatures>();

    static {
        Set<Integer> usedPositions = new HashSet<Integer>();

        for (LocusFeatures locusFeatures : LocusFeatures.values()) {
            int position = locusFeatures.getPosition();

            if (usedPositions.contains(position)) {
                throw new IllegalStateException("Duplicated position in LocusFeatures: " + position);
            } else {
                usedPositions.add(position);
                LOCUS_CACHE.put(locusFeatures.getPosition(), locusFeatures);
            }
        }
    }

    public static LocusFeatures valueByPosition(int position) {
        return LOCUS_CACHE.get(position);
    }

    private final int position;
    private final boolean deprecated;
    private final BigDecimal defaultValue; // used if this gene is absent

    private LocusFeatures(int position, boolean deprecated, BigDecimal defaultValueToOldVersions) {
        this.position = position;
        this.deprecated = deprecated;
        this.defaultValue = defaultValueToOldVersions;
    }

    public BigDecimal getDefaultValue() {
        return this.defaultValue;
    }

    @Override
    public int getPosition() {
        return position;
    }

    @Override
    public boolean isDeprecated() {
        return deprecated;
    }
}
