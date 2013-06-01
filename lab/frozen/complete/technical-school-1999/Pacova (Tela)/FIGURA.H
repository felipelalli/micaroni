#ifndef FIGURA_PACOVA_FELIPE_LALLI
#define FIGURA_PACOVA_FELIPE_LALLI

#include  <stdio.h>
#include <stdlib.h>
#include     <io.h>
#include "pacova.h"

#ifdef NUMERO_MAXIMO_DE_NOS
#error Impossivel continuar. Numero maximo de nos ja foi definido!
#else
#define NUMERO_MAXIMO_DE_NOS 1000
#endif

typedef float tipo_angulo;
typedef float tipo_raio;
typedef char  tipo_cor;
typedef int   tipo_xy;

typedef
  struct circular
  {
    tipo_angulo angulo1;
    tipo_raio raio1;
    tipo_angulo angulo2;
    tipo_raio raio2;
    tipo_cor cor;
  } estrutura_circular;

class obj_figura
{
  private:
    // Tela:
    pacova ctela;

    // N£meros de N¢s:
    unsigned int cnumero_de_nos;

    // Arquivo:
    char carquivo_definido;
    char cnomearq[20];
    FILE* carquivo;

    // Cache:
    char cbuffer_definido;
    estrutura_circular* cbuffer;

    // Somente Leitura:
    char carquivo_somente_leitura;

    // Propriedades:
    tipo_angulo cangulo;
    tipo_raio craio;
    tipo_xy cx;
    tipo_xy cy;

  protected:
    // Fun‡äes Protegidas:
    inline void poe(const tipo_xy& x1, const tipo_xy& y1,
                    const tipo_xy& x2, const tipo_xy& y2,
                    const tipo_cor& vcor);
    inline void tira();

  public:
    // Construtores e Destrutor:
    obj_figura();
    obj_figura(char* vnomearq);
   ~obj_figura();

   // Fun‡äes P£blicas:
   void abre_arquivo(char* vnomearq);
   void fecha_arquivo();

   // Intera‡Æo com o Usu rio:
   char edita();
   char exibe();
   char exibe(const tipo_xy& vx, const tipo_xy& vy, const tipo_angulo& vangulo, const tipo_raio& vraio);
   char apaga(const tipo_xy& vx, const tipo_xy& vy, const tipo_angulo& vangulo, const tipo_raio& vraio, const tipo_cor& vcor);
   char apaga(const tipo_cor& vcor);
   void muda ();

   // Conversäes:
   void converte(const tipo_xy& vx, const tipo_xy& vy, tipo_angulo* vangulo, tipo_raio* vraio);
   void converte(const tipo_angulo& vangulo, const tipo_raio& vraio, tipo_xy* vx, tipo_xy* vy, const tipo_xy& cx, const tipo_xy& cy);

   // Retornos:
   tipo_xy x();
   tipo_xy y();
   tipo_raio raio();
   tipo_angulo angulo();

   // Defini‡äes:
   void define(const tipo_xy& vx, const tipo_xy& vy,
               const tipo_angulo& vangulo, const tipo_raio& vraio);
   void defangulo(const tipo_angulo& vangulo);
   void defraio(const tipo_raio& vraio);
   void defx(const tipo_xy& vx);
   void defy(const tipo_xy& vy);
   void defxy(const tipo_xy& vx, const tipo_xy& vy);

/* // Operadores:
   obj_figura& operator++(int);
   obj_figura& operator++();
   obj_figura& operator--(int);
   obj_figura& operator--();
   obj_figura& operator+=(const tipo_angulo& vangulo);
   obj_figura& operator-=(const tipo_angulo& vangulo);
   obj_figura& operator+=(const tipo_raio& vraio);
   obj_figura& operator-=(const tipo_raio& vraio);
   obj_figura& operator= (const obj_figura& vfigura);
   obj_figura& operator= (const tipo_angulo& vangulo);
   obj_figura& operator= (const tipo_raio& vraio);
*/
};

#endif