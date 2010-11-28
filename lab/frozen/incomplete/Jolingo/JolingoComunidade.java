class JolingoComunidadeErro extends JolingoErro {}
class JolingoComunidadeErroVazia extends JolingoComunidadeErro {}
class JolingoComunidadeErroIncompatibilidade extends JolingoComunidadeErro {}

class JolingoComunidadeItem
{
  // Constantes:
  public static char JOLINGO = 'j';
  public static char BABA_VIRTUAL = 'b';
  public static char ALIMENTO = 'a';

  // Dados privados:
  private char cSou;
  private Object cEu;

  // Construtor:
  public JolingoComunidadeItem(Object esta, char oQueSou)
  {
    cSou = oQueSou;
    cEu = esta;
  }

  // Verifica‡äes:
  public char sou()
  {
    return cSou;
  }

  public Object eu()
  {
    return cEu;
  }
}

class JolingoComunidadeNo
{
  // Dados privados:
  private Object cEu;
  private JolingoComunidadeNo cProx;

  // Construtor:
  public JolingoComunidadeNo(Object esta, JolingoComunidadeNo prox)
  {
    cEu = esta;
    cProx = prox;
  }

  // Verifica‡äes:
  public Object eu()
  {
    return cEu;
  }

  public JolingoComunidadeNo proxima()
  {
    return cProx;
  }

  // Defini‡äes:
  public JolingoComunidadeNo proxima(JolingoComunidadeNo prox)
  {
    cProx = prox;
    return this;
  }
}

class JolingoComunidadeLista
{
  // Dados privados:
  private JolingoComunidadeNo cTopo;
  private int cNItens;

  // Construtor:
  public JolingoComunidadeLista()
  {
    cTopo = null;
  }

  // Fun‡äes:
  public JolingoComunidadeLista adiciona(Object outroItem)
  {
    cNItens++;

    if (vazio())
    {
      cTopo = new JolingoComunidadeNo(outroItem, null);
      cTopo.proxima(cTopo);
    }
    else
      cTopo.proxima(new JolingoComunidadeNo(outroItem, cTopo.proxima()));

    return this;
  }

  public boolean vazio()
  {
    return cTopo == null;
  }

  public Object retira()
   throws
    JolingoComunidadeErroVazia
  {
    if (vazio())
      throw new JolingoComunidadeErroVazia();
    else
      {
        cNItens--;
        Object retorno = atual();

        if (cNItens == 0)
          cTopo = null;
        else
          cTopo.proxima(cTopo.proxima().proxima());

        return retorno;
      }
  }

  public Object atual()
   throws
    JolingoComunidadeErroVazia
  {
    if (vazio())
      throw new JolingoComunidadeErroVazia();
    else
      return cTopo.proxima().eu();
  }

  public Object proxima()
   throws
    JolingoComunidadeErroVazia
  {
    if (vazio())
      throw new JolingoComunidadeErroVazia();
    else
      {
        cTopo = cTopo.proxima();
        return atual();
      }
  }

  public int nItens()
  {
    return cNItens;
  }

  public String toString()
  {
    String retorno = new String("[");

    try
    {
      for (int i = 1; i <= nItens(); i++)
      {
        retorno += atual();
        proxima();

        if (i < nItens())
          retorno += "&";
      }

      retorno += "]";
    }
    catch(JolingoComunidadeErroVazia E)
    {}

    return retorno;
  }
}

class JolingoComunidade extends JolingoComunidadeLista
{
  private String cNome;
  private String cAcaoDaBaba = new String();

  // Construtor:
  public JolingoComunidade(String nome)
  {
    super();
    cNome = new String(nome);
  }

  // Verifica‡äes:
  public String toString()
  {
    String retorno = new String();
    retorno = "Comunidade " + nome() + ":\n";

    if (vazio())
      retorno += "[vazia]";
    else
      try
      {
        for (int i = 1; i <= nItens(); i++)
        {
          if (oQueE() == JolingoComunidadeItem.JOLINGO)
            retorno += "Jolingo: " + jolingoAtual();
          else
            if (oQueE() == JolingoComunidadeItem.BABA_VIRTUAL)
              retorno += "Bab  Virtual: " + babaVirtualAtual();
            else
              if (oQueE() == JolingoComunidadeItem.ALIMENTO)
                retorno += "Alimento: " + alimentoAtual();

          if (i != nItens())
            retorno += "\n";

          proxima();
        }
      }
      catch(JolingoErro e){}

    retorno += cAcaoDaBaba;

    cAcaoDaBaba = new String();

    return retorno;
  }

  public String nome()
  {
    return new String(cNome);
  }

  public char oQueE()
   throws
    JolingoComunidadeErroVazia
  {
    return ((JolingoComunidadeItem) atual()).sou();
  }

  public Alimento alimentoAtual()
   throws
    JolingoComunidadeErroVazia,
     JolingoComunidadeErroIncompatibilidade
  {
    if (oQueE() != JolingoComunidadeItem.ALIMENTO)
      throw new JolingoComunidadeErroIncompatibilidade();

    return (Alimento) ((JolingoComunidadeItem) atual()).eu();
  }

  public Jolingo jolingoAtual()
   throws
    JolingoComunidadeErroVazia,
     JolingoComunidadeErroIncompatibilidade
  {
    if (oQueE() != JolingoComunidadeItem.JOLINGO)
      throw new JolingoComunidadeErroIncompatibilidade();

    return (Jolingo) ((JolingoComunidadeItem) atual()).eu();
  }

  public BabaVirtual babaVirtualAtual()
   throws
    JolingoComunidadeErroVazia,
     JolingoComunidadeErroIncompatibilidade
  {
    if (oQueE() != JolingoComunidadeItem.BABA_VIRTUAL)
      throw new JolingoComunidadeErroIncompatibilidade();

    return (BabaVirtual) ((JolingoComunidadeItem) atual()).eu();
  }

  public int quantosJolingosComNome(String nome)
  {
    Object ops = new Object();
    return quantosJolingosComNome(nome, ops);
  }

  public int quantosJolingosComNome(String nome, Object retorno)
  {
    int qtd = 0;

    try
    {
      if (vazio())
        return 0;
      else                
        {
          try
          {
            for (int i = 1; i <= nItens(); i++)
            {
              if (oQueE() == JolingoComunidadeItem.JOLINGO)
              {
                if (
                     jolingoAtual().nome().equalsIgnoreCase(nome) ||

                     (jolingoAtual().nome() +
                     jolingoAtual().sobreNomeDoPai()).
                     equalsIgnoreCase(nome) ||

                     (jolingoAtual().nome() +
                     jolingoAtual().sobreNomeDaMae()).
                     equalsIgnoreCase(nome) ||

                     (jolingoAtual().nome() +
                     jolingoAtual().sobreNomeDaMae() +
                     jolingoAtual().sobreNomeDoPai()).equalsIgnoreCase(nome)
                   )
                {
                  qtd++;
                  retorno = jolingoAtual();
                }
              }
              else
              {
                for (int c = 1; c <= babaVirtualAtual().nItens(); c++)
                  if (
                       babaVirtualAtual().jolingoAtual().nome().
                       equalsIgnoreCase(nome) ||

                       (babaVirtualAtual().jolingoAtual().nome() +
                       babaVirtualAtual().jolingoAtual().sobreNomeDoPai()).
                       equalsIgnoreCase(nome) ||

                       (babaVirtualAtual().jolingoAtual().nome() +
                       babaVirtualAtual().jolingoAtual().sobreNomeDaMae()).
                       equalsIgnoreCase(nome) ||

                       (babaVirtualAtual().jolingoAtual().nome() +
                       babaVirtualAtual().jolingoAtual().sobreNomeDaMae() +
                       babaVirtualAtual().jolingoAtual().sobreNomeDoPai()).
                       equalsIgnoreCase(nome)
                     )
                  {
                    qtd++;
                    retorno = babaVirtualAtual().jolingoAtual();
                  }
              }

              proxima();
            }
          }
          catch(JolingoComunidadeErroIncompatibilidade e){}
        }
    }
    catch(JolingoComunidadeErroVazia e){}

    return qtd;
  }

  // Defini‡äes:
  public JolingoComunidade adicionaJolingo(Jolingo j)
  {
    adiciona(new JolingoComunidadeItem(j, JolingoComunidadeItem.JOLINGO));
    return this;
  }

  public JolingoComunidade adicionaBabaVirtual(BabaVirtual b)
  {
    adiciona(new JolingoComunidadeItem(b, JolingoComunidadeItem.BABA_VIRTUAL));
    return this;
  }

  public JolingoComunidade adicionaAlimento(Alimento a)
  {
    adiciona(new JolingoComunidadeItem(a, JolingoComunidadeItem.ALIMENTO));
    return this;
  }

  // Fun‡äes
  public JolingoComunidade vive(int segundos)
   throws
    JolingoComunidadeErroVazia
  {
    for (int i = 0; i < segundos; i++)
      vive();

    return this;
  }

  public JolingoComunidade vive()
   throws
    JolingoComunidadeErroVazia
  {
    try
    {
      for (int i = 1; i <= nItens(); i++)
      {
        if (oQueE() == JolingoComunidadeItem.JOLINGO)
        {
          try
          {
            jolingoAtual().vive();
          }
          catch(JolingoErroNaoVive e){}
        }
        else
          if (oQueE() == JolingoComunidadeItem.BABA_VIRTUAL)
          {
            for (int c = 1; c <= babaVirtualAtual().nItens(); c++)
            {
              try
              {
                babaVirtualAtual().jolingoAtual().vive();
              }
              catch(JolingoErroNaoVive e){}

              babaVirtualAtual().proxima();
            }
    
            if (Jolingo.chance(10))
              cAcaoDaBaba = new String(" - A‡Æo da Bab  " +
                            babaVirtualAtual().nome() + ": " +
                            babaVirtualAtual().cuida());
          }

        proxima();
      }
    }
    catch(JolingoComunidadeErroIncompatibilidade e){}

    return this;
  }
}
