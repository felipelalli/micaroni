/**
GeneFun - F&F Fun 1999¸
*/

import java.lang.Math;
import java.lang.String;

//////////////
// GENE FUN //
//////////////
class GeneFun
{
  ////////////////
  // CONSTANTES //
  ////////////////
  private static boolean DOMINANTE = true;
  private static boolean RECESSIVO = false;

  /////////////////////
  // CARACTERÖSTICAS //
  /////////////////////
  private boolean c_LocusUm;
  private boolean c_LocusDois;

  //////////////////
  // CONSTRUTORES //
  //////////////////
  public GeneFun()
  {
    this.define((int) (Math.random() * 2), (int) (Math.random() * 2));
  }

  public GeneFun(GeneFun irmao)
  {
    this.define(irmao);
  }

  public GeneFun(boolean locusUm, boolean locusDois)
  {                                      
    this.define(locusUm, locusDois);
  }

  public GeneFun(int locusUm, int locusDois)
  {                                      
    this.define(locusUm, locusDois);
  }

  public GeneFun(boolean[] locus)
  {
    this.define(locus[0], locus[1]);
  }

  public GeneFun(String representacao)
  {
    if ((representacao.charAt(0) >= 'A') &&
        (representacao.charAt(0) <= 'Z'))
      this.defineLocusUm(GeneFun.DOMINANTE);
    else
      this.defineLocusUm(GeneFun.RECESSIVO);

    if ((representacao.charAt(1) >= 'A') &&
        (representacao.charAt(1) <= 'Z'))
      this.defineLocusDois(GeneFun.DOMINANTE);
    else
      this.defineLocusDois(GeneFun.RECESSIVO);

    this.arruma();
  }   

  ////////////////
  // DEFINI€åES //
  ////////////////
  public GeneFun define(GeneFun irmao)
  {
    c_LocusUm = irmao.c_LocusUm;
    c_LocusDois = irmao.c_LocusDois;
    return this;
  }

  public GeneFun define(boolean locusUm, boolean locusDois)
  {
    this.c_LocusUm = locusUm;
    this.c_LocusDois = locusDois;
    this.arruma();
    return this;
  }

  public GeneFun define(int locusUm, int locusDois)
  {
    return this.define(locusUm != 0, locusDois != 0);
  }

  public GeneFun defineLocusUm(boolean locusUm)
  {
    this.c_LocusUm = locusUm;
    return this;
  }

  public GeneFun defineLocusDois(boolean locusDois)
  {
    this.c_LocusDois = locusDois;
    return this;
  }

  //////////////////
  // VERIFICA€åES //
  //////////////////
  public boolean locusUm()
  {
    return this.c_LocusUm;
  }

  public boolean locusDois()
  {
    return this.c_LocusDois;
  }

  public boolean dominante()
  {
    return this.locusUm();
  }

  public boolean recessivo()
  {
    return !this.locusUm();
  }

  public boolean homozigoto()
  {
    return this.locusUm() == this.locusDois();
  }

  public boolean eIgual(GeneFun geneIrmao)
  {
    return (this.dominante() && geneIrmao.dominante()) ||
           (this.recessivo() && geneIrmao.recessivo());
  }

  public String toString()
  {
    String retorno = new String();

    if (this.locusUm())
      retorno = "A";
    else
      retorno = "a";

    if (this.locusDois())
      retorno += "A";
    else
      retorno += "a";

    return retorno;
  }

  public static GeneFun valueOf(String valor)
  {
    return new GeneFun(valor);
  }

  /////////////
  // FUN€åES //
  /////////////
  GeneFun casaCom(GeneFun irmao)
  {
    GeneFun resultado = new GeneFun(false, false);

    if (((int) (Math.random() * 2) + 1) == 1)
      resultado.defineLocusUm(this.locusUm());
    else
      resultado.defineLocusUm(this.locusDois());

    if (((int) (Math.random() * 2) + 1) == 1)
      resultado.defineLocusDois(irmao.locusUm());
    else
      resultado.defineLocusDois(irmao.locusDois());

    resultado.arruma();
    return resultado;
  }

  public GeneFun arruma()
  {
    if (this.locusDois() && !this.locusUm())
    {
      boolean aux = this.locusUm();
      this.c_LocusUm = this.locusDois();
      this.c_LocusDois = aux;
    }

    return this;
  }

}
