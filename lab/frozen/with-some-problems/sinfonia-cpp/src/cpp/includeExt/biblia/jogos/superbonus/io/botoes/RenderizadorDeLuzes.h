/*
 * $RCSfile: RenderizadorDeLuzes.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_)
#define AFX_RENDERIZADORDELUZES_H__14B4090D_38F9_441D_B98A_4EB882436AD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/logica/Renderizador.h"
#include "biblia/jogos/superbonus/EstadosSuperBonus.h"
#include "biblia/jogos/superbonus/io/botoes/Botao.h"
#include "biblia/jogos/superbonus/io/botoes/Piscador.h"

using namespace biblia::logica;
using namespace biblia::jogos::superbonus;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace io {
	    namespace botoes {
			class RenderizadorDeLuzes: public Renderizador {
				private:
					EstadosSuperBonus* RenderizadorDeLuzes
							::pEstadosSuperBonus;

					Piscador* RenderizadorDeLuzes::pPiscador;

				protected:
					virtual EstadosSuperBonus& RenderizadorDeLuzes::jogo();
					virtual Piscador& RenderizadorDeLuzes::piscador();

				public:
					RenderizadorDeLuzes::RenderizadorDeLuzes();
					virtual RenderizadorDeLuzes::~RenderizadorDeLuzes();

					// definições:
					virtual RenderizadorDeLuzes&
							RenderizadorDeLuzes
								::defineEstados(EstadosSuperBonus&);

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
