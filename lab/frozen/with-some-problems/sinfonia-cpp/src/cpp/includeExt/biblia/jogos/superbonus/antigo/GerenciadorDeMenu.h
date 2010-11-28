/*
 * $RCSfile: GerenciadorDeMenu.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef GERENCIADOR_DE_MENU_H_SW
#define GERENCIADOR_DE_MENU_H_SW

#include "biblia/jogos/superbonus/antigo/TelaCompleta.h"
#include "biblia/jogos/superbonus/antigo/MensagemBmp.h"
#include "biblia/jogos/superbonus/antigo/Marcacao.h"
#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
#include "biblia/jogos/superbonus/io/botoes/Piscador.h"
#include "biblia/jogos/superbonus/antigo/Menu.h"
#include "biblia/jogos/superbonus/antigo/MenuNaTela.h"
#include "biblia/jogos/superbonus/antigo/GerenciadorDeRelatorios.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/antigo/Sistema.h"
#include "biblia/jogos/superbonus/logica/Logicas.h"
#include "biblia/jogos/superbonus/dados/DHistorico.h"
#include "biblia/seguranca/Usuario.h"

using namespace biblia::jogos::superbonus::dados;
using namespace biblia::jogos::superbonus::io::botoes;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::jogos::superbonus::logica;

namespace biblia{
	namespace jogos {
		namespace superbonus {
			namespace antigo {

				class GerenciadorDeMenu{
					private:
						Botoes& pBotoes;
						Piscador& pPiscador;
						DHistorico& pHistorico;
						TelaCompleta& pTela;
						TipoUsuario& pTipoUsuario;

						Marcacao* pFundoMenu;
						Menu* pMenu;
						MenuNaTela* pMenuNaTela;

						MensagemBmp* pFonteNormal;
						MensagemBmp* pFonteIluminada;
						MensagemBmp* pFonteNegrito;
						MensagemBmp* pFonteTitulo;
						MensagemBmp* pFontePequena;

						GerenciadorDeRelatorios* pGerenciadorRelatorio;

						//Avança uma opção no menu
						short int avanca();
						//Retorna uma opção no menu
						short int retorna();

						bool pTeclado;

					public:
						GerenciadorDeMenu(TelaCompleta&,
										  Botoes&,
										  Piscador&,
										  Logicas&,
										  TipoUsuario&,
										  bool teclado = false);

						~GerenciadorDeMenu();
						//desenha o menu na tela
						void loopMenu();
				};
			}
		}
	}
}
#endif