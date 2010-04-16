package br.eti.fml.easydb.filesystemeasy;

import br.eti.fml.easydb.data.Data;

/**
 *
 * @author felipelalli
 */
abstract class DataFS implements Data {

  private String id;
  private FileSystemEasyDB fs;
  
  DataFS(FileSystemEasyDB fs) {
    this.id = Integer.toString((int)
            (Math.random() * Integer.MAX_VALUE), Character.MAX_RADIX);

    this.fs = fs;
  }
  
  DataFS(FileSystemEasyDB fs, String id) {
    this.id = id;
    this.fs = fs;
  }

  public String getID() {
    return this.id;
  }

  FileSystemEasyDB getFS() {
    return this.fs;
  }
}
