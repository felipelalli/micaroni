package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SimpleTextDescribing implements Describing<String> {
    private final LevelDetail levelDetail;

    public SimpleTextDescribing(LevelDetail levelDetail) {
        this.levelDetail = levelDetail;
    }

    @Override
    public String describe(Joelingo joelingo) {
        StringBuilder text = new StringBuilder();

        return text.toString();
    }
}
