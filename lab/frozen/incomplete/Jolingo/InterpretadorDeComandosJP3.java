class InterpretadorDeComandosJP3
{
  public static Resposta executa(String r, JolingoComunidade jc)
  {
    try
    {
      ComandoJP3 comando = new ComandoJP3(r);
      return executa(comando, jc);
    }
    catch(ComandoJP3ErroComandoInvalido e)
    {
      // caso o comando seja inv lido, automaticamente assume-se que ‚ msg.
      try
      {
        ComandoJP3 comando = new ComandoJP3("ms \"" + r + "\" * *");
        return executa(comando, jc);
      }
      catch(ComandoJP3ErroComandoInvalido E){}
    }

    return new Resposta("erro:ocorreu algum erro\n", false);
  }

  public static Resposta executa(ComandoJP3 c, JolingoComunidade jc)
  {
    Resposta retorno = new Resposta("erro:ocorreu algum erro", false);

    switch(c.comando())
    {
      case 1116:  // cria
        {
          try
          {
            Jolingo novoJolingo = new Jolingo(c.argumento());

            if (jc.quantosJolingosComNome(novoJolingo.nome() +
                                          novoJolingo.sobreNomeDaMae() +
                                          novoJolingo.sobreNomeDoPai()) > 0)
              return new Resposta("erro:Jolingo j  existente!", false);
            else
              {
                try
                {
                  if (!novoJolingo.nascido())
                    novoJolingo.nasce();

                  jc.adicionaJolingo(novoJolingo);
                }
                catch(JolingoErroJaNascido e){}
                catch(JolingoErroMorto e){}

                retorno = new Resposta(":Parab‚ns! Joling" +
                                       novoJolingo.sexo() + " " +
                                       novoJolingo.nome() +
                                       " j  est  viv" + novoJolingo.sexo() +
                                       "!" + " Cuide bem de " +
                                       novoJolingo.nome() + "! Boa sorte!");
              }
          }
          catch(JolingoErroSintaxeInvalida e)
          {
            return new Resposta("erro:Erro ao construir o Jolingo", false);
          }
        }
        break;

      case 2156:  // mata
        {
          Object obj = new Object();
          int quantosJolingos = jc.quantosJolingosComNome(c.quem(), obj);

          if (quantosJolingos < 1)
            return new Resposta("erro:Jolingo inexistente!", false);
          else
            if (quantosJolingos > 1)
              return new Resposta("erro:H  mais de um jolingo com esse nome!", false);
            else
              {
                Jolingo j = (Jolingo) obj;

                if (j.comBabaVirtual())
                  return new Resposta("erro:Retire o jolingo da bab  antes de assassin -lo!", false);
                else
                  {
                    try
                    {
                      System.out.println(j);
                      j.morre("assassinato a sangue frio por " + c.dono().nome());
                    }
                    catch(JolingoErroMorto e)
                    {
                      return new Resposta("erro:" + j.nome() + " j  estava " +
                                          "mortinho da silva!", false);
                    }
                    catch(JolingoErroNaoVive e)
                    {
                      return new Resposta("erro:Como se pode matar algo que nÆo vive?",
                                          false);
                    }
                     retorno =  new Resposta(":" + c.dono().nome() +
                                            " assassinou o " + j.nome() +
                                            " com sucesso!", true);
                  }
              }
        }
        break;

      case 5964:  // enterra
        {

        }
        break;

      case 572:   // doa
        {

        }
        break;

      case 5012:  // entrega
        {

        }
        break;

      case 8295:  // liberta
        {

        }
        break;

      case 23026: // tomaposse
        {

        }
        break;

      case 1900:  // pega
        {

        }
        break;

      case 1320:  // come
        {

        }
        break;

      case 858:   // bebe
        {

        }
        break;

      case 2550:  // pula
        {

        }
        break;

      case 5764:  // medico
        {

        }
        break;

      case 2530:  // brinca
        {

        }
        break;

      case 2233:  // banho
        {

        }
        break;

      case 3892:  // estuda
        {

        }
        break;

      case 1210:  // bate
        {

        }
        break;

      case 4030:  // desafia
        {

        }
        break;

      case 2784:  // cruza
        {

        }
        break;

      case 2600:  // aceita
        {

        }
        break;

      case 616:   // ms
        {

        }
        break;

      case 434:   // ve
        {

        }
        break;

      case 2040:  // olha
        {

        }
        break;

      case 17200: // problemas
        {

        }
        break;

      case 5750:  // aparencia
        {

        }
        break;

      case 13192: // historico
        {

        }
        break;

      case 588:   // ls
        {

        }
        break;

      case 1914:  // babas
        {

        }
        break;

      case 2688:  // comida
        {

        }
        break;

      case 18183: // Jesus Salva!
        {

        }
        break;

      case 1:     // /? -?
      case 0:     // ?
      case 2227:  // help
      case 1580:  // ajuda
      default:    // assume-se ajuda
        {
          
        }
    }

    return retorno;
  }
}
