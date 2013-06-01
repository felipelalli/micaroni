#ifndef JANELAS_F&F_FUN_1999_VER_SHAREWARE
#define JANELAS_F&F_FUN_1999_VER_SHAREWARE
#include "mousefun.h"
#include "pacova.h"
#include "definic.h"
#include "salvatel.h"

class JanelasFun
{
  private:
    pacova t;
    MouseFun mouse;

  public:
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
    void changetextstyle(int font, int direction, int charsize);
    char tela_limpa();
    void derrete(int x1, int y1, int x2, int y2, char corep = COR_FUNDO);
};

#endif