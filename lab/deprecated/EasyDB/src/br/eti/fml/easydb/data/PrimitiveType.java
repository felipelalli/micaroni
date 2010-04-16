package br.eti.fml.easydb.data;

import java.io.Serializable;

/**
 *
 * @author felipelalli
 */
public interface PrimitiveType<T extends Serializable> extends Data {
  /**
   * Get the value saved on DB. This function DON'T read
   * the DB again, just return the value of memory.
   */
  public T getValue();

  public Class getClassType();

  /**
   * This function will set the new value on memory and don't must
   * block. The DB system need to save this value on DB as soon as possible.
   * 
   * @return itself
   */
  public PrimitiveType<T> setValue(T newValue);
}
