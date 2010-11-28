/*
 * $RCSfile: Relatorio.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef RELATORIO_H_SW
#define RELATORIO_H_SW

#include "biblia/jogos/superbonus/antigo/ComponenteDeUmRelatorio.h"
#include "biblia/jogos/superbonus/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/superbonus/antigo/Tabela.h"

namespace biblia {
	namespace jogos {
		namespace superbonus {
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
