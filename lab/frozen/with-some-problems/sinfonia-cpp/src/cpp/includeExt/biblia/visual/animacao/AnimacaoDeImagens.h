/*
 * $RCSfile: AnimacaoDeImagens.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ANIMACAODEIMAGENS_H__3D207C81_43E7_4A7F_B761_4EE14BF67290__INCLUDED_)
#define AFX_ANIMACAODEIMAGENS_H__3D207C81_43E7_4A7F_B761_4EE14BF67290__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Bidimensional.h"
#include "biblia/visual/Posicionado.h"
#include "biblia/visual/Unicolor.h"
#include "biblia/visual/cores/Transparente.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/animacao/AnimacaoDeQuadros.h"

using namespace biblia::basico;
using namespace biblia::visual;
using namespace biblia::visual::cores;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
	namespace animacao {

		/**
		 * @see {@link #imagem()}.
		 */
		class AnimacaoDeImagens
				:public AnimacaoDeQuadros,
		         public Bidimensional,
				 public Posicionado,
				 public Unicolor,
				 public Objeto
		{
			protected:
				AnimacaoDeImagens::AnimacaoDeImagens(
						const Ponto& p,
						bool emLoop,
						bool vaiEVolta,
						bool sentidoInverso)
					:AnimacaoDeQuadros(emLoop, vaiEVolta, sentidoInverso),
					 Posicionado(p), Unicolor(Transparente(0))
				{}

			public:
				virtual AnimacaoDeImagens::~AnimacaoDeImagens() {};

				/**
				 * Função principal desta classe,
				 * retorna uma imagem posicionada
				 * atual desta AnimacaoDeImagens.
				 */
				virtual const ImagemPosicionada& AnimacaoDeImagens
						::imagem() const = 0;

				// Animacao:
				virtual Animacao& AnimacaoDeImagens::reinicia() = 0;

				virtual bool AnimacaoDeImagens::inicio() const = 0;
				virtual bool AnimacaoDeImagens::fim() const = 0;

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& AnimacaoDeImagens
						::executa(int quantasVezes) = 0;

				// AnimacaoDeQuadros:
				virtual unsigned int AnimacaoDeImagens
						::quantosQuadros() const = 0;

				virtual AnimacaoDeQuadros& AnimacaoDeImagens
						::vaiPara(unsigned int quadro) = 0;

				// Bidimensional:
				virtual Area AnimacaoDeImagens
						::areaQueOcupa() const = 0;
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAODEIMAGENS_H__3D207C81_43E7_4A7F_B761_4EE14BF67290__INCLUDED_)
