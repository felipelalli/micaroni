package br.eti.fml.jolingo;

import br.eti.fml.impl.cassandra.hector.CassandraHector;
import me.prettyprint.cassandra.serializers.StringSerializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Jolingo {
    private static final Logger log = LoggerFactory.getLogger(Jolingo.class);

    public static void main(String[] args) throws IOException {
        CassandraHector cassandraHector = new CassandraHector("cassandra small",
                "jolingo_dev", "test", "192.168.122.50",
                    "192.168.122.151", "192.168.122.97");

        StringSerializer ss = CassandraHector.getDefaultStringSerializer();

        log.info("*** V1");

        for (int i = 0; i < 100000; i++) {
            cassandraHector.lazyPut("xxx", "oi" + i, ss.toBytes("ola"));
        }

        cassandraHector.commitQueue("xxx");

        log.info("*** V2");

        for (int i = 0; i < 100000; i++) {
           System.out.println(i + "=" + ss.fromBytes(
                   cassandraHector.get("oi" + i)));
        }

        log.info("*** V3");

        cassandraHector.shutdown();
    }
}
