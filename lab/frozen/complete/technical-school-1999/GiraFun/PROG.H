#ifndef PROGRAMA_PRINCIPAL
#define PROGRAMA_PRINCIPAL
#include "fun.h"       // Classe Mae Geral
#include "janelas.h"   // Desktop e Janelas
#include "botoes.h"    // Botoes Graficos
#include "mousefun.h"  // Mouse
#include "pacova.h"    // Tela
#include "pintafun.h"  // Quadro de Desenho Grafico
#include "caixa.h"     // Caixa de Texto (nome do arquivo)

#define QUANTAS_FERRAMENTAS 10

class ProgramaPrincipal: public ObjFun
{
  protected:
    DesktopCalhau* desktop;
    FormularioCalhau* ferramentas;
    FormularioCalhau* frmdesenho;
    FormularioCalhau* frmnomearq;
    BotaoSimplesCalhau* cmdsair;
    BotaoSimplesCalhau* botao[QUANTAS_FERRAMENTAS];

  public:
    // Construtor e Destrutor:
    ProgramaPrincipal();
   ~ProgramaPrincipal();

    // Desaloca os Objetos (Janelas, Botäes etc.) e sai:
    void desaloca_tudo_e_sai();
};

#endif