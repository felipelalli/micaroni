package br.eti.fml.easydb;

import java.io.IOException;

/**
 *
 * @author felipelalli
 */
public class DatabaseException extends IOException {
  public DatabaseException(String msg) {
    super(msg);
  }

  public DatabaseException(String msg, Throwable t) {
    super(msg, t);
  }
  
  public DatabaseException(Throwable t) {
    super(t);
  }
}
