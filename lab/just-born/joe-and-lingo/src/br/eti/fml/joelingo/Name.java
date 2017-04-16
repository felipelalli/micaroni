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
    public static final Name JOE_FIRST_NAME = new Name("a", "dam");
    public static final Name LINGO_FIRST_NAME = new Name("e", "ve");
    public static final Name JOE_LAST_NAME = new Name("joe");
    public static final Name LINGO_LAST_NAME = new Name("lin", "go");

    private static final SecureRandom RANDOM = new SecureRandom();

    private static final String[] SYLLABLES = new String[]{
            "joe", "lin", "go", "fe", "li", "pe", "pe", "dro",
            "la", "li", "ca", "ro", "li", "ne", "na",
            "li", "li", "a", "na", "ne", "cris", "ti", "na", "al", "ba",
            "re", "be", "ca", "mi", "ca", "ro", "ni", "sil", "ves", "tre",
            "sil", "va", "na", "pri", "sci", "la", "seu", "cu",
            "ha", "ry", "po", "ter", "bru", "xao",
            "bru", "no", "na", "ra", "fa", "el", "lu", "cas",
            "mar", "cos", "jo", "a", "na", "ar", "roz", "fei", "jao",
            "jo", "ao", "mal", "va", "do", "mons", "tro",
            "lou", "co", "sem", "no", "sao", "al", "ca", "po", "ne",
            "bi", "chi", "nho", "vir", "tu", "al", "ta", "ma", "go", "tchi",
            "ma", "rik", "zu", "ker", "berg", "ste", "ca",
            "an", "dreas", "vi", "tor", "ma", "theus", "va", "gi", "na",
            "de", "us", "de", "ni", "se", "le", "o", "nar", "do",
            "le", "an", "dro", "a", "nar", "kis", "ta",
            "bit", "co", "in", "fus", "ca", "car", "ro", "bi", "ci", "cle", "ta",
            "gor", "do", "ma", "gro", "jo", "vi", "al", "mo", "vi", "le",
            "sau", "lo", "gos", "to", "so", "sa", "de", "li", "ca", "do",
            "for", "te", "ca", "pe", "ta", "bi", "al", "a", "na",
            "a", "li", "ce", "ma", "ra", "vi", "lha", "a", "dao",
            "e", "va", "ja", "va", "cor", "re", "ria", "tem", "po",
            "pu", "ta", "pu", "tis", "gri", "la", "a", "ni", "ta",
            "fun", "ki", "ro", "ki", "jo", "si", "as",
            "gus", "ta", "vo", "ga", "bri", "el", "da", "vid", "ma", "go", "val", "di", "via",
            "dei", "ta", "do", "de", "pe", "fa", "bio", "es", "dras", "an", "drew",
            "le", "gal", "jo", "ia", "ro", "dri", "go", "al", "do",
            "spi", "der", "sil", "va", "an", "der", "son", "ner", "vo", "zi", "nho",
            "pa", "to", "ayr", "ton", "se", "na", "do", "bra", "sil",
            "nis", "san", "toy", "o", "ta", "da", "ny", "cal", "das", "fri", "o", "ren", "to",
            "de", "do", "du", "ro", "sem", "ver", "go", "nha",
            "ar", "ris", "ca", "do", "ul", "tra", "je", "a", "ri", "gor", "ro", "ger", "ro", "cha", "mo", "rei", "ra",
            "e", "van", "ge", "lis", "ta", "bo", "zao", "bo", "zo", "ray", "a", "ne", "hen", "ri",
            "mi", "ri", "an", "a", "na", "pau", "la", "lo", "me", "lis", "sa",
            "an", "to", "nio", "sa", "pe", "ca", "co", "ris", "ti", "na",
            "lau", "ra", "la", "vi", "nia", "mu", "ri", "lo", "a", "mor", "lo", "ve",
            "tu", "do", "de", "bom", "pa", "ne", "la", "ma", "ri", "na", "jo", "el", "ma",
            "mar", "cia", "cio", "gis", "lai", "ne", "mar", "ce", "lo", "la", "ja", "na", "í", "na", "mei", "re",
            "si", "mo", "ne", "ta", "gi", "a", "cin", "to", "ge", "o", "va", "na", "pi", "tu", "xa", "da",
            "ni", "ela", "nei", "mar", "si", "dney", "tio", "tia", "su", "pla", "e", "du", "ar", "do", "mo", "ni", "ca",
            "car", "do", "zo", "ba", "ba", "ca", "ri", "car", "do", "lin", "do", "mar", "pi", "ra", "nha", "xo",
            "xo", "ta", "tra", "vis", "ti", "gre", "le", "ao", "tar", "ta", "ru", "ga", "gor", "gon", "zo", "la",
            "son", "ga", "mon", "ga", "ma", "ca", "co", "e", "ri", "ka", "hey", "ko", "da", "no", "ni", "nho",
            "fo", "fao", "fa", "ro", "fa", "ti", "co", "li", "no", "mi", "ki", "mil", "ki", "bin", "go", "ti", "a",
            "zi", "nha", "pin", "go", "to", "bi", "bo", "bi", "fra", "jo", "la", "piu", "piu", "ju", "ca", "na",
            "ta", "li", "no", "vi", "o", "le", "ta", "jor", "ge", "lan", "gui", "la", "gui", "lher", "me", "mu", "lher",
            "ho", "mem", "na", "bun", "da", "bus", "sun", "da", "ba", "bi", "pal", "mei", "ras", "flor", "es", "ta",
            "ma", "ta", "gal", "raul", "gil", "mar", "bo", "ro", "mau", "u", "va", "lou", "bo", "co", "ta", "pa", "ra",
            "ne", "gros", "o", "ro", "no", "chi", "ca", "to", "tó", "ne", "gao", "xi", "ca", "mo", "to", "na", "lin", "da",
            "be", "le", "za", "bo", "ni", "ta", "le", "ao", "fe", "liz", "a", "le", "gria", "hu", "go", "fa", "ri", "a",
            "só", "se", "fo", "de", "tô", "de", "bo", "de", "dor", "de", "ca", "bes", "sa", "le", "za", "do",
            "ro", "rai", "ma", "ma", "to", "gros", "so", "do", "sul", "bur", "ro", "ya", "mar", "ra",
            "doi", "do", "fei", "jo", "a", "da", "a", "dam", "dao", "e", "va", "ve", "chou", "mi", "a", "gui",
            "lu", "pi", "chá", "en", "ya", "boz", "mas", "su", "my", "a", "my", "nai", "a", "ra", "nay",
            "ex", "and", "bi", "go", "de", "bis", "se", "xu", "al", "fer", "ro", "fer", "nan", "do",
            "da", "mi", "ao", "pe", "ta"
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

    public String getFirstSyllable() {
        return StringUtils.capitalize(syllables.iterator().next());
    }

    public static Name generateName() {
        Name newName = new Name();
        int n = (int) Math.min(4L, Math.max(1L, (Math.round((RANDOM.nextGaussian() * 1.0) + 2.5))));

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

    public int size() {
        return toString().length();
    }
}
