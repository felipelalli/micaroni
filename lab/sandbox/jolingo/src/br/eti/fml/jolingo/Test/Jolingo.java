package br.eti.fml.jolingo.Test;

import org.apache.cassandra.thrift.Column;
import org.apache.cassandra.thrift.ConsistencyLevel;
import org.scale7.cassandra.pelops.Bytes;
import org.scale7.cassandra.pelops.Cluster;
import org.scale7.cassandra.pelops.Mutator;
import org.scale7.cassandra.pelops.Pelops;
import org.scale7.cassandra.pelops.Selector;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.List;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Jolingo {
    private static Logger logger = LoggerFactory.getLogger(Jolingo.class);

    public static void main(String[] args) {
        String pool = "pool";
        String keyspace = "jolingo_dev";
        String colFamily = "test";

        // init the connection pool
        Cluster cluster = new Cluster("192.168.122.50,192.168.122.97,192.168.122.151", 9160);
        Pelops.addPool(pool, cluster, keyspace);

        logger.info("*** A1");
        long now = System.currentTimeMillis();
        Mutator mutator = Pelops.createMutator(pool);

        for (int i = 0; i < 100000; i++) {
            String rowKey = "meu peido " + i;

            // write out some data
            mutator.writeColumns(
                    colFamily, rowKey,
                    mutator.newColumnList(
                            mutator.newColumn("name", "Dan"),
                            mutator.newColumn("age", Bytes.fromInt(33))
                    )
            );
        }

        mutator.execute(ConsistencyLevel.ANY);

        double avg = (System.currentTimeMillis() - now) / 100000d;
        logger.info("*** A2 " + avg + " ms");
        now = System.currentTimeMillis();

        for (int i = 0; i < 100000; i++) {
            String rowKey = "meu peido " + i;
            // read back the data we just wrote
            Selector selector = Pelops.createSelector(pool);
            List<Column> columns = selector.getColumnsFromRow(colFamily, rowKey, false, ConsistencyLevel.ONE);

//            System.out.println("\ni: " + i);
//            System.out.println("Name: " + Selector.getColumnStringValue(columns, "name"));
//            System.out.println("Age: " + Selector.getColumnValue(columns, "age").toInt());
        }

        avg = (System.currentTimeMillis() - now) / 100000d;
        logger.info("*** A3 " + avg + " ms");

        // shut down the pool
        Pelops.shutdown();
    }
}
