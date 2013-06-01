#include <stdlib.h>
#include "pacova.h"
#include "mousefun.h"
#include "janelas.h"
#include "botoes.h"
#include "editor.h"

#define AREA_DE_DESENHO 12, 26, 528, 452
#define BORDA 11, 25, 529, 453
#define LOCAL_FECHAR 525, 10, 532, 17
#define AREA_DE_FERRAMENTAS 552, 5, 632, 457
#define NUMERO_DE_FERRAMENTAS 3

#define DESENHO_LIVRE   0
#define DESENHA_LINHA   1
#define DESENHA_CIRCULO 2
#define DESENHA_PONTO   3

void sair()
{
  exit(0);
}

void desenho_sair(int x1, int y1, int x2, int y2)
{
  setcolor(0);
  line (x1 + 2, y1 + 2, x2 - 2, y2 - 2);
  line (x2 - 2, y1 + 2, x1 + 2, y2 - 2);
}

void main()
{
//  Acessorios a;
  pacova tela;
  MouseFun mouse(60, 30, 0);
  MOUSE_EVENTO evento;

  DesktopCalhau* desktop = new DesktopCalhau(0, 0, getmaxx(), getmaxy());
  desktop->c.cor_de_fundo = 3;
  desktop->c.estilo = SOLID_FILL;
  FormularioCalhau* ferramentas = new FormularioCalhau(100, 100, 200, 300, "Obj.");
  BotaoSimplesCalhau* cmdsair = new BotaoSimplesCalhau(0, 0, 10, 10, &sair, &desenho_sair);

  desktop->insere(ferramentas);
  desktop->insere(cmdsair);

  ++mouse; ++mouse;
  desktop->exibe(mouse);
  desktop->loop(mouse, &evento);

  delete desktop;
}

/*
void main()
{
  pacova t;
  JanelasFun j;
  MouseFun mouse(270, 235);
  EditorGarraFun e;

  BOLEANO sair = FALSO;
  MOUSE_EVENTO evento = FALSO;
  int ferramenta_atual = 0;

  mouse.desliga();
  j.limpeza(0, 0, t.max_x, t.max_y, 11);
  j.msg();
  j.janela(AREA_DE_FERRAMENTAS, "Obj.");
  j.janela(5, 5, 545, 457, "Local do Desenho [Sem-Nome.frn]");
  j.limpeza(BORDA, 0);
  j.quadrado3d(BORDA, COR_BORDA_SOMBRA, COR_BORDA_LUZ);

  for (int i = -60; i <= 10 * 30; i += 30)
    j.quadrado3d(560, 100 + i, 615, 125 + i, COR_BORDA_LUZ, COR_BORDA_SOMBRA);

  // Faz o Desenho do Ponto Gigante no Botao
  setcolor(0);
  setlinestyle(SOLID_LINE, 0, 3);
  for (i = 2; i >= 1; i--)
    circle (587, 82, i);

  // Faz o Desenho da Linha no Botao
  setcolor(4);
  setlinestyle(SOLID_LINE, 0, 3);
  line (574, 117, 601, 107);

  // Faz o Desenho do Circulo no Botao
  setcolor(5);
  setlinestyle(SOLID_LINE, 0, 1);
  circle(587, 82 + 60, 7);

  setcolor(0);
  j.escreva(560, 615, 410, "Sair");
  j.escreva(560, 615, 380, "Sobre");
  j.escreva(560, 615, 350, "Cor");
  j.escreva(560, 615, 320, "Limpa");
  j.escreva(560, 615, 290, "Refaz");
  j.escreva(560, 615, 260, "Volta");

  do
  {
    if (mouse.verifica(AREA_DE_DESENHO))
    {
      mouse.desliga();

      if (ferramenta_atual == DESENHO_LIVRE)
      {
        j.msg("Desenho Livre");
        e.desenho_livre(AREA_DE_DESENHO, mouse, t, &evento);
      }
      else
        if (ferramenta_atual == DESENHA_LINHA)
        {
          j.msg("Desenha Linha");
          e.desenha_linha(AREA_DE_DESENHO, mouse, t, &evento);
        }
        else
          if (ferramenta_atual == DESENHA_CIRCULO)
          {
            j.msg("Desenha C¡rculo");
            e.desenha_circulo(AREA_DE_DESENHO, mouse, t, &evento);
          }
          else
            if (ferramenta_atual == DESENHA_PONTO)
            {
              j.msg("Desenha Ponto");
              e.desenha_ponto(AREA_DE_DESENHO, mouse, t, &evento);
            }
    }
    else
      if (mouse.verifica(AREA_DE_FERRAMENTAS))
      {
        static clicado = FALSO;
        mouse.liga();
        mouse.liga();

        while ((mouse.verifica(AREA_DE_FERRAMENTAS)) && (!sair))
        {
          evento = mouse.evento_pause();

          if (evento == MOUSE_MOVE)
          {
            if (mouse.verifica(560, 70, 615, 95))
              j.msg("Desenha um Ponto");
            else
              if (mouse.verifica(560, 100, 615, 125))
                j.msg("Desenha uma Linha");
              else
                if (mouse.verifica(560, 130, 615, 155))
                  j.msg("Desenha um Circulo");
                else
                  j.msg();
          }
          else
            if (evento == MOUSE_DOWN)
            {
              clicado = VERDADEIRO;

              for (i = -60; i <= 300; i += 30)
                if (mouse.verifica(560, 100 + i, 615, 125 + i))
                {
                  mouse.desliga();
                  j.quadrado3d(560, 100 + i, 615, 125 + i, COR_BORDA_SOMBRA, COR_BORDA_LUZ);
                  mouse.liga();
                }
            }
            else
              if (evento == MOUSE_UP)
              {
                if (clicado)
                {
                  clicado = FALSO;

                  for (i = -60; i <= 300; i += 30)
                    if (mouse.verifica(560, 100 + i, 615, 125 + i))
                    {
                      mouse.desliga();
                      j.quadrado3d(560, 100 + i, 615, 125 + i, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
                      mouse.liga();
                    }
                }
              }
              else
                if (evento == MOUSE_UP_DIREITO)
                {
                  ferramenta_atual++;

                  if (ferramenta_atual >= NUMERO_DE_FERRAMENTAS)
                    ferramenta_atual = 0;
                }
        }

        if (clicado)
        {
          for (i = -60; i <= 300; i += 30)
          {
            mouse.desliga();
            j.quadrado3d(560, 100 + i, 615, 125 + i, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
            mouse.liga();
          }
        }

      }
      else // nas demais  reas
        {
          mouse.liga();
          mouse.liga();

          while ((!mouse.verifica(AREA_DE_DESENHO)) &&
                 (!mouse.verifica(AREA_DE_FERRAMENTAS)) &&
                 (!sair))
          {
             evento = mouse.evento_pause();

             if (evento == MOUSE_MOVE)
             {
               if (mouse.verifica(LOCAL_FECHAR))
                 j.msg("Clique Para Sair");
               else
                 j.msg();
             }
             else
               if (evento == MOUSE_UP)
               {
                 if (mouse.verifica(LOCAL_FECHAR))
                   sair = VERDADEIRO;
               }
          }
        }
  } while (!sair);
}

*/