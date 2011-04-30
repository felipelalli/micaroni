package br.eti.fml.campinas.local.index;

import br.eti.fml.campinas.util.DebugUtil;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("unused")
public class CorruptedIndexException extends IOException {
    private long position;
    private Node node;

    public CorruptedIndexException(long position, Node node) {
        this.position = position;
        this.node = node;
    }

    public CorruptedIndexException(String message, long position, Node node) {
        super(message);
        this.position = position;
        this.node = node;
    }

    public CorruptedIndexException(String message, Throwable cause, long position, Node node) {
        super(message, cause);
        this.position = position;
        this.node = node;
    }

    public CorruptedIndexException(Throwable cause, long position, Node node) {
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

