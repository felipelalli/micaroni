package br.eti.fml.campinas.local.index;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public abstract class Node {
    public enum NodeType {
        INDEX_NODE(IndexNode.INDEX_NODE_SIZE),
        HASH_NODE(HashNode.HASH_NODE_SIZE);

        private int size;

        NodeType(int size) {
            this.size = size;
        }

        public int getSize() {
            return size;
        }
    }

    private boolean corrupted = false;
    private NodeType type;

    protected Node(NodeType type) {
        this.type = type;
    }

    public boolean isCorrupted() {
        return corrupted;
    }

    public void setCorrupted(boolean corruptedNode) {
        this.corrupted = corruptedNode;
    }

    public NodeType getType() {
        return type;
    }
}
