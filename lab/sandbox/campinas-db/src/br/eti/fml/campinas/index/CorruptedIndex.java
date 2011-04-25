package br.eti.fml.campinas.index;

import br.eti.fml.campinas.util.DebugUtil;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CorruptedIndex extends Exception {
    private long position;
    private Node node;

    public CorruptedIndex(long position, Node node) {
        this.position = position;
        this.node = node;
    }

    public CorruptedIndex(String message, long position, Node node) {
        super(message);
        this.position = position;
        this.node = node;
    }

    public CorruptedIndex(String message, Throwable cause, long position, Node node) {
        super(message, cause);
        this.position = position;
        this.node = node;
    }

    public CorruptedIndex(Throwable cause, long position, Node node) {
        super(cause);
        this.position = position;
        this.node = node;
    }

    public long getPosition() {
        return position;
    }

    public Node getNode() {
        return node;
    }

    public String toString() {
        return "Corrupted " + this.node.getType() + " at "
                    + DebugUtil.niceName(this.getPosition())
                + ". More details: " + this.getNode()
                + " - " + super.toString();
    }
}

