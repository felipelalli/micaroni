#include "pintafun.h"

//////////////////////
// OBJETOS GRAFICOS //
//////////////////////
ObjetoGraficoMae::ObjetoGraficoMae()
{
  this->c_cor = cor_atual;
  this->c_grossura = grossura;
}

void PontoGrafico::exibe(int x1, int y1, int, int) const
{
  setlinestyle(0, 0, this->c_grossura);
  putpixel(this->c_x + x1, this->c_y + y1, this->c_cor);
  setlinestyle(0, 0, 1);
}

void LinhaGrafico::exibe(int x1, int y1, int, int) const
{
  setlinestyle(0, 0, this->c_grossura);
  setcolor(this->c_cor);
  line(this->c_x1 + x1, this->c_y1 + y1, this->c_x2 + x1, this->c_y2 + y1);
  setlinestyle(0, 0, 1);
}

void CirculoGrafico::exibe(int x1, int y1, int x2, int y2) const
{
  int x = getmaxx(), y = getmaxy();
  setcolor(this->c_cor);
  setlinestyle(0, 0, this->c_grossura);

  if (x2 > x)
    x2 = x;
  else
    if (x2 < 0)
      x2 = 0;

  if (x1 > x)
    x1 = x;
  else
    if (x1 < 0)
      x1 = 0;

  if (y2 > y)
    y2 = y;
  else
    if (y2 < 0)
      y2 = 0;

  if (y1 > y)
    y1 = y;
  else
    if (y1 < 0)
      y1 = 0;

  setviewport(x1, y1, x2, y2, 1);
  circle(this->c_x, this->c_y, this->c_raio);
  setviewport(0, 0, x, y, 0);
  setlinestyle(0, 0, 1);
}

//////////////////
// LISTA LIGADA //
//////////////////

ListaLigadaObjetosGraficos::ListaLigadaObjetosGraficos(): c_pri(NULL), c_ult(NULL),
                                          c_atual(NULL)
{}

ListaLigadaObjetosGraficos::~ListaLigadaObjetosGraficos()
{
  apaga_tudo();
}

// Fun‡äes:
void ListaLigadaObjetosGraficos::inicio()
{
  this->c_atual = this->c_pri;
}

void ListaLigadaObjetosGraficos::fim()
{
  this->c_atual = this->c_ult;
}

const BOLEANO ListaLigadaObjetosGraficos::ins(ObjetoGraficoMae* componente)
{
  no_objetos_graficos* novo_no = new no_objetos_graficos;

   novo_no->apont_classe = componente;
   novo_no->prox = NULL;

   if (vazia())
   {
     novo_no->ante = NULL;
     this->c_pri = novo_no;
   }
   else
     {
       novo_no->ante = this->c_ult;
       this->c_ult->prox = novo_no;
     }

   this->c_ult = novo_no;

   return VERDADEIRO;
}

void ListaLigadaObjetosGraficos::apaga_tudo()
{
  inicio();

  while (!vazia())
    del_atual();
}

const BOLEANO ListaLigadaObjetosGraficos::del_atual()
{
  if (!vazia())
  {
    if (this->c_atual->ante)
      this->c_atual->ante->prox = this->c_atual->prox;
    else
      this->c_pri = this->c_atual->prox;

    if (this->c_atual->prox)
      this->c_atual->prox->ante = this->c_atual->ante;
    else
      this->c_ult = this->c_atual->ante;

    delete this->c_atual;
    inicio();

    return VERDADEIRO;
  }
  else
    return FALSO;
}

const BOLEANO ListaLigadaObjetosGraficos::avanca()
{
  if (!vazia())
  {
    if (this->c_atual == this->c_ult)
    {
      this->c_atual = NULL;
      return FALSO;
    }
    else
    {
      this->c_atual = this->c_atual->prox;
      return VERDADEIRO;
    }
  }
  else
    return FALSO;
}

const BOLEANO ListaLigadaObjetosGraficos::volta()
{
  if (!vazia())
  {
    if (this->c_atual == this->c_pri)
    {
      this->c_atual = NULL;
      return FALSO;
    }
    else
    {
      this->c_atual = this->c_atual->ante;
      return VERDADEIRO;
    }
  }
  else
    return FALSO;
}

// Verifica‡äes:
const BOLEANO ListaLigadaObjetosGraficos::vazia() const
{
  return !((BOLEANO) this->c_pri);
}

ObjetoGraficoMae* ListaLigadaObjetosGraficos::atual() const
{
  return this->c_atual->apont_classe;
}

/////////////////////////////
// PARTE DO OBJETO NA TELA //
/////////////////////////////

PintaFun::PintaFun(const COORDENADA& x1, const COORDENADA& y1,
                   const COORDENADA& x2, const COORDENADA& y2,
                   const char* nomearq)
{
  this->c_x1 = x1;
  this->c_x2 = x2;
  this->c_y1 = y1;
  this->c_y2 = y2;
  this->c.cor_de_fundo = 0;

  this->c_arquivo = NULL;

  novo_arquivo(nomearq);
}

PintaFun::~PintaFun()
{
  // Aqui o objeto faz uma "coleta de lixo"
  for (c_lista.inicio(); !(c_lista.fora()); c_lista++)
    delete c_lista.atual();
}

char PintaFun::novo_arquivo(const char* nomearq)
{
  c_lista.apaga_tudo();
  return c_arquivo.abre(nomearq, "wb+");
}

char PintaFun::abre_arquivo(const char* nomearq)
{
  c_arquivo = nomearq;

  if (c_arquivo.aberto())
  {
    c_lista.apaga_tudo();

    for (c_arquivo.posicao(0); !c_arquivo.eof();)
    {
      char aux;
      fread(&aux, sizeof(char), 1, c_arquivo.arquivo());
      //c_arquivo--;

      if (aux == PONTO)
      {
        PontoGrafico* objeto = new PontoGrafico(0, 0);
        fread(objeto, sizeof(PontoGrafico), 1, c_arquivo.arquivo());
        c_lista.ins(objeto);
      }
      else
        if (aux == LINHA)
        {
          LinhaGrafico* objeto = new LinhaGrafico(0, 0, 0, 0);
          fread(objeto, sizeof(LinhaGrafico), 1, c_arquivo.arquivo());
          c_lista.ins(objeto);
        }
        else
          if (aux == CIRCULO)
          {
            CirculoGrafico* objeto = new CirculoGrafico(0, 0, 0);
            fread(objeto, sizeof(CirculoGrafico), 1, c_arquivo.arquivo());
            c_lista.ins(objeto);
          }
    }

    return VERDADEIRO;
  }
  else
    return FALSO;
}

char PintaFun::salva_no_arquivo(const char* nomearq)
{
  if (strcmp(nomearq, ""))
    c_arquivo.abre(nomearq, "wb+");

  if (c_arquivo.aberto())
  {
    c_arquivo.posicao(0);

    for (c_lista.inicio(); !(c_lista.fora()); c_lista++)
    {
      char aux = c_lista.atual()->tipo();
      fwrite(&aux, sizeof(char), 1, c_arquivo.arquivo());

      if (c_lista.atual()->tipo() == PONTO)
        fwrite(c_lista.atual(), sizeof(PontoGrafico), 1, c_arquivo.arquivo());
      else
        if (c_lista.atual()->tipo() == LINHA)
          fwrite(c_lista.atual(), sizeof(LinhaGrafico), 1, c_arquivo.arquivo());
        else
          if (c_lista.atual()->tipo() == CIRCULO)
            fwrite(c_lista.atual(), sizeof(CirculoGrafico), 1, c_arquivo.arquivo());
    }

    return VERDADEIRO;
  }

  return FALSO;
}

void PintaFun::exibe(MouseFun& mouse, BOLEANO atualizacao)
{
  --mouse;

  Acessorios a;

  a.quadrado3d(this->x1(), this->y1(), this->x2(), this->y2(),
               COR_BORDA_SOMBRA, COR_BORDA_LUZ);

  if (!atualizacao)
  {
    a.limpeza(this->x1() + 1, this->y1() + 1, this->x2() - 1, this->y2(),
              this->c.cor_de_fundo);

    for (c_lista.inicio(); !(c_lista.fora()); c_lista++)
      c_lista.atual()->exibe(this->x1(), this->y1(), this->x2(), this->y2());
  }

  ++mouse;
}

int PintaFun::loop(MouseFun& mouse, MOUSE_EVENTO* evento)
{
  --mouse;
//  Acessorios a;

  if (ferramenta == PONTO)
  {
//    a.msg("Clique para Fazer um Ponto");
    desenha_ponto(this->x1(), this->y1(), this->x2(), this->y2(), mouse, evento);
  }
  else
    if (ferramenta == LINHA)
    {
//      a.msg("Clique e Arraste Para Outro Local para Fazer uma Reta");
      desenha_linha(this->x1(), this->y1(), this->x2(), this->y2(), mouse, evento);
    }
    else
      if (ferramenta == CIRCULO)
      {
//        a.msg("Clique e Ajuste o Raio com o Botao Segurado");
        desenha_circulo(this->x1(), this->y1(), this->x2(), this->y2(), mouse, evento);
      }
      else
        if (ferramenta == LIVRE)
        {
//          a.msg("Clique e Segure para Fazer um Desenho Cont¡nuo");
          desenho_livre(this->x1(), this->y1(), this->x2(), this->y2(), mouse, evento);
        }

  if (*evento == MOUSE_UP_DIREITO)
  {
    c_lista.fim();
    c_lista.del_atual();
    exibe(mouse);
  }
  else
    exibe(mouse, VERDADEIRO);

  ++mouse;
  return VERDADEIRO;
}

////////////
// EDITOR //
////////////

void PintaFun::desenha_ponto(const COORDENADA& x1, const COORDENADA& y1,
                             const COORDENADA& x2, const COORDENADA& y2,
                             MouseFun& mouse, MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  if (*evento == MOUSE_DOWN)
    pinta = VERDADEIRO;
  else
    if (*evento == MOUSE_UP)
    {
      if (pinta)
      {
        PontoGrafico* ponto = new PontoGrafico(mouse.x() - this->x1(), mouse.y() - this->y1());
        c_lista.ins(ponto);
        ponto->exibe(this->x1(), this->y1(),
                     this->x2(), this->y2());
        //putpixel(mouse.x(), mouse.y(), 15);
        pinta = FALSO;
      }
    }
    else
      if (*evento == MOUSE_UP_DIREITO)
        return;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax, ay;
      ax = mouse.x();
      ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);
      line(ax, this->y1(), ax, this->y2());
      line(this->x1(), ay, this->x2(), ay);

      *evento = mouse.evento_pause();

      line(ax, this->y1(), ax, this->y2());
      line(this->x1(), ay, this->x2(), ay);
      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
      pinta = VERDADEIRO;
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          PontoGrafico* ponto = new PontoGrafico(mouse.x() - this->x1(), mouse.y() - this->y1());
          c_lista.ins(ponto);
          ponto->exibe(this->x1(), this->y1(),
                       this->x2(), this->y2());
          //putpixel(mouse.x(), mouse.y(), 15);
          pinta = FALSO;
        }
      }
      else
        if (*evento == MOUSE_UP_DIREITO)
          return;
  }
}
void PintaFun::desenho_livre(const COORDENADA& x1, const COORDENADA& y1,
                                   const COORDENADA& x2, const COORDENADA& y2,
                                   MouseFun& mouse, MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax, ay;
      ax = mouse.x();
      ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);
      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);

      *evento = mouse.evento_pause();

      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);
      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      mouse.area(x1, y1, x2, y2);
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        mouse.area(0, 0, getmaxx(), getmaxy());
        pinta = FALSO;
      }
      else
        if (*evento == MOUSE_UP_DIREITO)
          return;


    if (pinta)
    {
      COORDENADA x = mouse.x(), y = mouse.y();
/*
      setcolor(15);
      line(antx, anty, x, y);
*/
      LinhaGrafico* linha = new LinhaGrafico(antx - this->x1(), anty - this->y1(),
                                             x - this->x1(), y - this->y1());
      c_lista.ins(linha);
      linha->exibe(this->x1(), this->y1(),
                   this->x2(), this->y2());

      antx = x;
      anty = y;
    }
  }
}

void PintaFun::desenha_linha(const COORDENADA& x1, const COORDENADA& y1,
                             const COORDENADA& x2, const COORDENADA& y2,
                             MouseFun& mouse, MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;

  while (mouse.verifica(x1, y1, x2, y2))
  {
    {
      COORDENADA ax = mouse.x(), ay = mouse.y();

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);

      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);

      if (pinta)
      {
        setcolor(12);
        setlinestyle(1, 0, 0);
        line(antx, anty, ax, ay);
      }

      *evento = mouse.evento_pause();

      if (pinta)
        line(antx, anty, ax, ay);

      setcolor(7);
      setlinestyle(1, 0, 0);
      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);

      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      mouse.area(x1, y1, x2, y2);
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          /*
          setcolor(15);
          line(antx, anty, mouse.x(), mouse.y());
          */
          LinhaGrafico* linha = new LinhaGrafico(antx - this->x1(), anty - this->y1(),
                                                 mouse.x() - this->x1(), mouse.y() - this->y1());
          c_lista.ins(linha);
          linha->exibe(this->x1(), this->y1(),
                       this->x2(), this->y2());

          mouse.area(0, 0, getmaxx(), getmaxy());

          pinta = FALSO;
        }
      }
      else
        if (*evento == MOUSE_UP_DIREITO)
          return;
  }
}

void PintaFun::circulo(const COORDENADA& xx1, const COORDENADA& yy1,
                       const COORDENADA& xx2, const COORDENADA& yy2,
                       const COORDENADA& cx,  const COORDENADA& cy,
                       const int& raio)
{
  ConversorFun conv;

  for (double anglo = 0; anglo <= 360 - 6; anglo += 6)
  {
    int x1, y1;
    int x2, y2;
    conv.converte(anglo, raio, &x1, &y1, cx, cy);
    conv.converte(anglo + 6, raio, &x2, &y2, cx, cy);

    if (x1 > xx1 && x2 < xx2 && y1 > yy1 && y2 < yy2 &&
        x1 < xx2 && x2 > xx1 && y1 < yy2 && y2 > yy1)
      line (x1, y1, x2, y2);
  }
}

void PintaFun::desenha_circulo(const COORDENADA& x1, const COORDENADA& y1,
                               const COORDENADA& x2, const COORDENADA& y2,
                               MouseFun& mouse, MOUSE_EVENTO* evento)
{
  BOLEANO pinta = FALSO;
  COORDENADA antx, anty;
  ConversorFun conv;
  int raio;

  while (mouse.verifica(x1, y1, x2, y2) || pinta)
  {
    {
      COORDENADA ax = mouse.x(), ay = mouse.y();

      if (pinta)
      {
        double r, a;
        conv.converte(mouse.x(), mouse.y(), &a, &r, antx, anty);
        raio = (int) r;
      }

      setcolor(7);
      setlinestyle(1, 0, 0);
      setwritemode(XOR_PUT);

      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);

      if (pinta)
      {
        setcolor(10);
        setlinestyle(0, 0, 0);
        circulo(x1, y1, x2, y2, antx, anty, raio);
      }

      *evento = mouse.evento_pause();

      if (pinta)
        circulo(x1, y1, x2, y2, antx, anty, raio);

      setcolor(7);
      setlinestyle(1, 0, 0);
      line(ax, 0, ax, getmaxy());
      line(0, ay, getmaxx(), ay);

      setwritemode(COPY_PUT);
      setlinestyle(SOLID_LINE, 0, 0);
    }

    if (*evento == MOUSE_DOWN)
    {
      pinta = VERDADEIRO;
      antx = mouse.x();
      anty = mouse.y();
    }
    else
      if (*evento == MOUSE_UP)
      {
        if (pinta)
        {
          /*
          setcolor(15);
          setviewport(x1, y1, x2, y2, 1);*/
          //circle(antx - x1/*12*/, anty - y1/*26*/, raio);
          //setviewport(0, 0, getmaxx(), getmaxy(), 0);

          CirculoGrafico* cir = new CirculoGrafico(antx - this->x1() /* - 5*/,
                                                   anty - this->y1() /*- 20*/,
                                                   raio);
          c_lista.ins(cir);
          cir->exibe(this->x1(), this->y1(), this->x2(), this->y2());

          pinta = FALSO;
        }
      }
      else
        if (*evento == MOUSE_UP_DIREITO)
          return;
  }
}