/*
 * $RCSfile: RenderizadorDeComponentesEmTexto.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORDECOMPONENTESEMTEXTO_H__5B60A6AF_4A8B_4892_A161_AE3B78F698AD__INCLUDED_)
#define AFX_RENDERIZADORDECOMPONENTESEMTEXTO_H__5B60A6AF_4A8B_4892_A161_AE3B78F698AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/visual/formulario/RenderizadorDeComponentes.h"
#include "biblia/visual/formulario/Paginas.h"
#include "biblia/visual/formulario/PosicaoXYRelativa.h"
#include "biblia/visual/formulario/Formulario.h"
#include "biblia/visual/formulario/Plano.h"
#include "biblia/visual/formulario/Grupo.h"
#include "biblia/visual/formulario/Label.h"
#include "biblia/visual/formulario/SelecaoImagem.h"
#include "biblia/visual/formulario/TamanhoRelativo.h"
#include "biblia/visual/formulario/TabelaComponente.h"

using namespace biblia::tempo;
using namespace biblia::io::texto;
using namespace biblia::visual::formulario;

namespace biblia {
  namespace visual {
    namespace formulario {
	  namespace renderizadores {
		class RenderizadorDeComponentesEmTexto
				:public RenderizadorDeComponentes
		{
			private:
				FluxoDeTexto*
						RenderizadorDeComponentesEmTexto
							::pFluxo;

			protected:
				virtual RenderizadorDeComponentesEmTexto&
						RenderizadorDeComponentesEmTexto
							::desenha(Componente&, int nivel = 0);

				virtual FluxoDeTexto&
						RenderizadorDeComponentesEmTexto
							::fluxo();

			public:
				RenderizadorDeComponentesEmTexto
						::RenderizadorDeComponentesEmTexto(
								FluxoDeTexto&);

				virtual RenderizadorDeComponentesEmTexto
						::~RenderizadorDeComponentesEmTexto();

				// RenderizadorDeComponentes
				virtual Executavel&
						RenderizadorDeComponentesEmTexto
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORDECOMPONENTESEMTEXTO_H__5B60A6AF_4A8B_4892_A161_AE3B78F698AD__INCLUDED_)
