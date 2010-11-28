/*
 * $RCSfile: InterCliDConfiguracao.h,v $
 * $Date: 2005/01/19 17:21:59 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DCONFIGURACAO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DCONFIGURACAO_H

#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterCliDConfiguracao :  public InterfaceCliente,
												   public InterfaceDConfiguracao{

						private:

							GerenciadorRede* pGerenciadorRede;

						public:
							InterCliDConfiguracao::InterCliDConfiguracao (GerenciadorRede* rede);
							InterCliDConfiguracao::~InterCliDConfiguracao();

							bool InterCliDConfiguracao::ler         (int maquina,char* caminho,char* valor);
							bool InterCliDConfiguracao::escrever    (int maquina,char* caminho,char* valor);
							bool InterCliDConfiguracao::abrirArquivo(int maquina,char* arquivo);
					};
				}
			}
		}
	}
}

#endif