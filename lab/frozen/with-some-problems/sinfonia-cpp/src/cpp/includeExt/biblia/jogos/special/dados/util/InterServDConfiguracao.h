/*
 * $RCSfile: InterServDConfiguracao.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTER_SERV_DCONFIGURACAO_H
#define SBS_INTER_SERV_DCONFIGURACAO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/special/dados/util/InterfaceDConfiguracao.h"
using namespace biblia::jogos::special::dados::util;

#include "biblia/jogos/special/dados/DConfiguracao.h"
using namespace biblia::jogos::special::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace special{

			namespace dados{

				namespace util{

					class InterServDConfiguracao: public InterfaceServidor,
											      public InterfaceDConfiguracao{

						private:

							DConfiguracao* pConf;

						public:

							InterServDConfiguracao::InterServDConfiguracao(DConfiguracao* conf);
							virtual InterServDConfiguracao::~InterServDConfiguracao();

							bool InterServDConfiguracao::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif