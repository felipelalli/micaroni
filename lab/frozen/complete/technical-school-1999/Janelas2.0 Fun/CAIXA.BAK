#include "caixa.h"

CaixaTextoCalhau::CaixaTextoCalhau(const COORDENADA& x, const COORDENADA& y,
                                   const COORDENADA& tam, char* txt)
{
  this->c_x1 = x;
  this->c_x2 = x + tam;
  this->c_y1 = y;
  this->c_y2 = y + ALTURA_PADRAO;
  this->c.cor_de_fundo = 0;
  this->c.cor_de_frente = 15;
  strcpy(this->c.texto, txt);
}

void CaixaTextoCalhau::exibe(MouseFun& mouse, BOLEANO atualizacao)
{
  --mouse;

  Acessorios a;

  if (!atualizacao)
  {
    a.quadrado3d(this->x1(), this->y1(), this->x2(), this->y2(),
                 COR_BORDA_SOMBRA, COR_BORDA_LUZ);

    a.quadrado3d(this->x1() + 1, this->y1() + 1,
                 this->x2() - 1, this->y2() - 1,
                 COR_BORDA_SOMBRA, COR_BORDA_LUZ);

    a.limpeza(this->x1() + 2, this->y1() + 2, this->x2() - 2, this->y2() - 1,
              this->c.cor_de_fundo);
  }

  setcolor(this->c.cor_de_frente);
  a.gprintf(this->x1() + 5, this->y1() + ALTURA_PADRAO / 2 - 3, this->c.texto);

  ++mouse;
}

int CaixaTextoCalhau::loop(MouseFun& mouse, MOUSE_EVENTO* evento)
{
  int sair = VERDADEIRO;
  exibe(mouse);

  while (mouse.verifica(this->x1(), this->y1(), this->x2(), this->y2()) && sair)
  {
    *evento = mouse.evento_pause();

    if (*evento == MOUSE_DOWN)
      sair = FALSO;
  }

  Acessorios a;
  --mouse;

  a.limpa_teclado();

  while (!sair)
  {
    char st[2] = "?\0";
    char ch;

    setwritemode(XOR_PUT);
    int tamanho_do_texto = textwidth(this->c.texto);

//    a.limpa_teclado();
    while (!kbhit())
    {
      line(tamanho_do_texto + 3 + this->x1(), this->y2() - 4, tamanho_do_texto + 11 + this->x1(), this->y2() - 4);
      delay(TEMPO / 2);
      line(tamanho_do_texto + 3 + this->x1(), this->y2() - 4, tamanho_do_texto + 11 + this->x1(), this->y2() - 4);
      delay(TEMPO / 2);
    }
    a.le_teclado(&ch);
    st[0] = ch;
    setwritemode(COPY_PUT);

    if (ch == 13) // ENTER
      sair = VERDADEIRO;
    else
      if (ch == BACKSPACE)
      {
        if (strlen(this->c.texto))
        {
          this->c.texto[strlen(this->c.texto) - 1] = '\0';
          exibe(mouse);
        }
      }
      else
        {
          if ((tamanho_do_texto < (this->x2() - this->x1()) - 20))
          {
            strcat(this->c.texto, st);
            exibe(mouse, VERDADEIRO);
          }
        }
  }

  exibe(mouse);
  ++mouse; ++mouse;

  return VERDADEIRO;
}

const char* CaixaTextoCalhau::texto() const
{
  return this->c.texto;
}