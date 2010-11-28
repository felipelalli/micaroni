/*
 * $RCSfile: ImagemAllegro.h,v $
 * $Date: 2005/01/20 21:29:02 $
 * $Revision: 1.14 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_IMAGEMALLEGRO_H__2AC25DD2_BF17_4F4D_AAA4_C16C3CAA399C__INCLUDED_)
#define AFX_IMAGEMALLEGRO_H__2AC25DD2_BF17_4F4D_AAA4_C16C3CAA399C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <allegro.h>
#ifdef WIN32
#include <winalleg.h>
#endif

#include <typeinfo>
#include "biblia/basico/Excecao.h"
#include "biblia/util/Debug.h"
#include "biblia/mais/MaisExcecao.h"
#include "biblia/mais/allegro/Allegro.h"
#include "biblia/visual/imagem2d/Imagem.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Raio.h"
#include "biblia/visual/cores/Magenta.h"
#include "biblia/visual/geometricos/Circulo.h"
#include "biblia/visual/geometricos/Linha.h"
#include "biblia/visual/geometricos/Retangulo.h"

using namespace biblia::visual::imagem2d;
using namespace biblia::visual;

namespace biblia {
  namespace mais {
	namespace allegro {

		/**
		 * Esta classe não pode ser instanciada,
		 * veja {@link biblia::mais::allegro::Allegro}
		 * para poder criar uma 'imagem'.
		 *
		 * @see Allegro
		 */
		class ImagemAllegro: public Imagem {
			/*
			 * Friend é usado porque em Java
			 * uma classe do mesmo pacote pode acessar
			 * o protected da outra.
			 */
			friend class Allegro;
			friend class TelaAllegro;

			private:
				bool pInvisivel;
				bool pDeveDestruir;
				BITMAP* pImagem;

			protected:
				/**
				 * O BITMAP* não pode ser modificado
				 * ou deletado por fora, porque o
				 * destrutor dessa classe fará isso.
				 */
				ImagemAllegro::ImagemAllegro(
						BITMAP*, const Tamanho&,
						bool invisivel = true,
						const int tranparencia = 0,
						bool deveDestruirImagem = true);

				bool ImagemAllegro::invisivel() const;
				BITMAP* ImagemAllegro::imagem() const;

				/**
				 * Destrói esta imagem pra sempre.
				 */
				ImagemAllegro& ImagemAllegro::destroi();

				/**
				 * Faz uma cópia de outra imagem nela
				 * mesma.
				 */
				ImagemAllegro& ImagemAllegro::copia(
						const ImagemAllegro&);

			public:
 				BITMAP* ImagemAllegro::bitmapPointer();

				/**
				 * Se clone for 'false' ele copia
				 * a imagem em outra região de memória.
				 */
				ImagemAllegro::ImagemAllegro(
						const ImagemAllegro&,
						bool clone = false);

				virtual ImagemAllegro::~ImagemAllegro();

				virtual Imagem& ImagemAllegro::cola(
						const Imagem& origem,
						Ponto aonde,
						Ponto deOnde = Ponto(0, 0),
						Tamanho = Tamanho(0, 0));

				virtual Imagem& ImagemAllegro::desenha(
						const Geometrico&);

				virtual bool ImagemAllegro::sabeDesenhar(
						const Geometrico&) const;

				virtual Imagem& ImagemAllegro::pixel(
						const Ponto&, const Cor&);

				virtual const Cor& ImagemAllegro::pixel(
						const Ponto&) const;

				virtual Imagem& ImagemAllegro::tornaInvisivel(const Cor&);
				virtual Imagem& ImagemAllegro::tornaOpaca(const Cor&);

				virtual const std::deque<Cor>&
						ImagemAllegro::invisiveis() const;

				virtual Imagem& ImagemAllegro
						::operator=(const Imagem&);
		};
	}
  }
}

#endif // !defined(AFX_IMAGEMALLEGRO_H__2AC25DD2_BF17_4F4D_AAA4_C16C3CAA399C__INCLUDED_)
