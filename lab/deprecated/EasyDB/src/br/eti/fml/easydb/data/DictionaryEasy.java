package br.eti.fml.easydb.data;

import java.util.HashMap;
import java.util.Set;

/**
 *
 * @author felipelalli
 */
public interface DictionaryEasy extends Data {
  public abstract Data getDataByID(String id);
  //public T get(String name);

  public abstract DictionaryEasy put(String name, Data newData);
  public abstract DictionaryEasy remove(String name);

  /**
   * Retorna um dicionário que são os nomes e o ID do dado.
   */
  public abstract HashMap<String, String> createNativeDictionaryIndexedByName();

  public abstract Set<String> getKeys();
  public abstract int getSize();
}
