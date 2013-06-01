#include "calhau.h"

//////////////////////
// CLASSE PRINCIPAL //
//////////////////////

JanelaMae::JanelaMae():c_tipo(OBJETO_PADRAO),
                       x1(X1_PADRAO_CALHAU), y1(Y1_PADRAO_CALHAU),
                       x2(X2_PADRAO_CALHAU), y2(Y2_PADRAO_CALHAU),
                       c_marcado_para_excluir(FALSO)
{}

JanelaMae::~JanelaMae()
{
  fecha();
}

void JanelaMae::fecha()
{
  c_marcado_para_excluir = VERDADEIRO;
}

//////////////////
// LISTA LIGADA //
//////////////////

ListaLigadaJanelas::ListaLigadaJanelas(): c_pri(NULL), c_ult(NULL),
                                          c_atual(NULL)
{}

ListaLigadaJanelas::~ListaLigadaJanelas()
{
  apaga_tudo();
}

// Fun‡äes:
void ListaLigadaJanelas::inicio()
{
  this->c_atual = this->c_pri;
}

void ListaLigadaJanelas::fim()
{
  this->c_atual = this->c_ult;
}

const BOLEANO ListaLigadaJanelas::ins(JanelaMae* componente)
{
  no_janelas* novo_no = new no_janelas;
  novo_no->apont_classe = componente;
  novo_no->prox = NULL;

  if (!this->c_pri)
  {
    novo_no->ante = NULL;
    this->c_pri = novo_no;
    this->c_ult = novo_no;
  }
  else
    {
      novo_no->ante = this->c_ult;
      this->c_ult->prox = novo_no;
      this->c_ult = novo_no;
    }

  return VERDADEIRO;
}

void ListaLigadaJanelas::apaga_tudo()
{
  inicio();

  while (!vazia())
    del_atual();
}

const BOLEANO ListaLigadaJanelas::del_atual()
{
  if (!vazia())
  {
    if (this->c_atual->ante)
      this->c_atual->ante->prox = this->c_atual->prox;

    if (this->c_atual->prox)
      this->c_atual->prox->ante = this->c_atual->ante;

    no_janelas* temp = this->c_atual;
    delete temp;
    (*this)++;

    return VERDADEIRO;
  }
  else
    return FALSO;
}

void ListaLigadaJanelas::avanca()
{
  if (!vazia())
  {
    if (this->c_atual == this->c_ult)
      this->c_atual = this->c_pri;
    else
      this->c_atual = this->c_atual->prox;
  }
}

void ListaLigadaJanelas::volta()
{
  if (!vazia())
  {
    if (this->c_atual == this->c_pri)
      this->c_atual = this->c_ult;
    else
      this->c_atual = this->c_atual->ante;
  }
}

// Verifica‡äes:
const BOLEANO ListaLigadaJanelas::vazia() const
{
  return (BOLEANO) this->c_pri;
}

JanelaMae* ListaLigadaJanelas::atual() const
{
  return this->c_atual->apont_classe;
}

////////////////
// FORMULARIO //
////////////////

FormularioCalhau::FormularioCalhau
                (const COORDENADA& vx1, const COORDENADA& vy1,
                 const COORDENADA& vx2, const COORDENADA& vy2)
{
  this->x1 = vx1;
  this->x2 = vx2;
  this->y1 = vy1;
  this->y2 = vy2;
  this->c_tipo = FORMULARIO_CALHAU;
  this->c.cor_de_fundo = COR_FUNDO_DIALOGO;
  this->c.visivel = VERDADEIRO;
  this->c.ativa = FALSO;
  this->c.minimizado = FALSO;
  this->c.pode_minimizar = VERDADEIRO;
  this->c.pode_fechar = VERDADEIRO;
}

/////////////
// DESKTOP //
/////////////

DesktopCalhau::DesktopCalhau
             (const COORDENADA& vx1, const COORDENADA& vy1,
              const COORDENADA& vx2, const COORDENADA& vy2)
{
  this->x1 = vx1;
  this->x2 = vx2;
  this->y1 = vy1;
  this->y2 = vy2;
  this->c_tipo = DESKTOP_CALHAU;
  this->c.cor_de_fundo = COR_FUNDO;
  this->c.estilo = INTERLEAVE_FILL;
}

void DesktopCalhau::loop(MouseFun& mouse)
{
  mouse.evento_pause();

}
