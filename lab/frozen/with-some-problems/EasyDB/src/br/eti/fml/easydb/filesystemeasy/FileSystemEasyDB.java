package br.eti.fml.easydb.filesystemeasy;

import br.eti.fml.easydb.data.DictionaryEasy;
import br.eti.fml.easydb.data.EasyDB;
import br.eti.fml.easydb.data.ListEasy;
import br.eti.fml.easydb.data.PrimitiveType;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author felipelalli
 */
public final class FileSystemEasyDB extends EasyDB {

  private String path;
  private File dir;
  private DictionaryEasy root;

  protected FileSystemEasyDB(String path) throws IOException {
    this.path = path;
    this.dir = new File(path);

    if (!this.dir.isDirectory()) {
      throw new FileNotFoundException(this.dir.toString());
    } else {
      loadDB();
    }
  }

  private synchronized void loadDB() throws IOException {
    String dbIndex = this.path + "/index.db";

    File dbIndexFile = new File(dbIndex);

    if (!dbIndexFile.exists()) {
      DictionaryEasy r = createDictionary();

      PrintWriter pw = new PrintWriter(new FileOutputStream(dbIndexFile));
      pw.println(r.getID());

      pw.close();

      this.root = r;
    } else {
      BufferedReader br = new BufferedReader(new FileReader(dbIndexFile));
      String id = br.readLine();
      DictionaryEasy newRoot = getDictionaryEasy(id);
      
      br.close();

      this.root = newRoot;
    }
  }

  DictionaryEasy getDictionaryEasy(String ID) {
    return new DictionaryEasyFS(this, ID);
  }

  DictionaryEasy createDictionary() {
    return new DictionaryEasyFS(this);
  }

  String getPath() {
    return this.path;
  }

  // external:

  @Override
  public DictionaryEasy getRoot() {
    return this.root;
  }

  @Override
  public synchronized PrimitiveType newPrimitiveType(String name) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  @Override
  public synchronized ListEasy newList(String name) {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  @Override
  public synchronized DictionaryEasy newDictionary(String name) {
    DictionaryEasy newData = createDictionary();
    this.getRoot().put(name, newData);
    return newData;
  }
}
