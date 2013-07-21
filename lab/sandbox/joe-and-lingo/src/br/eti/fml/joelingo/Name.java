package br.eti.fml.joelingo;

import org.apache.commons.lang3.StringUtils;

import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Name extends JsonCapable<Name> {
    public static final Name JOE = new Name("joe");
    public static final Name LINGO = new Name("lin", "go");
    private static final SecureRandom RANDOM = new SecureRandom();

    private static final String[] SYLLABLES = new String[] {
            "a", "am", "ax", "ai", "ae", "at", "ali", "ami", "amy", "ar", "ao", "au",
            "e", "em", "ex", "ei", "ee", "eli", "emi", "emy", "er", "eo", "eu",
            "i", "im", "ix", "ii", "ie", "it", "ili", "imi", "imy", "ir", "io", "iu",
            "o", "om", "ox", "oi", "oe", "ot", "oli", "omi", "omy", "or", "ou",
            "u", "um", "ux", "ui", "ue", "ut", "uli", "umi", "umy", "ur", "ul",
            "ba", "be", "bi", "bo", "bu", "ba", "be", "bi", "bo", "bu",
            "bam", "bak", "bre", "bru", "bum", "bis", "bom", "bum", "bip", "ber",
            "ca", "ce", "ci", "co", "cu", "ca", "ce", "ci", "co", "cu", "cam",
            "cra", "cram", "cem", "cim", "com", "cop", "cry", "ces",
            "cru", "crem", "da", "de", "di", "do", "du", "da", "de", "di", "do", "du", "dam", "deo", "dim", "doi", "dis",
            "den", "dan", "dom", "dum", "duk", "dra", "dro", "dru", "dil", "des", "fa", "fe", "fi", "fo", "fu",
            "fa", "fe", "fi", "fo", "fu", "foo", "fau", "fei", "fom", "fui", "fra", "fam", "fat", "fim", "few", "fus", "fuz",
            "fow", "ga", "ge", "gi", "go", "gu", "ga", "ge", "gi", "go", "gu", "gra", "gam", "gre", "grem", "gem", "gez",
            "gom", "goi", "gum", "gus", "gap", "gep", "ha", "he", "hi", "ho", "hu", "huz",
            "ham", "hem", "him", "hoo", "haw", "ja", "je", "ji", "jo", "ju", "jan", "jaz",
            "ja", "je", "ji", "jo", "ju", "jem", "jim", "jap", "joe", "jak", "jew", "ka", "ke", "ki", "ko", "ku",
            "kke", "kra", "kro", "kry", "kru", "krom", "la", "le", "li", "lo", "lu",
            "la", "le", "li", "lo", "lu", "lee", "lha", "lho", "lin", "lim", "lam", "lan", "lat", "lot", "luc", "lis", "los", "lus", "luz",
            "loi", "luf", "ma", "me", "mi", "mo", "mu", "ma", "me", "mi", "mo", "mu", "mons", "mais", "max", "mex", "mix", "mox", "mux",
            "maz", "moi", "mui", "mei", "mer", "mos", "mim", "min", "mum", "mun", "mit", "myp",
            "man", "men", "nho", "na", "ne", "ni", "no", "nu", "na", "ne", "ni", "no", "nu", "noz", "nos", "nus", "noo", "nai", "nay", "nan",
            "pa", "pe", "pi", "po", "pu", "pa", "pe", "pi", "po", "pu", "poo", "pam", "pan", "pem", "pen", "pax", "paz", "pei",
            "pol", "pez", "piz", "pis", "pus", "puz", "putz", "paes", "pre", "pri", "prim",
            "ra", "re", "ri", "ro", "ru", "ra", "re", "ri", "ro", "ru", "ram", "rem", "ris", "rus", "rap",
            "rat", "row", "roq", "rok", "rock", "rol", "raw", "sa", "se", "si", "so", "su", "sa", "se", "si", "so", "su", "sam", "san", "sh",
            "sat", "sei", "sem", "sim", "sum", "sax", "sex", "sox", "sul", "ta", "te", "ti", "to",
            "tu", "ta", "te", "ti", "to", "tu", "tum", "tam", "tex", "tin", "tim", "tip", "tee", "tox", "tux", "tra", "tro", "tri",
            "wa", "we", "wi", "wo", "wu", "wow", "wua", "war", "woi", "wap",
            "va", "ve", "vi", "vo", "vu", "vam", "van", "vux", "vua", "voa", "vua", "vow",
            "ya", "yu", "ye", "you", "xa", "xe", "xi", "xo", "xu", "xam", "xou", "xow",
            "xol", "xoks", "za", "ze", "zi", "zo", "zu", "zoo", "zap", "zao"
    };

    private List<String> syllables = new ArrayList<String>(10);

    @SuppressWarnings("UnusedDeclaration") // used on Json
    public Name() {}

    public Name(String ... syllables) {
        this.syllables.addAll(Arrays.asList(syllables));
    }

    public String toString() {
        StringBuilder result = new StringBuilder();

        for (String s : syllables) {
            result.append(s);
        }

        return StringUtils.capitalize(result.toString());
    }

    public static Name generateName() {
        Name newName = new Name();
        int n = Math.min(4, Math.max(1, ((int) ((RANDOM.nextGaussian() * 1) + 3))));

        for (int i = 0; i < n; i++) {
            String randomSyllable = SYLLABLES[RANDOM.nextInt(SYLLABLES.length)];

            if (i == 0 && randomSyllable.length() == 1) { // this is to avoid start with "a", "e", "i" or "u"
                i--;
            } else {
                newName.syllables.add(randomSyllable);
            }
        }

        return newName;
    }

    public static Name generateName(Name motherLastName, Name fatherLastName) {
        Name name = new Name();

        String randomSyllable = SYLLABLES[RANDOM.nextInt(SYLLABLES.length)];

        name.syllables.add(randomSyllable);
        name.syllables.add(motherLastName.syllables.get(RANDOM.nextInt(motherLastName.syllables.size())));
        name.syllables.add(fatherLastName.syllables.get(RANDOM.nextInt(fatherLastName.syllables.size())));

        return name;
    }
}
