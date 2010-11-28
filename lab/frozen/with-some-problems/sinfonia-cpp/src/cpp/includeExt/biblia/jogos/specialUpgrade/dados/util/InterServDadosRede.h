/*
 * $RCSfile: InterServDadosRede.h,v $
 * $Date: 2005/01/19 17:22:01 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DADOS_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_DADOS_REDE_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDadosRede.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/armazenamento/volatil/ListaString.h"
#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterServDadosRede: public InterfaceServidor,
											  public InterfaceDadosRede{

						private:
							ListaString* pLstIP;
							ListaInt* pLstHub;
							ListaInt* pLstLigado;

							GerenciadorRedeWizard* pRede;
							ArqGerenciadorRedeWizard* pArqRede;

							void InterServDadosRede::pCarregar();

						public:

							InterServDadosRede::InterServDadosRede(GerenciadorRedeWizard* rede, ArqGerenciadorRedeWizard* arqRede);
							virtual InterServDadosRede::~InterServDadosRede();

							bool InterServDadosRede::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif