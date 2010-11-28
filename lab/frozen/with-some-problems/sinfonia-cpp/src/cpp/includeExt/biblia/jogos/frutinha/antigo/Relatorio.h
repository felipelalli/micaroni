/*
 * $RCSfile: Relatorio.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef TROPICAL_SBS_RELATORIO_H_SW
#define TROPICAL_SBS_RELATORIO_H_SW

#include "biblia/jogos/frutinha/antigo/ComponenteDeUmRelatorio.h"
#include "biblia/jogos/frutinha/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/frutinha/antigo/Tabela.h"

namespace biblia {
	namespace jogos {
		namespace frutinha {
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
