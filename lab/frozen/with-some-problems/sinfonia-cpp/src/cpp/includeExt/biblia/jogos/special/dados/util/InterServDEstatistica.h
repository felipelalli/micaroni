/*
 * $RCSfile: InterServDEstatistica.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTER_SERV_DESTATISTICA_H
#define SBS_INTER_SERV_DESTATISTICA_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/special/dados/util/InterfaceDEstatistica.h"
using namespace biblia::jogos::special::dados::util;

#include "biblia/jogos/special/dados/DEstatistica.h"
using namespace biblia::jogos::special::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace special{

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