/*
 * $RCSfile: InterCliDConfiguracao.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_DCONFIGURACAO_H
#define INTER_CLI_DCONFIGURACAO_H

#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/util/InterfaceDConfiguracao.h"
using namespace biblia::jogos::superbonus::dados::util;

namespace biblia{

	namespace jogos{

		namespace superbonus{

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