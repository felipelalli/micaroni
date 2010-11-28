/*
 * $RCSfile: PiscadorPlacaDelta.h,v $
 * $Date: 2005/01/20 17:44:47 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_PISCADOR_PLACADelta_H_TROPICAL
#define SBS_PISCADOR_PLACADelta_H_TROPICAL

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/jogos/frutinha/io/botoes/Piscador.h"
using namespace biblia::jogos::frutinha::io::botoes;


#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace io{

				namespace botoes{

					class PiscadorPlacaDelta: public Piscador{

						private:

							bool pTerminar;
							bool pTerminou;

							PlacaDelta& pPlacaDelta;
							Thread*    pMinhaThread;

							int PiscadorPlacaDelta::pConverteBotaoEmTecla (const Botao& b) const;

							enum Constantes{			

								TECLA_MUDA_APOSTA1  		= 0,
								TECLA_MUDA_APOSTA2			= 0, 								
								TECLA_MUDA_APOSTA3			= 1, 
								TECLA_MUDA_APOSTA4			= 1, 			
								TECLA_MUDA_APOSTA5			= 2,
								TECLA_COBRAR				= 3,
								TECLA_AJUDA					= 4, 								
								TECLA_AUTOMATICO			= 5,
								TECLA_APOSTA_MAXIMA			= 6,
								TECLA_JOGAR					= 7								
							};

						public:
							PiscadorPlacaDelta::PiscadorPlacaDelta (PlacaDelta& placaDelta);
							virtual PiscadorPlacaDelta::~PiscadorPlacaDelta();

							virtual Executavel& PiscadorPlacaDelta::executa();
					};
				}
			}
		}
	}
}

#endif
