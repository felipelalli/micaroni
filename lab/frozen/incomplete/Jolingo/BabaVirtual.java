class BabaVirtual extends JolingoComunidadeLista
{
  private String cNome;
  private int cQualidade;

  // Construtores:
  public BabaVirtual(String nome)
  {
    this(nome, 50);
  }

  public BabaVirtual(String nome, int qualidade)
  {
    super();
    cNome = new String(nome);
    cQualidade = qualidade;
  }

  // Fun‡äes redefinidas:
  public BabaVirtual adicionaJolingo(Jolingo jolingo)
  {
    jolingo.comBabaVirtual(true);
    adiciona(jolingo);
    return this;
  }

  public Jolingo retiraJolingo()
   throws
    JolingoComunidadeErroVazia,
     JolingoErroSintaxeInvalida
  {
    Jolingo retorno = new Jolingo(((Jolingo) retira()).toString());
    retorno.comBabaVirtual(false);
    return retorno;
  }

  // Verifica‡äes:
  public String nome()
  {
    return new String(cNome);
  }

  public int qualidade()
  {
    return cQualidade;
  }

  public Jolingo jolingoAtual()
   throws
    JolingoComunidadeErroVazia    
  {
    return (Jolingo) atual();
  }

  public String toString()
  {
    String retorno = new String("Bab  " + nome() + " cuidando de: [");

    if (vazio())
      retorno += "ningu‚m]";
    else
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

  // Fun‡äes:
  public Resposta cuida()
  {
    boolean tudoCerto = true;
    String resposta = new String();
    resposta = nome() + " cuidou dos seus Jolingos";

    try
    {
      for (int i = 1; i <= nItens(); i++)
      {
        if (jolingoAtual().morto())
          resposta += ", " + jolingoAtual().nome() + " est  mort" + jolingoAtual().sexo();
        else
          {
            if (!jolingoAtual().dormindo())
            {
              if (jolingoAtual().doente())
                resposta += ", " + jolingoAtual().faz(new AcaoMedico()).msg();
            
              if (jolingoAtual().fome() > 80 ||
                  jolingoAtual().alimentacao() < 20)
                resposta += ", " + jolingoAtual().come(
                new Alimento("banana", 50, 1, 60, 20, 10)).msg();

              if (jolingoAtual().sede() > 80)
                resposta += ", " + jolingoAtual().bebe(new Agua(20)).msg();

              if (jolingoAtual().educacao() < 50)
                resposta += ", " + jolingoAtual().faz(new AcaoBate()).msg();

              if (jolingoAtual().saude() < 20)
                resposta += ", " + jolingoAtual().faz(new AcaoPassaGelol()).msg();

              if (jolingoAtual().alegria() < 10)
                resposta += ", " + jolingoAtual().faz(new AcaoBrinca()).msg();

              if (jolingoAtual().sujeira() > 90)
                resposta += ", " + jolingoAtual().faz(new AcaoBanho()).msg();

              if (jolingoAtual().gramas() > 1000)
                resposta += ", " + jolingoAtual().faz(new AcaoExercicio()).msg();
            }
            else
              {
                resposta += ", " + jolingoAtual().nome() + " est  dormindo";
     
                if (jolingoAtual().fome() > 80 ||
                    jolingoAtual().alimentacao() < 20)
                {
                  jolingoAtual().acorda();
                  resposta += ", " + jolingoAtual().come(
                  new Alimento("banana", 50, 1, 60, 20, 10)).msg();
                }

                if (jolingoAtual().sede() > 80)
                {
                  jolingoAtual().acorda();
                  resposta += ", " + jolingoAtual().bebe(new Agua(20)).msg();
                }
              }
          }

          if (jolingoAtual().morto())
            tudoCerto = false;

        proxima();
      }
    }
    catch(JolingoErro e)
    {}

    return new Resposta(resposta, tudoCerto);
  }
}
