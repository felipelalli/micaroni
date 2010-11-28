/*
 * $RCSfile: RenderizadorDisplaySpecial.h,v $
 * $Date: 2005/01/13 17:09:49 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef AGES_SPECIAL_UPGRADE_WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/logica/Renderizador.h"
#include "biblia/io/display/Display.h"
#include "biblia/jogos/specialUpgrade/EstadosSpecial.h"

using namespace biblia::logica;
using namespace biblia::io::display;
using namespace biblia::jogos::specialUpgrade;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace io {
	    namespace display {

			class RenderizadorDisplaySpecial: public Renderizador {
				private:
					EstadosSpecial*
							RenderizadorDisplaySpecial
								::pEstadosSpecial;

					Display* RenderizadorDisplaySpecial
							::pDisplay;

					double RenderizadorDisplaySpecial
							::pValorAnterior;

				protected:
					virtual Display& RenderizadorDisplaySpecial
							::display();

					virtual EstadosSpecial&
							RenderizadorDisplaySpecial
								::jogo();

				public:
					RenderizadorDisplaySpecial
							::RenderizadorDisplaySpecial();

					virtual RenderizadorDisplaySpecial
							::~RenderizadorDisplaySpecial();

					// definições:
					virtual RenderizadorDisplaySpecial&
							RenderizadorDisplaySpecial
								::defineDisplay(Display*);

					virtual RenderizadorDisplaySpecial&
							RenderizadorDisplaySpecial
								::defineEstados(EstadosSpecial*);

					// Renderizador:
					virtual Executavel&
							RenderizadorDisplaySpecial
								::executa();
			};
		}
	  }
	}
  }
}

#endif // !defined(SBS_AFX_RENDERIZADORDISPLAYSUPERBONUS_H__E562B1D8_0F82_43BA_AEA9_07F2F5656288__INCLUDED_)
