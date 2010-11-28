/*
 * $RCSfile: PiscadorPlacaIO.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_PISCADOR_PLACAIO_H
#define SBS_PISCADOR_PLACAIO_H

#include "biblia/jogos/special/io/botoes/Piscador.h"
#include "biblia/jogos/special/io/botoes/LuzBotoes.h"
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