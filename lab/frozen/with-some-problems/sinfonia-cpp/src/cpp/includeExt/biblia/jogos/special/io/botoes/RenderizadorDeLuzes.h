/*
 * $RCSfile: RenderizadorDeLuzes.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(SBS_AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_)
#define SBS_AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/logica/Renderizador.h"
#include "biblia/jogos/special/EstadosSpecial.h"
#include "biblia/jogos/special/io/botoes/Botao.h"
#include "biblia/jogos/special/io/botoes/Piscador.h"

using namespace biblia::logica;
using namespace biblia::jogos::special;

namespace biblia {
  namespace jogos {
    namespace special {
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
