#include "janelas.h"
#include "pacova.h"
#include "botoes.h"
#include "caixa.h"

void desenho(int, int, int, int)
{}

void sair()
{
  exit(0);
}

void main()
{
  pacova tela;
  MouseFun mouse(getmaxx() / 2, getmaxy() / 2, 0);
  MOUSE_EVENTO evento;
/*
  DesktopCalhau* desktop =  new DesktopCalhau(0, 0, getmaxx(), getmaxy());
  FormularioCalhau* form1 = new FormularioCalhau(100, 100, 200, 200, "Teste 1");
  FormularioCalhau* form2 = new FormularioCalhau(150, 150, 300, 300, "Form 2");
  FormularioCalhau* form3 = new FormularioCalhau(450, 50, 540, 400, "Tes 3");
  FormularioCalhau* leo = new FormularioCalhau(10, 10, 200, 200, "Leo");
  BotaoSimplesCalhau* botao = new BotaoSimplesCalhau(455, 100, 50, 20, &vai, &desenho);
  BotaoSimplesCalhau* botaosair = new BotaoSimplesCalhau(5, 5, 20, 20, &sair, &desenho);
  BotaoSimplesCalhau* botaosair2 = new BotaoSimplesCalhau(26, 5, 30, 30, &sair, &desenho);
  BotaoSimplesCalhau* botaosair3 = new BotaoSimplesCalhau(26 + 31, 5, 40, 40, &sair, &desenho);
  CaixaTextoCalhau* caixa = new CaixaTextoCalhau(50, 50, 100, "teste");
  desktop->c.cor_de_fundo = 1;
*/
  DesktopCalhau* desktop = new DesktopCalhau(0, 0, getmaxx(), getmaxy());
  FormularioCalhau* barra = new FormularioCalhau(0, getmaxy() - 50, getmaxx(), getmaxy(), "Principal");
  BotaoSimplesCalhau* botaoSair = new BotaoSimplesCalhau(20, getmaxy() - 40, 20, 20, &sair, &desenho);
  desktop->c.cor_de_fundo = 1;

  ++mouse; ++mouse;
  desktop->insere(barra);
  barra->insere(botaoSair);

  desktop->exibe(mouse);
  desktop->loop(mouse, &evento);

  delete desktop;
  delete barra;
  delete botaoSair;
}