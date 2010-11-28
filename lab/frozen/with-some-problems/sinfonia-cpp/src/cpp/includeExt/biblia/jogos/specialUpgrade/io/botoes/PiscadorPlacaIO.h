/*
 * $RCSfile: PiscadorPlacaIO.h,v $
 * $Date: 2005/01/19 17:22:07 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_PISCADOR_PLACAIO_H
#define AGES_SPECIAL_UPGRADE_SBS_PISCADOR_PLACAIO_H

#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"
#include "biblia/jogos/specialUpgrade/io/botoes/LuzBotoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace io{

				namespace botoes{

					class PiscadorPlacaIO: public Piscador{

						private:

							bool pTerminar;
							bool pTerminou;

							LuzBotoes* pLuzBotoes;
							Thread*    pMinhaThread;

						public:
							PiscadorPlacaIO::PiscadorPlacaIO ():pLuzBotoes(NULL) {};
							PiscadorPlacaIO::PiscadorPlacaIO (LuzBotoes* luzBotoes);
							virtual PiscadorPlacaIO::~PiscadorPlacaIO();

							virtual Executavel& PiscadorPlacaIO::executa();
					};
				}
			}
		}
	}
}

#endif