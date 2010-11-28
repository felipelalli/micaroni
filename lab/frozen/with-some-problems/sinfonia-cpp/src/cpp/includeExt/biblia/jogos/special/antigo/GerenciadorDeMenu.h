/*
 * $RCSfile: GerenciadorDeMenu.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_GERENCIADOR_DE_MENU_H_SW
#define SBS_GERENCIADOR_DE_MENU_H_SW

#include "biblia/jogos/special/antigo/TelaCompleta.h"
#include "biblia/jogos/special/antigo/MensagemBmp.h"
#include "biblia/jogos/special/antigo/Marcacao.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/jogos/special/io/botoes/Piscador.h"
#include "biblia/jogos/special/antigo/Menu.h"
#include "biblia/jogos/special/antigo/MenuNaTela.h"
#include "biblia/jogos/special/antigo/GerenciadorDeRelatorios.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/jogos/special/antigo/Sistema.h"
#include "biblia/jogos/special/logica/Logicas.h"
#include "biblia/jogos/special/dados/DHistorico.h"
#include "biblia/seguranca/Usuario.h"

using namespace biblia::jogos::special::dados;
using namespace biblia::jogos::special::io::botoes;
using namespace biblia::jogos::special::dados;
using namespace biblia::jogos::special::logica;

namespace biblia{
	namespace jogos {
		namespace special {
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