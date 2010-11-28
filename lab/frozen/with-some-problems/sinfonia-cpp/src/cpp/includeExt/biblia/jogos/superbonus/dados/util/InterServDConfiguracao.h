/*
 * $RCSfile: InterServDConfiguracao.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_DCONFIGURACAO_H
#define INTER_SERV_DCONFIGURACAO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/util/InterfaceDConfiguracao.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
using namespace biblia::jogos::superbonus::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace superbonus{

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