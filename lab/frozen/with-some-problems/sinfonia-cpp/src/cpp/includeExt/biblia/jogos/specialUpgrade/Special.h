/*
 * $RCSfile: Special.h,v $
 * $Date: 2005/01/13 17:09:46 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_AFX_Special_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_AFX_Special_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/allegro/BasicoVisualAllegro.h"
using namespace biblia::mais::allegro;

#include "biblia/mais/fmod/FabricaDeSonsFMod.h"
using namespace biblia::mais::fmod;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/ExecutaveisEmSerie.h"
using namespace biblia::fluxo;

#include "biblia/io/som/CarregadorDeSom.h"
#include "biblia/io/som/ResultadoSonoro.h"
#include "biblia/io/som/Vitrola.h"
using namespace biblia::io::som;

#include "biblia/io/display/Display.h"
#include "biblia/io/display/DisplaySpider.h"
#include "biblia/io/display/DisplayLoddy.h"
#include "biblia/io/display/DisplayDelta.h"
using namespace biblia::io::display;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;

#include "biblia/tempo/UltraLong.h"
using namespace biblia::tempo;

#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/CarregadorWizard.h"
using namespace biblia::visual::dinamica;

#include "biblia/jogos/Jogo.h"
using namespace biblia::jogos;

#include "biblia/jogos/specialUpgrade/EstadosSpecial.h"
using namespace biblia::jogos::specialUpgrade;

#include "biblia/jogos/specialUpgrade/visual/RenderizadorGraficoDoubleUpgrade.h"
#include "biblia/jogos/specialUpgrade/visual/RenderizadorGraficoSpecial.h"
using namespace biblia::jogos::specialUpgrade::visual;

#include "biblia/jogos/specialUpgrade/visual/formulario/RenderizadorTelasSpecial.h"
using namespace biblia::jogos::specialUpgrade::visual::formulario;

#include "biblia/jogos/specialUpgrade/io/som/RenderizadorSonoroSpecial.h"
using namespace biblia::jogos::specialUpgrade::io::som;

#include "biblia/jogos/specialUpgrade/io/display/RenderizadorDisplaySpecial.h"
using namespace biblia::jogos::specialUpgrade::io::display;

#include "biblia/jogos/specialUpgrade/io/botoes/RenderizadorDeLuzes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/jogos/specialUpgrade/antigo/GerenciadorLicenca.h"
using namespace biblia::jogos::specialUpgrade::antigo;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {

		/**
		 * É por onde inicia o fluxo do jogo Super Bônus.
		 */
		class Special: public Jogo {
			private:
				// Capa:
				Skin pSkin;

				// Executáveis:
				ExecutaveisEmSerie pDispositivosDeSaida;
				ExecutaveisEmSerie pDispositivosDeEntrada;
				ExecutaveisEmSerie pRealizadores;
				ExecutaveisEmSerie pRenderizadores;

				// Estado Principal do Jogo:
				EstadosSpecial* pPrincipal;

				// Renderizadores:
				Renderizador* pRenderizadorVisual;
				RenderizadorSonoroSpecial pRenderizadorSonoro;
				RenderizadorDisplaySpecial pRenderizadorDisplay;
				RenderizadorDeLuzes pRenderizadorLuzes;
				RenderizadorTelasSpecial pRenderizadorTelas;

				// Realizadores:
				DesenhistaDeResultadoGraficoNaTela pDesenhista;
				Vitrola pVitrola;

				PlacaDelta* pPlacaDelta;
				PlacaLoddy* pPlacaLoddy;
				Display* pDisplay;

				// Visual:
				BasicoVisualAllegro pVisual;

				// Som:
				FabricaDeSonsFMod pFabricaDeSons;
				CarregadorDeSom pCarregadorDeSom;
				ResultadoSonoro pResultadoSonoro;

			protected:
				virtual const bool Special::doubleBonusUpgrade() const;
				virtual const bool Special::superBonusSpecialUpgrade() const;

				virtual EstadosSpecial& Special::principal();
				virtual const EstadosSpecial& Special::principal() const;
				virtual BasicoVisualAllegro& Special::visual();
				virtual const BasicoVisualAllegro& Special::visual() const;

				virtual Special& Special::inicializa();
				virtual Special& Special::finaliza();

			public:
				Special::Special(const Skin&);
				virtual Special::~Special();

				// Executavel:
				virtual Executavel& Special::executa();
		};
	}
  }
}

#endif // !defined(AFX_Special_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_)
