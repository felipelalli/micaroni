/*
 * $RCSfile: GerenciadorDeMenu.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TROPICAL_SBS_GERENCIADOR_DE_MENU_H_SW
#define TROPICAL_SBS_GERENCIADOR_DE_MENU_H_SW

#include "biblia/jogos/frutinha/antigo/TelaCompleta.h"
#include "biblia/jogos/frutinha/antigo/MensagemBmp.h"
#include "biblia/jogos/frutinha/antigo/Marcacao.h"
#include "biblia/jogos/frutinha/io/botoes/Botoes.h"
#include "biblia/jogos/frutinha/io/botoes/Piscador.h"
#include "biblia/jogos/frutinha/antigo/Menu.h"
#include "biblia/jogos/frutinha/antigo/MenuNaTela.h"
#include "biblia/jogos/frutinha/antigo/GerenciadorDeRelatorios.h"
#include "biblia/jogos/frutinha/dados/DConfiguracao.h"
#include "biblia/jogos/frutinha/antigo/Sistema.h"
#include "biblia/jogos/frutinha/logica/Logicas.h"
#include "biblia/jogos/frutinha/dados/DHistorico.h"
#include "biblia/seguranca/Usuario.h"

using namespace biblia::jogos::frutinha::dados;
using namespace biblia::jogos::frutinha::io::botoes;
using namespace biblia::jogos::frutinha::dados;
using namespace biblia::jogos::frutinha::logica;

namespace biblia{
	namespace jogos {
		namespace frutinha {
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