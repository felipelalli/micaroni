package br.eti.fml.easydb.data;

import java.util.List;

/**
 *
 * @author felipelalli
 */
public interface ListEasy extends Data {
  public abstract ListEntry getFirstElement();
  public abstract ListEntry getLastElement();

  public abstract ListEntry getListEntryByID(String id);
  public abstract Data getDataByID(String id);

  /**
   * Add after all.
   */
  public abstract ListEasy add(Data newElement);
  
  public abstract ListEasy addBeforeAll(Data newElement);
  public abstract ListEasy addAfter(String elementID, Data newElement);
  public abstract ListEasy addBefore(String elementID, Data newElement);
  
  public abstract ListEasy remove(String elementID);

  public abstract int getSize();

  /**
   *
   * @return um vetor de ID's
   */
  public abstract List<String> createIndex();
}
