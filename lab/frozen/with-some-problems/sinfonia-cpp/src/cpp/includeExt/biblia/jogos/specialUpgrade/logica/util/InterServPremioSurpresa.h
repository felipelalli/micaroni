/*
 * $RCSfile: InterServPremioSurpresa.h,v $
 * $Date: 2005/01/20 17:48:04 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_PREMIO_SURPRESA_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_PREMIO_SURPRESA_H



#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/logica/util/InterfacePremioSurpresa.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/PremioSurpresa.h"
using namespace biblia::jogos::specialUpgrade::logica;



namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterServPremioSurpresa: public InterfaceServidor,
											       public InterfacePremioSurpresa{

						private:
							PremioSurpresa** pPremioSurpresa;							
							PremioSurpresa& InterServPremioSurpresa::pGetPremio();

						public:

							InterServPremioSurpresa::InterServPremioSurpresa(PremioSurpresa** premioSurpresa);
							virtual InterServPremioSurpresa::~InterServPremioSurpresa();

							bool InterServPremioSurpresa::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif