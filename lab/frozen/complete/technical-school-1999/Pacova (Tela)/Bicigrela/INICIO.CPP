// Os procedimentos soltos foram devido Ö minha falta de tempo!
// N∆o Ç burrice nem erro da lingÅagem!
#include "figura.h"
#include "pacova.h"

#define TEMPO 20

void main()
{
  obj_figura roda("ops.fml");

  roda.edita();

  cleardevice();

  double cont2 = 1;
  double ops = 0.1;
  for (int cont = 0; cont <= 360 * 10; cont += 4, cont2 += ops)
  {
    if (cont2 > 4 || cont2 < 0.1)
      ops = -ops;

    roda.exibe(300, 200, cont, cont2);
    delay(30);
    roda.apaga(300, 200, cont, cont2, 0);
  }

  putpixel(200, 200, 12);

/*
  pacova tela;
  obj_figura roda ("ap_roda.fml");
  obj_figura bici ("ap_bici.fml");
  obj_figura grela("ap_grela.fml");

  if (roda.edita())
    cleardevice();

  if (bici.edita())
    cleardevice();

  if (grela.edita())
    cleardevice();

  tela.limpa_teclado();

  roda.defxy(300, 200);
  roda.defraio(3);
  bici.defxy(200, -100);
  bici.defraio(0.7);
  grela.defxy(tela.max_x + 180, (int) tela.max_y / 2);
  grela.defraio(0.7);
  char sinal = -1;
  char parar = FALSO;
  double ops = 0.0001;
  for (int ang = 0; (ang <= 360 * 1000) && (!keypressed); ang += sinal * 4)
  {
    roda.defangulo(ang);
    roda.defraio(roda.raio() - 0.01);
    roda.defx(roda.x() + sinal * 2);

    if ((roda.x() < -roda.raio()) || (roda.x() > tela.max_x + roda.raio()))
      sinal = -sinal;

    if (!parar)
    {
      bici.defy (bici.y() + 4);
      grela.defx(grela.x() - 5);
    }
    else
     {
       bici.defraio(bici.raio() + ops);
       grela.defraio(grela.raio() + ops);
       ops += 0.001;
     }

    if (ang <  -300)
      parar = VERDADEIRO;

    roda.exiben();
    bici.exiben();
    grela.exiben();
    delay(TEMPO);
    roda.apagan(0);
    bici.apagan(0);
    grela.apagan(0);
  }

  obj_figura andre("andre.fml");

  andre.edita();
  cleardevice();
  andre.defraio(1.2);
  andre.defangulo(-90);

  int ativo = 0;

  for (tela.limpa_teclado(); !keypressed; andre.defangulo(andre.angulo() + 1))
  {
    if (andre.raio() < -1.5)
      ativo = 1;

    if (ativo)
    {
      andre.defraio(andre.raio() + 0.05);
      andre.defangulo(andre.angulo() - 3);
    }
    else
      andre.defraio(andre.raio() - 0.005);

    andre.exibe();
    delay(TEMPO);
    andre.apaga(1);
  }

  for (tela.limpa_teclado(); !keypressed; andre.defangulo(andre.angulo() + 8))
  {
    if (ativo)
      andre.defraio(andre.raio() - 0.07);
    else
      andre.defraio(andre.raio() + 0.07);

    andre.exibe();
    delay(TEMPO);
    andre.apaga(0);
  }
*/
}
