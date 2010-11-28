package br.eti.fml.easydb.data;

/**
 *
 * @author felipelalli
 */
public interface Data {
  public Type getType();

  /**
   * Return the identification of this data
   * on DB.
   */
  public String getID();

  /**
   * Block until the data is saved in DB.
   * This function DON'T need to be called,
   * unless if you really want to make sure that
   * the data will be saved.
   *
   * @return itself
   */
  public Data saveRightNow();

  /**
   * Block until the data is recovered from DB.
   * This function DON'T need to be called,
   * unless if you really want to make sure that
   * the data is the same of DB.
   *
   * @return itself
   */
  public Data updateRightNow();
}
