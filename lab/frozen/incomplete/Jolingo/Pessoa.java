class PessoaErro extends Exception {}
class PessoaErroSintaxeInvalida extends PessoaErro {}
class PessoaErroEmailInvalido extends PessoaErro {}

class Pessoa
{
  // Dados Privados:
  private String cNome;
  private String cEmail;
  private String cSenha;

  // Contrutores:
  public Pessoa(String nome, String email, String senha)
   throws
    PessoaErroEmailInvalido
  {
    cNome = new String(nome.replace('ž', ' '));
    defineEmail(email);
    cSenha = xor56(senha.replace('ž', ' '));
  }

  public Pessoa(Pessoa irmao)
  {
    cNome = new String(irmao.cNome);
    cEmail = irmao.cEmail;
    cSenha = new String(irmao.cSenha);
  }

  public Pessoa(String dados)   
   throws                        
    PessoaErroSintaxeInvalida     
  {
    if (dados.charAt(0) != '{')
      throw new PessoaErroSintaxeInvalida();
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
              case 1: cNome = new String(temp); break;
              case 2: defineEmail(temp); break;
              case 3: cSenha = new String(temp);
            }
          }

          if (dados.charAt(i - 1) != '}')
            new PessoaErroSintaxeInvalida();
        }
        catch(StringIndexOutOfBoundsException e)
        {
          throw new PessoaErroSintaxeInvalida();
        }
        catch(PessoaErroEmailInvalido e)
        {
          throw new PessoaErroSintaxeInvalida();
        }
        catch(Exception e)
        {
          throw new PessoaErroSintaxeInvalida();
        }
      }
  }

  // Fun‡äes de Classe:
  private static String xor56(String senha)
  {
    String retorno = new String();
    int tamanho = senha.length();

    for (int i = 0; i < tamanho; i++)
      retorno += Character.getNumericValue(senha.charAt(i)) ^ 56;

    return retorno;
  }

  private static boolean valido(String email)
  {
    int arrobaInicio = email.indexOf('@');
    int arrobaFim = email.lastIndexOf('@');

    return (arrobaInicio != -1) &&
           (arrobaInicio == arrobaFim) &&
           (email.indexOf('.') != -1);
  }

  // Defini‡äes:
  public Pessoa defineEmail(String email)
   throws
    PessoaErroEmailInvalido
  {
    if (!valido(email))
      throw new PessoaErroEmailInvalido();
    else
      cEmail = new String(email);

    return this;
  }

  // Verifica‡äes:
  public String nome()
  {
    return new String(cNome);
  }

  public boolean mesmoNome(String outroNome)
  {
    return cNome.equalsIgnoreCase(outroNome);
  }

  public boolean mesmoEmail(String outroEmail)
  {
    return cEmail.equalsIgnoreCase(outroEmail);
  }

  public boolean mesmaSenha(String outraSenha)
  {
    return cSenha.compareTo(xor56(outraSenha)) == 0;
  }

  public boolean mesmaPessoa(Pessoa outra)
  {
    return mesmoNome(outra.cNome) &&
           mesmoEmail(outra.cEmail) &&
           cSenha.compareTo(outra.cSenha) == 0;
  }

  public String toString()
  {
    return new String("{"+ cNome + "ž" + cEmail + "ž" + cSenha + "}");
  }

  public static Pessoa valueOf(String oTal)
   throws
    PessoaErroSintaxeInvalida
  {
    return new Pessoa(oTal);
  }
}
