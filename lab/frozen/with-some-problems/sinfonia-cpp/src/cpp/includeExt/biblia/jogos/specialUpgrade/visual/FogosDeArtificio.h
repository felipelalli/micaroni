/*
 * $RCSfile: FogosDeArtificio.h,v $
 * $Date: 2005/01/13 17:09:51 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_FOGOSDEARTIFICIO_H__3263ED97_B36B_4382_9C46_F99F6BCC9FF1__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_FOGOSDEARTIFICIO_H__3263ED97_B36B_4382_9C46_F99F6BCC9FF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/ExecutavelOtimizado.h"
#include "biblia/visual/Ponto.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/jogos/specialUpgrade/visual/Fogo.h"

using namespace biblia::basico;
using namespace biblia::visual;
using namespace biblia::fluxo;
using namespace biblia::sorte;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace jogos {
	namespace specialUpgrade {
	  namespace visual {
		class FogosDeArtificio
				:public Objeto, public ExecutavelOtimizado
		{
			private:
				Cronometro* FogosDeArtificio::pCronometroEsquerdo;
				Cronometro* FogosDeArtificio::pCronometroMeio;
				Cronometro* FogosDeArtificio::pCronometroDireito;
				bool FogosDeArtificio::pDeveExplodirEsquerdo;
				bool FogosDeArtificio::pDeveExplodirMeio;
				bool FogosDeArtificio::pDeveExplodirDireito;
				Intervalo FogosDeArtificio::pIntervaloDeExplosao;

				Fogo FogosDeArtificio::pFogoMeio;
				Fogo FogosDeArtificio::pFogoDireito;
				Fogo FogosDeArtificio::pFogoEsquerdo;

			protected:
				Sorteio FogosDeArtificio::sorte;

			public:
				FogosDeArtificio::FogosDeArtificio();
				virtual FogosDeArtificio::~FogosDeArtificio();

				virtual FogosDeArtificio& FogosDeArtificio::lancaEsquerdo();
				virtual FogosDeArtificio& FogosDeArtificio::lancaMeio();
				virtual FogosDeArtificio& FogosDeArtificio::lancaDireito();
				virtual FogosDeArtificio& FogosDeArtificio
							::defineUniverso(UniversoDeTempo&);

				virtual bool FogosDeArtificio::deveExplodirEsquerdo();
				virtual bool FogosDeArtificio::deveExplodirMeio();
				virtual bool FogosDeArtificio::deveExplodirDireito();

				virtual bool FogosDeArtificio::iniciouEsquerdo() const;
				virtual bool FogosDeArtificio::iniciouMeio() const;
				virtual bool FogosDeArtificio::iniciouDireito() const;

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& FogosDeArtificio
						::executa(int quantasVezes);

				const Fogo& FogosDeArtificio::fogoMeio() const;
				const Fogo& FogosDeArtificio::fogoDireito() const;
				const Fogo& FogosDeArtificio::fogoEsquerdo() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_FOGOSDEARTIFICIO_H__3263ED97_B36B_4382_9C46_F99F6BCC9FF1__INCLUDED_)
