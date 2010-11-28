/*
 * $RCSfile: InterServLogicaAcumulado.h,v $
 * $Date: 2003/07/23 19:18:12 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef SBS_INTER_SERV_LOGICA_ACUMULADO_H
#define SBS_INTER_SERV_LOGICA_ACUMULADO_H

#include <stdlib.h>

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/jogos/special/logica/util/ArqLogicaAcumulado.h"
#include "biblia/jogos/special/logica/util/InterfaceLogicaAcumulado.h"
using namespace biblia::jogos::special::logica::util;

namespace biblia{

	namespace jogos{

		namespace special{

			namespace logica{

				namespace util{

					class InterServLogicaAcumulado: public InterfaceServidor,
													public InterfaceLogicaAcumulado{

						private:
							GerenciadorDeProbabilidades& pGerenciador;
							ArqLogicaAcumulado pArqDados;

							void InterServLogicaAcumulado::pIncrementarSequencia();

							InterServGerenciadorRede* pInterServGerenciadorRede;

						public:

							InterServLogicaAcumulado::InterServLogicaAcumulado(InterServGerenciadorRede* interServGerenciadorRede,GerenciadorDeProbabilidades& gerenciador);
							virtual InterServLogicaAcumulado::~InterServLogicaAcumulado();

							bool InterServLogicaAcumulado::processarRequisicao(char* buffer);

							void InterServLogicaAcumulado::setValor (double valor);
					};
				}
			}
		}
	}
}

#endif