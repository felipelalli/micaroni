/*
 * $RCSfile: InterCliLogicaAcumulado.h,v $
 * $Date: 2005/01/19 17:22:22 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_LOGICA_ACUMULADO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_LOGICA_ACUMULADO_H

#include <stdio.h>

#include "biblia/jogos/specialUpgrade/logica/util/InterfaceLogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterCliLogicaAcumulado:  public InterfaceCliente,
													public InterfaceLogicaAcumulado{

						private:

							double pValor;
							int pCodigo;
							int pSequencia;

						public:

							InterCliLogicaAcumulado::InterCliLogicaAcumulado(ComunicadorRede* redeCliente);
							virtual InterCliLogicaAcumulado::~InterCliLogicaAcumulado();

							bool   InterCliLogicaAcumulado::setValor(double valor);
							bool   InterCliLogicaAcumulado::addValor(double valor);
							double InterCliLogicaAcumulado::premiarAcumulado ();

							bool InterCliLogicaAcumulado::getDados();
							double InterCliLogicaAcumulado::getValor();
							int    InterCliLogicaAcumulado::getCodigo();
							int    InterCliLogicaAcumulado::getSequencia();
					};
				}
			}
		}
	}
}

#endif