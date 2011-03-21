package br.eti.fml.impl.cassandra.hector;

import br.eti.fml.data.db.keyvalue.KeyValue;
import br.eti.fml.data.db.keyvalue.KeyValueImpl;
import me.prettyprint.cassandra.connection.HConnectionManager;
import me.prettyprint.cassandra.serializers.AbstractSerializer;
import me.prettyprint.cassandra.serializers.StringSerializer;
import me.prettyprint.cassandra.service.CassandraHostConfigurator;
import me.prettyprint.hector.api.Cluster;
import me.prettyprint.hector.api.Keyspace;
import me.prettyprint.hector.api.beans.HColumn;
import me.prettyprint.hector.api.ddl.ColumnFamilyDefinition;
import me.prettyprint.hector.api.ddl.ComparatorType;
import me.prettyprint.hector.api.exceptions.HInvalidRequestException;
import me.prettyprint.hector.api.exceptions.HectorException;
import me.prettyprint.hector.api.factory.HFactory;
import me.prettyprint.hector.api.mutation.Mutator;
import me.prettyprint.hector.api.query.ColumnQuery;
import me.prettyprint.hector.api.query.QueryResult;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Queue;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class CassandraHector extends KeyValueImpl {

    private HConnectionManager connectionManager;
    private String defaultColumnFamily;
    private Mutator<String> defaultMutator;
    private Keyspace keyspace;

    private final static StringSerializer stringSerializer = new StringSerializer();
    private final static BytesSerializer bytesSerializer = new BytesSerializer();
    
    public static StringSerializer getDefaultStringSerializer() {
        return stringSerializer;
    }

    @SuppressWarnings("unused")
    public static BytesSerializer getDefaultBytesSerializer() {
        return bytesSerializer;
    }

    public static class BytesSerializer extends AbstractSerializer<byte[]> {
        @Override
        public ByteBuffer toByteBuffer(byte[] obj) {
            return ByteBuffer.wrap(obj);
        }

        @Override
        public byte[] fromByteBuffer(ByteBuffer byteBuffer) {
            byte[] result = new byte[byteBuffer.limit() - byteBuffer.position()];
            byteBuffer.get(result);
            return result;
        }
    }

    public CassandraHector(String clusterName, String keyspace,
                           String defaultColumnFamily, String ... hostsArray) {

        StringBuilder sb = new StringBuilder();

        for (String s : hostsArray) {
            sb.append(s).append(",");
        }

        if (sb.length() > 1) {
            sb.setLength(sb.length() - 1);
        }

        String hosts = sb.toString();

        connectionManager = new HConnectionManager(
            clusterName, new CassandraHostConfigurator(hosts));

        ColumnFamilyDefinition columnFamilyDefinition
                = HFactory.createColumnFamilyDefinition(keyspace,
                    KeyValue.DEFAULT_COLUMN, ComparatorType.UTF8TYPE);

        Cluster cluster = HFactory.getOrCreateCluster(clusterName, hosts);

        if (cluster == null) {
            throw new HectorException("Cluster " + clusterName + " does exists?");
        }

        try {
            cluster.addColumnFamily(columnFamilyDefinition);
        } catch (HInvalidRequestException e) {
            // ignores
        }

        this.keyspace = HFactory.createKeyspace(keyspace, cluster);
        this.defaultColumnFamily = defaultColumnFamily;

        this.defaultMutator
                = HFactory.<String, String, byte[]>createMutator(
                    this.keyspace, stringSerializer);
    }

    @Override
    public void put(String key, String column, byte[] data) throws IOException {
        defaultMutator.insert(key, defaultColumnFamily, HFactory.<String, byte[]>
                createColumn(column, data, stringSerializer, bytesSerializer));
    }

    @Override
    public byte[] get(String key, String column) throws IOException {
        ColumnQuery<String, String, byte[]> columnQuery =
            HFactory.createColumnQuery(keyspace,
                    stringSerializer, stringSerializer, bytesSerializer);

        columnQuery.setColumnFamily(defaultColumnFamily).setKey(key).setName(column);
        QueryResult<HColumn<String, byte[]>> result = columnQuery.execute();
        return result.get().getValue();
    }

    @Override
    public void delete(String key, String column) throws IOException {
        defaultMutator.delete(key, defaultColumnFamily, column, stringSerializer);
    }

    @Override
    public void commitQueue(String queueId) throws IOException {
        Queue<Operation> operations = this.getQueueOperations(queueId);

        Mutator<String> mutator = HFactory.<String, String, byte[]>createMutator(
                    this.keyspace, stringSerializer);

        while (!operations.isEmpty()) {
            Operation op = operations.poll();

            if (op.getType().equals(OperationType.DELETE)) {
                mutator.addDeletion(op.getKey(), defaultColumnFamily,
                        op.getColumn(), stringSerializer);
            } else if (op.getType().equals(OperationType.INSERT)) {
                mutator.addInsertion(op.getKey(), defaultColumnFamily,
                        HFactory.<String, byte[]>createColumn(
                                op.getColumn(), op.getValue(),
                                stringSerializer, bytesSerializer));
            }
        }

        mutator.execute();
    }

    @Override
    public void shutdown() throws IOException {
        connectionManager.shutdown();
    }
}
