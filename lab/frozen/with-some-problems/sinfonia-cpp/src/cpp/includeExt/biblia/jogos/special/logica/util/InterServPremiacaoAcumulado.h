/*
 * $RCSfile: InterServPremiacaoAcumulado.h,v $
 * $Date: 2004/06/08 01:15:27 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SBS_INTER_SERV_PREMIACAO_ACUMULADO_H
#define SBS_INTER_SERV_PREMIACAO_ACUMULADO_H

#include <stdlib.h>

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/special/logica/util/InterfacePremiacaoAcumulado.h"
using namespace biblia::jogos::special::logica::util;

#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/jogos/special/logica/LogicaAcumulado.h"
using namespace biblia::jogos::special::logica;

namespace biblia{

	namespace jogos{

		namespace special{

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