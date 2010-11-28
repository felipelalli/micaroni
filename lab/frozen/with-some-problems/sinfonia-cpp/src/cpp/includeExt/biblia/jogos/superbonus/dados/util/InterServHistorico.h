/*
 * $RCSfile: InterServHistorico.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_HISTORICO_H
#define INTER_SERV_HISTORICO_H

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/util/InterfaceHistorico.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/jogos/superbonus/dados/DHistorico.h"
#include "biblia/jogos/superbonus/dados/DEstatistica.h"
#include "biblia/jogos/superbonus/dados/UltimasJogadas.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include <stdio.h>

namespace biblia{

	namespace jogos{

		namespace superbonus{

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