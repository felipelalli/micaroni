class AcaoPula implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" + j.sexo() + " antes de fazˆ-l" +
                           j.sexo() + " pul -l" + j.sexo(), false);
    else
      {
        j.incAlegria(100);
        j.decEnergia(500);
        j.incSede(500);
        j.incFome(200);
        j.emagresse();

        return new Resposta(j.nome() + " pulou", true);
      }
  }
}

class AcaoExercicio implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" +
                          j.sexo() + " antes de exercit -l" +
                          j.sexo(), false);
    else
      {
        j.decAlegria(10);
        j.decEnergia(1000);
        j.incSede(2000);
        j.incFome(1000);
        j.emagresse(j.gramas() / 10);

        return new Resposta(j.nome() + " fez 56 flexäes", true);
      }
  }
}

class AcaoPassaGelol implements Acao
{
  public Resposta executa(Jolingo j)
  {
    j.incSaude(4000);                    
    j.decAlegria(10);
    return new Resposta(j.nome() + " foi passado Gelol", true);
  }
}

class AcaoMedico implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" + j.sexo() + " antes de lev -l" +
                           j.sexo() + " ao m‚dico", false);
    else
      {
        if (!j.doente())
        {
          j.decAlegria(300);
          j.decEnergia();
          j.decOtimismo(200);
          j.decEducacao(100);
          j.emagresse();
          return new Resposta(j.nome() + " nÆo est  doente. Ficou muito" +
                              " brav" + j.sexo() + " por tˆ-l" + j.sexo() +
                              " levado ao m‚dico", true);
        }
        else
         if (Doenca.chance(j.aDoenca().chanceDeCura()))
         {
           j.doenca(null);
           j.incAlegria(2000);
           j.emagresse();
           return new Resposta(j.nome() + " foi curado!", true);
         }
         else
           {
             j.decAlegria(200);
             j.emagresse();
             return new Resposta(j.nome() + " nÆo foi curado!", false);
           }
      }
  }
}

class AcaoBrinca implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" + j.sexo() + " antes de fazˆ-l" +
                           j.sexo() + " brinc -l" + j.sexo(), false);
    else
      {
        j.incAlegria(200 * (int) (j.energia() / 10));
        j.decEnergia(100);
        j.incSede(200);
        j.incFome(70);
        j.incOtimismo(500);
        j.incSujeira(300);
        j.emagresse();

        if (j.energia() < 30)
          return new Resposta(j.nome() +
          " brincou mas est  cansad" + j.sexo() + "!", true);
        else
          return new Resposta(j.nome() + " brincou e curtiu", true);
      }
  }
}

class AcaoEstuda implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" + j.sexo() + " antes de fazˆ-l" +
                           j.sexo() + " estudar qualquer coisa", false);
    else
      {
        j.decAlegria(30 * (int) ((100 - j.energia()) / 10));
        j.decEnergia(1000);
        j.incSede(5);
        j.incFome(5);
        j.incEducacao(1000);
        j.emagresse();

        if (j.energia() < 30)
          return new Resposta(j.nome() +
          " estudou mas est  cansad" + j.sexo() + "!", true);
        else
          return new Resposta(j.nome() + " estudou e rendeu", true);
      }
  }
}

class AcaoBate implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      j.acorda();

    j.decAlegria(10 * (j.fraqueza() + 1));
    j.decEnergia(1000);
    j.incEducacao(1000);

    if (j.macho())
      j.decSaude(25 * (j.fraqueza() + 1));
    else
      j.decSaude(30 * (j.fraqueza() + 1));

    j.incSede(100);
    j.incFome(20);
    j.decOtimismo((101 - j.otimismo()) * 10);
    j.emagresse();

    if (Jolingo.chance(56))
      j.doenca("hemorragia interna", "com manchas roxas pelo corpo", 10, 56);

    return new Resposta(j.nome() + " foi espancad" + j.sexo() + "!", true);
  }
}

class AcaoBanho implements Acao
{
  public Resposta executa(Jolingo j)
  {
    if (j.dormindo())
      return new Resposta(j.nome() + " est  dormindo. Acorde-" + j.sexo() + " antes de fazˆ-l" +
                           j.sexo() + " tomar banho", false);
    else
      {
        if (j.sujeira() < 30)
          j.incAlegria(j.otimismo() * j.educacao() - 1000);
        else                               
          j.incAlegria(j.educacao() * 10);

        j.decEnergia(100);
        j.incFome(20);
        j.incOtimismo(j.educacao() - 50);
        j.decSujeira(4000);

        if (Jolingo.chance(5))
          j.emagresse();

        if (j.sujeira() >= 50)
          return new Resposta(j.nome() +
          " tomou banho mas ainda est  sujinh" + j.sexo() + "!", true);
        else
          return new Resposta(j.nome() + " tomou banho", true);
      }
  }
}

class AcaoJesusSalva implements Acao
{
  public Resposta executa(Jolingo j)
  {
    j.incAlegria(10000);
    j.incOtimismo(10000);

    if (j.doente())
      j.doenca(null);

    j.decFome(10000);
    j.decSede(10000);
    j.incAlimentacao(10000);
    j.incSaude(10000);
    j.incEducacao(10000);
    j.decSujeira(10000);
    try
    {
      j.mudaDono(new Pessoa("Jesus Cristo", "Jesus@Deus.c‚u", "JEOVµ"));
    }
    catch(PessoaErroEmailInvalido e){}

    return new Resposta("Jesus salvou " + j.nome() + "! Agora ‚ de Jesus!", true);
  }
}

