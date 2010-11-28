package br.eti.fml.easydb.filesystemeasy;

import br.eti.fml.easydb.data.Data;
import br.eti.fml.easydb.data.DictionaryEasy;
import br.eti.fml.easydb.data.Type;
import java.util.HashMap;
import java.util.Set;

/**
 *
 * @author felipelalli
 */
class DictionaryEasyFS extends DataFS implements DictionaryEasy {

  DictionaryEasyFS(FileSystemEasyDB fs, String id) {
    super(fs, id);

    // Lê
  }
  
  DictionaryEasyFS(FileSystemEasyDB fs) {
    super(fs);

    // salva
  }

  public Type getType() {
    return Type.DICTIONARY;
  }

  public Data saveRightNow() {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public Data updateRightNow() {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public Data getDataByID(String id) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public DictionaryEasy put(String name, Data newData) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public DictionaryEasy remove(String name) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public HashMap<String, String> createNativeDictionaryIndexedByName() {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public Set<String> getKeys() {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  public int getSize() {
    throw new UnsupportedOperationException("Not supported yet.");
  }



}
