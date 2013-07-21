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
            "a", "am", "ax", "ai", "ae", "at", "ali", "ami", "amy", "ar",
            "e", "em", "ex", "ei", "ee", "et", "eli", "emi", "emy", "er",
            "i", "im", "ix", "ii", "ie", "it", "ili", "imi", "imy", "ir",
            "o", "om", "ox", "oi", "oe", "ot", "oli", "omi", "omy", "or",
            "u", "um", "ux", "ui", "ue", "ut", "uli", "umi", "umy", "ur", "ul",
            "ba", "be", "bi", "bo", "bu", "bam", "bak", "bre", "bru",
            "bum", "bis", "bom", "bum", "bip", "ber", "ca", "ce", "ci", "cko",
            "co", "cu", "cra", "cram", "cem", "cet", "cim", "com", "cop", "cry", "ces",
            "cru", "crem", "da", "de", "di", "do", "du", "dam", "deo", "dim", "ds", "doi",
            "den", "dan", "dom", "dum", "duk", "dra", "dru", "dil", "des", "fa", "fe", "fi", "fo", "fu",
            "foo", "fau", "fei", "fom", "fui", "fra", "fam", "fat", "fim", "few", "fus", "fuz",
            "fow", "ga", "ge", "gi", "go", "gu", "gra", "gam", "gre", "grem", "gem", "gez",
            "gom", "goi", "gum", "gus", "gap", "gep", "ha", "he", "hi", "ho", "hu", "huz",
            "ham", "hem", "him", "hoo", "haw", "ja", "je", "ji", "jo", "ju", "jan", "jaz",
            "jem", "jim", "jap", "joe", "jak", "jew", "ka", "ke", "ki", "ko", "ku",
            "kka", "kke", "kra", "kro", "kry", "kru", "krom", "la", "le", "li", "lo", "lee", "lha", "lho",
            "lu", "lin", "lim", "lam", "lan", "lat", "lot", "luc", "lis", "los", "lus", "luz",
            "loi", "luf", "ma", "me", "mi", "mo", "mons", "mu", "mais", "max", "mex", "mix", "mox", "mux",
            "maz", "moi", "mui", "mei", "mer", "mos", "moz", "mim", "min", "mum", "mun", "mit", "myp",
            "man", "men", "nho", "na", "ne", "ni", "no", "nu", "noz", "nos", "nus", "noo", "nai", "nay", "nan",
            "pa", "pe", "pi", "po", "pu", "poo", "pam", "pan", "pem", "pen", "pax", "paz", "pei",
            "pol", "pez", "piz", "pis", "pus", "puz", "putz", "paes", "pre", "pri", "prim", "qua", "que",
            "qui", "quo", "quan", "ra", "re", "ri", "ro", "ru", "ram", "rem", "ris", "rus", "rap",
            "rat", "row", "roq", "rok", "rock", "rol", "raw", "sa", "se", "se", "so", "su", "sam", "san", "sh",
            "sat", "sei", "sem", "sim", "sum", "sax", "sex", "sox", "sul", "ta", "te", "ti", "to",
            "tu", "tum", "tam", "tex", "tin", "tim", "tip", "tee", "tox", "tux", "tra", "tro", "tri",
            "wa", "we", "wi", "wo", "wu", "wow", "wua", "war", "woi", "wux", "wap",
            "va", "ve", "vi", "vo", "vu", "vam", "van", "vux", "vua", "voa", "vua", "vow",
            "ya", "yu", "ye", "you", "yui", "xa", "xe", "xi", "xo", "xu", "xux", "xuz", "xam", "xou", "xow",
            "xol", "xoks", "za", "ze", "zi", "zo", "zu", "zux", "zoo", "zap", "zao"
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
        int n = Math.min(5, Math.max(1, ((int) ((RANDOM.nextGaussian() * 1) + 3))));

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
