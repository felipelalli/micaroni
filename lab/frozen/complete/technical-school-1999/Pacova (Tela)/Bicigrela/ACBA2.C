#include                    <dos.h>
#include                   <math.h>
#include                  <conio.h>
#include                  <stdio.h>
#include                 <stdlib.h>
#include                 <stdarg.h>
#include                 <string.h>
#include 	           <graphics.h>

#define cor_borda_luz            15
#define cor_borda_sombra          8
#define cor_borda_ativa_luz      14
#define cor_borda_ativa_sombra    0
#define cor_titulo_ativo         15
#define cor_titulo_inativo        8
#define cor_barra_titulo_ativo    1
#define cor_barra_titulo_inativo  7
#define cor_botao_ativo           1
#define cor_botao_inativo         8
#define cor_botao_pressionado    12
#define cor_fundo_botao_inativo   7
#define cor_fundo_botao_ativo     3
#define cor_fundo_dialogo   	  7
#define cor_texto_dialogo         0
#define cor_fundo		          3
#define cor_sombra                0
#define tempo                   100

#define nulo                      0
#define enter                    13
#define esc                      27
#define tab                       9
#define barra_de_espaco          32
#define seta_cima               'H'
#define seta_baixo              'P'
#define seta_direita            'M'
#define seta_esquerda           'K'

#define botao_sim             "Sim"
#define botao_nao             "Nao"
#define botao_cancelar   "Cancelar"
#define botao_ok               "OK"

#define cor(x)          setcolor(x)
#define keypressed          kbhit()

#define V		      	         56
#define F    		              0
#define verdadeiro               56
#define falso                     0

#define pi                 3.141592

/* TIPOS */
typedef
       char estringue[70];

typedef
       estringue tipo_mensagem[20];

typedef
       struct xy
       {
	     int x;
	     int y;
	     int cor_ant; /* Cor Anterior */
       } tipo_xy;

typedef
       struct tipo_salva_tela
       {
	     char* tela;
	     struct xy posicao;
       } tipo_salva_tela;

/* VARIµVEIS GLOBAIS */
int     GraphDriver;	     /* Usado para o Modo Gr fico 		     */
int     GraphMode;
int     max_x, max_y;        /* Resolu‡Æo da Tela                     */
int     max_cores;		     /* Maximo de Cores Avali vel        	 */
int     auxx, auxy;		     /* Vari veis Auxiliares					 */
int     ErrorCode;		     /* Reports any graphics errors			 */
struct  palettetype palette; /* Used to read palette info	         */

/* Auxiliares */
tipo_salva_tela tela_antiga; /* Onde Tela Antiga Ser  Guardada		 */
char  caracter;
char  op;
char  aborta;
tipo_mensagem mensagem;

/* Fun‡äes Auxiliares */
int  inicializa_modo_grafico();
int  gprintf(int *xloc, int *yloc, char *fmt, ...);
void quadrado3d(int x, int y, int x2, int y2, int cor1, int cor2);
void janela(int x, int y, int x2, int y2, char* titulo, char ativo);
void limpeza(int x, int y, int x2, int y2, int core);
void limpeza_random(int x, int y, int x2, int y2);
void restaura_tela(tipo_salva_tela* tela);
void restaura_telab(tipo_salva_tela* tela, char sim);
void salva_tela(int x, int y, int x2, int y2, tipo_salva_tela* tela);
void salva_telab(int x, int y, int x2, int y2, tipo_salva_tela* tela, char sim);
void desaloca_tela_salva(tipo_salva_tela* t);
void escreva(int x, int x2, int y, char* texto);
void exibe_botao(int x, int y, int tam, char* titulo);
void exibe_botao_ativo(int x, int y, int tam, char* titulo);
void exibe_botao_pressionado(int x, int y, int tam, char* titulo);
char botao(int x, int y, int tam, char* titulo, char* ch);
void le_teclado(char* ch);
void limpa_teclado();
void bip();
void sai();
void pause();
void derrete(int x1, int y1, int x2, int y2, char corep);
char tela_limpa();
char dialogob(int tamx, int tamy, tipo_mensagem msg);
void dialogo(int tamx, int tamy, tipo_mensagem msg);
char opcao(int x, int y, tipo_mensagem msg);
void botao_fechar(int x, int y, char fechar);
void sombra(int x1, int y1, int x2, int y2);
void msg(char* txt);

void main()
{
  char erro = inicializa_modo_grafico();
  //tipo_salva_tela tela_aux;
  //tela_aux.tela = NULL;

  if (erro)
  {
    clrscr();
    printf("Erro ao inicializar modo Gr fico: %s\n", grapherrormsg(erro));
    printf("Pressione qualquer tecla para finalizar...");
    bip();
    pause();
  }
  else
   {
     limpeza(1, 1, max_x, max_y, cor_fundo);
// /*
     msg("testando...");

     strcpy(mensagem[0], "Teste");
     strcpy(mensagem[1], "Quer Apitar?");
     strcpy(mensagem[2], "Escolha SIM ou NÇO");
     strcpy(mensagem[3], "-FIM-");

     {
       char sai = F;
       char op = 1;

       do
       {
	 janela(100, 50, 160, 70, "J.", op == 1);
	 janela(100, 80, 160, 100, "F.", op == 2);
	 janela(100, 110, 160, 130, "G.", op == 3);
	 janela(100, 140, 160, 160, "A.", op == 4);

	 le_teclado(&caracter);

	 if (caracter == nulo)
	 {
	   le_teclado(&caracter);

	   if (caracter == seta_baixo)
	     op++;
	   else
	     op--;

	   if (op > 4)
	     op = 1;
	   else
	     if (op < 1)
	       op = 4;
	 }
	 else
	    if ((caracter == enter) || (caracter == esc))
	      sai = V;
       }
       while (!sai);
     }

     janela(140, 30, 400, 220, "Felipe", F);

     while (dialogob(230, 90, mensagem) == 3)
	bip();

     strcpy(mensagem[2], "Escolha OK ou OK");

     dialogo(180, 90, mensagem);

     janela(140, 30, 400, 220, "Felipe", V);

     op = 1;
     exibe_botao(300, 100, 70, "Sair");
     exibe_botao(160, 100, 70, "Talvez");

     do
       switch (op)
       {
	 case 1 :
	   if (botao(160, 100, 70, "Apitar", &caracter))
	      bip();
	   else
	       op++;
	   break;
	 case 2 :
	   if (botao(300, 100, 70, "Sair", &caracter))
	      sai();
	   else
	       op--;
       }
     while (!aborta);

//     limpeza(1, 1, max_x, max_y, cor_fundo);

     strcpy(mensagem[0], "Teste");
     strcpy(mensagem[1], "Quer Apitar?");
     strcpy(mensagem[2], "Enquanto Sim, Apitar");
     strcpy(mensagem[3], "-FIM-");

     while (dialogob(230, 90, mensagem) == 1)
	   bip();

     strcpy(mensagem[0], "Olha so'!!!");
     strcpy(mensagem[1], "Isso e' apenas um teste!!!");
     strcpy(mensagem[2], "Olha so' que legal!!!");
     strcpy(mensagem[3], "Voce escreve e pronto");
     strcpy(mensagem[4], "Quanto mais linhas voce coloca");
     strcpy(mensagem[5], "mais interessante fica");
     strcpy(mensagem[6], "-FIM-");

     dialogob(300, 150, mensagem);
  //*/

     strcpy(mensagem[0], "-");
     strcpy(mensagem[1], "-");
     strcpy(mensagem[2], "-");
     strcpy(mensagem[3], "Sair");
     strcpy(mensagem[4], "Sair deste treco");
     strcpy(mensagem[5], "Fazer com que este bagulho funcione");
     strcpy(mensagem[6], "-FIM-");

     opcao(10, 10, mensagem);

     derrete(1, 1, max_x, max_y, cor_fundo);
   }
}

void sai()
{
  aborta = V;
}

void msg(char* txt)
{
  quadrado3d(1, max_y - 15, max_x, max_y, cor_borda_luz, cor_borda_sombra);
  limpeza(2, max_y - 14, max_x - 1, max_y, cor_barra_titulo_inativo);
  cor(cor_titulo_inativo);
  escreva(1, max_x, max_y - 10, txt);
}

char dialogob(int tamx, int tamy, tipo_mensagem msg)
{
  char  cont;
  char  op = 1;
  char  sai = F;

  int y   = (int) (max_y / 2) - (tamy / 2);
  int x   = (int) (max_x / 2) - (tamx / 2);
  int y2  = (int) (max_y / 2) + (tamy / 2);
  int x2  = (int) (max_x / 2) + (tamx / 2);
  int px2 = (int) (max_x / 2) - textwidth("NÆo") - 20;
  int px1 = px2 - 60;
  int px3 = px2 + 60;
  int altura = textheight("H") + 4;

  janela(x, y, x2, y2, msg[0], V);

  cor(cor_texto_dialogo);
  for (cont = 1; strcmp(msg[cont], "-FIM-") != 0; cont++)
    escreva(0, max_x - 8, cont * altura + y + 15, msg[cont]);

  exibe_botao(px1, y2 - altura - 15, 50, botao_sim);
  exibe_botao(px2, y2 - altura - 15, 50, botao_nao);
  exibe_botao(px3, y2 - altura - 15, 82, botao_cancelar);

  do
  {
    switch (op)
    {
      case 1:
	 if (botao(px1, y2 - altura - 15, 50, botao_sim, &caracter))
	    sai = V;

      break;

      case 2:
        if (botao(px2, y2 - altura - 15, 50, botao_nao, &caracter))
           sai = V;

      break;

      case 3:
        if (botao(px3, y2 - altura - 15, 82, botao_cancelar, &caracter))
           sai = V;

      break;
    }

    if (caracter == seta_direita)
    {
	op++;

        if (op > 3)
	   op = 3;
    }
    else
      if (caracter == seta_esquerda)
      {
        op--;

        if (op < 1)
           op = 1;
      }
      else
        if (caracter == tab)
        {
	  op++;

          if (op > 3)
	    op = 1;
	}
	else
          if (caracter == esc)
	  {
            sai = V;
	    op = 3;
          }
  }
  while(!sai);

  restaura_tela(&tela_antiga);
  return op;
}

void dialogo(int tamx, int tamy, tipo_mensagem msg)
{
  int y   = (int) (max_y / 2) - (tamy / 2);
  int x   = (int) (max_x / 2) - (tamx / 2);
  int y2  = (int) (max_y / 2) + (tamy / 2);
  int x2  = (int) (max_x / 2) + (tamx / 2);
  int cont;
  int altura = textheight("H") + 4;

  janela(x, y, x2, y2, msg[0], V);

  cor(cor_texto_dialogo);
  for (cont = 1; strcmp(msg[cont], "-FIM-") != 0; cont++)
    escreva(0, max_x - 8, cont * altura + y + 15, msg[cont]);

  do
  {}
  while (!botao((int) (max_x / 2) - textwidth(botao_ok) - 15, y2 - altura - 15, textwidth(botao_ok) + 50, botao_ok, &caracter));

  restaura_tela(&tela_antiga);
}

void exibe_botao(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, cor_borda_luz, cor_borda_ativa_sombra);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, cor_fundo_dialogo, cor_fundo_dialogo);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, cor_borda_luz, cor_borda_sombra);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, cor_fundo_botao_inativo);
  cor(cor_botao_inativo);
  escreva(x, x + tam, y + 8, titulo);
}

void exibe_botao_ativo(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, cor_borda_ativa_luz, cor_borda_ativa_sombra);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, cor_fundo_dialogo, cor_fundo_dialogo);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, cor_borda_ativa_sombra, cor_borda_ativa_luz);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, cor_fundo_botao_ativo);
  cor(cor_botao_ativo);
  escreva(x, x + tam, y + 8, titulo);
}

void exibe_botao_pressionado(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, cor_borda_ativa_sombra, cor_borda_luz);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, cor_borda_sombra, cor_borda_luz);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, cor_borda_sombra, cor_borda_luz);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, cor_fundo_botao_ativo);
  cor(cor_botao_pressionado);
  escreva(x + 2, x + tam + 2, y + 9, titulo);
}

char botao(int x, int y, int tam, char* titulo, char* ch)
{
  char apertado, sai;

  exibe_botao_ativo(x, y, tam, titulo);

  do
  {
    le_teclado(ch);

    if (*ch == nulo)
       le_teclado(ch);

    if (*ch == esc || *ch == enter || *ch == tab ||
	*ch == seta_baixo || *ch == seta_cima || *ch == barra_de_espaco ||
	*ch == seta_direita || *ch == seta_esquerda)
       sai = V;
    else
        sai = F;

  } while (!sai);

  if (*ch == enter || *ch == barra_de_espaco)
    apertado = V;
  else
      apertado = F;

  if (apertado)
  {
     exibe_botao_pressionado(x, y, tam, titulo);
     delay(tempo);
     exibe_botao_ativo(x, y, tam, titulo);
  }
  else
     exibe_botao(x, y, tam, titulo);

  return apertado;
}

void escreva(int x, int x2, int y, char* texto)
{
   x = (int) ((x2 + x) / 2) - (textwidth(texto) / 2);
   gprintf(&x, &y, texto);
}

void salva_tela(int x1, int y1, int x2, int y2, tipo_salva_tela* t)
{
  desaloca_tela_salva(t);
  t->tela = malloc(imagesize(x1, y1, x2, y2));
  getimage(x1, y1, x2, y2, t->tela);
  t->posicao.x = x1;
  t->posicao.y = y1;
}

void salva_telab(int x, int y, int x2, int y2, tipo_salva_tela* tela, char sim)
{
  if (sim)
    salva_tela(x, y, x2, y2, tela);
}

void desaloca_tela_salva(tipo_salva_tela* t)
{
  free(t->tela);
}

void restaura_tela(tipo_salva_tela* t)
{
  putimage(t->posicao.x, t->posicao.y, t->tela, COPY_PUT);
}

void restaura_telab(tipo_salva_tela* tela, char sim)
{
  if (sim)
    restaura_tela(tela);
}

void quadrado3d(int x, int y, int x2, int y2, int cor1, int cor2)
{
	cor(cor1);
	line(x, y, x2, y);
	line(x, y, x, y2);
	cor(cor2);
	line(x, y2, x2, y2);
	line(x2, y2, x2, y);
}

void limpeza(int x, int y, int x2, int y2, int core)
{
  int conty;

  cor(core);

  for (conty = y; conty < y2; conty++)
	line(x, conty, x2, conty);
}

void limpeza_random(int x, int y, int x2, int y2)
{
  int contx, conty;

  for (conty = y; conty < y2; conty++)
    for (contx = x; contx < x2; contx++)
      putpixel(contx, conty, random(max_cores));
}

void janela(int x, int y, int x2, int y2, char* titulo, char ativo)
{
    int altura = textheight(titulo);

    salva_tela(x, y, x2 + 5, y2 + 5, &tela_antiga);
    quadrado3d(x, y, x2, y2, cor_borda_luz, cor_borda_sombra);
    limpeza(x + 1, y + 1, x2 - 1, y2, cor_fundo_dialogo);

    sombra(x2 + 1, y + 5, x2 + 5, y2 + 5);
    sombra(x + 5, y2 + 1, x2, y2 + 5);

	if (ativo)
	{
	  quadrado3d(x + 3, y + 3, x2 - 34, y + altura + 7, cor_borda_sombra, cor_borda_luz);
	  limpeza(x + 4, y + 4, x2 - 35, y + altura + 7, cor_barra_titulo_ativo);
	  cor(cor_titulo_ativo);
	  botao_fechar(x2 - 17, y + 9, V);
	  botao_fechar(x2 - 27, y + 9, F);
	}
	else
	{
	  quadrado3d(x + 3, y + 3, x2 - 13, y + altura + 7, cor_borda_luz, cor_borda_sombra);
	  limpeza(x + 4, y + 4, x2 - 14, y + altura + 7, cor_barra_titulo_inativo);
	  cor(cor_titulo_inativo);
	}

	x += 7;
	y += 6;
	gprintf(&x, &y, titulo);

	if (!ativo)
	  cor(cor_borda_sombra);
	else
	  cor(cor_borda_luz);

	line(x2 - 3, y + altura - 19, x2 - 3, y2 - 3);
	line(x2 - 6, y + altura - 19, x2 - 6, y2 - 3);
	line(x2 - 9, y + altura - 19, x2 - 9, y2 - 3);

    /*-=-*/

	if (ativo)
	  cor(cor_borda_sombra);
	else
	  cor(cor_borda_luz);

	line(x2 - 4, y + altura - 20, x2 - 4, y2 - 4);
	line(x2 - 7, y + altura - 20, x2 - 7, y2 - 4);
	line(x2 - 10, y + altura - 20, x2 - 10, y2 - 4);
}

int inicializa_modo_grafico()
{
  tela_antiga.tela = NULL;

  GraphDriver = DETECT; 	     	/* Request auto-detection	*/
  initgraph(&GraphDriver, &GraphMode, "");
  ErrorCode = graphresult();		/* Read result of initialization*/

  if(ErrorCode != grOk )		/* Error occured during init	*/
	return ErrorCode;

  getpalette(&palette);			/* Read the palette from board	*/
  max_cores = getmaxcolor() + 1;	/* Numero M ximo de Cores 	*/

  max_x = getmaxx();
  max_y = getmaxy();		     	/* Tamanho da Tela		  		*/

  return falso;
}

int gprintf(int *xloc, int *yloc, char *fmt, ...)
{
  va_list  argptr;			/* Argument list pointer	*/
  char str[140];			/* Buffer to build sting into	*/
  int cnt;				/* Result of SPRINTF for return */

  va_start( argptr, fmt );		/* Initialize va_ functions	*/

  cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
  outtextxy( *xloc, *yloc, str );	/* Send string in graphics mode */
  *yloc += textheight( "H" ) + 2;       /* Advance to next line         */

  va_end( argptr );			/* Close va_ functions		*/

  return( cnt );			/* Return the conversion count	*/
}

void le_teclado(char* ch)
{
  *ch = getch();
}

void limpa_teclado()
{
  char ch;

  while (keypressed)
    le_teclado(&ch);
}

void pause()
{
  char c;

  limpa_teclado();
  le_teclado(&c);
}

char tela_limpa()
{
  int contx, conty;

  for (contx = 1; contx <= max_x; contx++)
    for (conty = 1; conty <= max_y; conty++)
      if (getpixel(contx, conty) != cor_sombra)
         return F;

  return V;
}

void derrete(int x1, int y1, int x2, int y2, char corep)
{
  int x, y, core, sortex, sortey;

  do
  {
    do
    {
      x = random(x2 - x1) + x1;
      y = random(y2 - y1) + y1;
      core = getpixel(x, y);
    }
    while ((core == corep) && (!keypressed));

    sortey  = random(5) + 1;
    sortex = random(2) - random(2);

    if (y == 1)
      putpixel(x, y, cor_sombra);
    else
       putpixel(x, y, getpixel(x, y - 1));

    if ((y + sortey < y2) && (x + sortex < x2) && (x + sortex > x1))
       putpixel(x + sortex, y + sortey, core);
  }
  while (!keypressed);
}

void bip()
{
  cprintf("%c", 7);
}

void sombra(int x, int y, int x2, int y2)
{
    int contx, conty, cor_atual;

    for (contx = x; contx <= x2; contx++)
        for (conty = y; conty <= y2; conty++)
        {
            cor_atual = getpixel(contx, conty);

            if (cor_atual <= 6)
	       cor_atual = cor_sombra;
            else
              if (cor_atual == 7)
                 cor_atual = 8;
              else
		if (cor_atual >= 8)
                   cor_atual -= 8;

            putpixel(contx, conty, cor_atual);
        }
}

void botao_fechar(int x, int y, char fechar)
{
  cor(8);
  setfillstyle(SOLID_FILL, 0);
  fillellipse(x, y, 4, 4);
  cor(15);
  arc(x, y, 45, 180 + 45, 4);

  cor(14);
  if (fechar)
  {
    line(x - 1, y - 1, x + 1, y + 1);
    line(x - 1, y + 1, x + 1, y - 1);
  }
  else
     line(x - 1, y + 1, x + 1, y + 1);
}

char opcao(int x, int y, tipo_mensagem msg)
{
  int cont;
  int tamanhox = 0;
  int tamanhoy;
  int qtd = 0;

  for (cont = 0; strcmp(msg[cont], "-FIM-"); cont++)
  {
    int tamanhoaux = textwidth(msg[cont]);
    qtd++;

    if (tamanhoaux > tamanhox)
      tamanhox = tamanhoaux;
  }

  tamanhoy = (textheight("H") + 5) * qtd;

  quadrado3d(x, y, x + tamanhox + 10, y + tamanhoy + 5, cor_borda_luz, cor_borda_ativa_sombra);
  limpeza(x + 1, y + 1, x + tamanhox + 9, y + tamanhoy + 5, cor_fundo_dialogo);
  sombra(x + tamanhox + 11, y + 5, x + tamanhox + 15, y + tamanhoy + 10);
  sombra(x + 5, y + tamanhoy + 6, x + tamanhox + 10, y + tamanhoy + 10);

  for (cont = 0; strcmp(msg[cont], "-FIM-"); cont++)
  {
    int yy = cont * (textheight("H") + 5) + 15;
    int xx = x + 5;

    cor(cor_texto_dialogo);

    if (strcmp(msg[cont], "-"))
      gprintf(&xx, &yy, "%s", msg[cont]);
    else
     {
       cor(8);
       line(xx, yy + 3, xx + tamanhox - 1, yy + 3);
       cor(15);
       line(xx + 1, yy + 4, xx + tamanhox, yy + 4);
     }
  }

  pause();
}
