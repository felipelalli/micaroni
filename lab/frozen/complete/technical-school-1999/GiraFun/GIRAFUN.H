#ifndef GIRAFUN_F&F_FUN
#define GIRAFUN_F&F_FUN

///////////////
// INCLUSÂES //
///////////////
#include "fun.h"

////////////////
// DEFINIÄÂES //
////////////////
#define NUMERO_DE_SERIE 1

typedef
  unsigned char TIPO_COR;

//////////////////////////
// CLASSE ObjetoGrafico //
//////////////////////////
class ObjetoGrafico
{
  private:
    TIPO_COR cor_borda;
    TIPO_COR cor;
};

//////////////////////
// CLASSE PRINCIPAL //
//////////////////////
class GiraFun : public ObjFun
{
  public:
    // Lista de Objetos:
    ListaLigada<ObjGrafico> lista;

    // Construtor:
    GiraFun();
};

#endif