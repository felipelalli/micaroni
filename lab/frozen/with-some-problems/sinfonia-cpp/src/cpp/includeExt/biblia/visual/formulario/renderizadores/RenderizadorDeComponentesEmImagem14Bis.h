/*
 * $RCSfile: RenderizadorDeComponentesEmImagem14Bis.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RENDERIZADORDECOMPONENTESEMIMAGEM14BIS_H__134CF35F_232F_48F3_ABCA_F590F36726EF__INCLUDED_)
#define AFX_RENDERIZADORDECOMPONENTESEMIMAGEM14BIS_H__134CF35F_232F_48F3_ABCA_F590F36726EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/tempo/UltraLong.h"
#include "biblia/visual/Raio.h"
#include "biblia/visual/cores/Magenta.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/visual/geometricos/Linha.h"
#include "biblia/visual/geometricos/Circulo.h"
#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
#include "biblia/visual/formulario/RenderizadorDeComponentes.h"
#include "biblia/visual/formulario/Paginas.h"
#include "biblia/visual/formulario/PosicaoXYRelativa.h"
#include "biblia/visual/formulario/Formulario.h"
#include "biblia/visual/formulario/Plano.h"
#include "biblia/visual/formulario/Grupo.h"
#include "biblia/visual/formulario/Caixa3D.h"
#include "biblia/visual/formulario/Label.h"
#include "biblia/visual/formulario/SelecaoImagem.h"
#include "biblia/visual/formulario/TamanhoRelativo.h"
#include "biblia/visual/formulario/TabelaComponente.h"
#include "biblia/visual/formulario/BotaoComponente.h"
#include "biblia/visual/formulario/InputInteiro.h"
#include "biblia/visual/formulario/InputLimitado.h"
#include "biblia/visual/formulario/AnimacaoComponente.h"
#include "biblia/visual/formulario/Volume.h"
#include "biblia/visual/formulario/renderizadores/RenderizadorDeComponentesEmImagem.h"

using namespace biblia::tempo;
using namespace biblia::visual::cores;
using namespace biblia::visual::fonte;
using namespace biblia::visual::geometricos;
using namespace biblia::visual::formulario;

namespace biblia {
  namespace visual {
    namespace formulario {
	  namespace renderizadores {

 	    /**
	     * Batizado de 14bis, esse é "O Renderizador" das telas.
	     */
		class RenderizadorDeComponentesEmImagem14Bis
				:public RenderizadorDeComponentesEmImagem
		{
			private:
				Imagem* RenderizadorDeComponentesEmImagem14Bis
						::pImagem;

			protected:
				virtual RenderizadorDeComponentesEmImagem14Bis&
						RenderizadorDeComponentesEmImagem14Bis
							::desenha(Componente&, int nivel = 0);

				virtual RenderizadorDeComponentesEmImagem14Bis&
						RenderizadorDeComponentesEmImagem14Bis
							::escreve(const std::string& texto,
									  const Ponto& posicao,
									  const Tamanho tamanho,
									  int fonte = LabelComponente::NORMAL);

			public:
				RenderizadorDeComponentesEmImagem14Bis
						::RenderizadorDeComponentesEmImagem14Bis();

				virtual RenderizadorDeComponentesEmImagem14Bis
						::~RenderizadorDeComponentesEmImagem14Bis();

				// RenderizadorDeComponentesEmImagem
				virtual const Imagem*
						RenderizadorDeComponentesEmImagem14Bis
							::imagem() const;

				// RenderizadorDeComponentes
				virtual Executavel&
						RenderizadorDeComponentesEmImagem14Bis
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORDECOMPONENTESEMIMAGEM14BIS_H__134CF35F_232F_48F3_ABCA_F590F36726EF__INCLUDED_)
