/*
 * $RCSfile: RenderizadorDeFonteImagem.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORBASICODEFONTEIMAGEM_H__F846AEB1_2D64_4E58_A1CB_85E8075DD876__INCLUDED_)
#define AFX_RENDERIZADORBASICODEFONTEIMAGEM_H__F846AEB1_2D64_4E58_A1CB_85E8075DD876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/fonte/FonteImagem.h"
#include "biblia/visual/fonte/TextoComFonte.h"
#include "biblia/visual/imagem2d/Imagem.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Através de uma {@link biblia::visual::fonte::FonteImagem}
		 * converte um {@link std::string texto} em Imagem.
		 */
		class RenderizadorDeFonteImagem: public Objeto {
			private:
				FabricaDeImagens& RenderizadorDeFonteImagem::pFabrica;

			public:
				RenderizadorDeFonteImagem
						::RenderizadorDeFonteImagem
								(FabricaDeImagens&);

				virtual RenderizadorDeFonteImagem
						::~RenderizadorDeFonteImagem();

				virtual FabricaDeImagens& RenderizadorDeFonteImagem
						::fabrica();

				/**
				 * Renderiza um texto com fonte.
				 */
				virtual Imagem* RenderizadorDeFonteImagem
						::renderiza(TextoComFonte<FonteImagem>& oQue);

				static int RenderizadorDeFonteImagem
						::tamanhoHorizontal(TextoComFonte<FonteImagem>&);
		};
	}
  }
}

#endif // !defined(AFX_RENDERIZADORBASICODEFONTEIMAGEM_H__F846AEB1_2D64_4E58_A1CB_85E8075DD876__INCLUDED_)
