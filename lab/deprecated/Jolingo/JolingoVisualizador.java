import java.lang.String;

class JolingoVisualizador
{
  ////////////////
  // CONSTANTES //
  ////////////////
  public static int GERAL = 1;
  public static int SIMPLES = 2;
  public static int DETALHADO = 4;
  public static int PROBLEMAS = 8;
  public static int GENETICA = 16;


  ///////////////////////
  // FUNÄÂES DE CLASSE //
  ///////////////////////
  public static String iniciais(String nome)
  {
    String retorno = new String();
    String auxNome = nome.replace('_', ' ').replace('.', ' ').
                     replace('&', ' ').replace('+', ' ').replace('#', ' ').
                     replace('-', ' ').trim().toUpperCase();

    int tamanho = auxNome.length();
    retorno += auxNome.charAt(0);

    for (int i = 1; i < tamanho; i++)
      if (auxNome.charAt(i) == ' ')
        retorno += auxNome.charAt(++i);

    return retorno;
  }

  public static String ve(Jolingo oTal)
  {
    return ve(oTal, GERAL);
  }

  public static String ve(Jolingo oTal, int modo)
  {
    String retorno = new String();

    switch(modo)
    {
      case 2: // SIMPLES
        {
          if (oTal.livre())
            retorno = "[-LIVRE-] ";
          else
            retorno = "[" + iniciais(oTal.dono()) + "] ";

          retorno += oTal.sexo().toUpperCase() + " " +
                     oTal.nome()               + " " +
                     oTal.sobreNomeDoPai()     + " ";

          if (oTal.morto())
            retorno += "morreu de " + oTal.motivoDaMorte() + ".";
          else
            if (!oTal.nascido())
              retorno += "ainda n∆o nasceu.";
            else
              if (oTal.dormindo())
                retorno += "est† dormindo.";
              else
                {
                  if (oTal.saude() < 20)
                    retorno += "est† quebrad" + oTal.sexo() + " e ";

                  retorno += "est† ";

                  if (oTal.alegria() < 20 ||
                      oTal.sede() > 80 ||
                      oTal.fome() > 80)
                    retorno += "querendo alguma coisa";
                  else
                    if (oTal.alegria() > 90)
                      retorno += "felic°ssim" + oTal.sexo();
                    else
                      if (oTal.alegria() > 60)
                        retorno += "feliz";
                      else
                        if (oTal.alegria() > 40)
                          retorno += "cabisbaix" + oTal.sexo();
                        else
                          if (oTal.alegria() > 10)
                            retorno += "triste";
                          else
                            retorno += "muito triste";

                  retorno += ".";

                  if (oTal.doente() ||
                      Jolingo.chance(oTal.otimismo() * 10 + 1))
                    retorno += " Est† meio estranh" + oTal.sexo() + ".";
                }
        }
        break;

      case 4: // DETALHADO
        {
          if (oTal.livre())
            retorno = "[-LIVRE-] ";
          else
            retorno = "[" + iniciais(oTal.dono()) + "] ";

          retorno += oTal.sexo().toUpperCase() + " " +
                     oTal.nome()               + " " +
                     oTal.sobreNomeDaMae()     + " " +
                     oTal.sobreNomeDoPai()     + " ";

          if (!oTal.nascido())
            retorno += "ainda n∆o nasceu.";
          else
            {
              retorno += "viveu ";

              if (oTal.anos() > 0)
              {
                if (oTal.anos() > 1)
                  retorno += oTal.anos() + " anos, ";
                else
                  retorno += oTal.anos() + " ano, ";
              }

              if (oTal.dias() > 0)
              {
                if (oTal.dias() > 1)
                  retorno += oTal.dias() + " dias, ";
                else
                  retorno += oTal.dias() + " dia, ";
              }

              if (oTal.horas() > 0)
              {
                if (oTal.horas() > 1)
                  retorno += oTal.horas() + " horas, ";
                else
                  retorno += oTal.horas() + " hora, ";
              }

              if (oTal.minutos() > 0)
              {
                if (oTal.minutos() > 1)
                  retorno += oTal.minutos() + " minutos e ";
                else
                  retorno += oTal.minutos() + " minuto e ";
              }

              if (oTal.segundos() > 1)
                retorno += oTal.segundos() + " segundos.\n";
              else
                retorno += oTal.segundos() + " segundo.\n";


              if (oTal.morto())
                retorno += " Morreu de " + oTal.motivoDaMorte() + " pesando " +
                           oTal.gramas() + " gramas e " + oTal.milimetros() +
                           " mil°metros de altura.";
              else
                {
                  retorno += " Est† ";

                  if (oTal.dormindo())
                    retorno += "dormindo, ";
                  else
                    if (oTal.energia() < 30)
                      retorno += "morrendo de sono, ";
                    else
                      if (oTal.energia() < 50)
                        retorno += "com sono, ";
                      else
                        retorno += "acordad" + oTal.sexo() + ", ";

                  retorno += "est† ";

                  if (oTal.doente())
                  {
                    retorno += "doente, com " + oTal.aparencia() +
                               " h† " + oTal.tempoDeDoenca() + " segundos, ";

                    if (oTal.quantasDoencas() >= 2)
                      retorno += "j† teve " + oTal.quantasDoencas() +
                               " doenáas.";
                  }

                  if (oTal.alegria() > 90)
                    retorno += "felic°ssim" + oTal.sexo();
                  else
                    if (oTal.alegria() > 60)
                      retorno += "feliz";
                    else
                      if (oTal.alegria() > 40)
                        retorno += "cabisbaix" + oTal.sexo();
                      else
                        if (oTal.alegria() > 10)
                          retorno += "triste";
                        else
                          retorno += "muito triste";

                  retorno += ", ";

                  if (oTal.fome() > 80)
                    retorno += "com muita fome";
                  else
                    if (oTal.fome() > 50)
                      retorno += "com fome";
                    else
                      if (oTal.fome() > 20)
                        retorno += "com um pouco de fome";

                  retorno += ", ";

                  if (oTal.sede() > 80)
                    retorno += "morrendo de sede";
                  else
                    if (oTal.sede() > 50)
                      retorno += "com sede";
                    else
                      if (oTal.sede() > 20)
                        retorno += "com a boca seca";

                  retorno += ", ";

                  if (oTal.alimentacao() > 80)
                    retorno += "¢tima alimentaá∆o";
                  else
                    if (oTal.alimentacao() > 50)
                      retorno += "boa alimentaá∆o";
                    else
                      if (oTal.alimentacao() > 20)
                        retorno += "com falta de nutrientes";
                      else
                        retorno += "alimentaá∆o prec†ria, est† com sÇrios problemas de nutriá∆o";

                  retorno += ", est† ";

                  if (oTal.saude() > 80)
                    retorno += "°ntegr" + oTal.sexo();
                  else
                    if (oTal.saude() > 50)
                      retorno += "um pouco quebrad" + oTal.sexo();
                    else
                      if (oTal.saude() > 20)
                        retorno += "com feridas vis°veis";
                      else
                        retorno += "espancad" + oTal.sexo();

                  retorno += ", ";

                  if (oTal.otimismo() > 50)
                    retorno += "otimista";
                  else
                    if (oTal.otimismo() > 20)
                      retorno += "desconfiad" + oTal.sexo();
                    else
                      retorno += "pessimista";

                  retorno += ", ";

                  if (oTal.educacao() > 90)
                    retorno += "super educad" + oTal.sexo();
                  else
                    if (oTal.educacao() > 50)
                      retorno += "educad" + oTal.sexo();
                    else
                      if (oTal.educacao() > 20)
                        retorno += "meio mal-educad" + oTal.sexo();
                      else
                        retorno += "sem educaá∆o, muito mal-criad" + oTal.sexo();

                  retorno += " e ";

                  if (oTal.sujeira() > 80)
                    retorno += "imund" + oTal.sexo() + ", fedendo";
                  else
                    if (oTal.sujeira() > 50)
                      retorno += "suj" + oTal.sexo();
                    else
                      if (oTal.sujeira() > 20)
                        retorno += "sujinh" + oTal.sexo();
                      else
                        retorno += "limpinh" + oTal.sexo() +
                                   ", cheiros" + oTal.sexo();

                  retorno += ".";
                }
            }
        }
        break;

      case 8: // PROBLEMAS
        {
          if (oTal.livre())
            retorno = "[-LIVRE-] ";
          else
            retorno = "[" + iniciais(oTal.dono()) + "] ";

          retorno += oTal.sexo().toUpperCase() + " " +
                     oTal.nome()               + " " +
                     oTal.sobreNomeDoPai()     + " ";

          if (oTal.morto())
            retorno += "morreu de " + oTal.motivoDaMorte() + ".";
          else
            if (!oTal.nascido())
              retorno += "tem um enorme problema: ainda n∆o nasceu.";
            else
              if (oTal.dormindo())
                retorno += "est† dormindo.";
              else
                if (!oTal.doente() && oTal.fome() <= 40 &&
                     oTal.sede() <= 40 && oTal.otimismo() >= 50 &&
                     oTal.energia() >= 50 && oTal.alegria() >= 50 &&
                     oTal.alimentacao() >= 50 && oTal.saude() >= 60 &&
                     oTal.educacao() >= 60 && oTal.sujeira() <= 60)
                  retorno += "aparenta estar tudo OK, nada muito sÇrio. ParabÇns a " + oTal.dono() + "!";
                else
                  {
                    retorno += "est† ";

                    if (oTal.doente())
                      retorno += "doente tadinh" + oTal.sexo() +
                      ", est† com " + oTal.aparencia() + ", ";

                    if (oTal.fome() > 80)
                      retorno += "morrendo de fome, ";
                    else
                      if (oTal.fome() > 40)
                        retorno += "com fome, ";

                    if (oTal.sede() > 80)
                      retorno += "morrendo de sede, ";
                    else
                      if (oTal.sede() > 40)
                        retorno += "com sede, ";

                    if (oTal.otimismo() < 20)
                      retorno += "pessimista, ";
                    else
                      if (oTal.otimismo() < 50)
                        retorno += "desconfiad" + oTal.sexo() + ", ";

                    if (oTal.energia() < 30)
                      retorno += "morrendo de sono, ";
                    else
                      if (oTal.energia() < 50)
                        retorno += "cansad" + oTal.sexo() + ", ";

                    if (oTal.alegria() < 20)
                      retorno += "muito triste, ";
                    else
                      if (oTal.alegria() < 50)
                        retorno += "triste, ";

                    if (oTal.alimentacao() < 20)
                      retorno += "com alimentaá∆o prec†ria, ";
                    else
                      if (oTal.alimentacao() < 50)
                        retorno += "falta de nutrientes, ";

                    if (oTal.saude() < 20)
                      retorno += "espancad" + oTal.sexo() + ", ";
                    else
                      if (oTal.saude() < 60)
                        retorno += "quebrad" + oTal.sexo() + ", ";

                    if (oTal.educacao() < 20)
                      retorno += "sem educaá∆o, burr" + oTal.sexo() +
                      " pra caramba e ";
                    else
                      if (oTal.educacao() < 60)
                        retorno += "mal educad" + oTal.sexo() + " e ";

                    retorno += "s¢.";
                  }
        }
        break;

      case 16: // GENêTICA
        {

        }
        break;

      default: // GERAL
        {
          retorno = "Nome: " + oTal.nome() + " " + oTal.sobreNomeDaMae() + " "
                                           + oTal.sobreNomeDoPai() + "\n";
          if (oTal.livre())
            retorno += "Criador: ";
          else
            retorno += "Dono: ";

          retorno += oTal.dono() + "\n";

          if (!oTal.nascido())
            retorno += oTal.nome() + " ainda n∆o nasceu.";
          else
            {
              retorno += "Geneticamente ";

              if (oTal.macho())
                retorno += "ele";
              else
                retorno += "ela";

              retorno += " tem ";

              if (oTal.olhosClaros())
                retorno += "olhos claros";
              else
                retorno += "olhos escuros";

              retorno += ", ";

              if (oTal.cabeloClaro())
                retorno += "cabelo claro";
              else
                retorno += "cabelo escuro";

              retorno += ", ";

              if (oTal.cabeloLiso())
                retorno += "cabelo liso";
              else
                retorno += "cabelo crespo";

              retorno += ", ";

              if (oTal.comeMuito())
                retorno += "come muito, ";

              if (oTal.engordaMuito())
                retorno += "engorda com facilidade, ";

              if (oTal.formatoComprido())
                retorno += "Ç comprid" + oTal.sexo();
              else
                retorno += "parece uma bolinha";

              retorno += ", ";

              if (oTal.fofinho())
                retorno += "Ç fofinh" + oTal.sexo();
              else
                retorno += "Ç dur" + oTal.sexo();

              retorno += ", ";

              if (oTal.feiura() > 80)
                retorno += "Ç muito fei" + oTal.sexo();
              else
                if (oTal.feiura() > 50)
                  retorno += "Ç fei" + oTal.sexo();
                else
                  if (oTal.feiura() > 20)
                    retorno += "Ç bonitinh" + oTal.sexo();
                  else
                    retorno += "Ç lind" + oTal.sexo();

              retorno += " e ";

              if (oTal.fraqueza() > 80)
                retorno += "muito frac" + oTal.sexo();
              else
                if (oTal.fraqueza() > 50)
                  retorno += "frac" + oTal.sexo();
                else
                  if (oTal.fraqueza() > 20)
                    retorno += "fortinh" + oTal.sexo();
                  else
                    retorno += "forte";

              retorno += ".\n";
              retorno += "Viveu ";

              if (oTal.anos() > 0)
              {
                if (oTal.anos() > 1)
                  retorno += oTal.anos() + " anos, ";
                else
                  retorno += oTal.anos() + " ano, ";
              }

              if (oTal.dias() > 0)
              {
                if (oTal.dias() > 1)
                  retorno += oTal.dias() + " dias, ";
                else
                  retorno += oTal.dias() + " dia, ";
              }

              if (oTal.horas() > 0)
              {
                if (oTal.horas() > 1)
                  retorno += oTal.horas() + " horas, ";
                else
                  retorno += oTal.horas() + " hora, ";
              }

              if (oTal.minutos() > 0)
              {
                if (oTal.minutos() > 1)
                  retorno += oTal.minutos() + " minutos e ";
                else
                  retorno += oTal.minutos() + " minuto e ";
              }

              if (oTal.segundos() > 1)
                retorno += oTal.segundos() + " segundos.\n";
              else
                retorno += oTal.segundos() + " segundo.\n";

              retorno += "Agora est† ";

              if (oTal.morto())
              {
                retorno += "mort" + oTal.sexo() + ". Morreu em " + oTal.dataDaMorte() + ".\n";

                if (oTal.doente())
                  retorno += "Estava com " + oTal.doenca() + ".\n";

                retorno += "Morreu de " + oTal.motivoDaMorte() + ".\n";
                retorno += "Pesando " + oTal.gramas() + " gramas e ";
                retorno += "com " + oTal.milimetros() + " mil°metros de altura.";
              }
              else
                {
                  if (oTal.doente())
                    retorno += "com " + oTal.doenca() + ", ";

                  if (oTal.alimentacao() > 80)
                    retorno += "¢tima alimentaá∆o";
                  else
                    if (oTal.alimentacao() > 50)
                      retorno += "boa alimentaá∆o";
                    else
                      if (oTal.alimentacao() > 20)
                        retorno += "com falta de nutrientes";
                      else
                        retorno += "com sÇrios problemas de nutriá∆o";

                  retorno += ", ";

                  if (oTal.saude() > 80)
                    retorno += "°ntegro";
                  else
                    if (oTal.saude() > 50)
                      retorno += "quase °ntegro";
                    else
                      if (oTal.saude() > 20)
                        retorno += "meio quebrado";
                      else
                        retorno += "espancado";

                  retorno += ", ";

                  if (oTal.otimismo() > 80)
                    retorno += "otimista";
                  else
                    if (oTal.otimismo() > 50)
                      retorno += "quase otimista";
                    else
                      if (oTal.otimismo() > 20)
                        retorno += "quase pessimista";
                      else
                        retorno += "pessimista";

                  retorno += ", ";

                  if (oTal.dormindo())
                    retorno += "dormindo, ";

                  if (oTal.fome() > 80)
                    retorno += "com muita fome, ";
                  else
                    if (oTal.fome() > 50)
                      retorno += "com fome, ";
                    else
                      if (oTal.fome() > 20)
                        retorno += "com um pouco de fome, ";

                  if (oTal.sede() > 80)
                    retorno += "morrendo de sede, ";
                  else
                    if (oTal.sede() > 50)
                      retorno += "com sede, ";
                    else
                      if (oTal.sede() > 20)
                        retorno += "com a boca seca, ";

                  if (oTal.energia() > 80)
                    retorno += "bem enÇrgic" + oTal.sexo();
                  else
                    if (oTal.energia() > 50)
                      retorno += "enÇrgic" + oTal.sexo();
                    else
                      if (oTal.energia() > 20)
                        retorno += "bocejando";
                      else
                        retorno += "morrendo de sono";

                  retorno += ", ";
        
                  if (oTal.alegria() > 100)
                    retorno += "pulando de alegria, super feliz";
                  else
                    if (oTal.alegria() > 80)
                      retorno += "muito feliz";
                    else
                      if (oTal.alegria() > 50)
                        retorno += "alegre";
                      else
                        if (oTal.alegria() > 20)
                          retorno += "meio cabisbaix" + oTal.sexo();
                        else
                          retorno += "muito triste";

                  retorno += ", ";

                  if (oTal.educacao() > 100)
                    retorno += "muito educad" + oTal.sexo();
                  else
                    if (oTal.educacao() > 80)
                      retorno += "bem educad" + oTal.sexo();
                    else
                      if (oTal.educacao() > 50)
                        retorno += "educad" + oTal.sexo();
                      else
                        if (oTal.alegria() > 20)
                          retorno += "meio mal-educad" + oTal.sexo();
                        else
                          retorno += "muito mal-educad" + oTal.sexo();

                  retorno += " e ";

                  if (oTal.sujeira() > 80)
                    retorno += "imund" + oTal.sexo() + ", fedendo";
                  else
                    if (oTal.sujeira() > 50)
                      retorno += "suj" + oTal.sexo();
                    else
                      if (oTal.sujeira() > 20)
                        retorno += "sujinh" + oTal.sexo();
                      else
                        retorno += "limpinh" + oTal.sexo() + ", cheiroso";

                  retorno += ".\n";

                  retorno += "Est† pesando " + oTal.gramas() + " gramas ";
                  retorno += "e est† com " + oTal.milimetros() + " mil°metros de altura.";
                }
            }
        }          
    }            

    return retorno;
  }
}
