/*
 * $RCSfile: InterServLogicaAcumulado.h,v $
 * $Date: 2005/01/19 17:22:23 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_LOGICA_ACUMULADO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_LOGICA_ACUMULADO_H

#include <stdlib.h>

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/util/ArqLogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterfaceLogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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