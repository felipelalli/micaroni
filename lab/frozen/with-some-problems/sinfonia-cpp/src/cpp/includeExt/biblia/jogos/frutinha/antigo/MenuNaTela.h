/*
 * $RCSfile: MenuNaTela.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#ifndef TROPICAL_SBS_MENU_NA_TELA_SW
#define TROPICAL_SBS_MENU_NA_TELA_SW

#include "biblia/jogos/frutinha/antigo/TelaCompleta.h"
#include "biblia/jogos/frutinha/antigo/CoisaNaTela.h"
#include "biblia/jogos/frutinha/antigo/MensagemBmp.h"
#include "biblia/jogos/frutinha/antigo/Menu.h"

namespace biblia{
	namespace jogos {
		namespace frutinha {
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
