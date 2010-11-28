package br.eti.fml.easydb.data;

/**
 *
 * @author felipelalli
 */
public interface ListEntry extends Data {
  public abstract String previousElement();
  public abstract String nextElement();
  public abstract Data getData();

  public boolean isFirst();
  public boolean isLast();
}
