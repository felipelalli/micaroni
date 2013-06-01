#include "editor.h"

void EditorGarraFun::desenha_ponto(const COORDENADA& x1, const COORDENADA& y1,
                                   const COORDENADA& x2, const COORDENADA& y2,
                                   MouseFun& mouse, const pacova& t, MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax, ay;
      ax = mouse.x();
      ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);
      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      *evento = mouse.evento_pause();

      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);
      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
      pinta = VERDADEIRO;
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          putpixel(mouse.x(), mouse.y(), 15);
          pinta = FALSO;
        }
      }
  }

}
void EditorGarraFun::desenho_livre(const COORDENADA& x1, const COORDENADA& y1,
                                   const COORDENADA& x2, const COORDENADA& y2,
                                   MouseFun& mouse, const pacova& t,
                                   MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax, ay;
      ax = mouse.x();
      ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);
      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      *evento = mouse.evento_pause();

      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);
      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      mouse.area(x1, y1, x2, y2);
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        mouse.area(0, 0, t.max_x, t.max_y);
        pinta = FALSO;
      }

    if (pinta)
    {
      COORDENADA x = mouse.x(), y = mouse.y();
      setcolor(15);
      line(antx, anty, x, y);
      antx = x;
      anty = y;
    }
  }
}

void EditorGarraFun::desenha_linha(const COORDENADA& x1, const COORDENADA& y1,
                                   const COORDENADA& x2, const COORDENADA& y2,
                                   MouseFun& mouse, const pacova& t,
                                   MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax = mouse.x(), ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);

      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      if (pinta)
      {
        setcolor(12);
        setlinestyle(1, 0, 0);
        line(antx, anty, ax, ay);
      }

      *evento = mouse.evento_pause();

      if (pinta)
        line(antx, anty, ax, ay);

      setcolor(7);
      setlinestyle(1, 0, 0);
      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      mouse.area(x1, y1, x2, y2);
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          setcolor(15);
          line(antx, anty, mouse.x(), mouse.y());
          mouse.area(0, 0, t.max_x, t.max_y);
          pinta = FALSO;
        }
      }
  }
}

void EditorGarraFun::circulo(const COORDENADA& xx1, const COORDENADA& yy1,
                             const COORDENADA& xx2, const COORDENADA& yy2,
                             const COORDENADA& cx,
                             const COORDENADA& cy,
                             const int& raio)
{
  ConversorFun conv;

  for (double anglo = 0; anglo <= 360 - 6; anglo += 6)
  {
    int x1, y1;
    int x2, y2;
    conv.converte(anglo, raio, &x1, &y1, cx, cy);
    conv.converte(anglo + 6, raio, &x2, &y2, cx, cy);

    if (x1 > xx1 && x2 < xx2 && y1 > yy1 && y2 < yy2 &&
        x1 < xx2 && x2 > xx1 && y1 < yy2 && y2 > yy1)
      line (x1, y1, x2, y2);
  }
}

void EditorGarraFun::desenha_circulo(const COORDENADA& x1, const COORDENADA& y1,
                                     const COORDENADA& x2, const COORDENADA& y2,
                                     MouseFun& mouse, const pacova& t,
                                     MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;
  ConversorFun conv;
  int raio;

  while (mouse.verifica(x1, y1, x2, y2) || pinta)
  {
    {
      COORDENADA ax = mouse.x(), ay = mouse.y();

      if (pinta)
      {
        double r, a;
        conv.converte(mouse.x(), mouse.y(), &a, &r, antx, anty);
        raio = (int) r;
      }

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);

      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      if (pinta)
      {
        setcolor(10);
        setlinestyle(0, 0, 0);
        circulo(x1, y1, x2, y2, antx, anty, raio);
      }

      *evento = mouse.evento_pause();

      if (pinta)
        circulo(x1, y1, x2, y2, antx, anty, raio);

      setcolor(7);
      setlinestyle(1, 0, 0);
      line(ax, 0, ax, t.max_y);
      line(0, ay, t.max_x, ay);

      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          setcolor(15);
          setviewport(x1, y1, x2, y2, 1);
          circle(antx - 12, anty - 26, raio);
          setviewport(0, 0, t.max_x, t.max_y, 0);
          pinta = FALSO;
        }
      }
  }
}