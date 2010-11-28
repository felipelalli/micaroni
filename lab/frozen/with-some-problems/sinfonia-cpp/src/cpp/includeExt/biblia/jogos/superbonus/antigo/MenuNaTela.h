/*
 * $RCSfile: MenuNaTela.h,v $
 * $Date: 2003/06/16 22:40:59 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef MENU_NA_TELA_SW
#define MENU_NA_TELA_SW

#include "biblia/jogos/superbonus/antigo/TelaCompleta.h"
#include "biblia/jogos/superbonus/antigo/CoisaNaTela.h"
#include "biblia/jogos/superbonus/antigo/MensagemBmp.h"
#include "biblia/jogos/superbonus/antigo/Menu.h"

namespace biblia{
	namespace jogos {
		namespace superbonus {
			namespace antigo {
				
				/** MenuNaTela
					Exibe as op��es de um menu no em forma de figuras(coisaNaTela) */
				
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
