#ifndef LISTA_LIGADA_F&F_FUN_1999
#define LISTA_LIGADA_F&F_FUN_1999

#include <IOStream.H>
#include "fun.h"

/*
  Hierarquia:

 ษอออออป   ษอออออออออออออออออออออป
 บ Fun บ-->บ ListaLigada<TpElem> บ
 ศอออออผ   ศอออออออออออออออออออออผ
*/

template<class TpElem> class ListaLigada: public ObjFun
{
  protected:
    typedef
      struct NO_LISTA
      {
        TpElem corpo;
        NO_LISTA* prox;
      } NO_LISTA;

    typedef
      NO_LISTA* APONT_NO;

    APONT_NO pri;

  public:
    // Construtor e Destrutor:
    ListaLigada();
   ~ListaLigada();

    // Inclusฦo e Exclusฦo nฦo-ordenada:
    BOLEANO inclui(const TpElem&);
    BOLEANO exclui(const TpElem&);
    void* pesquisa(const TpElem&) const;

    // Vizualizaฦo:
    void lista() const;
};

#endif