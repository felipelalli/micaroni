#include "mousefun.h"

////////////////////////////
// CONSTRUTOR E DESTRUTOR //
////////////////////////////
MouseFun::MouseFun(COORDENADA x,
                   COORDENADA y,
                   BOLEANO aparece)
{
  versao(1, 1, 5);
  grau(VERSAO_LIVRE);
  data(14, 9, 1999);
  numero_de_serie(0);
  nome("Mouse");
  autor("Felipe Micaroni Lalli");

  if (inicializa())
  {
    posicao(x, y);

    if (aparece)
      liga();
    else
      desliga();
  }
}

MouseFun::~MouseFun()
{
  desliga();
}

////////////////
// PROTEGIDAS //
////////////////
BOLEANO MouseFun::inicializa()
{
  union REGS regs;
  regs.x.ax = FUNCAO_DE_INICIALIZACAO;
  int86(0x33, &regs, &regs);
  return regs.x.ax;
}

///////////////////
// FUN€åES éTEIS //
///////////////////
void MouseFun::posicao(const COORDENADA& x, const COORDENADA& y)
{
  union REGS regs;
  regs.x.ax = FUNCAO_POSICAO_DO_MOUSE;
  regs.x.cx = x;
  regs.x.dx = y;
  int86(MOUSE, &regs, &regs);
}

void MouseFun::area(const COORDENADA& x1, const COORDENADA& y1,
                    const COORDENADA& x2, const COORDENADA& y2)
{
	union REGS registers;
	registers.x.ax = FUNCAO_LIMITE_Y;
	registers.x.cx = y1;
	registers.x.dx = y2;
	int86(MOUSE, &registers, &registers);
	registers.x.ax = FUNCAO_LIMITE_X;
	registers.x.cx = x1;
	registers.x.dx = x2;
	int86(MOUSE, &registers, &registers);
}

void MouseFun::liga()
{
  union REGS regs;
  regs.x.ax = FUNCAO_LIGA;
  int86(MOUSE, &regs, &regs);
}

void MouseFun::desliga()
{
  union REGS regs;
  regs.x.ax = FUNCAO_DESLIGA;
  int86(MOUSE, &regs, &regs);
}

MouseFun& MouseFun::operator++()
{
  liga();
  return *this;
}

MouseFun& MouseFun::operator--()
{
  desliga();
  return *this;
}

//////////////////
// VERIFICA€åES //
//////////////////
inline COORDENADA MouseFun::x() const
{
  union REGS regs;
  regs.x.ax = FUNCAO_COORDENADAS;
  int86(MOUSE, &regs, &regs);
  return regs.x.cx;
}

inline COORDENADA MouseFun::y() const
{
  union REGS regs;
  regs.x.ax = FUNCAO_COORDENADAS;
  int86(MOUSE, &regs, &regs);
  return regs.x.dx;
}

inline BOTAO MouseFun::botao() const
{
  union REGS regs;
  regs.x.ax = FUNCAO_COORDENADAS;
  int86(MOUSE, &regs, &regs);
  return regs.x.bx;
}

MOUSE_EVENTO MouseFun::evento()
{
  static COORDENADA antex, antey;
  static BOTAO antebot;
  static BOLEANO variante = FALSO;
  static BOLEANO esquerdo_clicado = FALSO;
  static BOLEANO direito_clicado = FALSO;
  BOTAO atualbot = botao();
  COORDENADA atualx = x(), atualy = y();

  if (!variante)
  {
    antex = atualx;
    antey = atualy;
    antebot = atualbot;
    variante = VERDADEIRO;
  }
  else
   {
     if (((atualbot == BOTAO_ESQUERDO) && (antebot == FALSO)) ||
         ((atualbot == BOTAO_DO_MEIO) && (antebot == BOTAO_DIREITO)))
     {
       this->buffer.empilha(MOUSE_DOWN);
       esquerdo_clicado = VERDADEIRO;
     }
     else
       if ((atualbot == FALSO) && (antebot == BOTAO_ESQUERDO))
       {
         if (!esquerdo_clicado)
         {
           this->buffer.empilha(MOUSE_UP);
           this->buffer.empilha(MOUSE_DOWN);
         }
         else
           this->buffer.empilha(MOUSE_UP);

         esquerdo_clicado = FALSO;
       }
       else
         if (((atualbot == BOTAO_DIREITO) && (antebot == FALSO)) ||
             ((atualbot == BOTAO_DO_MEIO) && (antebot == BOTAO_ESQUERDO)))
         {
           this->buffer.empilha(MOUSE_DOWN_DIREITO);
           direito_clicado = VERDADEIRO;
         }
         else
           if ((atualbot == FALSO) && (antebot == BOTAO_DIREITO))
           {
             if (!direito_clicado)
             {
               this->buffer.empilha(MOUSE_UP_DIREITO);
               this->buffer.empilha(MOUSE_DOWN_DIREITO);
             }
             else
               this->buffer.empilha(MOUSE_UP_DIREITO);

             direito_clicado = FALSO;
           }
           else
             if ((atualbot == BOTAO_DO_MEIO) && (antebot == FALSO))
             {
               this->buffer.empilha(MOUSE_DOWN_DIREITO);
               this->buffer.empilha(MOUSE_DOWN);
               direito_clicado = VERDADEIRO;
               esquerdo_clicado = VERDADEIRO;
             }
             else
               if ((atualbot == FALSO) && (antebot == BOTAO_DO_MEIO))
               {
                 if (!esquerdo_clicado)
                 {
                   this->buffer.empilha(MOUSE_UP);
                   this->buffer.empilha(MOUSE_DOWN);
                 }
                 else
                   this->buffer.empilha(MOUSE_UP);

                 esquerdo_clicado = FALSO;

                 if (!direito_clicado)
                 {
                   this->buffer.empilha(MOUSE_UP_DIREITO);
                   this->buffer.empilha(MOUSE_DOWN_DIREITO);
                 }
                 else
                   this->buffer.empilha(MOUSE_UP_DIREITO);

                 direito_clicado = FALSO;
               }

     if ((atualx != antex) || (atualy != antey))
       this->buffer.empilha(MOUSE_MOVE);

     if ((esquerdo_clicado) && ((!atualbot) || (atualbot == BOTAO_DIREITO)))
     {
       this->buffer.empilha(MOUSE_UP);
       esquerdo_clicado = FALSO;
     }
     else
       if ((!esquerdo_clicado) && ((atualbot == BOTAO_ESQUERDO)
                                || (atualbot == BOTAO_DO_MEIO)))
       {
         this->buffer.empilha(MOUSE_DOWN);
         esquerdo_clicado = VERDADEIRO;
       }

     if ((direito_clicado) && ((!atualbot) || (atualbot == BOTAO_ESQUERDO)))
     {
       this->buffer.empilha(MOUSE_UP_DIREITO);
       direito_clicado = FALSO;
     }
     else
       if ((!direito_clicado) && ((atualbot == BOTAO_DIREITO)
                               || (atualbot == BOTAO_DO_MEIO)))
       {
         this->buffer.empilha(MOUSE_DOWN_DIREITO);
         direito_clicado = VERDADEIRO;
       }

     if (!this->buffer.vazia())
       variante = FALSO;
   }

   if (this->buffer.vazia())
     return FALSO;
   else
     return this->buffer.desempilha();
}

MOUSE_EVENTO MouseFun::evento_pause()
{
  for (int even = evento(); !even; even = evento());
  return even;
}

MOUSE_EVENTO MouseFun::evento_pause(const BOTAO& botao)
{
  for (int even = evento(); even != botao; even = evento());
  return even;
}

BOLEANO MouseFun::verifica(const COORDENADA& x1, const COORDENADA& y1,
                           const COORDENADA& x2, const COORDENADA& y2) const
{
  COORDENADA xat = x(), yat = y();
  return (x1 <= xat) && (x2 >= xat) && (y1 <= yat) && (y2 >= yat);
}

