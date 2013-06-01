#ifndef PINTA_F&F_FUN_1999_VER_1.0
#define PINTA_F&F_FUN_1999_VER_1.0

#include "janelas.h"
#include "conv.h"
#include "arqfun.h"

#define PONTO   1
#define LINHA   2
#define CIRCULO 4
#define LIVRE   8

#ifndef ARQTEMP
#define ARQTEMP "~temp~.tmp"
#endif

extern int ferramenta;
extern COR cor_atual;
extern int grossura;

class ObjetoGraficoMae
{
  protected:
    char c_tipo;           // 1 byte
    COR c_cor;             // 1 byte
    int c_grossura;        // 2 bytes

  public:
    ObjetoGraficoMae();
    virtual void exibe(int, int, int, int) const = 0;
    char tipo() const { return c_tipo; }
};

class PontoGrafico: public ObjetoGraficoMae
{
  protected:
    COORDENADA c_x, c_y;  // 4 bytes

  public:
    PontoGrafico(COORDENADA x, COORDENADA y) { c_x = x; c_y = y; c_tipo = PONTO; }
    void exibe(int, int, int, int) const;
};

class LinhaGrafico: public ObjetoGraficoMae
{
  protected:
    COORDENADA c_x1, c_y1, c_x2, c_y2; // 8 bytes

  public:
    LinhaGrafico(COORDENADA x1, COORDENADA y1, COORDENADA x2, COORDENADA y2)
    { c_x1 = x1; c_y1 = y1; c_x2 = x2; c_y2 = y2; c_tipo = LINHA; }

    void exibe(int, int, int, int) const;
};

class CirculoGrafico: public ObjetoGraficoMae
{
  protected:
    COORDENADA c_x, c_y, c_raio; // 6 bytes

  public:
    CirculoGrafico(COORDENADA x, COORDENADA y, COORDENADA r)
    { c_x = x; c_y = y; c_raio = r; c_tipo = CIRCULO; }

    void exibe(int, int, int, int) const;
};

class ListaLigadaObjetosGraficos
{
  typedef
    struct no_objetos_graficos
    {
      ObjetoGraficoMae* apont_classe;
      no_objetos_graficos* prox;
      no_objetos_graficos* ante;
    } no_objetos_graficos;

  protected:
    no_objetos_graficos* c_pri;
    no_objetos_graficos* c_ult;
    no_objetos_graficos* c_atual;

  public:
    ListaLigadaObjetosGraficos();
   ~ListaLigadaObjetosGraficos();

    // Verificacoes:
    const BOLEANO vazia() const;
    ObjetoGraficoMae* atual() const;
    const BOLEANO fora() const { return this->c_atual == NULL; }

    // Fun‡äes:
    const BOLEANO ins(ObjetoGraficoMae*);
    const BOLEANO del_atual();
    void inicio();
    void fim();
    const BOLEANO avanca();
    const BOLEANO volta();
    void apaga_tudo();
    ListaLigadaObjetosGraficos& operator++(int) { avanca(); return *this; }
    ListaLigadaObjetosGraficos& operator--(int) { volta(); return *this; }
};

class PintaFun: public JanelaMae
{
  protected:
    ListaLigadaObjetosGraficos c_lista;

    // Arquivo:
    ArqFun c_arquivo;

    // Somente Leitura:
    char c_arquivo_somente_leitura;

    void circulo(const COORDENADA&, const COORDENADA&,
                 const COORDENADA&, const COORDENADA&,
                 const COORDENADA&, const COORDENADA&, const int&);

    void desenho_livre(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, MOUSE_EVENTO*);

    void desenha_linha(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, MOUSE_EVENTO*);

    void desenha_circulo(const COORDENADA&, const COORDENADA&,
                         const COORDENADA&, const COORDENADA&,
                         MouseFun&, MOUSE_EVENTO*);

    void desenha_ponto(const COORDENADA&, const COORDENADA&,
                       const COORDENADA&, const COORDENADA&,
                       MouseFun&, MOUSE_EVENTO*);

  public:
    struct propriedades
    {
      COR cor_de_fundo;
    } c;

    PintaFun(const COORDENADA&, const COORDENADA&,
             const COORDENADA&, const COORDENADA&,
             const char* = ARQTEMP);
   ~PintaFun();

    // Arquivo:
    char novo_arquivo(const char* = ARQTEMP);
    char abre_arquivo(const char*);
    char salva_no_arquivo(const char* = "");

    // Exibe-se:
    void exibe(MouseFun&, BOLEANO = FALSO);

    // Procedimento que fica em loop
    int loop(MouseFun&, MOUSE_EVENTO*);
};

#endif