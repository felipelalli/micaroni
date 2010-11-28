/*
 * $RCSfile: RenderizadorDisplaySuperBonus.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_)
#define AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/logica/Renderizador.h"
#include "biblia/io/display/Display.h"
#include "biblia/jogos/superbonus/EstadosSuperBonus.h"

using namespace biblia::logica;
using namespace biblia::io::display;
using namespace biblia::jogos::superbonus;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace io {
	    namespace display {

			class RenderizadorDisplaySuperBonus: public Renderizador {
				private:
					EstadosSuperBonus*
							RenderizadorDisplaySuperBonus
								::pEstadosSuperBonus;

					Display* RenderizadorDisplaySuperBonus
							::pDisplay;

					double RenderizadorDisplaySuperBonus
							::pValorAnterior;

				protected:
					virtual Display& RenderizadorDisplaySuperBonus
							::display();

					virtual EstadosSuperBonus&
							RenderizadorDisplaySuperBonus
								::jogo();

				public:
					RenderizadorDisplaySuperBonus
							::RenderizadorDisplaySuperBonus();

					virtual RenderizadorDisplaySuperBonus
							::~RenderizadorDisplaySuperBonus();

					// definições:
					virtual RenderizadorDisplaySuperBonus&
							RenderizadorDisplaySuperBonus
								::defineDisplay(Display*);

					virtual RenderizadorDisplaySuperBonus&
							RenderizadorDisplaySuperBonus
								::defineEstados(EstadosSuperBonus*);

					// Renderizador:
					virtual Executavel&
							RenderizadorDisplaySuperBonus
								::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_)
