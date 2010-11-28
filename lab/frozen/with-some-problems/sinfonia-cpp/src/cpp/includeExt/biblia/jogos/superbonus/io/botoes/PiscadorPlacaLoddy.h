/*
 * $RCSfile: PiscadorPlacaLoddy.h,v $
 * $Date: 2003/06/11 18:24:27 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef PISCADOR_PLACALODDY_H
#define PISCADOR_PLACALODDY_H

#include "biblia/jogos/superbonus/io/botoes/Piscador.h"
using namespace biblia::jogos::superbonus::io::botoes;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace superbonus{

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
								BTN_COBRAR           =8,
								BTN_AJUDA            =15,
								BTN_CARTELAS         =14,
								BTN_TURBO_BOLA_EXTRA =10,
								BTN_NUMEROS          =13,
								BTN_APOSTA           =9,
								BTN_SUPER_TURBO      =12,
								BTN_JOGAR            =11,								
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