package br.eti.fml.easydb.filesystemeasy;

import br.eti.fml.basic.CreationError;
import br.eti.fml.basic.Factory;
import java.io.IOException;

/**
 *
 * @author felipelalli
 */
public class EasyDBFactory extends Factory<FileSystemEasyDB> {

  private static FileSystemEasyDB singleton = null;
  private String path;

  public EasyDBFactory(String path) {
    this.path = path;
  }

  @Override
  public FileSystemEasyDB createNew() throws CreationError {
    try {
      EasyDBFactory.singleton = new FileSystemEasyDB(this.path);
    } catch (IOException e) {
      throw new CreationError(e);
    }

    return EasyDBFactory.singleton;
  }
}
