/*
 * $RCSfile: InterServHistorico.h,v $
 * $Date: 2005/01/19 17:22:01 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_HISTORICO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_SERV_HISTORICO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/util/InterfaceHistorico.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"
#include "biblia/jogos/specialUpgrade/dados/DEstatistica.h"
#include "biblia/jogos/specialUpgrade/dados/UltimasJogadas.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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