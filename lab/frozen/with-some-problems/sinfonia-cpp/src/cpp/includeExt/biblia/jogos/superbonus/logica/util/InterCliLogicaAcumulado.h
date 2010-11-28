/*
 * $RCSfile: InterCliLogicaAcumulado.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_LOGICA_ACUMULADO_H
#define INTER_CLI_LOGICA_ACUMULADO_H

#include <stdio.h>

#include "biblia/jogos/superbonus/logica/util/InterfaceLogicaAcumulado.h"
using namespace biblia::jogos::superbonus::logica::util;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia{

	namespace jogos{

		namespace superbonus{

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