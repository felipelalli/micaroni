/*
 * $RCSfile: Tela.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TELA_H__BBF8AB13_D989_48E8_A5DD_E45A3D250F88__INCLUDED_)
#define AFX_TELA_H__BBF8AB13_D989_48E8_A5DD_E45A3D250F88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/imagem2d/Imagem.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/VisualExcecao.h"
#include "biblia/visual/BidimensionalImpl.h"
#include "biblia/io/monitor/MonitorExcecao.h"

using namespace biblia::visual::imagem2d;
using namespace biblia::visual;

namespace biblia {
  namespace io {
  	namespace monitor {

		/**
		 * Representa um Universo Bidimensional prático.
		 * <p>
		 * Esta tela é uma {@link
		 * biblia::visual::imagem2d::Imagem}.
		 */
		class Tela: public Imagem {
			protected:
				Tela::Tela(const Tamanho& resolucao);

			public:
				virtual Tela::~Tela();

				/**
				 * Cola uma imagem posicionada.
				 * @see Imagem#cola(const Imagem& origem,
				 *			  Ponto aonde,
				 *			  Ponto deOnde,
				 *			  Tamanho)
				 *
				 * @see biblia::visual::imagem2d::ImagemPosicionada
				 */
				virtual Tela& Tela::cola(
						const ImagemPosicionada&);

				/**
				 * Prepara a tela para receber
				 * as imagens que serão exibidas
				 * nela.
				 *
				 * @see #desenha()
				 */
				virtual Tela& Tela::limpa() = 0;

				/**
				 * Desenha os objetos que foram
				 * colados a partir da limpeza
				 * da tela.
				 *
				 * @see #limpa()
				 */
				virtual Tela& Tela::desenha() = 0;

				virtual Tela& Tela::inicializa() = 0;
				virtual Tela& Tela::finaliza() = 0;

				/**
				 * Para algumas operações com imagens é
				 * necessário que a tela esteja inicializada.
				 */
				virtual bool Tela::inicializada() const = 0;

				/**
				 * Retorna o 'espaço' que esta tela ocupa,
				 * começando da posição (0, 0) até sua resolução.
				 */
				virtual const Bidimensional& Tela::universo2d() const;
		};
	}
  }
}

#endif // !defined(AFX_TELA_H__BBF8AB13_D989_48E8_A5DD_E45A3D250F88__INCLUDED_)
