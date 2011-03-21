package br.eti.fml.data.db.keyvalue;

import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

/**
 * A basic implementation helper.
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public abstract class KeyValueImpl implements KeyValue {
    private Map<String, Queue<Operation>> operations
            = new HashMap<String, Queue<Operation>>();

    protected enum OperationType {
        INSERT, DELETE
    }

    protected class Operation {
        private OperationType type;
        private String key;
        private String column;
        private byte[] value;

        Operation(OperationType type, String key, String column, byte[] value) {
            this.type = type;
            this.key = key;
            this.column = column;
            this.value = value;
        }

        public OperationType getType() {
            return type;
        }

        public String getKey() {
            return key;
        }

        public byte[] getValue() {
            return value;
        }

        public String getColumn() {
            return column;
        }
    }

    protected Queue<Operation> getQueueOperations(String queueId) {
        return this.operations.get(queueId);
    }

    @Override
    public void lazyPut(String queueId, String key, byte[] data) throws IOException {
        this.lazyPut(queueId, key, KeyValue.DEFAULT_COLUMN, data);
    }

    @Override
    public void lazyPut(String queueId, String key, String column, byte[] data) throws IOException {
        if (!operations.containsKey(queueId)) {
            operations.put(queueId, new LinkedList<Operation>());
        }

        Operation operation = new Operation(OperationType.INSERT, key, column, data);
        operations.get(queueId).offer(operation);
    }

    @Override
    public void lazyDelete(String queueId, String key) throws IOException {
        this.lazyDelete(queueId, key, KeyValue.DEFAULT_COLUMN);
    }

    @Override
    public void lazyDelete(String queueId, String key, String column) throws IOException {
        if (!operations.containsKey(queueId)) {
            operations.put(queueId, new LinkedList<Operation>());
        }

        Operation operation = new Operation(OperationType.DELETE, key, null, null);
        operations.get(queueId).offer(operation);
    }

    @Override
    public byte[][] getSlice(String key, String startColumn, String endColumn)
            throws IOException, UnsupportedOperationException {

        throw new UnsupportedOperationException("getSlice is not supported yet!");
    }

    @Override
    public byte[] get(String key) throws IOException {
        return this.get(key, KeyValue.DEFAULT_COLUMN);
    }

    @Override
    public void put(String key, byte[] data) throws IOException {
        this.put(key, KeyValue.DEFAULT_COLUMN, data);
    }

    @Override
    public void delete(String key) throws IOException {
        this.delete(key, KeyValue.DEFAULT_COLUMN);
    }
}
