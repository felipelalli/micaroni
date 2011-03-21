package br.eti.fml.jolingo;

import br.eti.fml.impl.cassandra.hector.CassandraHector;
import com.esotericsoftware.kryo.Kryo;
import me.prettyprint.cassandra.serializers.StringSerializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.nio.ByteBuffer;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Jolingo {
    private static Logger log = LoggerFactory.getLogger(Jolingo.class);

    public static void main(String[] args) throws IOException {
        CassandraHector cassandraHector = new CassandraHector("cassandra small",
                "jolingo_dev", "test", "192.168.122.50", "192.168.122.151",
                "192.168.122.97");

        StringSerializer ss = CassandraHector.getDefaultStringSerializer();

        byte[] bytes = ss.toBytes("ola");
        System.out.println("size=" + bytes.length);
        cassandraHector.put("oi", bytes);

        byte[] bytes2 = cassandraHector.get("oi");
        System.out.println("size=" + bytes2.length);
        log.info("value=" + ss.fromBytes(bytes2));



        cassandraHector.shutdown();

        System.exit(0);
    }
}
