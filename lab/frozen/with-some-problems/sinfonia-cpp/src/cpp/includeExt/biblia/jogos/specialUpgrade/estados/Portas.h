/*
 * $RCSfile: Portas.h,v $
 * $Date: 2005/01/19 17:22:02 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_PORTAS_H
#define AGES_SPECIAL_UPGRADE_SBS_PORTAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"
using namespace biblia::jogos::specialUpgrade::dados;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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