/*
 * $RCSfile: Relatorio.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_RELATORIO_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_RELATORIO_H_SW

#include "biblia/jogos/specialUpgrade/antigo/ComponenteDeUmRelatorio.h"
#include "biblia/jogos/specialUpgrade/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/specialUpgrade/antigo/Tabela.h"

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				class Relatorio: public ComponenteDeUmRelatorio {
					private:
						ComponenteDeUmRelatorio* pComponente;
						int pPosicaoX, pPosicaoY;

					public:
						Relatorio(ComponenteDeUmRelatorio*,
									int x = 0, int y = 0);

						~Relatorio();
						ComponenteDeUmRelatorio* componente() const;
						int posicaoX() const;
						int posicaoY() const;
				};
			}
		}
	}
}
#endif
