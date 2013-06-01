#ifndef SALVA_TELA_F&F_FUN_1999
#define SALVA_TELA_F&F_FUN_1999
#include "graphics.h"

class TelaSalva
{
  private:
    // A tela salva ‚ dividida em dois para melhor aproveito da mem¢ria
    int tem_algo_salvo;

    int x, y;
    int y_do_meio;
    char* desenho1;
    char* desenho2;

  public:
    TelaSalva():tem_algo_salvo(0){};
   ~TelaSalva()
    {
      if (ha())
      {
        delete [] desenho1;
        delete [] desenho2;
      }
    }

    int ha() { return tem_algo_salvo; }

    int salva(const int& vx1,
              const int& vy1,
              const int& vx2,
              const int& vy2)
    {
      destroi();

      x = vx1;
      y = vy1;
      y_do_meio = (int ) (vy2 / 2) + 1;

      desenho1 = new char [imagesize(vx1, vy1, vx2, y_do_meio) + 1];
      desenho2 = new char [imagesize(vx1, y_do_meio + 1, vx2, vy2) + 1];

      if (!(desenho1 && desenho2))
        return 0;

      getimage(vx1, vy1, vx2, y_do_meio, desenho1);
      getimage(vx1, y_do_meio + 1, vx2, vy2, desenho2);
      tem_algo_salvo = 1;

      return 1;
    }

    int restaura()
    {
      if (ha())
      {
        putimage(x, y, desenho1, COPY_PUT);
        putimage(x, y_do_meio + 1, desenho2, COPY_PUT);
        return 1;
      }
      else
        return 0;
    }

    void destroi()
    {
      if (ha())
      {
        delete [] desenho1;
        delete [] desenho2;
        tem_algo_salvo = 0;
      }
    }
};

#endif