/*
 * $RCSfile: PiscadorPlacaLoddy.h,v $
 * $Date: 2005/01/19 17:22:08 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_PISCADOR_PLACALODDY_H
#define AGES_SPECIAL_UPGRADE_SBS_PISCADOR_PLACALODDY_H

#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace io{

				namespace botoes{

					class PiscadorPlacaLoddy: public Piscador{

						private:

							bool pTerminar;
							bool pTerminou;

							PlacaLoddy* pPlacaLoddy;
							Thread*    pMinhaThread;

							int PiscadorPlacaLoddy::pConverteBotaoEmTecla (const Botao& b) const;

							enum Constantes{
								BTN_COBRAR           =11,
								BTN_AJUDA            =12,
								BTN_CARTELAS         = 5,
								BTN_TURBO_BOLA_EXTRA = 8,//8=bolaextra
								BTN_NUMEROS          =15,
								BTN_APOSTA           =13,
								BTN_SUPER_TURBO      =9,
								BTN_JOGAR            =10,
							};

						public:
							PiscadorPlacaLoddy::PiscadorPlacaLoddy ():pPlacaLoddy(NULL) {};
							PiscadorPlacaLoddy::PiscadorPlacaLoddy (PlacaLoddy* placaLoddy);
							virtual PiscadorPlacaLoddy::~PiscadorPlacaLoddy();

							virtual Executavel& PiscadorPlacaLoddy::executa();
					};
				}
			}
		}
	}
}

#endif
