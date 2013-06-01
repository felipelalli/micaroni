#ifndef PILHA_F&F_FUN_1999_VER_1.0
#define PILHA_F&F_FUN_1999_VER_1.0

#include <stdlib.h>

template<class TIPO> class Pilha
{
  typedef
    struct no_pilha
    {
      TIPO corpo;
      no_pilha* prox;
    } no_pilha;

  private:
    no_pilha* pri;

  public:
    Pilha():pri(NULL){}
   ~Pilha();

    void empilha(const TIPO& elemento)
    {
      no_pilha* novo = new no_pilha;
      novo->corpo = elemento;
      novo->prox = pri;
      pri = novo;
    }

    const TIPO& desempilha();
    char vazia() const { return !pri; }
}

template <class TIPO> Pilha<TIPO>::~Pilha()
{
  no_pilha* temp;

  for (no_pilha* atual = pri; atual; atual = atual->prox, delete temp)
    temp = atual;
}

template <class TIPO> const TIPO& Pilha<TIPO>::desempilha()
{
  static TIPO retorno;

  if (!vazia())
  {
    retorno = pri->corpo;
    pri = pri->prox;
  }
  else
    abort();

  return retorno;
}

#endif