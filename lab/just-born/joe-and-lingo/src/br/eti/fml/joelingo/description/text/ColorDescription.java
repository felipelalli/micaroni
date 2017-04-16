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

    /**
     * 0,0,0     - preto
     0,0,85    - azul escuro
     0,0,170   - azul
     0,0,255   - azul intenso
     0,85,0    - verde escuro
     0,85,85   - verde azulado
     0,85,170  - azul royal
     0,85,255  - azul royal claro
     0,170,0   - verde
     0,170,85  - verde esmeralda
     0,170,170 - azul ciano
     0,170,255 - azul taparuere
     0,255,0   - verde intenso
     0,255,85  - esmeralda
     0,255,170 - verde primavera
     0,255,255 - ciano claro
     85,0,0    - vermelho escuro
     85,0,85    - roxo
     85,0,170   - violeta
     85,0,255   - azul violeta
     85,85,0    - bege
     85,85,85   - cinza escuro
     85,85,170  - azul ardósia
     85,85,255  - azul real
     85,170,0   - verde musgo
     85,170,85  - verde opaco
     85,170,170 - ciano opaco
     85,170,255 - azul furtivo
     85,255,0   - verde limão
     85,255,85  - verde limão claro
     85,255,170 - verde piscina
     85,255,255 - ciano claro
     170,0,0     - vermelho escuro
     170,0,85    - rosa escuro
     170,0,170   - violeta intenso
     170,0,255   - roxo intenso
     170,85,0    - marrom
     170,85,85   - salmão escuro
     170,85,170  - roxo opaco
     170,85,255  - violeta opaco
     170,170,0   - amarelo escuro
     170,170,85  - amarelo acinzentado
     170,170,170 - cinza
     170,170,255 - roxo claro
     170,255,0   - verde limão ardente
     170,255,85  - verde limão claro
     170,255,170 - verde claro
     170,255,255 - ciano claro
     255,0,0     - vermelho sangue
     255,0,85    - rosa brilhante
     255,0,170   - pink
     255,0,255   - magenta
     255,85,0    - laranja
     255,85,85   - vermelho terra cotta
     255,85,170  - rosa
     255,85,255  - magenta claro
     255,170,0   - marrom alaranjado
     255,170,85  - bege claro
     255,170,170 - rosa claro
     255,170,255 - rosa violeta
     255,255,0   - amarelo sol
     255,255,85  - amarelo claro
     255,255,170 - amarelo bem claro
     255,255,255 - branco
     */
    private static final String[][][] COLORS = new String[][][] {
            new String[][] {
                new String[] { "preto",         "azul escuro",     "azul",            "azul intenso" },
                new String[] { "verde escuro",  "verde azulado",   "azul royal",      "azul royal claro" },
                new String[] { "verde",         "verde esmeralda", "azul ciano",      "azul taparuere" },
                new String[] { "verde intenso", "esmeralda",       "verde primavera", "azul ciano claro" },
            },
            new String[][] {
                new String[] { "vermelho escuro", "roxo",              "violeta",       "azul violeta" },
                new String[] { "bege escuro",     "cinza escuro",      "azul ardósia",  "azul real" },
                new String[] { "verde musgo",     "verde opaco",       "ciano opaco",   "azul furtivo" },
                new String[] { "verde limão",     "verde limão claro", "verde piscina", "azul ciano claro" }
            },
            new String[][] {
                new String[] { "vermelho escuro",     "rosa escuro",         "violeta intenso", "roxo intenso" },
                new String[] { "marrom",              "salmão escuro",       "roxo opaco",      "violeta opaco" },
                new String[] { "amarelo escuro",      "amarelo acinzentado", "cinza",           "roxo claro" },
                new String[] { "verde limão ardente", "verde limão claro",   "verde claro",     "azul ciano claro" }
            },
            new String[][] {
                new String[] { "vermelho sangue",   "rosa brilhante",       "pink",             "magenta" },
                new String[] { "laranja",           "vermelho terra cotta", "rosa",             "magenta claro" },
                new String[] { "marrom alaranjado", "bege claro",           "rosa claro",       "rosa violeta" },
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
        return COLORS[(int) (red * 3.9999)][(int) (green * 3.9999)][(int) (blue * 3.9999)];
    }
}
