package br.eti.fml.ridiculousdb;

import java.io.File;
import java.io.IOException;
import java.io.Serializable;
import java.util.List;

class Bean implements Serializable {
    public Bean() {
        this.numero = (int) (Math.random() * 1000);
        this.dinheiro = Math.random() * 100d;
    }

    public int numero;
    public double dinheiro;

    @Override
    public String toString() {
        return "b: " + numero + " / " + dinheiro;
    }

    public static CustomComparator getComparatorByNumero() {
        return new CustomComparator() {
            public int compare(byte[] a, byte[] b) {
                Bean beanA = (Bean) RidiculousDB.bytesToObject(a);
                Bean beanB = (Bean) RidiculousDB.bytesToObject(b);

                return beanA.numero == beanB.numero ? 0
                     : beanA.numero < beanB.numero ? -1 : 1;
            }

            public String name() {
                return "NUMERO";
            }
        };
    }

    public static CustomComparator getComparatorByDinheiro() {
        return new CustomComparator() {
            public int compare(byte[] a, byte[] b) {
                Bean beanA = (Bean) RidiculousDB.bytesToObject(a);
                Bean beanB = (Bean) RidiculousDB.bytesToObject(b);

                return beanA.dinheiro == beanB.dinheiro ? 0
                     : beanA.dinheiro < beanB.dinheiro ? -1 : 1;
            }

            public String name() {
                return "DINHEIRO";
            }
        };
    }

    public static CustomComparator getComparatorByBoth() {
        return new CustomComparator() {
            public int compare(byte[] a, byte[] b) {
                Bean beanA = (Bean) RidiculousDB.bytesToObject(a);
                Bean beanB = (Bean) RidiculousDB.bytesToObject(b);

                return beanA.numero == beanB.numero ?
                    (beanA.dinheiro == beanB.dinheiro ? 0
                     : beanA.dinheiro < beanB.dinheiro ? -1 : 1)
                     : beanA.numero < beanB.numero ? -1 : 1;
            }

            public String name() {
                return "BOTH";
            }
        };
    }
}

/**
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public class Main {
    public static void main(String[] args) throws IOException {
        TokyoCabinetRDB db = new TokyoCabinetRDB(
                new File("/home/felipelalli/cdb-data"));

        long time = System.currentTimeMillis();

        {
            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");

            time = System.currentTimeMillis();

            System.out.println("Creating...");

            BigList list = new BigList(db, "bigone",
                    new CustomComparator[]
                        { Bean.getComparatorByNumero(),
                          Bean.getComparatorByDinheiro(),
                          Bean.getComparatorByBoth()
                        });

            for (int i = 0; i < 1000; i++) {
                String newKey = TypesFactory.generateRandomKey();
                new ObjectRDB<Bean>(db, newKey, new Bean());
                list.insert(newKey);
            }

            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");
            
            time = System.currentTimeMillis();

            System.out.println("All...");

            {
                List<String> keys = list.getFirsts(100);

                for (int i = 0; i < keys.size(); i++) {
                    String key = keys.get(i);
                    //System.out.println(i + ": " + new ObjectRDB<Bean>(db, key));
                }
            }

            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");

            time = System.currentTimeMillis();

            System.out.println("Sorted all by numero");

            {
                List<String> keys = list.getSortedFirsts("NUMERO", 100);

                for (int i = 0; i < keys.size(); i++) {
                    String key = keys.get(i);
                    //System.out.println(i + ": " + new ObjectRDB<Bean>(db, key));
                }
            }

            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");

            time = System.currentTimeMillis();

            System.out.println("Sorted all by dinheiro");

            {
                List<String> keys = list.getSortedFirsts("DINHEIRO", 100);

                for (int i = 0; i < keys.size(); i++) {
                    String key = keys.get(i);
                    //System.out.println(i + ": " + new ObjectRDB<Bean>(db, key));
                }
            }

            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");

            time = System.currentTimeMillis();

            System.out.println("Sorted all by both");

            {
                List<String> keys = list.getSortedFirsts("BOTH", 100);

                for (int i = 0; i < keys.size(); i++) {
                    String key = keys.get(i);
                    System.out.println(i + ": " + new ObjectRDB<Bean>(db, key));
                }
            }

            System.out.println("TIME: "
                    + (System.currentTimeMillis() - time) + " ms");

            time = System.currentTimeMillis();

            db.printInfo();
        }

        System.out.println("TIME: " + (System.currentTimeMillis() - time) + " ms");
        db.close();
    }
}
