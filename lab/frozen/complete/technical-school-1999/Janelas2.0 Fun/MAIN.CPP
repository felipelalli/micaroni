#include "janelas.h"
#include "pacova.h"
#include "botoes.h"
#include "caixa.h"

class teste
{
  public:
    int oi();

    static void desenho(int, int, int, int);
    static void ops();
    static void sair();
    static void vai();
};

void teste::desenho(int x1, int y1, int x2, int y2)
{
  setcolor(0);
  line (x1 + 5, y1 + 5, x2 - 5, y2 - 5);
}

void teste::sair()
{
  exit(0);
}

void teste::vai()
{
  cleardevice();
}

void teste::ops()
{
  pacova tela;
  MouseFun mouse(250, 250, 0);
  MOUSE_EVENTO evento;

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

  ++mouse; ++mouse;
  desktop->insere(form1);
  desktop->insere(form3);
  desktop->insere(form2);
  desktop->insere(leo);
  desktop->insere(botaosair);
  desktop->insere(botaosair2);
  desktop->insere(botaosair3);
  form3->insere(botao);
  leo->insere(caixa);

  desktop->exibe(mouse);
  desktop->loop(mouse, &evento);

  delete desktop;
  delete form1;
  delete form2;
  delete form3;
  delete botao;
}

void main()
{
  teste::ops();
}