#include "prog.h"

//  Esta pouca-vergonha de vari†vel global Ç devido Öquele erro do C++
// de n∆o permitir a passagem de um endereáo de uma funá∆o mesmo ela
// sendo p£blica.
PintaFun* area;
CaixaTextoCalhau* nome_do_arquivo;
int ferramenta = FALSO;
COR cor_atual = 15;
int grossura = 1;

// Acessorios Indispensaveis
pacova tela;
MouseFun mouse(575 / 2, 485 / 2, 0);
MOUSE_EVENTO evento;

void ferramenta_ponto()
{
  ferramenta = PONTO;
}

void ferramenta_reta()
{
  ferramenta = LINHA;
}

void ferramenta_circulo()
{
  ferramenta = CIRCULO;
}

void ferramenta_livre()
{
  ferramenta = LIVRE;
}

void sobre()
{
  Acessorios a;
  a.bip();
}

void sair()
{
  //  Foráa a sa°da do programa.
  //  Esta coxambra Ç devido ao fato
  // do C++ n∆o suportar a passagem
  // de um endereáo de uma funá∆o que
  // pertence Ö sua classe.
  //  Portanto o mouse Ç jogado para fora
  // da tela foráando a sa°da desastrosa.

  MouseFun mouse;
  mouse.area(0, 0, getmaxx() + 10, getmaxy() + 10);
  mouse.posicao(getmaxx() + 5, getmaxy() + 5);
  cleardevice();
  cout << "\n\"Porque Deus amou o mundo de tal maneira que deu o Seu filho\nunigenito para que todo aquele que nele cre nao pereáa,\nmas tenha a vida eterna.\" Jo 3:16";
}

void desenho_sair(int x1, int y1, int x2, int y2)
{
  setcolor(0);
  setlinestyle(0, 0, 3);
  line (x1 + 2, y1 + 2, x2 - 2, y2 - 2);
  line (x2 - 2, y1 + 2, x1 + 2, y2 - 2);
  setlinestyle(0, 0, 1);
}

void desenho_ponto(int x1, int y1, int x2, int y2)
{
  setcolor(0);
  setlinestyle(0, 0, 3);
  circle((int) (x1 + x2) / 2, (int) (y1 + y2) / 2, 2);
  setlinestyle(0, 0, 1);
}

void desenho_linha(int x1, int y1, int x2, int y2)
{
  setcolor(4);
  setlinestyle(0, 0, 3);
  line (x1 + 6, y1 + 10, x2 - 6, y2 - 10);
  setlinestyle(0, 0, 1);
}

void desenho_circulo(int x1, int y1, int x2, int y2)
{
  setcolor(1);
  circle((int) (x1 + x2) / 2, (int) (y1 + y2) / 2, 8);
}

void desenho_sobre(int x1, int y1, int x2, int)
{
  Acessorios a;
  setcolor(6);
  settextstyle(0, 0, 3);
  a.escreva(x1, x2, y1 + 5, "?");
  settextstyle(0, 0, 1);
}

void desenho_salvar(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  setcolor(0);
  settextstyle(2, 0, 4);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 2, "salva");
  settextstyle(0, 0, 1);
}

void desenho_novo(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  setcolor(0);
  settextstyle(2, 0, 4);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 2, "novo");
  settextstyle(0, 0, 1);
}

void desenho_abre(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  setcolor(0);
  settextstyle(2, 0, 4);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 2, "abre");
  settextstyle(0, 0, 1);
}

void desenho_livre(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  setcolor(0);
  settextstyle(2, 0, 4);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 2, "livre");
  settextstyle(0, 0, 1);
}

void desenho_cor(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  a.limpeza(x1 + 2, y1 + 2, x2 - 2, y2 - 1, cor_atual);
  settextstyle(0, 0, 1);
  setcolor(cor_atual ^ 6);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 4, "COR");
  settextstyle(0, 0, 1);
}

void muda_cor()
{
  cor_atual++;

  if (cor_atual > 15)
    cor_atual = 0;
}

void desenho_grossura(int x1, int y1, int x2, int y2)
{
  Acessorios a;
  settextstyle(2, 0, 4);
  setcolor(0);
  a.escreva(x1, x2, (y1 + y2) / 2 - textheight("H") + 2, "gross.");
  settextstyle(0, 0, 1);
  setlinestyle(0, 0, grossura);
  line (x1 + 2, y1 + 6, x2 - 2, y1 + 6);
  line (x1 + 2, y2 - 6, x2 - 2, y2 - 6);
  setlinestyle(0, 0, 0);
}

void muda_grossura()
{
  if (grossura == 3)
    grossura = 1;
  else
    grossura = 3;
}

void arquivo_salvar()
{
  area->salva_no_arquivo(nome_do_arquivo->texto());
}

void arquivo_novo()
{
  area->abre_arquivo(nome_do_arquivo->texto());
  area->exibe(mouse);
}

void arquivo_abre()
{
  area->abre_arquivo(nome_do_arquivo->texto());
  area->exibe(mouse);
}

void ProgramaPrincipal::desaloca_tudo_e_sai()
{
  // Desintegrando Objetos
  if (desktop)
    delete desktop;

  if (ferramentas)
    delete ferramentas;

  if (cmdsair)
    delete cmdsair;

  for (int i = 0; i < QUANTAS_FERRAMENTAS; i++)
    if (botao[i])
      delete botao[i];
}

ProgramaPrincipal::ProgramaPrincipal()
{
  // Mouse:
  mouse.area(0, 0, getmaxx(), getmaxy());

  // Cabecalho:
  versao(1, 0, 0);
  grau(VERSAO_TESTE);
  data(30, 9, 1999);
  numero_de_serie(0);
  nome("Projeto GiraFun - COTUCA 1999");
  autor("Caceffo, Lalli e Magalhaes");

  // Criacao dos Objetos
  desktop = new DesktopCalhau(0, 0, getmaxx(), getmaxy());
  ferramentas = new FormularioCalhau(565, 50, 635, QUANTAS_FERRAMENTAS * 32 + 86, "Obj.");
  frmdesenho  = new FormularioCalhau(0, 0, 585, 473, "Desenho");
  cmdsair = new BotaoSimplesCalhau(getmaxx() - 10, 0, 10, 10, &sair, &desenho_sair);
  area = new PintaFun(5, 20, 570, 465);
  frmnomearq = new FormularioCalhau(500, 10, 660, 60, "Nome do Arquivo");
  nome_do_arquivo = new CaixaTextoCalhau(510, 32, 122, "novo.frn");

  // A f¢rmula para calcular o y Ç (i * 32 + 80)
  botao[0] = new BotaoSimplesCalhau(572, 80, 45, 30, &ferramenta_livre, &desenho_livre);
  botao[1] = new BotaoSimplesCalhau(572, 112, 45, 30, &ferramenta_ponto, &desenho_ponto);
  botao[2] = new BotaoSimplesCalhau(572, 144, 45, 30, &ferramenta_reta, &desenho_linha);
  botao[3] = new BotaoSimplesCalhau(572, 176, 45, 30, &ferramenta_circulo, &desenho_circulo);
  botao[4] = new BotaoSimplesCalhau(572, 208, 45, 30, &arquivo_abre, &desenho_abre);
  botao[5] = new BotaoSimplesCalhau(572, 240, 45, 30, &arquivo_salvar, &desenho_salvar);
  botao[6] = new BotaoSimplesCalhau(572, 272, 45, 30, &sobre, &desenho_sobre);
  botao[7] = new BotaoSimplesCalhau(572, 304, 45, 30, &muda_cor, &desenho_cor);
  botao[8] = new BotaoSimplesCalhau(572, 336, 45, 30, &muda_grossura, &desenho_grossura);
  botao[9] = new BotaoSimplesCalhau(572, 368, 45, 30, &arquivo_novo, &desenho_novo);

  // Modificando Propriedades Padr‰es
  desktop->c.cor_de_fundo = 1;
  frmdesenho->c_foco = VERDADEIRO;

  // Pondo Cada Macaco no Seu Galho
  desktop->insere(frmdesenho);
  desktop->insere(ferramentas);
  desktop->insere(frmnomearq);
  frmdesenho->insere(area);
  desktop->insere(cmdsair);
  frmnomearq->insere(nome_do_arquivo);

  for (int i = 0; i < QUANTAS_FERRAMENTAS; i++)
    ferramentas->insere(botao[i]);

  // Botando Para Funcionar
  ++mouse; ++mouse;
  desktop->exibe(mouse);
  desktop->loop(mouse, &evento);
}

ProgramaPrincipal::~ProgramaPrincipal()
{
  desaloca_tudo_e_sai();
}

