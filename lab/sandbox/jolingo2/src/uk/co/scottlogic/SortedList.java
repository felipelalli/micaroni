package uk.co.scottlogic;

import java.io.Serializable;
import java.lang.reflect.Array;
import java.util.AbstractList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * SortedList is an implementation of a {@link List}, backed by an AVL tree.
 * Does not support any optional operations, with the exception of: {@code remove(int)},
 * {@code remove(Object)}, {@code clear} and {@code add()}.
 * <p/>
 * Performs all the main operations: {@code contains}, {@code add}, {@code remove} and {@code get}
 * in time <i>O(log(n))</i>, where <i>n</i> is the number of elements in the list.
 * <p/>
 * This implementation is not synchronised so if you need multi-threaded access then consider wrapping
 * it using the {@link Collections#synchronizedList} method.
 * <p/>
 * The iterators this list provides are <i>fail-fast</i>, so any structural
 * modification, other than through the iterator itself, cause it to throw a
 * {@link ConcurrentModificationException}.
 *
 * @param <T> the type of element that this sorted list will store.
 * @author Mark Rhodes
 * @version 1.1
 * @see List
 * @see Collection
 * @see AbstractList
 */
public class SortedList<T> extends AbstractList<T> implements Serializable {

    private static final long serialVersionUID = -7115342129716877152L;

    //the entry point into the data structure..
    private Node root;

    //The comparator to use when comparing the list elements.
    private final Comparator comparator;

    /**
     * Constructs a new, empty SortedList which sorts the elements
     * according to the given {@code Comparator}.
     *
     * @param comparator the {@code Comparator} to sort the elements by.
     */
    public SortedList(Comparator comparator) {
        this.comparator = comparator;
    }

    public SortedList() {
        this(new Comparator<Comparable>() {
            @Override
            public int compare(Comparable o1, Comparable o2) {
                return o1.compareTo(o2);
            }
        });
    }

    /**
     * Inserts the given object into this {@link SortedList} at the appropriate
     * location, so as to ensure that the elements in the list are kept in
     * the order specified by the given {@code Comparator}.
     * <p/>
     * This method only allows non-null values to be added to the list, if the given
     * object is null, the list remains unaltered and false returned.
     *
     * @param object the object to add.
     * @return false when the given object is null and true otherwise.
     */
    @Override
    public boolean add(T object) {
        boolean treeAltered = false;
        if (object != null) {
            //wrap the value in a node..
            Node toAdd = new Node(object);
            if (root == null) { //structure is currently empty..
                root = toAdd;
            } else {
                Node current = root;
                while (current != null) { //should always break!
                    int comparison = toAdd.compareTo(current);

                    if (comparison < 0) { //toAdd < node
                        if (current.leftChild == null) {
                            current.setLeftChild(toAdd);
                            break;
                        } else {
                            current = current.leftChild;
                        }
                    } else { //toAdd > node (equal should not be possible)
                        if (current.rightChild == null) {
                            current.setRightChild(toAdd);
                            break;
                        } else {
                            current = current.rightChild;
                        }
                    }
                }
            }
            treeAltered = true;
            modCount++; //see AbstractList#modCount, incrementing this allows for iterators to be fail-fast..
        }
        return treeAltered;
    }


    /**
     * Tests if this tree has exactly the same structure and values as the given one,
     * should only be used for testing.
     *
     * @param other the {@code SortedList} to compare this to.
     * @return true if and only if all this {@code SortedList} are structurally the same with
     *         each node containing the same values.
     */
    boolean structurallyEqualTo(SortedList<T> other) {
        return (other == null) ? false : structurallyEqualTo(root, other.root);
    }

    private boolean structurallyEqualTo(Node currentThis, Node currentOther) {
        if (currentThis == null) {
            return currentOther == null;
        } else if (currentOther == null) {
            return false;
        }
        return currentThis.value.equals(currentOther.value)
                && structurallyEqualTo(currentThis.leftChild, currentOther.leftChild)
                && structurallyEqualTo(currentThis.rightChild, currentOther.rightChild);
    }

    /**
     * Returns the number of elements in this {@code SortedList}.
     *
     * @return the number of elements stored in this {@code SortedList}.
     */
    @Override
    public int size() {
        return (root == null) ? 0 : 1 + root.numChildren;
    }

    /**
     * Returns whether or not the given object is present in this {@code SortedList}.
     * The comparison check uses the {@code Object#equals(Object)} method and work
     * under the assumption that the given <code>obj</code> must have type <code>T</code>
     * to be equal to the elements in this {@code SortedList}.  Works in time
     * <i>O(log(n))</i>, where <i>n</i> is the number of elements in the list.
     *
     * @param obj the object to check for.
     * @return true if the given object is present in this {code SortedList}.
     */
    @SuppressWarnings("unchecked")
    @Override
    public boolean contains(Object obj) {
        return obj != null
                && !isEmpty()
                && findFirstNodeWithValue((T) obj) != null;
    }

    //Returns the node representing the given value in the tree, which can be null if
    //no such node exists..
    private Node findFirstNodeWithValue(T value) {
        Node current = root;
        while (current != null) {
            //use the comparator on the values, rather than nodes..
            int comparison = comparator.compare(current.value, value);
            if (comparison == 0) {
                //find the first such node..
                while (current.leftChild != null
                        && comparator.compare(current.leftChild.value, value) == 0) {
                    current = current.leftChild;
                }
                break;
            } else if (comparison < 0) { //need to go right..
                current = current.rightChild;
            } else {
                current = current.leftChild;
            }
        }
        return current;
    }

    /**
     * Removes and returns the element at the given index in this {@code SortedList}.  Since the list
     * is sorted this is the "index"-th smallest element, counting from 0-<i>n</i>-1.
     * <p/>
     * For example, calling {@code remove(0)} will remove the smallest element in the list.
     *
     * @param index the index of the element to remove.
     * @return the element which was removed from the list.
     * @throws IllegalArgumentException in the case that the index is not a valid index.
     */
    @Override
    public T remove(int index) {
        //get the node at the index, will throw an error if the node index doesn't exist..
        Node nodeAtIndex = findNodeAtIndex(index);
        remove(nodeAtIndex);
        return nodeAtIndex.value;
    }

    /**
     * Removes the first node in the list with the given value, if such
     * a node exists, otherwise does nothing.  Comparisons
     * on elements are done using the {@code #equals(Object)} method.
     * <p/>
     * Returns whether or not a matching element was found and removed or not.
     *
     * @param value the object to remove from this {@code SortedList}.
     * @return <code>true</code> if the given object was found in this
     *         {@code SortedList} and removed, <code>false</code> otherwise.
     */
    @Override
    public boolean remove(Object value) {
        boolean treeAltered = false;
        if (value != null && root != null && value.getClass().equals(root.value.getClass())) {
            @SuppressWarnings("unchecked")
            Node toRemove = findFirstNodeWithValue((T) value);
            if (toRemove != null) {
                remove(toRemove);
                treeAltered = true;
            }
        }
        return treeAltered;
    }

    //removes the given node from the tree, rebalancing if required, adds to modcount too..
    private void remove(Node toRemove) {
        if (toRemove.isLeaf()) {
            Node parent = toRemove.parent;
            if (parent == null) { //case where there is only one element in the list..
                root = null;
            } else {
                toRemove.detachFromParentIfLeaf();
            }
        } else if (toRemove.hasTwoChildren()) { //interesting case..
            Node successor = toRemove.successor(); //will not be a non-null leaf or has one child!!

            //switch the values of the nodes over, then delete the switched node..
            toRemove.switchValuesForThoseIn(successor);
            remove(successor); //will be one of the simpler cases.

        } else if (toRemove.leftChild != null) {
            toRemove.leftChild.contractParent();
        } else { //leftChild is null but right isn't..
            toRemove.rightChild.contractParent();
        }
        modCount++; //see AbstractList#modCount, incrementing this allows for iterators to be fail-fast..
    }

    /**
     * Returns the element at the given index in this {@code SortedList}.  Since the list is sorted,
     * this is the "index"th smallest element, counting from 0-<i>n</i>-1.
     * <p/>
     * For example, calling {@code get(0)} will return the smallest element in the list.
     *
     * @param index the index of the element to get.
     * @return the element at the given index in this {@code SortedList}.
     * @throws IllegalArgumentException in the case that the index is not a valid index.
     */
    @Override
    public T get(int index) {
        return findNodeAtIndex(index).value;
    }

    //Returns the node at the given index.
    //throws IllegalArgumentException in the case that the the index is not valid.
    private Node findNodeAtIndex(int index) {
        if (index < 0 || index >= size()) {
            throw new IllegalArgumentException(index + " is not valid index.");
        }
        Node current = root;
        //the the number of smaller elements of the current node as we traverse the tree..
        int totalSmallerElements = (current.leftChild == null) ? 0 : current.leftChild.sizeOfSubTree();
        while (current != null) {  //should always break, due to constraint above..
            if (totalSmallerElements == index) {
                break;
            }
            if (totalSmallerElements > index) { //go left..
                current = current.leftChild;
                totalSmallerElements--;
                totalSmallerElements -= (current.rightChild == null) ? 0 : current.rightChild.sizeOfSubTree();
            } else { //go right.. 
                totalSmallerElements++;
                current = current.rightChild;
                totalSmallerElements += (current.leftChild == null) ? 0 : current.leftChild.sizeOfSubTree();
            }
        }
        return current;
    }

    /**
     * Provides an {@code Iterator} which provides the elements of this {@code SortedList}
     * in the order determined by the given {@code Comparator}.
     * <p/>
     * This implementation allows the entire list to be iterated over in time <i>O(n)</i>,
     * where <i>n</i> is the number of elements in the list.
     *
     * @return an {@code Iterator} which provides the elements of this {@code SortedList}
     *         in the order determined by the given {@code Comparator}.
     */
    @Override
    public Iterator<T> iterator() {
        return new Itr();
    }

    //Implementation of the Iterator interface that uses the successor method
    //to improve speed..
    private class Itr implements Iterator<T> {

        //the index of the next node..
        private int nextIndex = 0;
        private Node nextNode = findNodeAtIndex(0);

        //the last one returned..
        private Node lastReturned = null;

        private int expectedModCount = modCount;

        @Override
        public boolean hasNext() {
            return nextIndex < size();
        }

        @Override
        public T next() {
            checkModCount();

            if (nextNode == null) {
                throw new NoSuchElementException();
            }

            //update fields..
            lastReturned = nextNode;
            nextIndex++;
            nextNode = nextNode.successor();

            return lastReturned.value;
        }

        @Override
        public void remove() {
            checkModCount();

            if (lastReturned == null) {
                throw new IllegalStateException();
            }

            SortedList.this.remove(lastReturned);
            nextIndex--;
            lastReturned = null;
            expectedModCount = modCount;
        }

        //Checks if the expected modcount is what it's expected to be,
        //throws ConcurrentModificationException..
        private void checkModCount() {
            if (expectedModCount != modCount) {
                throw new ConcurrentModificationException();
            }
        }
    }

    /**
     * Returns whether or not the list contains any elements.
     *
     * @return {@code true} if the list has no element in it
     *         and {@code false} otherwise.
     */
    @Override
    public boolean isEmpty() {
        return root == null;
    }

    /**
     * Removes all elements from the list, leaving it empty.
     */
    @Override
    public void clear() {
        root = null; //TF4GC.
    }

    /**
     * Returns a new array containing all the elements in this {@code SortedList}.
     *
     * @return an array representation of this list.
     */
    @Override
    public Object[] toArray() {
        Object[] array = new Object[size()];
        int positionToInsert = 0;  //where the next element should be inserted..

        if (root != null) {
            Node next = root.smallestNodeInSubTree(); //start with the smallest value.
            while (next != null) {
                array[positionToInsert] = next.value;
                positionToInsert++;

                next = next.successor();
            }
        }
        return array;
    }

    /**
     * Copies the elements in the {@code SortedList} to the given array if it is large
     * enough to store them, otherwise it returns a new array of the same type with the
     * elements in it.
     * <p/>
     * If the length of the given array is larger than the size of this {@code SortedList}
     * then, the elements in this list are put into the start of the given array and the
     * rest of the array is left untouched.
     *
     * @return an array representation of this list.
     * @throws ClassCastException in the case that the provided array can not hold
     *                            objects of this type stored in this {@code SortedList}.
     */
    @SuppressWarnings("unchecked")
    @Override
    public <E> E[] toArray(E[] holder) {
        int size = size();

        //if it's not big enough to the elements make a new array of the same type..
        if (holder.length < size) {
            Class<?> classOfE = holder.getClass().getComponentType();
            holder = (E[]) Array.newInstance(classOfE, size);
        }
        //populate the array..
        Iterator<T> itr = iterator();
        int posToAdd = 0;
        while (itr.hasNext()) {
            holder[posToAdd] = (E) itr.next();
            posToAdd++;
        }
        return holder;
    }

    /**
     * Returns the smallest balance factor across the entire list, this serves not other
     * purpose other than for testing.
     *
     * @return the minimum of all balance factors for nodes in this tree, or 0 if this tree is empty.
     */
    int minBalanceFactor() {
        int minBalanceFactor = 0;
        Node current = root;
        while (current != null) {
            minBalanceFactor = Math.min(current.getBalanceFactor(), minBalanceFactor);
            current = current.successor();
        }
        return minBalanceFactor;
    }

    /**
     * Returns the largest balance factor across the entire list, this serves not other
     * purpose other than for testing.
     *
     * @return the maximum of all balance factors for nodes in this tree, or 0 if this tree is empty.
     */
    int maxBalanceFactor() {
        int maxBalanceFactor = 0;
        Node current = root;
        while (current != null) {
            maxBalanceFactor = Math.max(current.getBalanceFactor(), maxBalanceFactor);
            current = current.successor();
        }
        return maxBalanceFactor;
    }

    //Implementation of the AVL tree rebalancing starting at the startNode and working up the tree...
    private void rebalanceTree(Node startNode) {
        Node current = startNode;
        while (current != null) {
            //get the difference between the left and right subtrees at this point..
            int balanceFactor = current.getBalanceFactor();

            if (balanceFactor == -2) { //the right side is higher than the left.
                if (current.rightChild.getBalanceFactor() == 1) { //need to do a double rotation..
                    current.rightChild.leftChild.rightRotateAsPivot();
                }
                current.rightChild.leftRotateAsPivot();

            } else if (balanceFactor == 2) { //left side higher than the right.
                if (current.leftChild.getBalanceFactor() == -1) { //need to do a double rotation..
                    current.leftChild.rightChild.leftRotateAsPivot();
                }
                current.leftChild.rightRotateAsPivot();
            }

            if (current.parent == null) { //the root may have changed so this needs to be updated..
                root = current;
                break;
            } else {
                //make the request go up the tree..
                current = current.parent;
            }
        }
    }

    //to be used as like a static var to get the next node's id..
    private int NEXT_NODE_ID = Integer.MIN_VALUE;

    //Inner class used to represent positions in the tree. Each node stores a list of equal values,
    //is aware of their children and parent nodes, the height of the subtree rooted at that point and
    //the total number of children elements they have (measured in the number of values, not nodes).
    private class Node implements Comparable<Node> {
        final int id = NEXT_NODE_ID++; //get the id and increment it..
        T value; //the data value being stored at this node

        Node leftChild;
        Node rightChild;
        Node parent;

        //The "cached" values used to speed up methods..
        int height;
        int numChildren;

        //Constructs a new Node which initially just stores the given value.
        public Node(T t) {
            this.value = t;
        }

        //Returns whether or not this node two non-null children..
        public boolean hasTwoChildren() {
            return leftChild != null && rightChild != null;
        }

        //Removes this node if it's a leaf node and updates the number of children and heights in the tree..
        public void detachFromParentIfLeaf() {
            if (!isLeaf() || parent == null) {
                throw new RuntimeException("Call made to detachFromParentIfLeaf, but this is not a leaf node with a parent!");
            }
            if (isLeftChildOfParent()) {
                parent.setLeftChild(null);
            } else {
                parent.setRightChild(null);
            }
        }

        //returns the grand parent of this node if there is one..
        public Node getGrandParent() {
            return (parent != null && parent.parent != null) ? parent.parent : null;
        }

        //Moves this node up the tree one notch, updates values and rebalancing the tree..
        public void contractParent() {
            if (parent == null || parent.hasTwoChildren()) {
                throw new RuntimeException("Can not call contractParent on root node or when the parent has two children!");
            }
            Node grandParent = getGrandParent();
            if (grandParent != null) {
                if (isLeftChildOfParent()) {
                    if (parent.isLeftChildOfParent()) {
                        grandParent.leftChild = this;
                    } else {
                        grandParent.rightChild = this;
                    }
                    parent = grandParent;
                } else {
                    if (parent.isLeftChildOfParent()) {
                        grandParent.leftChild = this;
                    } else {
                        grandParent.rightChild = this;
                    }
                    parent = grandParent;
                }
            } else { //no grandparent..
                parent = null;
                root = this; //update root in case it's not done elsewhere..
            }

            //finally clean up by updating values and rebalancing..
            updateCachedValues();
            rebalanceTree(this);
        }

        /**
         * Provides an {@code Iterator} that provides the elements in the order
         * determines by the given {@code Comparator}.  Exhibits fail-fast behaviour
         * which works on a best-effort basis, i.e. it will throw an
         *
         * @return an {@code Iterator} that provides the elements in the order
         *         determines by the given {@code Comparator}.
         */

        //Returns true iff this is the left child of it's parent node..
        public boolean isLeftChildOfParent() {
            return parent != null && parent.leftChild == this;
        }

        //Returns true iff this is the left child of it's parent node..
        public boolean isRightChildOfParent() {
            return parent != null && parent.rightChild == this;
        }

        //Compares the t values using the comparator, if they are equal it uses the
        //node it - older nodes considered to be smaller..
        public int compareTo(Node other) {
            int comparison = comparator.compare(value, other.value);
            return (comparison == 0) ? (id - other.id) : comparison;
        }

        //Finds the smallest node in the tree rooted at this node..
        public Node smallestNodeInSubTree() {
            Node current = this;
            while (current != null) {
                if (current.leftChild == null) {
                    break;
                } else {
                    current = current.leftChild;
                }
            }
            return current;
        }

        //Finds the largest node in the tree rooted at this node..
        public Node largestNodeInSubTree() {
            Node current = this;
            while (current != null) {
                if (current.rightChild == null) {
                    break;
                } else {
                    current = current.rightChild;
                }
            }
            return current;
        }

        //Gets the next biggest node in the tree (which is null if this is the largest)..
        public Node successor() {
            Node successor = null;
            if (rightChild != null) {
                successor = rightChild.smallestNodeInSubTree();
            } else if (parent != null) {
                Node current = this;
                while (current != null && current.isRightChildOfParent()) {
                    current = current.parent;
                }
                successor = current.parent;
            }
            return successor;
        }

        //gets the node that is the next smallest in the tree (null if this is the smallest)..
        @SuppressWarnings("unused")
        public Node predecessor() {
            Node predecessor = null;
            if (leftChild != null) {
                predecessor = leftChild.largestNodeInSubTree();
            } else if (parent != null) {
                Node current = this;
                while (current != null && current.isLeftChildOfParent()) {
                    current = current.parent;
                }
                predecessor = current.parent;
            }
            return predecessor;
        }

        //Sets the child node to the left/right, should only be used if the given node
        //is null or a leaf, and the current child is the same..
        private void setChild(boolean isLeft, Node leaf) {
            //perform the update..
            if (leaf != null) {
                leaf.parent = this;
            }
            if (isLeft) {
                leftChild = leaf;
            } else {
                rightChild = leaf;
            }

            //make sure any change to the height of the tree is dealt with..
            updateCachedValues();
            rebalanceTree(this);
        }

        //returns if this node is leaf or not..
        public boolean isLeaf() {
            return (leftChild == null && rightChild == null);
        }

        //to string method for debugging..
        @Override
        public String toString() {
            StringBuffer sb = new StringBuffer();
            sb.append("[Node: value: ").append(value);
            sb.append(", leftChild value: ").append((leftChild == null) ? "null" : leftChild.value);
            sb.append(", rightChild value: ").append((rightChild == null) ? "null" : rightChild.value);
            sb.append(", height: ").append(height);
            sb.append(", numChildren: ").append(numChildren).append("]\n");
            return sb.toString();
        }

        //performs a left rotation using this node as a pivot..
        public void leftRotateAsPivot() {
            if (parent == null || parent.rightChild != this) {
                throw new RuntimeException("Can't left rotate as pivot has no valid parent node.");
            }

            //first move this node up the tree, detaching parent...
            Node oldParent = parent;
            Node grandParent = getGrandParent();
            if (grandParent != null) {
                if (parent.isLeftChildOfParent()) {
                    grandParent.leftChild = this;
                } else {
                    grandParent.rightChild = this;
                }
            }
            this.parent = grandParent; //could be null.

            //now make old parent left child and put old left child as right child of parent..
            Node oldLeftChild = leftChild;
            oldParent.parent = this;
            leftChild = oldParent;
            if (oldLeftChild != null) {
                oldLeftChild.parent = oldParent;
            }
            oldParent.rightChild = oldLeftChild;

            //now we need to update the values for height and number of children..
            oldParent.updateCachedValues();
        }

        //returns the number of children plus the number of values..
        public int sizeOfSubTree() {
            return 1 + numChildren;
        }

        //performs a left rotation using this node as a pivot..
        public void rightRotateAsPivot() {
            if (parent == null || parent.leftChild != this) {
                throw new RuntimeException("Can't right rotate as pivot has no valid parent node.");
            }
            //first move this node up the tree, detaching parent...
            Node oldParent = parent;
            Node grandParent = getGrandParent();
            if (grandParent != null) {
                if (parent.isLeftChildOfParent()) {
                    grandParent.leftChild = this;
                } else {
                    grandParent.rightChild = this;
                }
            }
            this.parent = grandParent; //could be null.

            //now switch right child to left child of old parent..
            oldParent.parent = this;
            Node oldRightChild = rightChild;
            rightChild = oldParent;
            if (oldRightChild != null) {
                oldRightChild.parent = oldParent;
            }
            oldParent.leftChild = oldRightChild;

            //now we need to update the values for height and number of children..
            oldParent.updateCachedValues();
        }

        //updates the height and the number of children for nodes on the path to this..
        private void updateCachedValues() {
            Node current = this;
            while (current != null) {
                if (current.isLeaf()) {
                    current.height = 0;
                    current.numChildren = 0;
                } else {
                    //deal with the height..
                    int leftTreeHeight = (current.leftChild == null) ? 0 : current.leftChild.height;
                    int rightTreeHeight = (current.rightChild == null) ? 0 : current.rightChild.height;
                    current.height = 1 + Math.max(leftTreeHeight, rightTreeHeight);

                    //deal with the number of children..
                    int leftTreeSize = (current.leftChild == null) ? 0 : current.leftChild.sizeOfSubTree();
                    int rightTreeSize = (current.rightChild == null) ? 0 : current.rightChild.sizeOfSubTree();
                    current.numChildren = leftTreeSize + rightTreeSize;
                }
                //propagate up the tree..
                current = current.parent;
            }
        }

        //Just replaces the values this this node with those in other
        //and updates the number of children in the tree..
        //should only be called when this is doing to be removed and has just one value..
        public void switchValuesForThoseIn(Node other) {
            this.value = other.value;  //switch the values over, nothing else need change..
        }

        //returns (height of the left subtree - the right of the right subtree)..
        public int getBalanceFactor() {
            return ((leftChild == null) ? 0 : leftChild.height + 1) -
                    ((rightChild == null) ? 0 : rightChild.height + 1);
        }

        //Sets the left child node.
        public void setLeftChild(Node leaf) {
            if ((leaf != null && !leaf.isLeaf()) || (leftChild != null && !leftChild.isLeaf())) {
                throw new RuntimeException("setLeftChild should only be called with null or a leaf node, to replace a likewise child node.");
            }
            setChild(true, leaf);
        }

        //Sets the right child node.
        public void setRightChild(Node leaf) {
            if ((leaf != null && !leaf.isLeaf()) || (rightChild != null && !rightChild.isLeaf())) {
                throw new RuntimeException("setRightChild should only be called with null or a leaf node, to replace a likewise child node.");
            }
            setChild(false, leaf);
        }
    } //End of inner class: Node.

}
