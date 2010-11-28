/*
 * $RCSfile: Portas.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_PORTAS_H
#define SBS_PORTAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/special/dados/DHistorico.h"
using namespace biblia::jogos::special::dados;

namespace biblia{

	namespace jogos{

		namespace special{

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