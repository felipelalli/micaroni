package br.eti.fml.joelingo;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class SimpleTextDescribing implements Describing {
    private final LevelDetail levelDetail;

    public SimpleTextDescribing(LevelDetail levelDetail) {
        this.levelDetail = levelDetail;
    }

    @Override
    public String describe(Description description) {
        StringBuilder text = new StringBuilder();

        return text.toString();
    }
}
