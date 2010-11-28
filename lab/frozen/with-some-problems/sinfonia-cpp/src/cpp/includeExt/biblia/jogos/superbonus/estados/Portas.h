#ifndef PORTAS_H
#define PORTAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/superbonus/dados/DHistorico.h"
using namespace biblia::jogos::superbonus::dados;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace estados{

				class Portas: public Objeto{

					private:	

						DHistorico* pHistorico;

						bool pPortaMaquinaAberta;
						bool pPortaCofreAberta;
						bool pPortaCPUAberta;

					public:
						Portas::Portas(DHistorico* historico);
						Portas::~Portas();

						void Portas::estadosPortas (bool portaMaquinaAberta,
													bool portaCofreAberta,
													bool portaCPUAberta);

						bool Portas::portaMaquinaAberta();
						bool Portas::portaCofreAberta();
						bool Portas::portaCPUAberta();
				};
			}
		}
	}
}

#endif