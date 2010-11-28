/*
 * $RCSfile: InterServLogicaAcumulado.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_LOGICA_ACUMULADO_H
#define INTER_SERV_LOGICA_ACUMULADO_H

#include <stdlib.h>

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/jogos/superbonus/logica/util/ArqLogicaAcumulado.h"
#include "biblia/jogos/superbonus/logica/util/InterfaceLogicaAcumulado.h"
using namespace biblia::jogos::superbonus::logica::util;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				namespace util{

					class InterServLogicaAcumulado: public InterfaceServidor,
													public InterfaceLogicaAcumulado{

						private:
							ProbabilidadesDoJogo* pProbabilidadesDoJogo;
							ArqLogicaAcumulado pArqDados;

							void InterServLogicaAcumulado::pIncrementarSequencia();

							InterServGerenciadorRede* pInterServGerenciadorRede;

						public:

							InterServLogicaAcumulado::InterServLogicaAcumulado(InterServGerenciadorRede* interServGerenciadorRede,ProbabilidadesDoJogo* probJogo);
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