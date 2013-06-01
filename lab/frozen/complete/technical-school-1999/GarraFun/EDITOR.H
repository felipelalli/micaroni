#ifndef EDITOR_GARRAFUN_F&F_FUN_1999
#define EDITOR_GARRAFUN_F&F_FUN_1999

#include "mousefun.h"
#include "graphics.h"
#include "pacova.h"
#include "conv.h"

class EditorGarraFun
{
  private:
    void circulo(const COORDENADA&, const COORDENADA&,
                 const COORDENADA&, const COORDENADA&,
                 const COORDENADA&, const COORDENADA&, const int&);

  public:
    void desenho_livre(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, const pacova& t, MOUSE_EVENTO*);

    void desenha_linha(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, const pacova& t, MOUSE_EVENTO*);

    void desenha_circulo(const COORDENADA&, const COORDENADA&,
                         const COORDENADA&, const COORDENADA&,
                         MouseFun&, const pacova& t, MOUSE_EVENTO*);

    void desenha_ponto(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, const pacova& t, MOUSE_EVENTO*);
};

#endif