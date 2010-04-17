import java.io.File;
import java.io.RandomAccessFile;
import java.io.IOException;
import java.util.Date;
import java.util.Stack;

class Fato
{
  private Date cMomento;
  private int cTamanho;
  private String cFato;

  public Fato(String fato)
  {
    cFato = new String(fato);
    cTamanho = cFato.length();
    cMomento = new Date();
  }

  public Fato(String fato, Date momento)
  {
    cFato = new String(fato);
    cTamanho = cFato.length();
    cMomento = momento;
  }

  public Fato(Fato irmao)
  {
    cMomento = irmao.cMomento;
    cTamanho = irmao.cTamanho;
    cFato = new String(irmao.cFato);
  }

  public String fato()
  {
    return new String(cFato);
  }

  public Date momento()
  {
    return cMomento;
  }

  public int tamanho()
  {
    return cTamanho;
  }

  public String toString()
  {
    return "(" + momento() + ") " + fato();
  }
}

class HistoricoErro extends IOException {}
class HistoricoErroLeitura extends HistoricoErro {}
class HistoricoErroGravacao extends HistoricoErro {}

class Historico
{
  public static String ARQUIVO = "Historico.jolingo";
  public static String INDICE = "Historico.jolingo.indice";

  public static boolean zera()
  {
    try
    {
      File arq = new File(ARQUIVO);
      File arqIndice = new File(INDICE);

      if (arq.exists())
        arq.delete();

      if (arqIndice.exists())
        arqIndice.delete();

      arq.createNewFile();
      arqIndice.createNewFile();
      return true;
    }
    catch(IOException e)
    {
      return false;
    }
  }

  public static void registra(Fato fato)
   throws
    HistoricoErroLeitura,
     HistoricoErroGravacao,
      IOException
  {
    File arq = new File(ARQUIVO);
    File arqIndice = new File(INDICE);

    if (!arq.exists() || !arqIndice.exists())
    {
      if (arq.exists())
        arq.delete();

      if (arqIndice.exists())
        arqIndice.delete();

      arq.createNewFile();
      arqIndice.createNewFile();
    }

    if (!arq.canRead() || !arqIndice.canRead())
      throw new HistoricoErroLeitura();
    else
      if (!arq.canWrite() || !arqIndice.canWrite())
        throw new HistoricoErroGravacao();
      else
        {
          // abre os arquivos para gravaá∆o e leitura:
          RandomAccessFile arquivo = new RandomAccessFile(arq, "rw");
          RandomAccessFile arquivoIndice = new RandomAccessFile(arqIndice, "rw");

          // posiciona os arquivos no final:
          arquivo.seek(arquivo.length());
          arquivoIndice.seek(arquivoIndice.length());

          // grava no arquivo de °ndice a posiá∆o do pr¢ximo registro:
          arquivoIndice.writeLong(arquivo.getFilePointer());

          // grava no arquivo o fato:
          arquivo.writeLong(fato.momento().getTime());
          arquivo.writeInt(fato.tamanho());
          arquivo.write(fato.fato().getBytes());

          // fecha os arquivos:
          arquivo.close();
          arquivoIndice.close();
        }
  }

  public static Stack recupera()
   throws
    HistoricoErroLeitura,
     IOException
  {
    return recupera((int) (Integer.MAX_VALUE / 8));
  }

  public static Stack recupera(int quantos)
   throws
    HistoricoErroLeitura,
     IOException
  {
    // cria uma pilha vazia que ser† o retorno:
    Stack registros = new Stack();

    // trata os arquivos:
    File arq = new File(ARQUIVO);
    File arqIndice = new File(INDICE);

    if (arq.exists() && arqIndice.exists())
    {
      if (!arq.canRead() || !arqIndice.canRead())
        throw new HistoricoErroLeitura();
      else
        {
          // abre os arquivos somente leitura:
          RandomAccessFile arquivo = new RandomAccessFile(arq, "r");
          RandomAccessFile arquivoIndice = new RandomAccessFile(arqIndice, "r");

          // marca a posiá∆o em que se dar† o in°cio:
          long desdeOnde = arquivoIndice.length() - (quantos * 8);
       
          // se o n£mero a ser lido passou do limite, ent∆o s∆o lido todas:
          if (desdeOnde < 0)
            desdeOnde = 0;

          // posiciona o arquivo de °ndice na posiá∆o correta:
          arquivoIndice.seek(desdeOnde);

          // faz enquanto n∆o acaba o arquivo:
          while (arquivoIndice.getFilePointer() < arquivoIndice.length())
          {
            // là no arq. de °nd. que posiá∆o f°sica est† o registro atual:
            long posReal = arquivoIndice.readLong();

            // busca o registro na posiá∆o real indicado pelo arq. de °nd.:
            arquivo.seek(posReal);

            // là o momento do fato:
            long momento = arquivo.readLong();

            // là o tamanho da string:
            int tamanho = arquivo.readInt();

            // là o fato em si de acordo com o tamanho:
            byte[] fatoLido = new byte[tamanho];
            arquivo.read(fatoLido, 0, tamanho);

            // monta um fato e o empilha:
            Fato fato = new Fato(new String(fatoLido), new Date(momento));
            registros.push(fato);
          }
        }
    }

    return registros;
  }
}

