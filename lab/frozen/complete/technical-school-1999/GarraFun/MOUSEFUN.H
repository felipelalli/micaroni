#ifndef MOUSEFUN_F&FFUN_1999
#define MOUSEFUN_F&FFUN_1999

#include <dos.h>
#include "fun.h"
#include "pilha.h"
/*
  Hierarquia:

 …ÕÕÕÕÕª    …ÕÕÕÕÕÕÕÕÕÕª
 ∫ Fun ∫=-ƒ>∫ MouseFun ∫
 »ÕÕÕÕÕº    »ÕÕÕÕÕÕÕÕÕÕº
*/

/////////////
// PADRÂES //
/////////////
#define POSICAO_PADRAO_X 0
#define POSICAO_PADRAO_Y 0

////////////////
// DEFINIÄÂES //
////////////////
#define MOUSE 0x33

// Funá‰es do mouse:
#define FUNCAO_DE_INICIALIZACAO 0x0
#define FUNCAO_LIGA             0x1
#define FUNCAO_DESLIGA          0x2
#define FUNCAO_COORDENADAS      0x3
#define FUNCAO_POSICAO_DO_MOUSE 0x4
#define FUNCAO_PRESSIONADO      0x5
#define FUNCAO_LIBERADO         0x6
#define FUNCAO_LIMITE_X         0x7
#define FUNCAO_LIMITE_Y         0x8

// Eventos:
#define MOUSE_MOVE 1
#define MOUSE_DOWN 2
#define MOUSE_UP   4
#define MOUSE_DOWN_DIREITO 8
#define MOUSE_UP_DIREITO  16
#define MOUSE_DOWN_AMBOS  32
#define MOUSE_UP_AMBOS    64

// Bot‰es:
#define BOTAO_ESQUERDO 1
#define BOTAO_DIREITO  2
#define BOTAO_DO_MEIO  3

///////////
// TIPOS //
///////////
#ifndef COORDENADA
typedef
  unsigned int COORDENADA;
#endif

#ifndef COR
typedef
  unsigned char COR;
#endif

#ifndef MOUSE_EVENTO
typedef
  unsigned char MOUSE_EVENTO;
#endif

#ifndef BOTAO
typedef
  unsigned char BOTAO;
#endif

class MouseFun: public ObjFun
{
  private:
    Pilha<MOUSE_EVENTO> buffer;

  protected:
    BOLEANO inicializa();

  public:
    // Construtores e Destrutor:
    MouseFun(COORDENADA = POSICAO_PADRAO_X, // X inicial
             COORDENADA = POSICAO_PADRAO_Y, // Y inicial
             BOLEANO    = VERDADEIRO);   // Indica se o mouse aparece
   ~MouseFun();

    // Func‰es Èteis:
    void liga();    // Liga o Mouse
    void desliga(); // Desliga o Mouse
    void posicao(const COORDENADA&, const COORDENADA&); // X, Y
    MouseFun& operator++();
    MouseFun& operator--();
    void area(const COORDENADA&, const COORDENADA&,
              const COORDENADA&, const COORDENADA&);

    // Verificaá‰es:
    COORDENADA x() const;
    COORDENADA y() const;
    BOTAO botao() const;
    MOUSE_EVENTO evento();
    MOUSE_EVENTO evento_pause();
    MOUSE_EVENTO evento_pause(const BOTAO& botao);
    BOLEANO verifica(const COORDENADA&, const COORDENADA&,
                     const COORDENADA&, const COORDENADA&) const;
};

#endif