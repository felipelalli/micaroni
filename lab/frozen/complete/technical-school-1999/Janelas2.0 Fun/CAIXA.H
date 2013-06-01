#ifndef CAIXA_TEXTO_CALHAU_F&F_FUN_1999_VER_1.0
#define CAIXA_TEXTO_CALHAU_F&F_FUN_1999_VER_1.0

#include "janelas.h"

#ifndef NUMERO_DE_LETRAS_MAXIMO
#define NUMERO_DE_LETRAS_MAXIMO 100
#endif

#ifndef ALTURA_PADRAO
#define ALTURA_PADRAO 20
#endif

class CaixaTextoCalhau: public JanelaMae
{
  public:
    struct propriedades
    {
      COR cor_de_fundo;
      COR cor_de_frente;
      char texto[NUMERO_DE_LETRAS_MAXIMO];
    } c;

    CaixaTextoCalhau(const COORDENADA&, const COORDENADA&,
                     const COORDENADA&, char* = "");

    const char* texto() const;

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

#endif