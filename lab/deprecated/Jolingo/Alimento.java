class AlimentoErro extends Exception {}
class AlimentoErroSintaxeInvalida extends AlimentoErro {}

class Alimento
{
  // Dados privados:
  private String cNome;
  private int cMataFome;
  private int cMataSede;
  private int cNutrientes;
  private int cGramas;
  private int cAumentaAlegria;

  // Construtores:
  public Alimento(String nome, int mataFome, int mataSede,
                  int nutrientes, int gramas)
  {
    cNome = new String(nome);
    cMataFome = mataFome;
    cMataSede = mataSede;
    cNutrientes = nutrientes;
    cGramas = gramas;
    cAumentaAlegria = 0;
  }

  public Alimento(String nome, int mataFome, int mataSede,
                  int nutrientes, int gramas, int aumentaAlegria)
  {
    cNome = new String(nome);
    cMataFome = mataFome;
    cMataSede = mataSede;
    cNutrientes = nutrientes;
    cGramas = gramas;
    cAumentaAlegria = aumentaAlegria;
  }

  public Alimento()
  {
    cNome = new String("?");
  }

  public Alimento(String dados)
   throws                        
    AlimentoErroSintaxeInvalida     
  {
    if (dados.charAt(0) != '{')
      new AlimentoErroSintaxeInvalida();
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
              case 1: cNome = temp; break;
              case 2: cMataFome = Integer.valueOf(temp).intValue(); break;
              case 3: cMataSede = Integer.valueOf(temp).intValue(); break;
              case 4: cNutrientes = Integer.valueOf(temp).intValue(); break;
              case 5: cGramas = Integer.valueOf(temp).intValue();
            }
          }

          if (dados.charAt(i - 1) != '}')
            new AlimentoErroSintaxeInvalida();
        }
        catch(StringIndexOutOfBoundsException e)
        {
          new AlimentoErroSintaxeInvalida();
        }
      }
  }

  // Verifica‡äes:
  public String toString()
  {
    return new String("{" + cNome + "ž" + cMataFome + "ž" + cMataSede + "ž"
                          + cNutrientes + "ž" + cGramas + "}");
  }

  public static Alimento valueOf(String dados)
   throws
    AlimentoErroSintaxeInvalida
  {
    return new Alimento(dados);
  }

  public String nome()
  {
    return new String(cNome);
  }

  public int aumentaAlegria()
  {
    return cAumentaAlegria;
  }

  public int mataFome()
  {
    return cMataFome;
  }

  public int mataSede()
  {
    return cMataSede;
  }

  public int nutrientes()
  {
    return cNutrientes * cGramas;
  }

  public int gramas()
  {
    return cGramas;
  }

  // Defini‡äes:
  public Alimento tiraGramas(int qtd)
  {
    cGramas -= qtd;

    if (cGramas < 0)
      cGramas = 0;

    return this;
  }

  public Alimento tiraGrama()
  {
    return tiraGramas(1);
  }

}

class Agua extends Alimento
{
  public Agua(int gramas)
  {
    super(" gua", 0, 100, 5, gramas);
  }
}
