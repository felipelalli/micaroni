#ifndef DEFINICOES_BASICAS
#define DEFINICOES_BASICAS

#include                    <dos.h>
#include                   <math.h>
#include                  <conio.h>
#include                  <stdio.h>
#include                 <stdlib.h>
#include                 <stdarg.h>
#include                 <string.h>
#include 	           <graphics.h>

/* Cores: */
#define COR_BORDA_LUZ            15
#define COR_BORDA_SOMBRA          8
#define COR_BORDA_ATIVA_LUZ      14
#define COR_BORDA_ATIVA_SOMBRA    0
#define COR_TITULO_ATIVO         15
#define COR_TITULO_INATIVO        8
#define COR_BARRA_TITULO_ATIVO    1
#define COR_BARRA_TITULO_INATIVO  7
#define COR_BOTAO_ATIVO           1
#define COR_BOTAO_INATIVO         8
#define COR_BOTAO_PRESSIONADO    12
#define COR_FUNDO_BOTAO_INATIVO   7
#define COR_FUNDO_BOTAO_ATIVO    11
#define COR_FUNDO_DIALOGO   	  7
#define COR_TEXTO_DIALOGO         0
#define COR_FUNDO		          3
#define COR_SOMBRA                0
#define COR_FUNDO_STATUS          7
#define COR_TEXTO_STATUS          1
#define COR_FUNDO_NO              3
#define COR_FUNDO_NO_PONTA       14
#define COR_TEXTO_NO              0
#define COR_X_NO                  0
#define COR_LUZ_FORTE            14
#define COR_LUZ_FRACA             6
#define COR_LIGACAO               4
#define COR_TELA                  0
#define COR_TEXTO_TELA           15
#define COR_TEXTO_SELECIONADO    14
#define COR_FUNDO_SELECIONADO     4

/* Tempo: */
#define TEMPO                   100

/* Teclas: */
#define NULO                      0
//#define ENTER                    13
#define ESC                      27
#define TAB                       9
#define BACKSPACE                 8
//#define BARRA_DE_ESPACO          32
#define SETA_CIMA               'H'
#define SETA_BAIXO              'P'
#define SETA_DIREITA            'M'
#define SETA_ESQUERDA           'K'

/* Textos: */
#define BOTAO_SIM             "Sim"
#define BOTAO_NAO             "Nao"
#define BOTAO_CANCELAR   "Cancelar"
#define BOTAO_OK               "OK"
#define FIM                 "-FIM-"

/* Macros: */
#define cor(x)          setcolor(x)
#define keypressed          kbhit()

/* Boleanas: */
#define V		      	         56
//#define F    		              0

/* Valores Matem ticos: */
#define PI                 3.141592

/* TIPOS */
typedef
  char estringue[70];

typedef
  estringue tipo_mensagem[20];

#endif