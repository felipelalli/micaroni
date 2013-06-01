#include "lista.h"
/* ษออออออออออออออออออออออออออออป
   บ Construtores e Destrutores บ
   ศออออออออออออออออออออออออออออผ */
template<class TpElem> ListaLigada<TpElem>::ListaLigada():pri(NULL)
{
  versao(1, 0, 0);
  grau(VERSAO_LIVRE);
  data(4, 9, 1999);
  numero_de_serie(0);
  nome("Lista Ligada");
  autor("Felipe Micaroni Lalli");
}

template<class TpElem> ListaLigada<TpElem>::~ListaLigada()
{
  APONT_NO atual = this->pri;
  APONT_NO anterior = this->pri;

  while (atual)
  {
    atual = atual->prox;
    delete anterior;
    anterior = atual;
  }

  if (this->pri)
    pri = NULL;
}

/* ษออออออออออออออออออออออออป
   บ Inclui/Exclui/Pesquisa บ
   ศออออออออออออออออออออออออผ */
template<class TpElem> void* ListaLigada<TpElem>
::pesquisa(const TpElem& elemento) const
{
  APONT_NO atual = this->pri;

  while (atual)
  {
    if (atual->corpo == elemento)
      return (void*) atual;
    else
      atual = atual->prox;
  }

  return NULL;
}

template<class TpElem> BOLEANO ListaLigada<TpElem>
::exclui(const TpElem& elemento)
{
  APONT_NO atual = this->pri;
  APONT_NO anterior = this->pri;

  // Se for o primeiro da lista...
  if (atual->corpo == elemento)
  {
    this->pri = anterior->prox->prox;
    delete atual;
    return VERDADEIRO;
  }
  else // est  no meio da lista...
    {
      atual = atual->prox;

      while (atual)
      {
        if (atual->corpo == elemento)
        {
          anterior->prox = atual->prox;
          delete atual;
          return VERDADEIRO;
        }
        else
          {
            anterior = atual;
            atual = atual->prox;
          }
      }

      return FALSO;
    }
}

template<class TpElem> BOLEANO ListaLigada<TpElem>
::inclui(const TpElem& elemento)
{
  APONT_NO novo = new NO_LISTA;

  novo->prox = this->pri;
  novo->corpo = elemento;
  this->pri = novo;

  return VERDADEIRO;
}

template<class TpElem> void ListaLigada<TpElem>::lista() const
{
  cout << '\n';

  for (APONT_NO atual = this->pri; atual; atual = atual->prox)
    cout << atual->corpo << ' ';
}
