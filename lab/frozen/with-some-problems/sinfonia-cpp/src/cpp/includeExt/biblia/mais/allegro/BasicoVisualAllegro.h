/*
 * $RCSfile: BasicoVisualAllegro.h,v $
 * $Date: 2003/06/10 19:16:53 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BASICOVISUALALLEGRO_H__45892E75_C25F_4507_9839_42347DFA00C5__INCLUDED_)
#define AFX_BASICOVISUALALLEGRO_H__45892E75_C25F_4507_9839_42347DFA00C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include "biblia/mais/allegro/Allegro.h"
#include "biblia/util/Debug.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/mais/allegro/CapturadorDeTelaAllegro.h"
#include "biblia/mais/allegro/FabricaDeImagensAllegroSegura.h"
#include "biblia/mais/allegro/TempoGlobalAllegro.h"
#include "biblia/seguranca/ChaveSeguranca.h"

using namespace biblia::util;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;
using namespace biblia::visual::dinamica;
using namespace biblia::seguranca;

namespace biblia {
  namespace mais {
 	namespace allegro {

		/**
		 * Define o fundo o que está definido por "fundo"
		 * no {@link #carregador()}.
		 */
		class BasicoVisualAllegro: public BasicoVisual {
			private:
				ChaveSeguranca* pChaveSeguranca;
				CarregadorDeComponentes* BasicoVisualAllegro::pCarregador;
				FabricaDeImagensAllegroSegura* BasicoVisualAllegro::pFabrica;
				TelaAllegro* BasicoVisualAllegro::pTela;
				TempoGlobalAllegro* BasicoVisualAllegro::pTempoGlobal;
				Cronometro* BasicoVisualAllegro::pTempo;

			public:
				BasicoVisualAllegro::BasicoVisualAllegro();
				virtual BasicoVisualAllegro::~BasicoVisualAllegro();

				// BasicoVisual:
				virtual BasicoVisual& BasicoVisualAllegro
						::reinicia();

				virtual CarregadorDeComponentes&
						BasicoVisualAllegro::carregador();

				virtual FabricaDeImagens&
						BasicoVisualAllegro::fabrica();

				virtual TelaComFundo&
						BasicoVisualAllegro::tela();

				virtual UniversoDeTempo&
						BasicoVisualAllegro::tempo();

				virtual const CarregadorDeComponentes&
						BasicoVisualAllegro::carregador() const;

				virtual const FabricaDeImagens&
						BasicoVisualAllegro::fabrica() const;

				virtual const TelaComFundo&
						BasicoVisualAllegro::tela() const;

				virtual const UniversoDeTempo&
						BasicoVisualAllegro::tempo() const;
		};
	}
  }
}

#endif // !defined(AFX_BASICOVISUALALLEGRO_H__45892E75_C25F_4507_9839_42347DFA00C5__INCLUDED_)
