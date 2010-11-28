/*
 * $RCSfile: ImagemPosicionada.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_IMAGEMPOSICIONADA_H__0EBA57BA_4970_4A80_B244_A92684292356__INCLUDED_)
#define AFX_IMAGEMPOSICIONADA_H__0EBA57BA_4970_4A80_B244_A92684292356__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/Posicionado.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/Bidimensional.h"
#include "biblia/visual/VisualExcecao.h"
#include "biblia/visual/imagem2d/Imagem.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
	namespace imagem2d {

		/**
		 * É uma imagem posicionada.
		 */
		class ImagemPosicionada:
				public Posicionado,
				public Bidimensional,
				public Objeto
		{
			private:
				Imagem& ImagemPosicionada::pImagem;

			public:
				explicit ImagemPosicionada::ImagemPosicionada(
						Imagem& novaImagem, const Ponto& posicao);

				ImagemPosicionada::ImagemPosicionada(
						const ImagemPosicionada&);

				virtual ImagemPosicionada::~ImagemPosicionada();
 				virtual const Imagem& ImagemPosicionada::operator()() const;
				virtual Imagem& ImagemPosicionada::operator()();

				// Bidimensional:
				virtual Area ImagemPosicionada
						::areaQueOcupa() const;
		};
	}
  }
}

#endif // !defined(AFX_IMAGEMPOSICIONADA_H__0EBA57BA_4970_4A80_B244_A92684292356__INCLUDED_)
