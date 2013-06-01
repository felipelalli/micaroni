#ifndef BOTOES_CALHAU_F&F_FUN_1999_VER_1.0
#define BOTOES_CALHAU_F&F_FUN_1999_VER_1.0

#include "janelas.h"

class BotaoSimplesCalhau: public JanelaMae
{
  public:
    struct propriedades
    {
      void(*funcao)();
      void(*desenho)(int, int, int, int);
      COR cor_de_fundo;
    } c;

    BotaoSimplesCalhau(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       void(*)() = NULL, void(*)(int, int, int, int) = NULL);

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

#endif