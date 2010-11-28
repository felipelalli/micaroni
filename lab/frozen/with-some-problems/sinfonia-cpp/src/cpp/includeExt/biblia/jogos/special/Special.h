/*
 * $RCSfile: Special.h,v $
 * $Date: 2004/06/18 01:50:26 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_Special_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_)
#define AFX_Special_H__124CA4D5_3BB4_4E0C_9E00_744118F2FE99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


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


#include "biblia/tempo/UltraLong.h"
using namespace biblia::tempo;

#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/CarregadorWizard.h"
using namespace biblia::visual::dinamica;

#include "biblia/jogos/Jogo.h"
using namespace biblia::jogos;

#include "biblia/jogos/special/EstadosSpecial.h"
using namespace biblia::jogos::special;

#include "biblia/jogos/special/visual/RenderizadorGraficoSpecial.h"
#include "biblia/jogos/special/visual/RenderizadorGraficoDouble.h"
#include "biblia/jogos/special/visual/RenderizadorSimulacaoSpecial.h"
using namespace biblia::jogos::special::visual;

#include "biblia/jogos/special/visual/formulario/RenderizadorTelasSpecial.h"
using namespace biblia::jogos::special::visual::formulario;

#include "biblia/jogos/special/io/som/RenderizadorSonoroSpecial.h"
using namespace biblia::jogos::special::io::som;

#include "biblia/jogos/special/io/display/RenderizadorDisplaySpecial.h"
using namespace biblia::jogos::special::io::display;

#include "biblia/jogos/special/io/botoes/RenderizadorDeLuzes.h"
using namespace biblia::jogos::special::io::botoes;

#include "biblia/jogos/special/antigo/GerenciadorLicenca.h"
using namespace biblia::jogos::special::antigo;

namespace biblia {
  namespace jogos {
    namespace special {

		/**
		 * É por onde inicia o fluxo do jogo Super Bônus.
		 */
		class Special: public Jogo {
			private:
				// Capa:
				Skin Special::pSkin;

				// Executáveis:
				ExecutaveisEmSerie Special::pDispositivosDeSaida;
				ExecutaveisEmSerie Special::pDispositivosDeEntrada;
				ExecutaveisEmSerie Special::pRealizadores;
				ExecutaveisEmSerie Special::pRenderizadores;

				// Estado Principal do Jogo:
				EstadosSpecial* Special::pPrincipal;

				// Renderizadores:
				Renderizador* Special::pRenderizadorVisual;
				RenderizadorSonoroSpecial Special::pRenderizadorSonoro;
				RenderizadorDisplaySpecial Special::pRenderizadorDisplay;
				RenderizadorDeLuzes Special::pRenderizadorLuzes;
				RenderizadorTelasSpecial Special::pRenderizadorTelas;

				// Realizadores:
				DesenhistaDeResultadoGraficoNaTela Special::pDesenhista;
				Vitrola Special::pVitrola;

				PlacaDelta* Special::pPlacaDelta;
				PlacaLoddy* Special::pPlacaLoddy;
				Display* Special::pDisplay;

				// Visual:
				BasicoVisualAllegro Special::pVisual;

				// Som:
				FabricaDeSonsFMod Special::pFabricaDeSons;
				CarregadorDeSom Special::pCarregadorDeSom;
				ResultadoSonoro Special::pResultadoSonoro;

			protected:
				virtual const bool Special::doubleBonus() const;
				virtual const bool Special::superBonusSpecial() const;
				virtual const bool Special::simulacao() const;

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
