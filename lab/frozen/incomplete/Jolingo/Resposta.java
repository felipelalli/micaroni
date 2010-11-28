class Resposta
{
  // Dados privados:
  private String cMsgRetorno = new String();
  private boolean cSucesso = false;

  // Construtor:
  public Resposta(String msg)
  {
    this(msg, true);
  }

  public Resposta(String msg, boolean sucesso)
  {
    cMsgRetorno = new String(msg);
    cSucesso = sucesso;
  }

  // Verifica‡äes:
  public String toString()
  {
    String retorno = new String();
    retorno += "(" + cMsgRetorno + ")[";

    if (sucesso())
      retorno += "OK";
    else
      retorno += "!";

    retorno += "]";

    return retorno;
  }

  public String msg()
  {
    return new String(cMsgRetorno);
  }

  public boolean sucesso()
  {
    return cSucesso;
  }
}
