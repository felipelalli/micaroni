/*
 * $RCSfile: SuperBonus.h,v $
 * $Date: 2005/02/03 00:56:30 $
 * $Revision: 1.20 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_SUPERBONUS_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_)
#define AFX_SUPERBONUS_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/allegro/BasicoVisualAllegro.h"
#include "biblia/mais/fmod/FabricaDeSonsFMod.h"
#include "biblia/io/som/CarregadorDeSom.h"
#include "biblia/io/som/ResultadoSonoro.h"
#include "biblia/io/som/Vitrola.h"
#include "biblia/io/display/DisplaySpider.h"
#include "biblia/io/display/DisplayDelta.h"
#include "biblia/io/display/DisplayLoddy.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/ExecutaveisEmSerie.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/jogos/Jogo.h"
#include "biblia/jogos/superbonus/EstadosSuperBonus.h"
#include "biblia/jogos/superbonus/visual/RenderizadorGraficoSuperBonus.h"
#include "biblia/jogos/superbonus/visual/formulario/RenderizadorTelasSuperBonus.h"
#include "biblia/jogos/superbonus/io/som/RenderizadorSonoroSuperBonus.h"
#include "biblia/jogos/superbonus/io/display/RenderizadorDisplaySuperBonus.h"
#include "biblia/jogos/superbonus/io/botoes/RenderizadorDeLuzes.h"
#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/CarregadorWizard.h"

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;

using namespace biblia::fluxo;
using namespace biblia::tempo;
using namespace biblia::mais::fmod;
using namespace biblia::mais::allegro;
using namespace biblia::io::som;
using namespace biblia::visual::dinamica;
using namespace biblia::jogos::superbonus::visual;
using namespace biblia::jogos::superbonus::visual::formulario;
using namespace biblia::jogos::superbonus::io::som;
using namespace biblia::jogos::superbonus::io::display;
using namespace biblia::jogos::superbonus::io::botoes;

namespace biblia {
  namespace jogos {
    namespace superbonus {

		/**
		 * É por onde inicia o fluxo do jogo Super Bônus.
		 */
		class SuperBonus: public Jogo {
			private:

				ChaveSeguranca pChaveSistema;

				ExecutaveisEmSerie SuperBonus::pDispositivosDeSaida;
				ExecutaveisEmSerie SuperBonus::pDispositivosDeEntrada;
				ExecutaveisEmSerie SuperBonus::pRealizadores;
				ExecutaveisEmSerie SuperBonus::pRenderizadores;

				// Estado Principal do Jogo:
				EstadosSuperBonus* SuperBonus::pPrincipal;

				// Renderizadores:
				RenderizadorGraficoSuperBonus SuperBonus::pRenderizadorVisual;
				RenderizadorSonoroSuperBonus SuperBonus::pRenderizadorSonoro;
				RenderizadorDisplaySuperBonus SuperBonus::pRenderizadorDisplay;
				RenderizadorDeLuzes SuperBonus::pRenderizadorLuzes;
				RenderizadorTelasSuperBonus SuperBonus::pRenderizadorTelas;

				// Realizadores:
				DesenhistaDeResultadoGraficoNaTela SuperBonus::pDesenhista;
				Vitrola SuperBonus::pVitrola;

				PlacaDelta* SuperBonus::pPlacaDelta;
				PlacaLoddy* SuperBonus::pPlacaLoddy;
				Display* SuperBonus::pDisplay;

				// Visual:
				BasicoVisualAllegro SuperBonus::pVisual;

				// Som:
				FabricaDeSonsFMod SuperBonus::pFabricaDeSons;
				CarregadorDeSom SuperBonus::pCarregadorDeSom;
				ResultadoSonoro SuperBonus::pResultadoSonoro;

			protected:
				EstadosSuperBonus& SuperBonus::principal();
				const EstadosSuperBonus& SuperBonus::principal() const;
				BasicoVisualAllegro& SuperBonus::visual();
				const BasicoVisualAllegro& SuperBonus::visual() const;

				virtual SuperBonus& SuperBonus::inicializa();
				virtual SuperBonus& SuperBonus::finaliza();

			public:
				SuperBonus::SuperBonus();
				virtual SuperBonus::~SuperBonus();

				// Executavel:
				virtual Executavel& SuperBonus::executa();
		};
	}
  }
}

#endif // !defined(AFX_SUPERBONUS_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_)
