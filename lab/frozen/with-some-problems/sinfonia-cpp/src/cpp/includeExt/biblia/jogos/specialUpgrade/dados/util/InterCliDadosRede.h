/*
 * $RCSfile: InterCliDadosRede.h,v $
 * $Date: 2005/01/19 17:21:58 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DADOS_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DADOS_REDE_H

#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDadosRede.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterCliDadosRede :  public InterfaceCliente,
												   public InterfaceDadosRede{

						private:

							GerenciadorRede* pGerenciadorRede;

						public:
							InterCliDadosRede::InterCliDadosRede (GerenciadorRede* rede);
							InterCliDadosRede::~InterCliDadosRede();

							bool InterCliDadosRede::limpar (int maquina);
							bool InterCliDadosRede::removerMaquina (int maquinaRemota, int maquina);
							bool InterCliDadosRede::adicionarMaquina (int maquina, char* ip, int hub, bool ligado);
							bool InterCliDadosRede::concluir (int maquina);

							int InterCliDadosRede::qtsMaquinasNaRede(int maquina);
							bool InterCliDadosRede::trazerMaquinaDaRede (int maquinaRemota, int maquina, char* ip, int* hub, bool* ligado);
					};
				}
			}
		}
	}
}

#endif