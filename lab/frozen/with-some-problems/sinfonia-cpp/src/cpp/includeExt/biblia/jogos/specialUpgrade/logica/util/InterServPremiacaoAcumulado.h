/*
 * $RCSfile: InterServPremiacaoAcumulado.h,v $
 * $Date: 2005/01/19 17:22:23 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */
#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_PREMIACAO_ACUMULADO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_PREMIACAO_ACUMULADO_H

#include <stdlib.h>

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/logica/util/InterfacePremiacaoAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterServPremiacaoAcumulado: public InterfaceServidor,
													   public InterfacePremiacaoAcumulado{

						private:
							GerenciadorDeProbabilidades& pGerenciador;
							LogicaAcumulado** pAcumulado;

						public:

							InterServPremiacaoAcumulado::InterServPremiacaoAcumulado(GerenciadorDeProbabilidades& gerenciador, LogicaAcumulado** acumulado);
							virtual InterServPremiacaoAcumulado::~InterServPremiacaoAcumulado();

							bool InterServPremiacaoAcumulado::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif