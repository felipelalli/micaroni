#ifndef JANELAS_CALHAU_F&F_FUN_1999_VER_1.0
#define JANELAS_CALHAU_F&F_FUN_1999_VER_1.0

#include "definic.h"
#include "mousefun.h"

#include <iostream.h>

#ifndef COR
typedef
  unsigned char COR;
#endif

#define X1_PADRAO_CALHAU 10
#define Y1_PADRAO_CALHAU 10
#define X2_PADRAO_CALHAU 50
#define Y2_PADRAO_CALHAU 50

#define OBJETO_PADRAO     0
#define DESKTOP_CALHAU    1
#define FORMULARIO_CALHAU 2

class Acessorios
{
  public:
    int gprintf(int xloc, int yloc, char *fmt, ...)
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

    void pause() const
    {
      char c;

      limpa_teclado();
      le_teclado(&c);
    }

    void le_teclado(char* ch) const
    {
      *ch = getch();
    }

    void limpa_teclado() const;

    void bip() const
    {
      cout << (char) 7;
    }
    void msg(char* txt = "");
    void quadrado3d(int x, int y, int x2, int y2, int cor1, int cor2);
    void limpeza(int x, int y, int x2, int y2, int core = 15);
    void escreva(int x, int x2, int y, char* texto);
    void janela(int x, int y, int x2, int y2, char* titulo, char ativo = VERDADEIRO);
    void sombra(int x, int y, int x2, int y2);
    void botao_fechar(int x, int y, char fechar);
    void apaga(int x1, int y1, int x2, int y2);
    void bip(int = TEMPO / 4, int = 300);
    char dialogob(int tamx, int tamy, tipo_mensagem msg);
    void dialogo(int tamx, int tamy, tipo_mensagem msg);
    void exibe_botao(int x, int y, int tam, char* titulo = " ");
    void exibe_botao_ativo(int x, int y, int tam, char* titulo = " ");
    void exibe_botao_pressionado(int x, int y, int tam, char* titulo = " ");
    char botao(int x, int y, int tam, char* titulo, char* ch);
    void janela_vazia(int x, int y, int x2, int y2, char* titulo = " ", char ativo = VERDADEIRO);
    char tela_limpa();
};

class JanelaMae
{
  typedef
    unsigned int TIPO_DO_OBJETO;

  private:
    BOLEANO c_marcado_para_excluir;

  protected:
    TIPO_DO_OBJETO c_tipo;
    COORDENADA c_x1, c_y1, c_x2, c_y2;

  public:
    JanelaMae();
   ~JanelaMae();
    const TIPO_DO_OBJETO& tipo() const { return this->c_tipo; }

    // Propriedades p£blicas:
    BOLEANO c_foco;

    // Fun‡äes e defini‡äes espec¡ficas:
    void fecha();
    void define(const COORDENADA& esquerda, const COORDENADA& cima,
                const COORDENADA& direita, const COORDENADA& baixo)
    {
      c_x1 = esquerda;
      c_y1 = cima;
      c_x2 = direita;
      c_y2 = baixo;
    }

    // Verifica‡äes:
    const BOLEANO& fechado() const { return this->c_marcado_para_excluir; }
    const COORDENADA& x1() const { return this->c_x1; }
    const COORDENADA& x2() const { return this->c_x2; }
    const COORDENADA& y1() const { return this->c_y1; }
    const COORDENADA& y2() const { return this->c_y2; }
    const BOLEANO& foco() const { return this->c_foco; }

    // Comuns:
    virtual int loop(MouseFun&, MOUSE_EVENTO*) = 0;
    virtual void exibe(MouseFun&, BOLEANO = FALSO) = 0;
    // Acima: se o valor BOLEANO significa se ‚ atualiza‡Æo ou nÆo
};

class ListaLigadaJanelas
{
  typedef
    struct no_janelas
    {
      JanelaMae* apont_classe;
      no_janelas* prox;
      no_janelas* ante;
    } no_janelas;

  protected:
    no_janelas* c_pri;
    no_janelas* c_ult;
    no_janelas* c_atual;

  public:
    ListaLigadaJanelas();
   ~ListaLigadaJanelas();

    // Verificacoes:
    const BOLEANO vazia() const;
    JanelaMae* atual() const;
    const BOLEANO fora() const { return this->c_atual == NULL; }

    // Fun‡äes:
    const BOLEANO ins(JanelaMae*);
    const BOLEANO del_atual();
    void inicio();
    void fim();
    const BOLEANO avanca();
    const BOLEANO volta();
    void apaga_tudo();
    ListaLigadaJanelas& operator++(int) { avanca(); return *this; }
    ListaLigadaJanelas& operator--(int) { volta(); return *this; }
};

class DesktopCalhau: public JanelaMae
{
  protected:
    ListaLigadaJanelas objetos;

  public:
    struct propriedades
    {
      COR cor_de_fundo;
      int estilo;
    } c;

    DesktopCalhau(const COORDENADA&, const COORDENADA&,
                  const COORDENADA&, const COORDENADA&);

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Insere algum objeto no desktop (ex.: janela, icone, botao)
    const BOLEANO insere(JanelaMae*);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

class FormularioCalhau: public JanelaMae
{
  protected:
    ListaLigadaJanelas objetos;
    COORDENADA c_antey2, c_antex2;

  public:
    struct propriedades
    {
      COR cor_de_fundo;
      char* titulo;
      BOLEANO visivel:1;
      BOLEANO minimizado:1;
      BOLEANO pode_minimizar:1;
      BOLEANO pode_fechar:1;
    } c;

    FormularioCalhau(const COORDENADA&, const COORDENADA&,
                     const COORDENADA&, const COORDENADA&,
                     char*);
   ~FormularioCalhau();

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Insere algum objeto no desktop (ex.: janela, icone, botao)
    const BOLEANO insere(JanelaMae*);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

#endif