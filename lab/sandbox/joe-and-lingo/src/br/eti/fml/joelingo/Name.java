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
            "ni", "ela", "nei", "mar", "sid", "ney", "tio", "tia", "su", "pla", "e", "du", "ar", "do", "mo", "ni", "ca",
            "car", "do", "zo", "ba", "ba", "ca", "ri", "car", "do", "lin", "do", "mar", "pi", "ra", "nha", "xo",
            "xo", "ta", "tra", "vis", "ti", "gre", "le", "ao", "tar", "ta", "ru", "ga", "gor", "gon", "zo", "la"
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
}
