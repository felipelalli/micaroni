/*
 * $RCSfile: InterServHistorico.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTER_SERV_HISTORICO_H
#define SBS_INTER_SERV_HISTORICO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/special/dados/util/InterfaceHistorico.h"
using namespace biblia::jogos::special::dados::util;

#include "biblia/jogos/special/dados/DHistorico.h"
#include "biblia/jogos/special/dados/DEstatistica.h"
#include "biblia/jogos/special/dados/UltimasJogadas.h"
using namespace biblia::jogos::special::dados;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace special{

			namespace dados{

				namespace util{

					class InterServHistorico: public InterfaceServidor,
											  public InterfaceHistorico{

						private:

							ListaString* pLista;
							DHistorico* pHistorico;
							DEstatistica* pEstatistica;
							UltimasJogadas* pUltimasJogadas;

							int pTamanhoLista;

						public:

							InterServHistorico::InterServHistorico(DHistorico* historico, DEstatistica* estatistica, UltimasJogadas* ultimasJogadas);
							virtual InterServHistorico::~InterServHistorico();

							bool InterServHistorico::processarRequisicao(char* buffer);
					};
				}
			}
		}
	}
}

#endif