import java.lang.Math;

class DoencaErro extends Exception {}
class DoencaErroSintaxeInvalida extends DoencaErro {}

class Doenca
{
  // Constantes:
  public static long DOENCA_DESCONHECIDA = 0;

  // Dados privados:
  private boolean cDoente;
  private String cNome;
  private String cAparencia;
  private int cChanceDeCura;
  private long cCodigo;
  
  // Fun‡äes de classe:
  public static boolean chance(int qtd)
  {
    return (int) (Math.random() * 100 + 1) <= qtd;
  }

  // Construtores:
  public Doenca()
  {
    cDoente = false;
    cNome = new String();
    cAparencia = new String();
    cCodigo = DOENCA_DESCONHECIDA;
    cChanceDeCura = 0;
  }

  public Doenca(Doenca irmao)
  {
    cDoente = irmao.cDoente;
    cNome = new String(irmao.cNome);
    cAparencia = new String(irmao.cAparencia);
    cCodigo = irmao.cCodigo;
    cChanceDeCura = irmao.cChanceDeCura;
  }

  public Doenca(String nome, String aparencia)
  {
    this(nome, aparencia, 0, DOENCA_DESCONHECIDA);
  }

  public Doenca(String nome, String aparencia, int chanceDeCura)
  {
    this(nome, aparencia, chanceDeCura, DOENCA_DESCONHECIDA);
  }

  public Doenca(String nome, String aparencia,
                int chanceDeCura, int codigo)
  {
    this(nome, aparencia, chanceDeCura, (long) codigo);
  }

  public Doenca(String nome, String aparencia,
                int chanceDeCura, long codigo)
  {
    cDoente = true;
    cNome = new String(nome);
    cAparencia = new String(aparencia);
    cChanceDeCura = chanceDeCura;
    cCodigo = codigo;
  }

  public Doenca(String dados)
   throws                        
    DoencaErroSintaxeInvalida     
  {
    if (dados.charAt(0) != '{')
      new DoencaErroSintaxeInvalida();
    else
      {
        try
        {
          int tamanho = dados.length();
          int indice = 0;
          int i;

          for (i = 1; i < tamanho; i++)
          {
            String temp = new String();

            for (;dados.charAt(i) != '}' && dados.charAt(i) != 'ž'; i++)
              temp += dados.charAt(i);

            switch(++indice)
            {
              case 1: cDoente = Boolean.valueOf(temp).booleanValue(); break;
              case 2: cNome = new String(temp); break;
              case 3: cAparencia = new String(temp); break;
              case 4: cChanceDeCura = Integer.valueOf(temp).intValue(); break;
              case 5: cCodigo = Long.valueOf(temp).longValue(); break;
            }
          }

          if (dados.charAt(i - 1) != '}')
            new PessoaErroSintaxeInvalida();
        }
        catch(StringIndexOutOfBoundsException e)
        {
          new DoencaErroSintaxeInvalida();
        }
      }
  }

  // Defini‡äes:
  public Doenca redefineChanceDeCura(int chance)
  {
    cChanceDeCura = chance;
    return this;
  }

  // Verifica‡äes:
  public boolean doente()
  {
    return cDoente;
  }

  public String nome()
  {
    return new String(cNome);
  }

  public String aparencia()
  {
    return new String(cAparencia);
  }

  public int chanceDeCura()
  {
    return cChanceDeCura;
  }

  public long codigo()
  {
    return cCodigo;
  }

  public String toString()
  {
    return new String("{"+ cDoente + "ž" + cNome + "ž" + cAparencia + "ž" +
                           cChanceDeCura + "ž" + cCodigo + "}");
  }

  public static Doenca valueOf(String dados)
   throws
    DoencaErroSintaxeInvalida
  {
    return new Doenca(dados);
  }
}
