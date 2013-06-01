#include "pacova.h"

void main()
{
  pacova tela;

  setvisualpage(0);
  setactivepage(0);
  setcolor(2);

  line(20, 20, 300, 300);

  tela.pause();

  setvisualpage(1);
  setactivepage(1);
  setcolor(4);
  line(10, 10, 200, 200);

  tela.pause();

  setvisualpage(0);
  tela.pause();
  setvisualpage(1);
  tela.pause();
  setvisualpage(0);
  tela.pause();
  setvisualpage(1);
  tela.pause();
}