/*
 * $RCSfile: InterCliHistorico.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_HISTORICO_H
#define INTER_CLI_HISTORICO_H

#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/util/InterfaceHistorico.h"
using namespace biblia::jogos::superbonus::dados::util;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				namespace util{

					class InterCliHistorico :  public InterfaceCliente,
											   public InterfaceHistorico{

						private:

							GerenciadorRede* pGerenciadorRede;

						public:
							InterCliHistorico::InterCliHistorico (GerenciadorRede* rede);
							InterCliHistorico::~InterCliHistorico();

							int InterCliHistorico::qtsDados (int maquina,int qualHistorico);
							bool InterCliHistorico::getDado  (int maquina,int qualHistorico,int qualLinha, char* valor);

							bool InterCliHistorico::adicionarEvento (int maquina,long codigoEvento, const char* usuario = "-", const char* descricao = "-");
					};
				}
			}
		}
	}
}

#endif