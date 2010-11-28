/*
 * $RCSfile: MenuNaTela.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_MENU_NA_TELA_SW
#define AGES_SPECIAL_UPGRADE_SBS_MENU_NA_TELA_SW

#include "biblia/jogos/specialUpgrade/antigo/TelaCompleta.h"
#include "biblia/jogos/specialUpgrade/antigo/CoisaNaTela.h"
#include "biblia/jogos/specialUpgrade/antigo/MensagemBmp.h"
#include "biblia/jogos/specialUpgrade/antigo/Menu.h"

namespace biblia{
	namespace jogos {
		namespace specialUpgrade {
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
