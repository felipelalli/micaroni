/*
 * $RCSfile: InterServDEstatistica.h,v $
 * $Date: 2005/01/19 17:22:01 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DESTATISTICA_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DESTATISTICA_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDEstatistica.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/jogos/specialUpgrade/dados/DEstatistica.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterServDEstatistica: public InterfaceServidor,
											      public InterfaceDEstatistica{

						private:

							DEstatistica* pEstatistica;

						public:

							InterServDEstatistica::InterServDEstatistica(DEstatistica* estatistica);
							virtual InterServDEstatistica::~InterServDEstatistica();

							bool InterServDEstatistica::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif