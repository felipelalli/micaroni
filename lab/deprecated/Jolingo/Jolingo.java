/** Classe Jolingo - Projeto Comunidade de Jolingos Virtuais */
/** Felipe Micaroni Lalli - F&F Fun 2000∏                    */
/** Todos os Direitos Reservados                             */
/** Maio/2000                                                */

import java.lang.*;
import java.util.Date;

class JolingoErro extends Exception {}
class JolingoErroJaNascido extends JolingoErro {}
class JolingoErroHomossexualismo extends JolingoErro {}
class JolingoErroNaoVive extends JolingoErro {}
class JolingoErroNaoNascido extends JolingoErroNaoVive {}
class JolingoErroMorto extends JolingoErroNaoVive {}
class JolingoErroSintaxeInvalida extends JolingoErro {}

class Jolingo
{                             
  // Constantes:
  public static boolean MACHO = true;
  public static boolean FEMEA = false;
  public static int PESO_MAXIMO = 1500;
  public static int ALTURA_MAXIMA = 200;
  public static int PESO_MINIMO  = 10;
  public static int ALTURA_MINIMA = 20;
  public static int TEMPO_COM_DOENCA_MAXIMO = 7200;

  // Doenáas:
  public static long DESCONHECIDO = 1;
  public static long DOENCA_GENETICA = 2;
  public static long GRIPE = 4;
  public static long SARAMPO = 8;
  public static long CATAPORA = 16;
  public static long DEPRESSAO = 32;
  public static long FEBRE_AMARELA = 64;
  public static long FEBRE = 128;
  public static long AIDS = 256;
  public static long STRESS = 512;
  public static long SUJEIRA = 1024;
  public static long LEPSTOPIROSE = 2048;
  public static long MICOSE = 4096;

  // Caracter°sticas:
  private String cNome;
  private String cSobreNomeDaMae;
  private String cSobreNomeDoPai;
  private Pessoa cDono;
  private boolean cMacho;
  private Date cDataDeNascimento = new Date(0);
  private Date cDataDaMorte = new Date(0);

  // Genes:
  private GeneFun gOlhosClaros;
  private GeneFun gDoencaGrave;
  private GeneFun gCabeloClaro;
  private GeneFun gCabeloLiso;
  private GeneFun gComeMuito;
  private GeneFun gEngordaMuito;
  private GeneFun gFormatoComprido;
  private GeneFun gFofinho;
  private GeneFun gCresceMuito;
  private int gFeiura;
  private int gFraqueza;
  private long gIdadeMaximaEmSegundos;

  // Estados:
  private boolean eLivre = false;
  private long eSegundosVividos = 0;
  private boolean eNascido = false;
  private boolean eDormindo;
  private boolean eMorto = false;
  private boolean eComBabaVirtual = false;
  private String eMotivoDaMorte = new String("?");
  private int eGramas;
  private int eMilimetros;
  private Doenca eDoenca = new Doenca();
  private int eQuantasDoencas = 0;
  private int eFome;
  private int eSede;
  private int eEnergia;
  private int eAlegria;
  private int eAlimentacao;
  private int eSaude;
  private int eOtimismo;
  private int eEducacao;
  private int eSujeira;

  // Auxiliares:
  private int aTempoDeDoenca;
  private int aFome = 0;
  private int aSede = 0;
  private int aEnergia = 0;
  private int aAlegria = 0;
  private int aAlimentacao = 0;
  private int aSaude = 0;
  private int aOtimismo = 0;
  private int aEducacao = 0;
  private int aSujeira = 0;

  ///////////////////////
  // FUNÄÂES DE CLASSE //
  ///////////////////////
  private static String geraNome()
  {
    String retorno = new String();
    int quantasVezes = (int) (Math.random() * 2) + 2;

    for (int i = 0; i < quantasVezes; i++)
      switch ((int) (Math.random() * 16) + 1)
      {
        case 1:  retorno += "du";  break;
        case 2:  retorno += "an";  break;
        case 3:  retorno += "su";  break;
        case 4:  retorno += "to";  break;
        case 5:  retorno += "di";  break;
        case 6:  retorno += "ca";  break;
        case 7:  retorno += "lan"; break;
        case 8:  retorno += "ju";  break;
        case 9:  retorno += "san"; break;
        case 10: retorno += "edi"; break;
        case 11: retorno += "lo";  break;
        case 12: retorno += "va";  break;
        case 13: retorno += "cu";  break;
        case 14: retorno += "pin"; break;
        case 15: retorno += "oi";  break;
        case 16: retorno += "api"; break;
      }

    return retorno;
  }

  public static Jolingo casa(Jolingo mae, Jolingo pai)
   throws
    JolingoErroHomossexualismo,
     JolingoErroNaoVive
  {
    return new Jolingo(mae, pai);
  }

  public static Jolingo casa(Jolingo mae, Jolingo pai, String nome)
   throws
    JolingoErroHomossexualismo,
     JolingoErroNaoVive
  {
    return new Jolingo(mae, pai, nome);
  }

  public static boolean chance(int umaEmCada)
  {
    return chance((long) umaEmCada);
  }

  public static boolean chance(long umaEmCada)
  {
    return ((long) (Math.random() * umaEmCada) == umaEmCada - 1);
  }

  public static boolean chance(double umaEmCada)
  {
    long arredondado = Math.round(umaEmCada);
    return ((long) (Math.random() * arredondado) == arredondado - 1);
  }

  //////////////////
  // CONSTRUTORES //                 
  //////////////////
  // Recebendo uma string contendo um toString() de outro jolingo
  public Jolingo(String dadosJolingo)
   throws
    JolingoErroSintaxeInvalida
  {
    if (!dadosJolingo.endsWith("ü") || dadosJolingo.charAt(0) != 'ü')
      throw new JolingoErroSintaxeInvalida();

    int indice = 0;
    int tamanho = dadosJolingo.length();      
                                         
    try
    {
    for (int i = 1; i < tamanho; i++)
    {
      String temp = new String();

      for (; dadosJolingo.charAt(i) != '|' &&
             dadosJolingo.charAt(i) != 'ü'; i++)
        temp += dadosJolingo.charAt(i);

      switch(++indice)
      {
        case  1: cNome = temp; break;
        case  2: cSobreNomeDaMae = temp; break;
        case  3: cSobreNomeDoPai = temp; break;
        case  4: try
                 {
                   cDono = Pessoa.valueOf(temp);
                 }
                 catch(PessoaErroSintaxeInvalida e)
                 {
                   throw new JolingoErroSintaxeInvalida();
                 }
                 break;
        case  5: cMacho = Boolean.valueOf(temp).booleanValue(); break;
        case  6: cDataDeNascimento = new Date(Long.valueOf(temp).longValue()); break;
        case  7: cDataDaMorte = new Date(Long.valueOf(temp).longValue()); break;
        case  8: gOlhosClaros = GeneFun.valueOf(temp); break;
        case  9: gDoencaGrave = GeneFun.valueOf(temp); break;
        case 10: gCabeloClaro = GeneFun.valueOf(temp); break;
        case 11: gCabeloLiso = GeneFun.valueOf(temp); break;
        case 12: gComeMuito = GeneFun.valueOf(temp); break;
        case 13: gEngordaMuito = GeneFun.valueOf(temp); break;
        case 14: gFormatoComprido = GeneFun.valueOf(temp); break;
        case 15: gFofinho = GeneFun.valueOf(temp); break;
        case 16: gCresceMuito = GeneFun.valueOf(temp); break;
        case 17: gFeiura = Integer.valueOf(temp).intValue(); break;
        case 18: gFraqueza = Integer.valueOf(temp).intValue(); break;
        case 19: gIdadeMaximaEmSegundos = Long.valueOf(temp).longValue(); break;
        case 20: eSegundosVividos = Long.valueOf(temp).longValue(); break;
        case 21: eNascido = Boolean.valueOf(temp).booleanValue(); break;
        case 22: eDormindo = Boolean.valueOf(temp).booleanValue(); break;
        case 23: eMorto = Boolean.valueOf(temp).booleanValue(); break;
        case 24: eMotivoDaMorte = temp; break;
        case 25: eGramas = Integer.valueOf(temp).intValue(); break;
        case 26: eMilimetros = Integer.valueOf(temp).intValue(); break;
        case 27: try
                 {
                   eDoenca = new Doenca(temp);
                 }
                 catch(DoencaErroSintaxeInvalida e)
                 {
                   throw new JolingoErroSintaxeInvalida();
                 }
                 break;
        case 28: eQuantasDoencas = Integer.valueOf(temp).intValue(); break;
        case 29: eFome = Integer.valueOf(temp).intValue(); break;
        case 30: eSede = Integer.valueOf(temp).intValue(); break;
        case 31: eEnergia = Integer.valueOf(temp).intValue(); break;
        case 32: eAlegria = Integer.valueOf(temp).intValue(); break;
        case 33: eAlimentacao = Integer.valueOf(temp).intValue(); break;
        case 34: eSaude = Integer.valueOf(temp).intValue(); break;
        case 35: eOtimismo = Integer.valueOf(temp).intValue(); break;
        case 36: aTempoDeDoenca = Integer.valueOf(temp).intValue(); break;
        case 37: aFome = Integer.valueOf(temp).intValue(); break;
        case 38: aSede = Integer.valueOf(temp).intValue(); break;
        case 39: aEnergia = Integer.valueOf(temp).intValue(); break;
        case 40: aAlegria = Integer.valueOf(temp).intValue(); break;
        case 41: aAlimentacao = Integer.valueOf(temp).intValue(); break;
        case 42: aSaude = Integer.valueOf(temp).intValue(); break;
        case 43: aOtimismo = Integer.valueOf(temp).intValue(); break;
        case 44: eEducacao = Integer.valueOf(temp).intValue(); break;
        case 45: aEducacao = Integer.valueOf(temp).intValue(); break;
        case 46: eSujeira = Integer.valueOf(temp).intValue(); break;
        case 47: aSujeira = Integer.valueOf(temp).intValue(); break;
        case 48: eLivre = Boolean.valueOf(temp).booleanValue(); break;
        case 49: eComBabaVirtual = Boolean.valueOf(temp).booleanValue();
      }
    }
    }
    catch(Exception e)
    {
      throw new JolingoErroSintaxeInvalida();
    }
  }

  public Jolingo(Pessoa dono, String sobreNomeDaMae,
                              String sobreNomeDoPai)
  {
    this(dono, geraNome(), sobreNomeDaMae, sobreNomeDoPai,
        ((int) (Math.random() * 2)) == 1);
  }

  public Jolingo(Pessoa dono, String sobreNomeDaMae,
                              String sobreNomeDoPai, boolean macho)
  {
    this(dono, geraNome(), sobreNomeDaMae, sobreNomeDoPai, macho);
  }

  public Jolingo(Pessoa dono, String nome,
                 String sobreNomeDaMae, String sobreNomeDoPai,
                 boolean macho)
  {
    cNome = nome.replace('|', ' ').replace('_', ' ').trim();
    cSobreNomeDaMae = sobreNomeDaMae.replace('|', ' ').replace('_', ' ').trim();
    cSobreNomeDoPai = sobreNomeDoPai.replace('|', ' ').replace('_', ' ').trim();
    cDono = new Pessoa(dono);
    cMacho = macho;

    gOlhosClaros = new GeneFun();
    gDoencaGrave = new GeneFun();
    gCabeloClaro = new GeneFun();
    gCabeloLiso = new GeneFun();
    gComeMuito = new GeneFun();
    gEngordaMuito = new GeneFun();
    gFormatoComprido = new GeneFun();
    gFofinho = new GeneFun();
    gCresceMuito = new GeneFun();
    gFeiura = (int) (Math.random() * 100) + 1;
    gFraqueza = (int) (Math.random() * 100) + 1;
    gIdadeMaximaEmSegundos = (long) (Math.random() * 100000000) +
                             (long) (Math.random() * 100000000) +
                             (long) (Math.random() * 100000000);
  }

  public Jolingo(Jolingo mae, Jolingo pai)
   throws
    JolingoErroHomossexualismo,
     JolingoErroNaoVive
  {
    this(mae, pai, geraNome());
  }

  public Jolingo(Jolingo mae, Jolingo pai, String nome)
   throws
    JolingoErroHomossexualismo,
     JolingoErroNaoVive
  {
    if (!mae.nascido() || mae.morto() ||
        !pai.nascido() || pai.morto())
      throw new JolingoErroNaoVive();

    nome = nome.replace('|', ' ').replace('_', ' ').trim();

    if (!mae.equals(pai))
    {
      mae.incAlegria((int) (Math.random() * 5000));
      pai.incAlegria((int) (Math.random() * 5000));
    }

    if (mae.macho() == pai.macho())
      throw new JolingoErroHomossexualismo();
    else
      {
        cNome = nome;
        Jolingo auxMae;
        Jolingo auxPai;

        try
        {
          if (mae.femea())
          {
            auxMae = new Jolingo(mae.toString());
            auxPai = new Jolingo(pai.toString());
          }
          else
            {
              auxMae = new Jolingo(pai.toString());
              auxPai = new Jolingo(mae.toString());
            }
 
          cSobreNomeDaMae = auxMae.cSobreNomeDoPai;
          cSobreNomeDoPai = auxPai.cSobreNomeDoPai;

          cDono = new Pessoa(auxMae.cDono);
          cMacho = (int) (Math.random() * 2) == 1;

          gOlhosClaros = auxMae.gOlhosClaros.casaCom(auxPai.gOlhosClaros);
          gDoencaGrave = auxMae.gDoencaGrave.casaCom(auxPai.gDoencaGrave);
          gCabeloClaro = auxMae.gCabeloClaro.casaCom(auxPai.gCabeloClaro);
          gCabeloLiso = auxMae.gCabeloLiso.casaCom(auxPai.gCabeloLiso); 
          gComeMuito = auxMae.gComeMuito.casaCom(auxPai.gComeMuito); 
          gEngordaMuito = auxMae.gEngordaMuito.casaCom(auxPai.gEngordaMuito); 
          gFormatoComprido = auxMae.gFormatoComprido.casaCom(auxPai.gFormatoComprido); 
          gFofinho = auxMae.gFofinho.casaCom(auxPai.gFofinho);
          gCresceMuito = auxMae.gCresceMuito.casaCom(auxPai.gCresceMuito);

          int puxouAMae = (int) (Math.random() * 100) + 1;

          gFeiura = ((int) (auxMae.gFeiura * puxouAMae / 100)) +
                    ((int) (auxPai.gFeiura * (100 - puxouAMae) / 100));

          gFraqueza = ((int) (auxMae.gFraqueza * puxouAMae / 100)) +
                    ((int) (auxPai.gFraqueza * (100 - puxouAMae) / 100));

          gIdadeMaximaEmSegundos =
            ((long) (auxMae.gIdadeMaximaEmSegundos * puxouAMae / 100)) +
            ((long) (auxPai.gFeiura * (100 - puxouAMae) / 100));

        }
        catch(JolingoErroSintaxeInvalida e){}
      }
  }

  //////////////////
  // VERIFICAÄÂES //
  //////////////////
  public static Jolingo valueOf(String valor)
   throws
    JolingoErroSintaxeInvalida
  {
    return new Jolingo(valor);
  }

  public String toString()
  {
    return new String(                 "ü" +
              cNome                  + "|" +
              cSobreNomeDaMae        + "|" +
              cSobreNomeDoPai        + "|" +
              cDono                  + "|" +
              cMacho                 + "|" +
              cDataDeNascimento.getTime() + "|" +
              cDataDaMorte.getTime()      + "|" +
              gOlhosClaros           + "|" +
              gDoencaGrave           + "|" +
              gCabeloClaro           + "|" +
              gCabeloLiso            + "|" +
              gComeMuito             + "|" +
              gEngordaMuito          + "|" +
              gFormatoComprido       + "|" +
              gFofinho               + "|" +
              gCresceMuito           + "|" +
              gFeiura                + "|" +
              gFraqueza              + "|" +
              gIdadeMaximaEmSegundos + "|" +
              eSegundosVividos       + "|" +
              eNascido               + "|" +
              eDormindo              + "|" +
              eMorto                 + "|" +
              eMotivoDaMorte         + "|" +
              eGramas                + "|" +
              eMilimetros            + "|" +
              eDoenca                + "|" +
              eQuantasDoencas        + "|" +
              eFome                  + "|" +
              eSede                  + "|" +
              eEnergia               + "|" +
              eAlegria               + "|" +
              eAlimentacao           + "|" +
              eSaude                 + "|" +
              eOtimismo              + "|" +
              aTempoDeDoenca         + "|" +
              aFome                  + "|" +
              aSede                  + "|" +
              aEnergia               + "|" +
              aAlegria               + "|" +
              aAlimentacao           + "|" +
              aSaude                 + "|" +
              aOtimismo              + "|" +
              eEducacao              + "|" +
              aEducacao              + "|" +
              eSujeira               + "|" +
              aSujeira               + "|" +
              eLivre                 + "|" +
              eComBabaVirtual        + "ü");
  }

  public boolean quer()
  {
    if (livre())
      return chance(101 - otimismo());
    else
      return false;
  }

  public int tempoDeDoenca()
  {
    return aTempoDeDoenca;
  }

  public boolean verificaDono(Pessoa tentativa)
  {
    return tentativa.mesmaPessoa(cDono);
  }

  public boolean livre()
  {
    return eLivre;
  }

  public boolean comBabaVirtual()
  {
    return eComBabaVirtual;
  }

  public String nome()
  {
    return cNome;
  }

  public String sobreNomeDaMae()
  {
    return cSobreNomeDaMae;
  }

  public String sobreNomeDoPai()
  {
    return cSobreNomeDoPai;
  }

  public String dono()
  {
    return cDono.nome();
  }

  public boolean macho()
  {
    return cMacho;
  }

  public boolean femea()
  {
    return !cMacho;
  }

  public String motivoDaMorte()
  {
    return eMotivoDaMorte;
  }

  public Date dataDaMorte()
  {
    return cDataDaMorte;
  }

  public Date dataDeNascimento()
  {
    return cDataDeNascimento;
  }

  public boolean nascido()
  {
    return eNascido;
  }

  public boolean morto()
  {
    return eMorto;
  }

  public String sexo()
  {
    if (this.cMacho)
      return new String("o");
    else
      return new String("a");
  }

  public boolean olhosClaros()
  {
    return gOlhosClaros.recessivo();
  }

  public boolean doencaGrave()
  {
    return gDoencaGrave.recessivo();
  }

  public boolean cabeloClaro()
  {
    return gCabeloClaro.recessivo();
  }

  public boolean cabeloLiso()
  {
    return gCabeloLiso.recessivo();
  }

  public boolean comeMuito()
  {
    return gComeMuito.recessivo();
  }

  public boolean engordaMuito()
  {
    return gEngordaMuito.recessivo();
  }

  public boolean formatoComprido()
  {
    return gFormatoComprido.recessivo();
  }

  public boolean fofinho()
  {
    return gFofinho.recessivo();
  }

  public boolean cresceMuito()
  {
    return gCresceMuito.recessivo();
  }

  public int feiura()
  {
    return gFeiura;
  }

  public int fraqueza()
  {
    return gFraqueza + ((int) ((100 - alimentacao()) / 10));
  }

  private long idadeMaximaEmSegundos()
  {
    return gIdadeMaximaEmSegundos;
  }

  public long segundosVividos()
  {
    return eSegundosVividos;
  }

  public long minutosVividos()
  {
    return (long) (eSegundosVividos / 60);
  }

  public long horasVividas()
  {
    return (long) (minutosVividos() / 60);
  }

  public long diasVividos()
  {
    return (long) (horasVividas() / 24);
  }

  public int anosVividos()
  {
    return (int) (diasVividos() / 365);
  }

  public int segundos()
  {
    return (int) (eSegundosVividos % 60);
  }

  public int minutos()
  {
    return (int) (minutosVividos() % 60);
  }

  public int horas()
  {
    return (int) (horasVividas() % 24);
  }

  public int dias()
  {
    return (int) (diasVividos() % 365);
  }

  public int anos()
  {
    return anosVividos();
  }

  public int gramas()
  {
    return eGramas;
  }

  public int milimetros()
  {
    return eMilimetros;
  }

  public boolean doente()
  {
    return eDoenca.doente();
  }

  public String doenca()
  {
    return eDoenca.nome();
  }

  public Doenca aDoenca()
  {
    return eDoenca;
  }

  public String aparencia()
  {
    return eDoenca.aparencia();
  }

  public long codigoDaDoenca()
  {
    return eDoenca.codigo();
  }

  public int quantasDoencas()
  {
    return eQuantasDoencas;
  }

  public int fome()
  {
    return eFome;
  }

  public int sede()
  {
    return eSede;
  }

  public int energia()
  {
    return eEnergia;
  }

  public int sono()
  {
    return 100 - eEnergia;
  }

  public int alegria()
  {
    return eAlegria;
  }

  public int alimentacao()
  {
    return eAlimentacao;
  }

  public int saude()
  {
    return eSaude;
  }

  public int otimismo()
  {
    return eOtimismo;
  }

  public int pessimismo()
  {
    return 100 - eOtimismo;
  }

  public int educacao()
  {
    return eEducacao;
  }

  public int sujeira()
  {
    return eSujeira;
  }

  public boolean dormindo()
  {
    return eDormindo;
  }

  ////////////////
  // DEFINIÄÂES //
  ////////////////
  public Jolingo mudaDono(Pessoa outroDono)
  {
    cDono = new Pessoa(outroDono);
    return this;
  }

  public Jolingo liberdade()
  {
    eLivre = true;
    return this;
  }

  public Jolingo incTempoDeDoenca()
  {
    aTempoDeDoenca++;
    return this;
  }

  public Jolingo engorda()
  {
    return engorda(1);
  }

  public Jolingo engorda(int qtd)
  {
    if (engordaMuito())
      incGramas(qtd);
    else
      for (int i = 0; i < qtd; i++)
        if (chance(2))
          incGramas();

    return this;
  }

  public Jolingo emagresse()
  {
    return emagresse(1);
  }

  public Jolingo emagresse(int qtd)
  {
    return decGramas(qtd);
  }

  public Jolingo incGramas()
  {
    return incGramas(1);
  }

  public Jolingo decGramas()
  {
    return decGramas(1);
  }

  public Jolingo incGramas(int quantidade)
  {
    eGramas += quantidade;

    if (eGramas > PESO_MAXIMO)
    {
      try
      {
        morre("engordar muito");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo decGramas(int quantidade)
  {
    eGramas -= quantidade;
    
    if (eGramas < PESO_MINIMO)
    {
      try
      {
        morre("ficar muito magr" + sexo());
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo incMilimetros()
  {
    return incMilimetros(1);
  }

  public Jolingo decMilimetros()
  {
    return decMilimetros(1);
  }

  public Jolingo incMilimetros(int quantidade)
  {
    eMilimetros += quantidade;

    if (eMilimetros > ALTURA_MAXIMA)
    {
      try
      {
        morre("crescer demais");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo decMilimetros(int quantidade)
  {

    eMilimetros -= quantidade;

    if (eMilimetros < ALTURA_MINIMA)
    {
      try
      {
        morre("diminuir demais");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo doenca(Doenca qualDoenca)
  {
    if (qualDoenca == null)
      eDoenca = new Doenca();
    else
      eDoenca = new Doenca(qualDoenca);

    return this;
  }

  public Jolingo doenca(String qualDoenca, String aparencia,
                        int chance, int codigo)
  {
    return doenca(qualDoenca, aparencia, chance, (long) codigo);
  }

  public Jolingo doenca(String qualDoenca, String aparencia,
                        int chance, long codigo)
  {
    aTempoDeDoenca = 0;
    eQuantasDoencas++;
    eDoenca = new Doenca(qualDoenca, aparencia, chance, codigo);

    return this;
  }

  public Jolingo incFome()
  {
    return incFome(1);
  }

  public Jolingo decFome()
  {
    return decFome(1);
  }

  public Jolingo incFome(int quantidade)
  {
    aFome += quantidade;

    while (aFome >= 100)
    {
      aFome -= 100;
      eFome++;
    }

    if (eFome > 100)
    {
      try
      {
        morre("fome");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo decFome(int quantidade)
  {
    aFome -= quantidade;

    while (aFome < 0)
    {
      aFome += 100;
      eFome--;
    }

    if (eFome < 0)
      eFome = 0;

    return this;
  }

  public Jolingo incSede()
  {
    return incSede(1);
  }

  public Jolingo decSede()
  {
    return decSede(1);
  }

  public Jolingo incSede(int quantidade)
  {
    aSede += quantidade;

    while (aSede >= 100)
    {
      aSede -= 100;
      eSede++;
    }

    if (eSede > 100)
    {
      try
      {
        morre("sede");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo decSede(int quantidade)
  {
    aSede -= quantidade;

    while (aSede < 0)
    {
      aSede += 100;
      eSede--;
    }

    if (eSede < 0)
      eSede = 0;

    return this;
  }

  public Jolingo incEnergia()
  {
    return incEnergia(1);
  }

  public Jolingo decEnergia()
  {
    return decEnergia(1);
  }

  public Jolingo incEnergia(int quantidade)
  {
    aEnergia += quantidade;

    while (aEnergia >= 100)
    {
      aEnergia -= 100;
      eEnergia++;
    }

    if (eEnergia > 100)
      eEnergia = 100;

    return this;
  }

  public Jolingo decEnergia(int quantidade)
  {
    aEnergia -= quantidade;

    while (aEnergia < 0)
    {
      aEnergia += 100;
      eEnergia--;
    }

    if (eEnergia < -1)
    {
      try
      {
        morre("sono profundo");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo incAlegria()
  {
    return incAlegria(1);
  }

  public Jolingo decAlegria()
  {
    return decAlegria(1);
  }


  public Jolingo incAlegria(int quantidade)
  {
    aAlegria += quantidade;

    while (aAlegria >= 100)
    {
      aAlegria -= 100;
      eAlegria++;

      if (eAlegria > 100)
        eAlegria = 100;
    }

    return this;
  }

  public Jolingo decAlegria(int quantidade)
  {
    aAlegria -= quantidade;

    while (aAlegria < 0)
    {
      aAlegria += 100;
      eAlegria--;
    }
                       
    if (eAlegria < 0)
    {
      try
      {
        morre("tristeza profunda");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo incAlimentacao()
  {
    return incAlimentacao(1);
  }

  public Jolingo decAlimentacao()
  {
    return decAlimentacao(1);
  }

  public Jolingo incAlimentacao(int quantidade)
  {
    aAlimentacao += quantidade;

    while (aAlimentacao >= 100)
    {
      aAlimentacao -= 100;
      eAlimentacao++;
    }

    if (eAlimentacao > 100)
      eAlimentacao = 100;

    return this;
  }

  public Jolingo decAlimentacao(int quantidade)
  {
    aAlimentacao -= quantidade;

    while (aAlimentacao < 0)
    {
      aAlimentacao += 100;
      eAlimentacao--;
    }

    if (eAlimentacao < 0)
    {
      try
      {
        morre("falta de nutrientes");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo incSaude()
  {
    return incSaude(1);
  }

  public Jolingo decSaude()
  {
    return decSaude(1);
  }

  public Jolingo incSaude(int quantidade)
  {
    aSaude += quantidade;

    while (aSaude >= 100)
    {
      aSaude -= 100;
      eSaude++;
    }

    if (eSaude > 100)
      eSaude = 100;

    return this;
  }

  public Jolingo decSaude(int quantidade)
  {
    aSaude -= quantidade;

    while (aSaude < 0)
    {
      aSaude += 100;
      eSaude--;
    }

    if (eSaude < 0)
    {
      try
      {
        morre("feridas graves");
      }
      catch(JolingoErro e){}
    }

    return this;
  }

  public Jolingo incOtimismo()
  {
    return incOtimismo(1);
  }

  public Jolingo decOtimismo()
  {
    return decOtimismo(1);
  }

  public Jolingo incOtimismo(int quantidade)
  {
    aOtimismo += quantidade;

    while (aOtimismo >= 100)
    {
      aOtimismo -= 100;
      eOtimismo++;
    }

    if (eOtimismo > 100)
      eOtimismo = 100;

    return this;
  }

  public Jolingo decOtimismo(int quantidade)
  {
    aOtimismo -= quantidade;

    while (aOtimismo < 0)
    {
      aOtimismo += 100;
      eOtimismo--;
    }

    if (eOtimismo < 0)
      eOtimismo = 0;

    return this;
  }

  public Jolingo incEducacao()
  {
    return incEducacao(1);
  }

  public Jolingo decEducacao()
  {
    return decEducacao(1);
  }

  public Jolingo incEducacao(int quantidade)
  {
    aEducacao += quantidade;

    while (aEducacao >= 100)
    {
      aEducacao -= 100;
      eEducacao++;
    }

    return this;
  }

  public Jolingo decEducacao(int quantidade)
  {
    aEducacao -= quantidade;

    while (aEducacao < 0)
    {
      aEducacao += 100;
      eEducacao--;
    }

    return this;
  }

  public Jolingo incSujeira()
  {
    return incSujeira(1);
  }

  public Jolingo decSujeira()
  {
    return decSujeira(1);
  }

  public Jolingo incSujeira(int quantidade)
  {
    aSujeira += quantidade;

    while (aSujeira >= 100)
    {
      aSujeira -= 100;
      eSujeira++;
    }

    return this;
  }

  public Jolingo decSujeira(int quantidade)
  {
    aSujeira -= quantidade;

    while (aSujeira < 0)
    {
      aSujeira += 100;
      eSujeira--;
    }

    if (eSujeira < 0)
      eSujeira = 0;

    return this;
  }

  /////////////
  // FUNÄÂES //
  /////////////
  public Jolingo nasce()
   throws
    JolingoErroMorto,
     JolingoErroJaNascido
  {
    if (eNascido)
      throw new JolingoErroJaNascido();
    else
      if (eMorto)
        throw new JolingoErroMorto();
      else
        {
          cDataDeNascimento = new Date();
          eNascido = true;
          eDormindo = false;
          eGramas = (int) (Math.random() * 10) + 40;

          if (fofinho())
            eGramas += 10;

          if (engordaMuito())
            eGramas += 10;

          eGramas += (int) ((100 - fraqueza()) / 10);

          eMilimetros = (int) (Math.random() * 20) + 20;

          if (formatoComprido())
            eMilimetros += 5;

          if (cSobreNomeDaMae.equalsIgnoreCase(cSobreNomeDoPai) && chance(100))
            doenca("sÇrios problemas mentais", "cara de Mongol, provindo da Mong¢lia", 0, 1);

          if (doencaGrave())
            doenca("doenáa grave genÇtica", "queda de cabelos", 0, 2);

          eFome = (int) (Math.random() * 10) + 40;
          eSaude = 100;
          eOtimismo = (int) (Math.random() * 80) + 20;
          eEducacao = 0;
          eSujeira = 0;

          if (comeMuito())
            eFome += 20;

          eSede = (int) (Math.random() * 40) + 60;
          eEnergia = (int) (Math.random() * 40) + 40;
          eAlegria = (int) (Math.random() * 30) + 70;

          if (doente())
            eAlegria -= 70;
        }

    return this;
  }

  public Jolingo morre()
   throws
    JolingoErroNaoNascido,
     JolingoErroMorto
  {
    return morre("motivo desconhecido");
  }

  public Jolingo morre(String motivo)
   throws
    JolingoErroNaoNascido,
     JolingoErroMorto
  {
    if (eMorto)
      throw new JolingoErroMorto();
    else
      if (!eNascido)
        throw new JolingoErroNaoNascido();
      else
        {
          cDataDaMorte = new Date();
          eMorto = true;
          eMotivoDaMorte = motivo;
        }

    return this;
  }

  public Jolingo comBabaVirtual(boolean com)
  {
    eComBabaVirtual = com;
    return this;
  }

  public boolean tentaCurar()
  {
    if (Doenca.chance(eDoenca.chanceDeCura()))
    {
      eDoenca = new Doenca();
      return true;
    }
    else
      return false;
  }

  public Jolingo dorme()
  {
    incAlegria((int) ((50 - energia()) / 2));
    eDormindo = true;
    return this;
  }

  public Jolingo acorda()
  {
    incAlegria((int) ((energia() - 50) / 2));
    eDormindo = false;
    return this;
  }

  public Jolingo vive(int segundos)
   throws
    JolingoErroNaoVive
  {
    for (int i = 0; i < segundos; i++)
      vive();

    return this;
  }

  public Jolingo vive()
   throws
    JolingoErroNaoVive
  {
    if (morto() || !nascido())
      throw new JolingoErroNaoVive();
    else
    {
      eSegundosVividos++;

      if (eSegundosVividos > idadeMaximaEmSegundos())
        morre("velhice");
      else
        {
          if (doente() && chance(864))
            decSaude(100);

          if (chance(36))
            incSede(100);

          if (comeMuito())
          {
            if (chance(72))
              incFome(100);
          }
          else
            if (chance(108))
              incFome(100);

          if (chance(1800))
            emagresse(alimentacao() * -9 / 100 + 10);

          if (fome() > 80 || sede() > 80)
            if (chance(900))
              emagresse();

          if (chance((otimismo() + 2) * 728 / 100 * 864000))
            morre("pessimismo");

          // Doenáas:
          {
            if (tempoDeDoenca() > TEMPO_COM_DOENCA_MAXIMO)
              morre(doenca());
  
            if (doente())
              incTempoDeDoenca();

            long ch = (long) (otimismo() / 80 + 1) +
                             ((100 - fraqueza()) / 80 + 1) +
                             (alimentacao() / 50 + 1);

            if (chance(172800 * ch))
              doenca("gripe", "espirrando e quente", 50, GRIPE);

            if (chance(1296000 * ch))
              doenca("sarampo", "com bolinhas vermelhas", 10, SARAMPO);

            if (chance(1296000 * ch))
              doenca("catapora", "com feridas pelo corpo", 10, CATAPORA);

            if (chance(86400 * ch / (alegria() + 1)))
              doenca("depress∆o", "chorando sem parar", 25, DEPRESSAO);

            if (chance(1296000 * ch))
              doenca("febre amarela", "amarel" + sexo(), 10, FEBRE_AMARELA);

            if (chance(172800 * ch))
              doenca("febre natural", "quente", 40, FEBRE);

            if (chance(2592000 * ch))
              doenca("AIDS", "estranh" + sexo(), 0, AIDS);

            if (alegria() > 80 && feiura() < 20 && chance(86400 * ch))
              doenca("stress", "nervos" + sexo(), 50, STRESS);

            if (sujeira() > 80 && chance(8240 * ch))
              doenca("sujeira crìnica", "fedid" + sexo() + " pracaramba",
                     30, SUJEIRA);

            if (chance(1296000 * ch))
              doenca("lepstopirose", "queda de cabelos", 10, LEPSTOPIROSE);
          }

          if (dormindo())
          {
            if (chance(9))
              incEnergia(100);

            if (chance(31536000))
              morre("afogaá∆o no travesseiro");

            if (doente() && chance(60))
              acorda();

            if (energia() > 90)
              acorda();
            else
              if (energia() > 60)
              {
                if (chance(1800))
                  acorda();
              }
              else
                if (energia() > 40 && chance(3600))
                  acorda();

            if (!cresceMuito())
            {
              if (chance(86400))
                incMilimetros();
            }
            else
              if (chance(259200))
                incMilimetros(5);

            if (chance(36))
              incSaude(100);
          }
          else // est† acordado...
            {
              if (chance(18))
                decEnergia(100);

              if (chance(864))
                incSujeira(100 - educacao());

              if (doente())
              {
                if (chance(864))
                  decOtimismo(100);
              }
              else
                if (chance(6048))
                  incOtimismo(100);

              if (doente() && chance(60))
                dorme();

              if (energia() < 10)
                dorme();
              else
                if (energia() < 40)
                {
                  if (chance(1800))
                    dorme();
                }
                else
                  if (energia() < 60 && chance(3600))
                    dorme();

              if (!cresceMuito())
              {
                if (chance(259200))
                  incMilimetros();
              }
              else
                if (chance(2592000))
                  incMilimetros(15);

              if (alegria() > 90 && chance(108))
                incFome(100);

              if (chance((alimentacao() * (720 - 1) / 100 + 1) * 86400))
                morre("m† alimentaá∆o");

              if (doencaGrave())
                if (chance((otimismo() * 364 / 100 + 1) * 864))
                  decAlegria(100);

              if (formatoComprido() && chance(31536))
                decAlegria(10);

              if (!fofinho() && chance(31536))
                decAlegria(10);

              if (chance(864))
                decAlegria((feiura() + 1) / (otimismo() + 1) - 1);

              if (chance(1728))
                decAlegria((fraqueza() + 1) / (otimismo() + 1) - 1);
            }
        }
    }

    return this;
  }

  public Jolingo casaCom(Jolingo marido)
   throws
    JolingoErroNaoVive,
     JolingoErroHomossexualismo
  {
    return new Jolingo(this, marido);
  }

  public Resposta bebe(Alimento bebida)
   throws
    JolingoErroNaoVive
  {
    if (bebida.mataSede() + 10 >= bebida.mataFome())
      return comeDeFato(bebida);
    else // tentando beber comida?
      {
        decAlegria(1000);
        decOtimismo(100);
        decAlimentacao(100);
        decSaude();

        if (chance(100))
          morre("se engasgar tentando tomar " + bebida.nome());

        return new Resposta("imposs°vel tomar comida", false);
      }
  }

  public Resposta come(Alimento comida)
   throws
    JolingoErroNaoVive
  {
    if (comida.mataFome() + 10 >= comida.mataSede())
      return comeDeFato(comida);
    else // tentando comer bebida?
      {
        decAlegria(1000);
        decOtimismo(100);
        decAlimentacao(100);
        decSaude();

        if (chance(100))
          morre("se engasgar tentando comer " + comida.nome());

        return new Resposta("imposs°vel comer bebida", false);
      }
  }

  private Resposta comeDeFato(Alimento comida)
   throws
    JolingoErroNaoVive
  {
    if (morto() || !nascido())
      throw new JolingoErroNaoVive();

    if (sede() > comida.mataSede() || fome() > comida.mataFome())
    {
      if (chance(100000))
        morre("se engasgar com " + comida.nome());

      if (sujeira() > 70 && chance(100))
        doenca("micose m£ltipla", "muito colorido", 30, MICOSE);

      decSede(comida.mataSede() * 100);
      decFome(comida.mataFome() * 100);
      incAlimentacao(comida.nutrientes());

      while ((sede() > comida.mataSede() || fome() > comida.mataFome()) &&
             comida.gramas() > 0)
      {
        decEnergia();
        incAlegria();
        engorda();
        comida.tiraGrama();
      }

      incAlegria(comida.aumentaAlegria());
    }

    if (comida.mataSede() + 10 >= comida.mataFome())
      return new Resposta(nome() + " bebeu " + comida.nome(), true);
    else
      if (comida.mataFome() + 10 >= comida.mataSede())
        return new Resposta(nome() + " comeu " + comida.nome(), true);
      else
        return new Resposta(nome() + " se alimentou com " + comida.nome(), true);


  }

  // Faz aá∆o, e no retorno, tem resposta da aá∆o,
  // se sucesso ou n∆o, etc.
  public Resposta faz(Acao acao)
   throws
    JolingoErroNaoVive
  {
    if (morto() || !nascido())
      throw new JolingoErroNaoVive();

    return acao.executa(this);
  }
}
