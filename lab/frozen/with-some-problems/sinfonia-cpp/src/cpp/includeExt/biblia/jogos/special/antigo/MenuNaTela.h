/*
 * $RCSfile: MenuNaTela.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_MENU_NA_TELA_SW
#define SBS_MENU_NA_TELA_SW

#include "biblia/jogos/special/antigo/TelaCompleta.h"
#include "biblia/jogos/special/antigo/CoisaNaTela.h"
#include "biblia/jogos/special/antigo/MensagemBmp.h"
#include "biblia/jogos/special/antigo/Menu.h"

namespace biblia{
	namespace jogos {
		namespace special {
			namespace antigo {
				
				/** MenuNaTela
					Exibe as opções de um menu no em forma de figuras(coisaNaTela) */
				
				class MenuNaTela {
					private:
						Menu& pMenu;

						MensagemBmp& pFonteNormal;
						MensagemBmp& pFonteIluminada;

					public:
						MenuNaTela(Menu& menu, MensagemBmp& fonteNormal,
						MensagemBmp& fonteIluminada);

						~MenuNaTela();

						//exibe as posicoes do menu na posicao indicada
						void exibeMenu(TelaCompleta& tela) const;
				};
			}
		}
	}
}
#endif
