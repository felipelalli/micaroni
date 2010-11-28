/*
 * $RCSfile: InterServPremiacaoAcumulado.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_PREMIACAO_ACUMULADO_H
#define INTER_SERV_PREMIACAO_ACUMULADO_H

#include <stdlib.h>

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/jogos/superbonus/logica/util/InterfacePremiacaoAcumulado.h"
using namespace biblia::jogos::superbonus::logica::util;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
using namespace biblia::jogos::superbonus::dados;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				namespace util{

					class InterServPremiacaoAcumulado: public InterfaceServidor,
													   public InterfacePremiacaoAcumulado{

						private:
							Sorteio pSorteio;
							ProbabilidadesDoJogo* pProbabilidadesDoJogo;

						public:

							InterServPremiacaoAcumulado::InterServPremiacaoAcumulado(DConfiguracao* conf);
							virtual InterServPremiacaoAcumulado::~InterServPremiacaoAcumulado();

							bool InterServPremiacaoAcumulado::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif