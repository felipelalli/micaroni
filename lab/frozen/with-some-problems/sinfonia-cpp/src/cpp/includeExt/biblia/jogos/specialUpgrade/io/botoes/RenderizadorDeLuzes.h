/*
 * $RCSfile: RenderizadorDeLuzes.h,v $
 * $Date: 2005/01/13 17:09:49 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/logica/Renderizador.h"
#include "biblia/jogos/specialUpgrade/EstadosSpecial.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Botao.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"

using namespace biblia::logica;
using namespace biblia::jogos::specialUpgrade;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace io {
	    namespace botoes {
			class RenderizadorDeLuzes: public Renderizador {
				private:
					EstadosSpecial* RenderizadorDeLuzes
							::pEstadosSpecial;

					Piscador* RenderizadorDeLuzes::pPiscador;

				protected:
					virtual EstadosSpecial& RenderizadorDeLuzes::jogo();
					virtual Piscador& RenderizadorDeLuzes::piscador();

				public:
					RenderizadorDeLuzes::RenderizadorDeLuzes();
					virtual RenderizadorDeLuzes::~RenderizadorDeLuzes();

					// definições:
					virtual RenderizadorDeLuzes&
							RenderizadorDeLuzes
								::defineEstados(EstadosSpecial&);

					virtual RenderizadorDeLuzes&
							RenderizadorDeLuzes
								::definePiscador(Piscador&);

					// Renderizador:
					virtual Executavel& RenderizadorDeLuzes::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_)
