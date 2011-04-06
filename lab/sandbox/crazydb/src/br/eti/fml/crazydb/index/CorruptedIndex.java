package br.eti.fml.crazydb.index;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
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
        return "Corrupted node type " + this.node.getType() + " at #"
                    + Long.toHexString(this.getPosition())
                + ". More details: " + this.getNode();
    }
}
