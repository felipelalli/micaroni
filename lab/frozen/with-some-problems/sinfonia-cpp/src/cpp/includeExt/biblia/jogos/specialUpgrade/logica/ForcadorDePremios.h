/*
 * $RCSfile: ForcadorDePremios.h,v $
 * $Date: 2005/01/20 17:48:04 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_FORCADOR_DE_PREMIOS_H
#define AGES_SPECIAL_UPGRADE_FORCADOR_DE_PREMIOS_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;


#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;



namespace biblia {

	namespace jogos {

		namespace specialUpgrade {

			namespace logica {

				class ForcadorDePremios: public Objeto {

					private:
						Botoes& pBotoes;

						static int pQuantosPremios;
						static int pIndicePremios[12];
						static char pBotoesPremios[12];

					public:
						ForcadorDePremios::ForcadorDePremios(Botoes& botoes);
						virtual ForcadorDePremios::~ForcadorDePremios();												
						
						int ForcadorDePremios::qualPremioForcar();
				};
			}
		}
	}
}

#endif
