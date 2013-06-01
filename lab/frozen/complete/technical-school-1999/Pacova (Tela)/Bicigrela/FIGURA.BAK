#include "figura.h"

obj_figura::obj_figura():carquivo_definido(FALSO),
                         carquivo(NULL),
                         cnumero_de_nos(0),
                         cbuffer_definido(FALSO),
                         carquivo_somente_leitura(FALSO),
                         cgrossura(1),
                         cangulo(0),
                         craio(1)
{
  cx = (tipo_xy) ctela.max_x / 2;
  cy = (tipo_xy) ctela.max_y / 2;
}

obj_figura::obj_figura(char* vnomearq):cnumero_de_nos(0),
                                       cbuffer_definido(FALSO),
                                       cgrossura(1),
                                       cangulo(0),
                                       craio(1)
{
  cx = (tipo_xy) ctela.max_x / 2;
  cy = (tipo_xy) ctela.max_y / 2;
  carquivo = NULL;
  carquivo_definido = FALSO;
  abre_arquivo(vnomearq);
}

obj_figura::~obj_figura()
{
  fclose(carquivo);

  if (cbuffer)
    free(cbuffer);
}

char obj_figura::abre_arquivo(char* vnomearq)
{
  if (!carquivo_definido)
  {
    if (!(carquivo = fopen(vnomearq, "rb")))
    {
      carquivo = fopen(vnomearq, "ab+");
      carquivo_somente_leitura = FALSO;
    }
    else
    {
      cnumero_de_nos = (unsigned int) filelength(fileno(carquivo)) / sizeof(estrutura_circular);
      carquivo_somente_leitura = VERDADEIRO;
    }

    strcpy(cnomearq, vnomearq);

    carquivo_definido = VERDADEIRO;
    rewind(carquivo);
    return VERDADEIRO;
  }
  else
    return FALSO;
}

// CONVERSOR -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void obj_figura::converte(const tipo_xy& vx, const tipo_xy& vy, tipo_angulo* vangulo, tipo_raio* vraio)
{
  tipo_xy cx = (tipo_xy) (ctela.max_x + 1) / 2;
  tipo_xy cy = (tipo_xy) (ctela.max_y + 1) / 2;

  if (vx == cx && vy == cy)
  {
    *vangulo = 0;
    *vraio = 0;
  }
  else
    if (vx == cx)
    {
      if (vy > cy)
      {
        *vraio = vy - cy;
        *vangulo = 270;
      }
      else
        if (vy < cy)
        {
          *vraio = cy - vy;
          *vangulo = 90;
        }
    }
    else
      if (vy == cy)
      {
        if (vx > cx)
        {
          *vraio = vx - cx;
          *vangulo = 0;
        }
        else
         if (vx < cx)
         {
           *vraio = cx - vx;
           *vangulo = 180;
         }
      }
      else
        if (vx > cx && vy < cy) /* Primeiro Quadrante */
        {
          *vraio = sqrt(pow((vx - cx), 2) + pow((cy - vy), 2));
          *vangulo = atan2((cy - vy), (vx - cx)) * 180 / PI;
        }
        else
          if (vx < cx && vy < cy) /* Segundo Quadrante */
          {
            *vraio = sqrt(pow((cx - vx), 2) + pow((cy - vy), 2));
            *vangulo = 180 - (atan2((cy - vy), (cx - vx)) * 180 / PI);
          }
          else
            if (vx < cx && vy > cy) /* Terceiro Quadrante */
            {
              *vraio = sqrt(pow((cx - vx), 2) + pow((vy - cy), 2));
              *vangulo = 180 + (atan2((vy - cy), (cx - vx)) * 180 / PI);
            }
            else
              if (vx > cx && vy > cy) /* Quarto Quadrante */
              {
                *vraio = sqrt(pow((vx - cx), 2) + pow((vy - cy), 2));
                *vangulo = 360 - (atan2((vy - cy), (vx - cx)) * 180 / PI);
              }
}

void obj_figura::converte(const tipo_angulo& vangulo, const tipo_raio& vraio, tipo_xy* vx, tipo_xy* vy, const tipo_xy& cx, const tipo_xy& cy)
{
  *vx = cos(vangulo * (PI / 180)) * vraio + cx;
  *vy = sin(vangulo * (PI / 180)) * vraio + cy;
}

// EXIBE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
char obj_figura::exibe(const tipo_xy& vx, const tipo_xy& vy, const tipo_angulo& vangulo, const tipo_raio& vraio)
{
  defxy(vx, vy);
  defangulo(vangulo);
  defraio(vraio);

  return exibe();
}

char obj_figura::exiben()
{
  char retorno;

  if (cgrossura == 3)
  {
    cgrossura = 1;
    retorno = exibe();
    cgrossura = 3;
  }

  if (cgrossura == 1)
    retorno = exibe();

  return retorno;
}

char obj_figura::exibe()
{
  if (!carquivo_definido)
    return FALSO;
  else
   {
     if (!cbuffer_definido)
     {
       cbuffer = (estrutura_circular*) malloc(sizeof(estrutura_circular) * cnumero_de_nos);
       cbuffer_definido = VERDADEIRO;

       rewind(carquivo);
       fread(cbuffer, sizeof(estrutura_circular), cnumero_de_nos, carquivo);
     }

     if (cgrossura == 3)
       setlinestyle(SOLID_LINE, 1, 3);
     else
       setlinestyle(SOLID_LINE, 1, 1);

     for (unsigned int cont = 0; cont < cnumero_de_nos; cont++)
     {
       tipo_xy x1, y1, x2, y2;
       converte(cbuffer[cont].angulo1 + cangulo, cbuffer[cont].raio1 * craio, &x1, &y1, cx, cy);
       converte(cbuffer[cont].angulo2 + cangulo, cbuffer[cont].raio2 * craio, &x2, &y2, cx, cy);
       cor(cbuffer[cont].cor);
       line(x1, y1, x2, y2);
     }

     return VERDADEIRO;
   }
}

// APAGA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
char obj_figura::apagan(const tipo_cor& vcor)
{
  char retorno;

  if (cgrossura == 3)
  {
     cgrossura = 1;
     retorno = apaga(vcor);
     cgrossura = 3;
  }
  else
    retorno = apaga(vcor);

  return retorno;
}

char obj_figura::apaga(const tipo_xy& vx, const tipo_xy& vy, const tipo_angulo& vangulo, const tipo_raio& vraio, const tipo_cor& vcor)
{
  defxy(vx, vy);
  defangulo(vangulo);
  defraio(vraio);

  return apaga(vcor);
}

char obj_figura::apaga(const tipo_cor& vcor)
{
  if (!carquivo_definido)
    return FALSO;
  else
   {
     if (!cbuffer_definido)
     {
       cbuffer = (estrutura_circular*) malloc(sizeof(estrutura_circular) * cnumero_de_nos);
       cbuffer_definido = VERDADEIRO;
       rewind(carquivo);
       fread(cbuffer, sizeof(estrutura_circular), cnumero_de_nos, carquivo);
     }

     if (cgrossura == 3)
       setlinestyle(SOLID_LINE, 1, 3);
     else
       setlinestyle(SOLID_LINE, 1, 1);

     for (unsigned int cont = 0; cont < cnumero_de_nos; cont++)
     {
       tipo_xy x1, y1, x2, y2;
       converte(cbuffer[cont].angulo1 + cangulo, cbuffer[cont].raio1 * craio, &x1, &y1, cx, cy);
       converte(cbuffer[cont].angulo2 + cangulo, cbuffer[cont].raio2 * craio, &x2, &y2, cx, cy);
       cor(vcor);
       line(x1, y1, x2, y2);
     }

     return VERDADEIRO;
   }
}

// EDITOR -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
inline void obj_figura::poe(const tipo_xy& x1, const tipo_xy& y1,
                            const tipo_xy& x2, const tipo_xy& y2,
                            const tipo_cor& vcor)
{
  estrutura_circular caux;

  converte(x1, y1, &caux.angulo1, &caux.raio1);
  converte(x2, y2, &caux.angulo2, &caux.raio2);

  caux.angulo1 = -caux.angulo1;
  caux.angulo2 = -caux.angulo2;
  caux.cor = vcor;
  cor(vcor);
  line(x1, y1, x2, y2);

  fwrite(&caux, sizeof(estrutura_circular), 1, carquivo);

  cnumero_de_nos++;
}

inline void obj_figura::tira()
{

}

char obj_figura::edita()
{
  ctela.limpa_teclado();
  MouseFun mouse(getmaxx() / 2, getmaxy() / 2, 0);

  if (carquivo_somente_leitura)
    return FALSO;
  else
    if (!carquivo_definido)
      return FALSO;
    else
     {
       tipo_xy cx, cy;
       tipo_xy cxant, cyant;
       tipo_xy ccentrox, ccentroy;
       tipo_angulo cangulo = 0;
       tipo_raio craio = 1;
       char ccirculo = FALSO;
       char ccor = 15;
       char* cursor = (char*) malloc(sizeof(char) * 2);
       char caracter = NULL;
       char clicado = FALSO;
       char velocidade = 1;

       cx = (tipo_xy) (ctela.max_x + 1) / 2;
       cy = (tipo_xy) (ctela.max_y + 1) / 2;

       ccentrox = cx;
       ccentroy = cy;

       cor(8);
       line(cx, 0, cx, ctela.max_y);
       line(0, cy, ctela.max_x, cy);

       putpixel(0, 0, 15);
       getimage(0, 0, 0, 0, cursor);
       putpixel(0, 0, 0);

       do
       {
         cx = mouse.x();
         cy = mouse.y();

         if (keypressed)
         {
           ctela.le_teclado(&caracter);

           switch (caracter)
           {
             case CARACTER_NULO:
               ctela.le_teclado(&caracter);

               if (!ccirculo)
               {
                 switch (caracter)
                 {
                   case SETA_CIMA:
                     cy -= velocidade;
                   break;

                   case SETA_BAIXO:
                     cy += velocidade;
                   break;

                   case SETA_DIREITA:
                     cx += velocidade;
                   break;

                   case SETA_ESQUERDA:
                     cx -= velocidade;
                   break;
                 }
               }
               else
                 {
                   switch (caracter)
                   {
                     case SETA_CIMA:
                       craio += velocidade;
                     break;

                     case SETA_BAIXO:
                       craio -= velocidade;
                     break;

                     case SETA_DIREITA:
                       cangulo += velocidade;
                     break;

                     case SETA_ESQUERDA:
                       cangulo -= velocidade;
                     break;
                   }

                   converte(cangulo, craio, &cx, &cy, ccentrox, ccentroy);
                 }

             break;

             case BARRA_DE_ESPACO:
               if (!clicado)
               {
                 clicado = VERDADEIRO;
                 cxant = cx;
                 cyant = cy;
               }
               else
                 {
                   clicado = FALSO;
                   poe(cx, cy, cxant, cyant, ccor);
                 }
             break;

             case CTRL_A:
               poe(cx + 5, cy, cx + 20, cy + 13, ccor);
               poe(cx, cy, cx + 15, cy + 16, ccor);
               poe(cx - 2, cy + 5, cx + 13, cy + 19, ccor);
               poe(cx - 4, cy + 7, cx + 11, cy + 20, ccor);
               poe(cx - 5, cy + 14, cx + 12, cy, ccor);
               poe(cx - 1, cy + 16, cx + 15, cy + 2, ccor);
               poe(cx + 3, cy + 19, cx + 17, cy + 5, ccor);
               poe(cx + 6, cy + 20, cx + 20, cy + 8, ccor);
             break;

             case CTRL_B:
               ccor++;

               if (ccor > 15)
                 ccor = 0;
             break;

             case CTRL_D:
               if (!ccirculo)
               {
                 ccentrox = cx;
                 ccentroy = cy;
               }
               else
                 if (ccirculo)
                 {
                   cx = ccentrox;
                   cy = ccentroy;
                 }

               ccirculo = !ccirculo;
             break;

             case MAIS:
               velocidade++;
             break;

             case MENOS:
               velocidade--;
             break;

             case CTRL_Z:
               tira();
             break;
           }
         }

         putimage(cx, cy, cursor, XOR_PUT);
         delay(1);
         putimage(cx, cy, cursor, XOR_PUT);
       }
       while(caracter != ENTER);

       return VERDADEIRO;
     }
}

// DEFINICOES E RETORNOS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Retornos:
tipo_xy obj_figura::x()
{
  return cx;
}

tipo_xy obj_figura::y()
{
  return cy;
}

tipo_raio obj_figura::raio()
{
  return craio;
}

tipo_angulo obj_figura::angulo()
{
  return cangulo;
}

// Defini‡äes:
void obj_figura::define(const tipo_xy& vx, const tipo_xy& vy,
                      const tipo_angulo& vangulo, const tipo_raio& vraio)
{
  defxy(vx, vy);
  defangulo(vangulo);
  defraio(vraio);
}

void obj_figura::defangulo(const tipo_angulo& vangulo)
{
  cangulo = vangulo;
}

void obj_figura::defraio(const tipo_raio& vraio)
{
  craio = vraio;

  if ((abs(craio) >= 3) && (cgrossura == 1))
    cgrossura = 3;
  else
    if ((abs(craio) < 3) && (cgrossura == 3))
      cgrossura = 1;
}

void obj_figura::defx(const tipo_xy& vx)
{
  cx = vx;
}

void obj_figura::defy(const tipo_xy& vy)
{
  cy = vy;
}

void obj_figura::defxy(const tipo_xy& vx, const tipo_xy& vy)
{
  cx = vx;
  cy = vy;
}





