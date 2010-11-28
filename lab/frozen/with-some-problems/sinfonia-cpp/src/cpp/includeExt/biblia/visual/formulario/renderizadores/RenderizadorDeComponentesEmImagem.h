/*
 * $RCSfile: RenderizadorDeComponentesEmImagem.h,v $
 * $Date: 2004/07/16 21:33:58 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RENDERIZADORDECOMPONENTESEMIMAGEM_H__D9F57C06_62CA_497A_BA50_EDCE75677092__INCLUDED_)
#define AFX_RENDERIZADORDECOMPONENTESEMIMAGEM_H__D9F57C06_62CA_497A_BA50_EDCE75677092__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/visual/imagem2d/Imagem.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/formulario/AnimacaoComponente.h"
#include "biblia/visual/formulario/RenderizadorDeComponentes.h"

using namespace biblia::visual::imagem2d;
using namespace biblia::visual::formulario;
using namespace biblia::visual::dinamica;

namespace biblia {
  namespace visual {
    namespace formulario {
	  namespace renderizadores {

		class RenderizadorDeComponentesEmImagem
				:public RenderizadorDeComponentes
		{
			private:
				bool pVisivel;
				BasicoVisual* pVisual;

			protected:
				RenderizadorDeComponentesEmImagem();
				virtual BasicoVisual& visual();

			public:
				virtual RenderizadorDeComponentesEmImagem
						::~RenderizadorDeComponentesEmImagem();

				virtual RenderizadorDeComponentesEmImagem&
						RenderizadorDeComponentesEmImagem
							::defineVisual(BasicoVisual&);

				virtual const bool& visivel() const;
				virtual RenderizadorDeComponentesEmImagem& visivel(const bool&);

				// por enquanto é público. ver cpp
				virtual RenderizadorDeComponentesEmImagem&
						RenderizadorDeComponentesEmImagem
							::apagaAnimacoes(Componente&);

				virtual const Imagem*
						RenderizadorDeComponentesEmImagem
							::imagem() const = 0;

				// RenderizadorDeComponentes
				virtual Executavel&
						RenderizadorDeComponentesEmImagem
							::executa() = 0;
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORDECOMPONENTESEMIMAGEM_H__D9F57C06_62CA_497A_BA50_EDCE75677092__INCLUDED_)
