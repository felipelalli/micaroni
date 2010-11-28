/*
 * $RCSfile: Relatorio.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_RELATORIO_H_SW
#define SBS_RELATORIO_H_SW

#include "biblia/jogos/special/antigo/ComponenteDeUmRelatorio.h"
#include "biblia/jogos/special/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/special/antigo/Tabela.h"

namespace biblia {
	namespace jogos {
		namespace special {
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
