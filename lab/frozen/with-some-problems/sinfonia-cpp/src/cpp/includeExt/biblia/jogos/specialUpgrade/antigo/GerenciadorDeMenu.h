/*
 * $RCSfile: GerenciadorDeMenu.h,v $
 * $Date: 2005/01/19 17:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_GERENCIADOR_DE_MENU_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_GERENCIADOR_DE_MENU_H_SW

#include "biblia/jogos/specialUpgrade/antigo/TelaCompleta.h"
#include "biblia/jogos/specialUpgrade/antigo/MensagemBmp.h"
#include "biblia/jogos/specialUpgrade/antigo/Marcacao.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"
#include "biblia/jogos/specialUpgrade/antigo/Menu.h"
#include "biblia/jogos/specialUpgrade/antigo/MenuNaTela.h"
#include "biblia/jogos/specialUpgrade/antigo/GerenciadorDeRelatorios.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
#include "biblia/jogos/specialUpgrade/antigo/Sistema.h"
#include "biblia/jogos/specialUpgrade/logica/Logicas.h"
#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"
#include "biblia/seguranca/Usuario.h"

using namespace biblia::jogos::specialUpgrade::dados;
using namespace biblia::jogos::specialUpgrade::io::botoes;
using namespace biblia::jogos::specialUpgrade::dados;
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia{
	namespace jogos {
		namespace specialUpgrade {
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