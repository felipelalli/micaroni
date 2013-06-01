void msg(char* txt)
{
  static char ult_msg[200] = "";

  if (strcmp(txt, ult_msg))
  {
    quadrado3d(0, t.max_y - 15, t.max_x, t.max_y, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
    limpeza(1, t.max_y - 14, t.max_x - 1, t.max_y, COR_FUNDO_STATUS);
    cor(COR_TEXTO_STATUS);
    escreva(0, t.max_x, t.max_y - 10, txt);
    strcpy(ult_msg, txt);
  }
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

void escreva(int x, int x2, int y, char* texto)
{
   x = (int) ((x2 + x) / 2) - (textwidth(texto) / 2);
   t.gprintf(x, y, texto);
}

void janela(int x, int y, int x2, int y2, char* titulo, char ativo)
{
    int altura = textheight(titulo);

    quadrado3d(x, y, x2, y2, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
    limpeza(x + 1, y + 1, x2 - 1, y2, COR_FUNDO_DIALOGO);

    sombra(x2 + 1, y + 5, x2 + 5, y2 + 5);
    sombra(x + 5, y2 + 1, x2, y2 + 5);

    if (ativo)
    {
      quadrado3d(x + 3, y + 3, x2 - 34, y + altura + 7, COR_BORDA_SOMBRA, COR_BORDA_LUZ);
      limpeza(x + 4, y + 4, x2 - 35, y + altura + 7, COR_BARRA_TITULO_ATIVO);
      cor(COR_TITULO_ATIVO);
      botao_fechar(x2 - 17, y + 9, VERDADEIRO);
      botao_fechar(x2 - 27, y + 9, FALSO);
    }
    else
    {
      quadrado3d(x + 3, y + 3, x2 - 13, y + altura + 7, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
      limpeza(x + 4, y + 4, x2 - 14, y + altura + 7, COR_BARRA_TITULO_INATIVO);
      cor(COR_TITULO_INATIVO);
    }

    t.gprintf(x + 7, y + 6, titulo);

    if (!ativo)
      cor(COR_BORDA_SOMBRA);
    else
      cor(COR_BORDA_LUZ);

    line(x2 - 3, y + altura - 2, x2 - 3, y2 - 3);
    line(x2 - 6, y + altura - 2, x2 - 6, y2 - 3);
    line(x2 - 9, y + altura - 2, x2 - 9, y2 - 3);

    /*-=-*/

    if (ativo)
      cor(COR_BORDA_SOMBRA);
    else
      cor(COR_BORDA_LUZ);

    line(x2 - 4, y + altura - 3, x2 - 4, y2 - 4);
    line(x2 - 7, y + altura - 3, x2 - 7, y2 - 4);
    line(x2 - 10, y + altura - 3, x2 - 10, y2 - 4);
}

void sombra(int x, int y, int x2, int y2)
{
    int contx, conty, cor_atual;

    for (contx = x; contx <= x2; contx++)
        for (conty = y; conty <= y2; conty++)
        {
            cor_atual = getpixel(contx, conty);

            if (cor_atual <= 6)
              cor_atual = COR_SOMBRA;
            else
              if (cor_atual == 7)
                 cor_atual = 8;
              else
                if (cor_atual == 15)
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

void apaga(int x1, int y1, int x2, int y2)
{
  int contx, conty, cont;

  for (contx = x1; contx <= x2 && !keypressed; contx++)
    for (conty = y1; conty <= y2; conty++)
    {
      if (cont)
        sombra(contx, conty, contx, conty);

      cont = !cont;
    }
}

void bip(int tem, int fre)
{
  sound(fre);
  delay(tem);
  sound(fre + 100);
  delay(tem);

  nosound();
}

char dialogob(int tamx, int tamy, tipo_mensagem msg)
{
  char cont;
  char op = 1;
  char sai = FALSO;
  char caracter;
  TelaSalva tela_salva;

  int y   = (int) (t.max_y / 2) - (tamy / 2);
  int x   = (int) (t.max_x / 2) - (tamx / 2);
  int y2  = (int) (t.max_y / 2) + (tamy / 2);
  int x2  = (int) (t.max_x / 2) + (tamx / 2);
  int px2 = (int) (t.max_x / 2) - textwidth("N∆o") - 20;
  int px1 = px2 - 60;
  int px3 = px2 + 60;
  int altura = textheight("H") + 4;

  tela_salva.salva(x, y, x2 + 5, y2 + 5);
  janela(x, y, x2, y2, msg[0], V);

  cor(COR_TEXTO_DIALOGO);
  for (cont = 1; strcmp(msg[cont], FIM) != 0; cont++)
    escreva(0, t.max_x - 8, cont * altura + y + 15, msg[cont]);

  exibe_botao(px1, y2 - altura - 15, 50, BOTAO_SIM);
  exibe_botao(px2, y2 - altura - 15, 50, BOTAO_NAO);
  exibe_botao(px3, y2 - altura - 15, 82, BOTAO_CANCELAR);

  do
  {
    switch (op)
    {
      case 1:
        if (botao(px1, y2 - altura - 15, 50, BOTAO_SIM, &caracter))
          sai = V;

      break;

      case 2:
        if (botao(px2, y2 - altura - 15, 50, BOTAO_NAO, &caracter))
          sai = V;

      break;

      case 3:
        if (botao(px3, y2 - altura - 15, 82, BOTAO_CANCELAR, &caracter))
          sai = V;

      break;
    }

    if (caracter == SETA_DIREITA)
    {
      op++;

      if (op > 3)
        op = 3;
    }
    else
      if (caracter == SETA_ESQUERDA)
      {
        op--;

        if (op < 1)
          op = 1;
      }
      else
        if (caracter == TAB)
        {
          op++;

          if (op > 3)
            op = 1;
         }
         else
           if (caracter == ESC)
           {
             sai = V;
             op = 3;
           }
  }
  while(!sai);

  mouse.desliga();
  tela_salva.restaura();
  mouse.liga();
  return op;
}

char botao(int x, int y, int tam, char* titulo, char* ch)
{
  char apertado, sai;

  exibe_botao_ativo(x, y, tam, titulo);

  do
  {
    t.le_teclado(ch);

    if (*ch == NULL)
       t.le_teclado(ch);

    if (*ch == ESC || *ch == ENTER || *ch == TAB ||
    *ch == SETA_BAIXO || *ch == SETA_CIMA || *ch == BARRA_DE_ESPACO ||
    *ch == SETA_DIREITA || *ch == SETA_ESQUERDA)
       sai = V;
    else
        sai = FALSO;

  } while (!sai);

  if (*ch == ENTER || *ch == BARRA_DE_ESPACO)
    apertado = V;
  else
      apertado = FALSO;

  if (apertado)
  {
     exibe_botao_pressionado(x, y, tam, titulo);
     delay(TEMPO);
     exibe_botao_ativo(x, y, tam, titulo);
  }
  else
     exibe_botao(x, y, tam, titulo);

  return apertado;
}

void exibe_botao(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, COR_BORDA_LUZ, COR_BORDA_ATIVA_SOMBRA);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, COR_FUNDO_DIALOGO, COR_FUNDO_DIALOGO);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, COR_FUNDO_BOTAO_INATIVO);
  cor(COR_BOTAO_INATIVO);
  escreva(x, x + tam, y + 8, titulo);
}

void exibe_botao_ativo(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, COR_BORDA_ATIVA_LUZ, COR_BORDA_ATIVA_SOMBRA);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, COR_FUNDO_DIALOGO, COR_FUNDO_DIALOGO);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, COR_BORDA_ATIVA_SOMBRA, COR_BORDA_ATIVA_LUZ);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, COR_FUNDO_BOTAO_ATIVO);
  cor(COR_BOTAO_ATIVO);
  escreva(x, x + tam, y + 8, titulo);
}

void exibe_botao_pressionado(int x, int y, int tam, char* titulo)
{
  quadrado3d(x, y, x + tam, y + textheight(titulo) + 14, COR_BORDA_ATIVA_SOMBRA, COR_BORDA_LUZ);
  quadrado3d(x + 1, y + 1, x + tam - 1, y + textheight(titulo) + 13, COR_BORDA_SOMBRA, COR_BORDA_LUZ);
  quadrado3d(x + 2, y + 2, x + tam - 2, y + textheight(titulo) + 12, COR_BORDA_SOMBRA, COR_BORDA_LUZ);
  limpeza(x + 3, y + 3, x + tam - 3, y + textheight(titulo) + 12, COR_FUNDO_BOTAO_ATIVO);
  cor(COR_BOTAO_PRESSIONADO);
  escreva(x + 2, x + tam + 2, y + 9, titulo);
}

void janela_vazia(int x, int y, int x2, int y2, char* titulo, char ativo)
{
    int altura = textheight(titulo);

    quadrado3d(x, y, x2, y2, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
    limpeza(x + 1, y + 1, x2 - 1, y + 16, COR_FUNDO_DIALOGO);

    if (ativo)
    {
      quadrado3d(x + 3, y + 3, x2 - 34, y + altura + 7, COR_BORDA_SOMBRA, COR_BORDA_LUZ);
      limpeza(x + 4, y + 4, x2 - 35, y + altura + 7, COR_BARRA_TITULO_ATIVO);
      cor(COR_TITULO_ATIVO);
      botao_fechar(x2 - 17, y + 9, V);
      botao_fechar(x2 - 27, y + 9, FALSO);
    }
    else
    {
      quadrado3d(x + 3, y + 3, x2 - 13, y + altura + 7, COR_BORDA_LUZ, COR_BORDA_SOMBRA);
      limpeza(x + 4, y + 4, x2 - 14, y + altura + 7, COR_BARRA_TITULO_INATIVO);
      cor(COR_TITULO_INATIVO);
    }

    t.gprintf(x + 7, y + 6, titulo);

    if (!ativo)
      cor(COR_BORDA_SOMBRA);
    else
      cor(COR_BORDA_LUZ);

    line(x2 - 3, y + altura - 2, x2 - 3, y2 - 3);
    line(x2 - 6, y + altura - 2, x2 - 6, y2 - 3);
    line(x2 - 9, y + altura - 2, x2 - 9, y2 - 3);

    /*-=-*/

    if (ativo)
      cor(COR_BORDA_SOMBRA);
    else
      cor(COR_BORDA_LUZ);

    line(x2 - 4, y + altura - 3, x2 - 4, y2 - 4);
    line(x2 - 7, y + altura - 3, x2 - 7, y2 - 4);
    line(x2 - 10, y + altura - 3, x2 - 10, y2 - 4);
}

void changetextstyle(int font, int direction, int charsize)
{
  int ErrorCode;

  graphresult();            /* clear error code        */
  settextstyle(font, direction, charsize);
  ErrorCode = graphresult();        /* check result         */
  if( ErrorCode != grOk ){        /* if error occured        */
    closegraph();
    printf(" Fonte n∆o encontrada: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }
}

char tela_limpa()
{
  int contx, conty;

  for (contx = 1; contx <= t.max_x; contx++)
    for (conty = 1; conty <= t.max_y; conty++)
      if (getpixel(contx, conty) != COR_SOMBRA)
         return FALSO;

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
      putpixel(x, y, COR_SOMBRA);
    else
       putpixel(x, y, getpixel(x, y - 1));

    if ((y + sortey < y2) && (x + sortex < x2) && (x + sortex > x1))
       putpixel(x + sortex, y + sortey, core);
  }
  while (!keypressed);
}

void dialogo(int tamx, int tamy, tipo_mensagem msg)
{
  int y   = (int) (t.max_y / 2) - (tamy / 2);
  int x   = (int) (t.max_x / 2) - (tamx / 2);
  int y2  = (int) (t.max_y / 2) + (tamy / 2);
  int x2  = (int) (t.max_x / 2) + (tamx / 2);
  int cont;
  int altura = textheight("H") + 4;
  char caracter;
  TelaSalva ant;

  ant.salva(x, y, x2 + 5, y2 + 5);
  janela(x, y, x2, y2, msg[0], V);

  cor(COR_TEXTO_DIALOGO);
  for (cont = 1; strcmp(msg[cont], FIM) != 0; cont++)
    escreva(0, t.max_x - 8, cont * altura + y + 15, msg[cont]);

  do
  {}
  while (!botao((int) (t.max_x / 2) - textwidth(BOTAO_OK) - 15, y2 - altura - 15, textwidth(BOTAO_OK) + 50, BOTAO_OK, &caracter));

  ant.restaura();
}
