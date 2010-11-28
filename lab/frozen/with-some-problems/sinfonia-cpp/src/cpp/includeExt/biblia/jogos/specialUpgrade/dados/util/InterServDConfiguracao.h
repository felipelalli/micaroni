/*
 * $RCSfile: InterServDConfiguracao.h,v $
 * $Date: 2005/01/19 17:22:01 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DCONFIGURACAO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DCONFIGURACAO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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