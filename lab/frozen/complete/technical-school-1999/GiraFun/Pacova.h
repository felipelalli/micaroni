#ifndef PACOVA_TELA_FELIPE_LALLI
#define PACOVA_TELA_FELIPE_LALLI

//#include      <dos.h>
#include     <math.h>
#include    <stdio.h>
#include    <conio.h>
#include   <stdarg.h>
//#include   <string.h>
#include <graphics.h>
#include <iostream.h>

#ifdef cor(x)
#undef cor(x)
#endif
#define cor(x) setcolor(x)

#ifdef keypressed
#undef keypressed
#endif
#define keypressed kbhit()

#ifndef PI
#define PI 3.141592
#endif

#ifndef FALSO
#define FALSO 0
#endif

#ifndef VERDADEIRO
#define VERDADEIRO 1
#endif

#ifndef ENTER
#define ENTER (char) 13
#endif

#ifndef CARACTER_NULO
#define CARACTER_NULO '\0'
#endif

#ifndef SETA_DIREITA
#define SETA_DIREITA 'M'
#endif

#ifndef SETA_ESQUERDA
#define SETA_ESQUERDA 'K'
#endif

#ifndef SETA_BAIXO
#define SETA_BAIXO 'P'
#endif

#ifndef SETA_CIMA
#define SETA_CIMA 'H'
#endif

#ifndef BARRA_DE_ESPACO
#define BARRA_DE_ESPACO ' '
#endif

#ifndef MAIS
#define MAIS '+'
#endif

#ifndef MENOS
#define MENOS '-'
#endif

#ifndef CTRL_A
#define CTRL_A (char) 1
#endif

#ifndef CTRL_B
#define CTRL_B (char) 2
#endif

#ifndef CTRL_C
#define CTRL_C (char) 3
#endif

#ifndef CTRL_D
#define CTRL_D (char) 4
#endif

#ifndef CTRL_E
#define CTRL_E (char) 4
#endif

#ifndef CTRL_Z
#define CTRL_Z (char) 26
#endif

class pacova
{
  protected:
    // Utilizados para o modo gr fico:
    int     GraphDriver;	     /* Usado para o Modo Gr fico   */
    int     GraphMode;
    int     ErrorCode;		     /* Reports any graphics errors	*/
    struct  palettetype palette; /* Used to read palette info	*/

  public:
    // Vari veis P£blicas:
    int max_x, max_y; /* Resolu‡Æo da Tela          */
    int max_cores;	  /* Maximo de Cores Avali vel  */
    int auxx, auxy;	  /* Vari veis Auxiliares		*/
    char pagina_atual;

    // Construtores e Destrutores:
    pacova();
   ~pacova();

    // Inicializa‡äes:
    int inicializa_modo_grafico();

    // Procedimentos e Fun‡äes de Tela:
    int gprintf(int xloc, int yloc, char *fmt, ...);

    // Procedimentos Relacionados com Entrada/Sa¡da de Usu rio
    void bip() const;
    void pause() const;
    void limpa_teclado() const;
    void le_teclado(char* ch) const;
};

#endif
