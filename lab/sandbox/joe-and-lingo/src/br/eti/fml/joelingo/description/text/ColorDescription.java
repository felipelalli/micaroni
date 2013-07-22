package br.eti.fml.joelingo.description.text;

import br.eti.fml.joelingo.LevelDetail;

import java.text.MessageFormat;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
@SuppressWarnings("SpellCheckingInspection")
public class ColorDescription implements Description {
    private final LevelDetail levelDetail;
    private final double red;
    private final double green;
    private final double blue;
    private final Importance importance;
    private final String itemDescribed;

    private static final String[][][] COLORS = new String[][][] {
            new String[][] {
                new String[] { "preto",         "azul escuro",     "azul",            "azul intenso" },
                new String[] { "verde escuro",  "verde azulado",   "azul royal",      "azul royal claro" },
                new String[] { "verde",         "verde esmeralda", "azul ciano",      "azul taparuere" },
                new String[] { "verde intenso", "esmeralda",       "verde primavera", "ciano claro" },
            },
            new String[][] {
                new String[] { "vermelho escuro", "roxo",              "violeta",       "azul violeta" },
                new String[] { "bege",            "cinza escuro",      "azul ardósia",  "azul real" },
                new String[] { "verde musgo",     "verde opaco",       "ciano opaco",   "azul furtivo" },
                new String[] { "verde limão",     "verde limão claro", "verde piscina", "ciano claro" }
            },
            new String[][] {
                new String[] { "vermelho escuro",     "rosa escuro",         "violeta intenso", "roxo intenso" },
                new String[] { "marrom",              "salmão escuro",       "roxo opaco",      "violeta opaco" },
                new String[] { "amarelo escuro",      "amarelo acinzentado", "cinza",           "roxo claro" },
                new String[] { "verde limão ardente", "verde limão claro",   "verde claro",     "ciano claro" }
            },
            new String[][] {
                new String[] { "vermelho sangue",   "rosa brilhante",       "pink",             "magenta" },
                new String[] { "laranja",           "vermelho terra cotta", "rosa",             "magenta claro" },
                new String[] { "marrom alaranjado", "bege",                 "rosa claro",       "rosa violeta" },
                new String[] { "amarelo sol",       "amarelo claro",        "branco amarelado", "branco" }
            },
    };

    public ColorDescription(LevelDetail levelDetail, Importance importance, String itemDescribed, double red, double green, double blue) {
        this.levelDetail = levelDetail;
        this.importance = importance;
        this.itemDescribed = itemDescribed;
        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    @Override
    public Goodness getGoodness() {
        return Goodness.NEUTRAL;
    }

    @Override
    public boolean isRelevant() {
        boolean relevant = false;

        switch (importance) {
            case SEVERE:
                relevant = true;
                break;
            case HIGH:
                relevant = levelDetail.ordinal() > LevelDetail.SMS_TWITTER.ordinal();
                break;
            case LOW:
                relevant = levelDetail.ordinal() > LevelDetail.NORMAL.ordinal();
                break;
        }

        return relevant;
    }

    @Override
    public String toString() {
        return MessageFormat.format(itemDescribed, makeColor());
    }

    private String makeColor() {
        return COLORS[(int) (red * 4)][(int) (green * 4)][(int) (blue * 4)];
    }
}
