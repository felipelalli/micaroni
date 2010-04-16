package br.eti.fml.easydb.data;

/**
 *
 * @author felipelalli
 */
public abstract class EasyDB {
  public abstract DictionaryEasy getRoot();

  public abstract PrimitiveType newPrimitiveType(String name);
  public abstract ListEasy newList(String name);
  public abstract DictionaryEasy newDictionary(String name);
}
