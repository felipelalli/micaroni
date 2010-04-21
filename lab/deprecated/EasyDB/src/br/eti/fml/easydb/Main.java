package br.eti.fml.easydb;

import br.eti.fml.easydb.data.DictionaryEasy;
import br.eti.fml.easydb.data.EasyDB;
import br.eti.fml.easydb.data.PrimitiveType;
import br.eti.fml.easydb.filesystemeasy.EasyDBFactory;

/**
 *
 * @author felipelalli
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        EasyDB easyDB = new EasyDBFactory("/home/felipelalli").createNew();

        DictionaryEasy root = easyDB.getRoot();
        PrimitiveType<Integer> count = easyDB.newPrimitiveType("count");
        
        root.put("test", count);
        
    }

}
