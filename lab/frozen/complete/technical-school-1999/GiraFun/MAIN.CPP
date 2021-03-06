#include "prog.h"
#include "figura.h"

void main()
{
  pacova tela;
  MOUSE_EVENTO evento;
  MouseFun mouse(414, 238, 0);

  mouse.area(0, 0, 1000, 1000);

  obj_figura Jesus("Jesus.fff");

  if (Jesus.edita())
    cleardevice();

  Jesus.defangulo(90);

  do
  {
    tipo_angulo angulo, raio;
    Jesus.converte(mouse.x(), mouse.y(), &angulo, &raio);
    Jesus.defraio(raio / 100);
    Jesus.defangulo(360 - angulo);

    Jesus.exibe();
    evento = mouse.evento_pause();
    Jesus.apaga(0);

  } while (evento != MOUSE_UP);

  ++mouse; ++mouse;
  // Programa Principal (Executa o Construtor e o Destrutor)
  ProgramaPrincipal p;
}
