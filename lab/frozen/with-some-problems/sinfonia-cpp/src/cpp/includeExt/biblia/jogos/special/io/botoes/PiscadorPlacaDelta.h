/*
 * $RCSfile: PiscadorPlacaDelta.h,v $
 * $Date: 2004/04/25 01:25:36 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef SBS_PISCADOR_PLACADelta_H
#define SBS_PISCADOR_PLACADelta_H

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/jogos/special/io/botoes/Piscador.h"
using namespace biblia::jogos::special::io::botoes;


#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace special{

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
								BTN_COBRAR           = 2,
								BTN_AJUDA            = 5,
								BTN_CARTELAS         = 3,
								BTN_TURBO_BOLA_EXTRA = 7,//8=bolaextra
								BTN_NUMEROS          = 4,
								BTN_APOSTA           = 0,
								BTN_SUPER_TURBO      = 1,
								BTN_JOGAR            = 6,								
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
