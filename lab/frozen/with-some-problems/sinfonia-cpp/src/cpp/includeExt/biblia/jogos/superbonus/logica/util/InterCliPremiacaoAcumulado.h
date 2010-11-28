/*
 * $RCSfile: InterCliPremiacaoAcumulado.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_PREMIACAO_ACUMULADO_H
#define INTER_CLI_PREMIACAO_ACUMULADO_H

#include <stdio.h>

#include "biblia/jogos/superbonus/logica/util/InterfacePremiacaoAcumulado.h"
using namespace biblia::jogos::superbonus::logica::util;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				namespace util{

					class InterCliPremiacaoAcumulado: public InterfaceCliente,
													  public InterfacePremiacaoAcumulado,
													  public Executavel{

						private:
							ListaInt pLstPremiacao;

							bool pTerminar;
							bool pTerminou;
							Thread* pMinhaThread;

							enum Constantes{
								TAMANHO_BUFFER = 4
							};

						public:

							InterCliPremiacaoAcumulado::InterCliPremiacaoAcumulado(ComunicadorRede* redeCliente);
							virtual InterCliPremiacaoAcumulado::~InterCliPremiacaoAcumulado();

							bool InterCliPremiacaoAcumulado::premiouAcumulado();

							Executavel& InterCliPremiacaoAcumulado::executa();
					};
				}
			}
		}
	}
}

#endif