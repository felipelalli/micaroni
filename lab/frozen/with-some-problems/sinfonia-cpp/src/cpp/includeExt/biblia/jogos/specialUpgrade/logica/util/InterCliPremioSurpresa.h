/*
 * $RCSfile: InterCliPremioSurpresa.h,v $
 * $Date: 2005/01/20 17:48:04 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_PREMIO_SURPRESA_H
#define AGES_SPECIAL_UPGRADE_SBS_INTER_CLI_PREMIO_SURPRESA_H


#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/logica/util/InterfacePremioSurpresa.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;



namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterCliPremioSurpresa :  public Executavel,
													public InterfaceCliente,
												    public InterfacePremioSurpresa{
					
						private:

							//Infomações sobre o premio
							int  pValorAcumuladoServidor;
							bool pPremioLancadoServidor;
							int  pValorPremioServidor;

							int  pValorASerEnviadoParaOServidor;
							bool pGanhouPremioSurpresa;
							int  pValorGanho;
							
							Semaforo pSema;


							//Controle de fluxo
							bool pTerminar;
							bool pTerminou;							
							Thread* pThread;									

							//Rede							
							GerenciadorRede* pGerenciadorRede;



						public:
							InterCliPremioSurpresa::InterCliPremioSurpresa (GerenciadorRede* rede);
							InterCliPremioSurpresa::~InterCliPremioSurpresa();

							void InterCliPremioSurpresa::adicionaValor         (int valor);
							void InterCliPremioSurpresa::ganhouPremioSurpresa  (int valor);
							bool InterCliPremioSurpresa::premioLancadoServidor ();
							int  InterCliPremioSurpresa::valorPremioServidor   ();
							int  InterCliPremioSurpresa::valorAcumuladoServidor();


							Executavel& InterCliPremioSurpresa::executa();											
					};
				}
			}
		}
	}
}

#endif
