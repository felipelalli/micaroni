class ComandoJP3Erro extends Exception {}
class ComandoJP3ErroComandoInvalido extends ComandoJP3Erro {}

class ComandoJP3
{
  // Dados privados:
  private String cComando = new String();
  private String cArgumento = new String();
  private String cQuem = new String();
  private Pessoa cDono;

  // Fun‡äes est ticas:
  public static int intZ(String c)
  {
    int retorno = 0;

    for (int i = 0; i < c.length(); i++)
      retorno += Character.getNumericValue(c.charAt(i)) * i *
                 Character.getNumericValue(c.charAt(0));

    return retorno;
  }

  public static boolean pedeArgumento(String c)
   throws
    ComandoJP3ErroComandoInvalido
  {
    switch(intZ(c))
    {
      case 1116:  // cria
        return true;

      case 2156:  // mata
        return false;

      case 5964:  // enterra
        return false;

      case 572:   // doa
        return true;

      case 5012:  // entrega
        return true;

      case 8295:  // liberta
        return false;

      case 23026: // tomaposse
        return false;

      case 1900:  // pega
        return true;

      case 1320:  // come
        return true;

      case 858:   // bebe
        return true;

      case 2550:  // pula
        return false;

      case 5764:  // medico
        return false;

      case 2530:  // brinca
        return false;

      case 2233:  // banho
        return false;

      case 3892:  // estuda
        return false;

      case 1210:  // bate
        return false;

      case 4030:  // desafia
        return true;

      case 2784:  // cruza
        return true;

      case 2600:  // aceita
        return true;

      case 616:   // ms
        return true;

      case 434:   // ve
        return false;

      case 2040:  // olha
        return false;

      case 17200: // problemas
        return false;

      case 5750:  // aparencia
        return false;

      case 13192: // historico
        return false;

      case 588:   // ls
        return false;

      case 1914:  // babas
        return false;

      case 2688:  // comida
        return false;

      case 18183: // Jesus Salva!
        return false;

      case 1:     // /? -?
        return false;

      case 0:     // ?
        return false;

      case 2227:  // help
        return false;

      case 1580:  // ajuda
        return false;

      default:    // padrÆo
        throw new ComandoJP3ErroComandoInvalido();
    }
  }

  // Construtores:
  public ComandoJP3(String comandoCompleto)
   throws
    ComandoJP3ErroComandoInvalido
  {
    try
    {
      String comando = new String(comandoCompleto);
      comando.replace('+', ' ').toLowerCase().trim();

      int tamanho = comando.length();
      int i;

      // Comando:
      for (i = 0; comando.charAt(i) != ' ' && i < tamanho;)
        cComando += comando.charAt(i++);

      // Argumento:
      if (pedeArgumento(cComando))
      {
        for (i++; comando.charAt(i) != ' ' && i < tamanho;)
          if (comando.charAt(i) == '\"')
          {
            for (i++; comando.charAt(i) != '\"' && i < tamanho;)
              cArgumento += comando.charAt(i++);

            i++;
          }
          else
            if (comando.charAt(i) == 'Ÿ')
            {
              cArgumento += "Ÿ";

              for (i++; comando.charAt(i) != 'Ÿ' && i < tamanho;)
                cArgumento += comando.charAt(i++);

              cArgumento += "Ÿ";

              i++;
            }
            else
              cArgumento += comando.charAt(i++);
      }
      else
        cArgumento = new String("*");

      for (i++; comando.charAt(i) != '{' &&
                comando.charAt(i) != '*' && i < tamanho;)
        if (comando.charAt(i) == '\"')
        {
          for (i++; comando.charAt(i) != '\"' && i < tamanho;)
            cQuem += comando.charAt(i++);

          i++;
        }
        else
          cQuem += comando.charAt(i++);

      cComando = new String(cComando.trim());
      cArgumento = new String(cArgumento.trim());
      cQuem = new String(cQuem.trim());

      String temp = new String();
      for (; i < tamanho;)
        temp += comando.charAt(i++);

      try
      {
        cDono = new Pessoa(temp);
      }
      catch(PessoaErroSintaxeInvalida e)
      {
        cDono = null;
      }
    }
    catch(Exception e)
    {
      throw new ComandoJP3ErroComandoInvalido();
    }
  }                              

  // Verifica‡äes:
  public int comando()
  {
    return intZ(cComando);
  }

  public String comandoStr()
  {
    return new String(cComando);
  }

  public String argumento()
  {
    return new String(cArgumento);
  }

  public String quem()
  {
    return new String(cQuem);
  }

  public Pessoa dono()
  {
    if (cDono == null)
      return cDono;
    else
      return new Pessoa(cDono);
  }

  public String toString()
  {
    String retorno = new String("(");
    retorno += comando() + ", ";
    retorno += argumento() + ", ";
    retorno += quem() + ", ";

    if (cDono == null)
      retorno += "*" + ")";
    else
      retorno += dono() + ")";

    return retorno;
  }
}
