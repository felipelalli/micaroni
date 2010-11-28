/*
 * $RCSfile: RenderizadorDeComponentes.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORGRAFICODECOMPONENTES_H__888ED747_DA10_48A2_8AC9_9889B509A05B__INCLUDED_)
#define AFX_RENDERIZADORGRAFICODECOMPONENTES_H__888ED747_DA10_48A2_8AC9_9889B509A05B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/logica/Renderizador.h"
#include "biblia/visual/formulario/Componente.h"

using namespace biblia::logica;

namespace biblia {
  namespace visual {
    namespace formulario {

		class RenderizadorDeComponentes: public Renderizador {
			private:
				Componente* RenderizadorDeComponentes::pInicio;

			protected:
				RenderizadorDeComponentes
						::RenderizadorDeComponentes();

			public:
				virtual RenderizadorDeComponentes
						::~RenderizadorDeComponentes();

				virtual const Componente& RenderizadorDeComponentes
						::inicio() const;

				virtual Componente& RenderizadorDeComponentes
						::inicio();

				virtual RenderizadorDeComponentes&
						RenderizadorDeComponentes::defineInicio
							(Componente*);

				// Renderizador:
				virtual Executavel&
						RenderizadorDeComponentes
							::executa() = 0;
		};
	}
  }
}

#endif // !defined(AFX_RENDERIZADORGRAFICODECOMPONENTES_H__888ED747_DA10_48A2_8AC9_9889B509A05B__INCLUDED_)
