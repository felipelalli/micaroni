/*
 * $RCSfile: InterServDadosRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_DADOS_REDE_H
#define INTER_SERV_DADOS_REDE_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/superbonus/dados/util/InterfaceDadosRede.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/armazenamento/volatil/ListaString.h"
#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia{

	namespace jogos{

		namespace superbonus{

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