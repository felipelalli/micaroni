import java.lang.*;
import java.io.*;
import java.util.*;

class Principal
{
  public static void main(String[] args) throws Exception
  {
    Historico.zera();

    for (int vez = 0; vez <= 56000; vez++)
      Historico.registra(new Fato("Fato n£mero " + vez));

    Stack fatos = Historico.recupera();

    while (!fatos.empty())
    {
      System.out.println((Fato) fatos.pop());
    }
  }
}

/*
{
  public static void main(String[] args) throws Exception
  {
    Pessoa dono = new Pessoa("Felipe Micaroni Lalli", "fe@campinas.net",
                             "2674");

    Jolingo jolingo = new Jolingo(dono, "Fabiane",
                                  "da Silva", "Lugli", Jolingo.FEMEA).nasce();

//  BabaVirtual baba = new BabaVirtual("Creusa");

    JolingoComunidade jc = new JolingoComunidade("Jolingolƒndia");
    System.out.println(InterpretadorDeComandosJP3.executa("cria " + jolingo + " * " + dono, jc));
    System.out.println(InterpretadorDeComandosJP3.executa("mata fabiane " + dono, jc));

//  baba.adiciona(jolingo);
//  jc.adicionaBabaVirtual(baba);

    BufferedReader BR = new BufferedReader(new InputStreamReader(System.in));

    for(int i = 0;; i++)
    {
      long inicio = System.currentTimeMillis();

      System.out.println(jc.vive(24*3600));

      while (System.currentTimeMillis() - inicio < 1000);
    }
  }
}
*/
/*
{
  public static void main(String[] args) throws Exception
  {
    System.out.println(ComandoJP3.intZ("cruza"));
    System.out.println(ComandoJP3.intZ("aceita"));

    Pessoa dono = new Pessoa("Felipe Micaroni Lalli", "fe@campinas.net",
                             "2674");

    ComandoJP3 c = new ComandoJP3("entrega Josefa JoÆo da Silva " + dono);

    System.out.println(c);
  }
}

/*
{
  public static void main(String[] args) throws Exception
  {
    Hashtable teste = new Hashtable();
    teste.put(new String("cria"), new Integer(56));
    teste.put(new String("mata"), new Integer(13));
    teste.put(new String("estrucida"), new Integer(123));

    System.out.println(teste);

    System.out.println(teste.get(new String("mata")));
  }
}
/*
  public static void main(String[] args) throws Exception
  {
    JolingoComunidade ops = new JolingoComunidade("Qwerty Uiop");

    Pessoa dono = new Pessoa("Felipe Micaroni Lalli", "fe@campinas.net",
                             "2674");

    Jolingo jotaLeto = new Jolingo(dono, "Jota Leto",
                                   "Lugli", "Lalli", Jolingo.MACHO).nasce();

    Jolingo maria = new Jolingo(dono, "Mariazinha",
                                "Lugli", "Lalli", Jolingo.FEMEA).nasce();

    Jolingo larissa = new Jolingo(dono, "Larissa",
                                  "Lugli", "Lalli", Jolingo.FEMEA).nasce();

    Jolingo felipe = new Jolingo(dono, "Felipe",
                                 "Lugli", "Lalli", Jolingo.MACHO).nasce();

    BabaVirtual creusa = new BabaVirtual("Creusa");
    creusa.adiciona(larissa).adiciona(felipe);

    ops.adicionaJolingo(jotaLeto).adicionaJolingo(maria).
        adicionaBabaVirtual(creusa);

    System.out.println(ops);
  }
}


/*
  public static void main(String[] args) throws Exception
  {
   // System.out.println(Acao.converte(new File("Medico.ato")));
    System.out.println(Character.isDigit(' '));
  }
*/
/*
    Doenca ops = new Doenca("febre", "p lido", 10, 30);
    Doenca caga = new Doenca(ops.toString());
    System.out.println(ops);
    System.out.println(caga);

    Alimento o = new Alimento("febre", 10, 20, 30);
    Alimento c = new Alimento(o.toString());
    System.out.println(o);
    System.out.println(c);


  }
*//*
    Pessoa ops = new Pessoa("Felipe Micaroni Lalli",
                            431979467, "abc");

    System.out.println(ops);
    Pessoa outra = new Pessoa(ops.toString());
    System.out.println(outra);
    System.out.println("---------");
    System.out.println(ops.mesmaPessoa(outra));
  }
*//*
    Jolingo a1 = new Jolingo("Felipe Micaroni Lalli",
                             "Fabiane", "da Silva", "Lugli",
                              Jolingo.FEMEA);

    Jolingo a2 = new Jolingo("Felipe Micaroni Lalli",
                             "Felipe", "Micaroni", "Lalli",
                              Jolingo.MACHO);

    Jolingo filho = new Jolingo(a1, a2);
    String dados = filho.nasce().toString();

    System.out.println(filho);
    System.out.println("----------------");
    Jolingo animal = new Jolingo(dados);
    System.out.println(animal);
  }
*//*
{
  public static void main(String[] args) throws Exception
  {
    Pessoa pessoa = new Pessoa("Priscila Micaroni Lalli",
                                "pri@palmeirense.com.br", "fe3li4pe");

    Jolingo bixo1 = new Jolingo(pessoa, "da Silva", "Lugli");
    Jolingo bixo2 = new Jolingo(pessoa, "Micaroni", "Lalli");

    bixo1.nasce();
    System.out.println(bixo1);
    System.out.println("------------------");

    bixo2.nasce();
    System.out.println(bixo2);
    System.out.println("------------------");

    Jolingo bixo3 = new Jolingo(bixo1, bixo2);
    bixo3.nasce();
    System.out.println(bixo3);

    System.out.println("------------------");

    Jolingo bixo4 = new Jolingo(bixo1, bixo2);
    bixo4.nasce();
    System.out.println(bixo4);

    while (!(bixo3.morto() && bixo4.morto()))
    {
      long inicio = System.currentTimeMillis();

      try
      {
        bixo3.vive(50);
      }
      catch(JolingoErroNaoVive e){}

      try
      {
        bixo4.vive(50);
      }
      catch(JolingoErroNaoVive e){}

      if (!bixo3.morto())
        System.out.println(
        bixo3.bebe(new Agua(10)).msg());

      if (!bixo3.morto())
        System.out.println(
        bixo3.come(new Alimento("banana", 50, 1, 60, 100, 10)).msg());

      System.out.println("------------------");
      System.out.println(JolingoVisualizador.ve(bixo3,
                         JolingoVisualizador.GERAL));

      System.out.println("----------");
      System.out.println(JolingoVisualizador.ve(bixo4,
                         JolingoVisualizador.GERAL));

      while (System.currentTimeMillis() - inicio < 1000);
    }
  }
}
*/
