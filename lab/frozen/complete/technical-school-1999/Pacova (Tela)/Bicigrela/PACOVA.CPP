#include "pacova.h"

pacova::pacova()
{
  cout << "Utilit rio de Tela Pacova 1.0\n";

  char erro = inicializa_modo_grafico();

  if (erro)
  {
    cout << "Erro ao inicializar modo Gr fico: " << grapherrormsg(erro) << "\n";
    cout << "Pressione qualquer tecla para finalizar...";
    bip();
    pause();
  }
}

int pacova::inicializa_modo_grafico()
{
  GraphDriver = VGA; 	     	/* Request auto-detection	*/
  GraphMode = VGAMED;
  initgraph(&GraphDriver, &GraphMode, "");
  ErrorCode = graphresult();		/* Read result of initialization*/
  if(ErrorCode != grOk )		/* Error occured during init   	*/
    return ErrorCode;

  getpalette(&palette);			/* Read the palette from board	*/
  max_cores = getmaxcolor() + 1;	/* Numero M ximo de Cores 	*/

  max_x = getmaxx();
  max_y = getmaxy();		     	/* Tamanho da Tela		  		*/

  return FALSO;
}

int pacova::gprintf(int xloc, int yloc, char *fmt, ...)
{
  va_list  argptr;			/* Argument list pointer	*/
  char str[140];			/* Buffer to build sting into	*/
  int cnt;				/* Result of SPRINTF for return */

  va_start( argptr, fmt );		/* Initialize va_ functions	*/

  cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
  outtextxy( xloc, yloc, str );	/* Send string in graphics mode */

  va_end( argptr );			/* Close va_ functions		*/

  return( cnt );			/* Return the conversion count	*/
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\\

void pacova::pause() const
{
  char c;

  limpa_teclado();
  le_teclado(&c);
}

void pacova::le_teclado(char* ch) const
{
  *ch = getch();
}

void pacova::limpa_teclado() const
{
  char ch;

  while (keypressed)
    le_teclado(&ch);
}

void pacova::bip() const
{
  cout << (char) 7;
}