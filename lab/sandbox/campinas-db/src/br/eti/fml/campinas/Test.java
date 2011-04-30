package br.eti.fml.campinas;

import br.eti.fml.campinas.local.CampinasLocalDB;
import org.apache.log4j.Logger;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicLong;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class Test {
    private static final Logger log = Logger.getLogger(Test.class);

    public static void main(String[] args) throws IOException, InterruptedException {
        CampinasLocalDB db = new CampinasLocalDB("my database", "db", 512);

        log.info(db.getInfo());
        //int tests = 1000000000;
        //int tests = 300000;
        //int tests = 50000000;
        //int tests = 1000000;
        int tests = 800000;

        DecimalFormat format = new DecimalFormat("#,###");
        AtomicLong checkpoint = new AtomicLong(System.currentTimeMillis());
        AtomicLong count = new AtomicLong(0);

        try {
            for (int i = 0; i < tests; i++) {
                count.incrementAndGet();

                String key = "key" + i;
                byte[] value = getValue(i);

                db.put(key, value);

                if (i % 100000 == 0) {
                    log.info(format.format(i) + " - " + getSpeed(checkpoint, count));
                }
            }

            log.info("\n*** CHECKING... ");

            for (int i = 0; i < tests; i++) {
                count.incrementAndGet();

                String key = "key" + i;
                byte[] dataBaseValue = db.get(key);
                byte[] writtenValue = getValue(i);

                if (Arrays.equals(writtenValue, dataBaseValue)) {
                    if (i % 100000 == 0 ) {
                        log.info(format.format(i) + " - "
                                + getSpeed(checkpoint, count));
                    }
                } else {
                    log.info(format.format(i));
                    log.info("*** ERROR " + Arrays.toString(dataBaseValue)
                            + " must be " + Arrays.toString(writtenValue));
                }
            }

            log.info(db.getInfo());

        } finally {
            db.shutdown();
        }
    }

    private final static ByteBuffer buffer = ByteBuffer.allocate(4);
    private final static DecimalFormat format = new DecimalFormat("#,##0");
    private final static DecimalFormat format2 = new DecimalFormat("#," +
            "##0.00000");

    private static String getSpeed(AtomicLong checkpoint, AtomicLong count) {
        long now = System.currentTimeMillis();
        double diffTime = now - checkpoint.get();
        double registersPerSecond = ((double) count.get()) / (diffTime / 1000d);
        double millis = diffTime / count.get();

        checkpoint.set(now);
        count.set(0);
        return format.format(registersPerSecond) + " r/s or "
                + format2.format(millis) + " ms";
    }

    private static byte[] getValue(int i) {
        buffer.position(0);
        buffer.putInt(i);
        byte[] value = new byte[4];
        buffer.position(0);
        buffer.get(value);
        return value;
    }
}
