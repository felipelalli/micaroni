#include "figura.h"
#include "pacova.h"

void main()
{
///*
  obj_figura roda("opa.fml");
  pacova tela;

  if (roda.edita())
    cleardevice();

  double cont2 = 1;
  double ops = 0.1;

  roda.defxy(300, 200);

  for (int cont = 0; cont <= 360 * 10 && (!keypressed); cont += 4, cont2 += ops)
  {
    if (cont2 > 4 || cont2 < 0.1)
      ops = -ops;

    roda.defangulo(cont);
//    roda.defraio(cont2);

    roda.exibe();
    roda.muda();
  }
//*/
/*
  roda.abre_arquivo("felipe.fml");

  if (roda.edita())
    cleardevice();

  roda.defxy(250, 200);
  roda.defraio(0.5);

  for (float angulo = 0; (!keypressed); angulo += 1)
  {
    roda.defangulo(angulo);
    roda.exibe();
    roda.muda();
  }

*/
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

    roda.exibe();
    bici.exibe();
    grela.exibe();
    roda.muda();
  }
*/
/*
  obj_roda a("ops.fml");
  obj_roda b("b.fml");
  obj_roda pato("pato.fml");

  a.edita();
  b.edita();
  pato.edita();

  for (tipo_angulo angulo = 0; (angulo <= 360 * 1000) && (!keypressed); angulo += 2)
  {
    a.defangulo(angulo);
    b.defangulo(angulo * 4);
    pato.defangulo(angulo * 8);

    a.defraio(a.raio() - 0.001);

    a.exibe();
    b.exibe();
    pato.exibe();

    delay(20);

    a.apaga(0);
    b.apaga(0);
    pato.apaga(0);

  }
*/
}
