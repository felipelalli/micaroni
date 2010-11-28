/*
 * $RCSfile: InterServDEstatistica.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_DESTATISTICA_H
#define INTER_SERV_DESTATISTICA_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/util/InterfaceDEstatistica.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/jogos/superbonus/dados/DEstatistica.h"
using namespace biblia::jogos::superbonus::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace superbonus{

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