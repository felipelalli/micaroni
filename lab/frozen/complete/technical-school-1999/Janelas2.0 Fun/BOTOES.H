#ifndef BOTOES_CALHAU_F&F_FUN_1999_VER_1.0
#define BOTOES_CALHAU_F&F_FUN_1999_VER_1.0

#include "janelas.h"

typedef
  void(*tipo_funcao)();

typedef
  void(*tipo_funcao_desenho)(int, int, int, int);

class BotaoSimplesCalhau: public JanelaMae
{
  public:
    struct propriedades
    {
      tipo_funcao funcao;
      tipo_funcao_desenho desenho;
      COR cor_de_fundo;
    } c;

    BotaoSimplesCalhau(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       tipo_funcao, tipo_funcao_desenho);

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

#endif