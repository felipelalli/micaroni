#ifndef JANELAS_CALHAU_F&F_FUN_1999_VER_1.0
#define JANELAS_CALHAU_F&F_FUN_1999_VER_1.0

#include "definic.h"
#include "mousefun.h"

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

class JanelaMae
{
  typedef
    unsigned int TIPO_DO_OBJETO;

  private:
    BOLEANO c_marcado_para_excluir;

  protected:
    TIPO_DO_OBJETO c_tipo;
    COORDENADA x1, y1, x2, y2;

  public:
    JanelaMae();
   ~JanelaMae();
    const TIPO_DO_OBJETO& tipo() const { return this->c_tipo; }

    // Fun‡äes e defini‡äes espec¡ficas:
    void fecha();

    // Verifica‡äes:
    const BOLEANO& fechado() const { return this->c_marcado_para_excluir; }

    // Comuns:
    virtual void loop(MouseFun&) = 0;
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

    // Fun‡äes:
    const BOLEANO ins(JanelaMae* componente);
    const BOLEANO del_atual();
    void inicio();
    void fim();
    void avanca();
    void volta();
    void apaga_tudo();
    ListaLigadaJanelas& operator++(int) { avanca(); return *this; }
    ListaLigadaJanelas& operator--(int) { volta(); return *this; }
};

class DesktopCalhau: public JanelaMae
{
    struct propriedades
    {
      COR cor_de_fundo;
      int estilo;
    } c;

    ListaLigadaJanelas objetos;

  public:
    DesktopCalhau(const COORDENADA&, const COORDENADA&,
                  const COORDENADA&, const COORDENADA&);

    void loop(MouseFun&);
};

class FormularioCalhau: public JanelaMae
{
  protected:
    struct propriedades
    {
      COR cor_de_fundo;
      BOLEANO visivel:1;
      BOLEANO ativa:1;
      BOLEANO minimizado:1;
      BOLEANO pode_minimizar:1;
      BOLEANO pode_fechar:1;
    } c;

  public:
    FormularioCalhau(const COORDENADA&, const COORDENADA&,
                     const COORDENADA&, const COORDENADA&);
    void loop(MouseFun&){}
};

#endif