/*
 * $RCSfile: InterCliDEstatistica.h,v $
 * $Date: 2005/01/19 17:21:59 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DESTATISTICA_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_DESTATISTICA_H

#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceDEstatistica.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterCliDEstatistica :  public InterfaceCliente,
												  public InterfaceDEstatistica{

						private:

							GerenciadorRede* pGerenciadorRede;

						public:
							InterCliDEstatistica::InterCliDEstatistica (GerenciadorRede* rede);
							InterCliDEstatistica::~InterCliDEstatistica();

							bool InterCliDEstatistica::ler      (int maquina,char* caminho,char* valor);
							bool InterCliDEstatistica::escrever (int maquina,char* caminho,char* valor);
							bool InterCliDEstatistica::abrirArquivoBasico (int maquina, char* arquivo);
							bool InterCliDEstatistica::apagaGeral(int maquina);
							bool InterCliDEstatistica::apagaParcial(int maquina);
							bool InterCliDEstatistica::zeraTudo(int maquina);
					};
				}
			}
		}
	}
}

#endif