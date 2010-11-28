/*
 * $RCSfile: Imagem.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.16 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_IMAGEM_H__8175BE2A_64B8_464F_B8F6_DE5EF31858A8__INCLUDED_)
#define AFX_IMAGEM_H__8175BE2A_64B8_464F_B8F6_DE5EF31858A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/visual/Dimensionavel.h"
#include "biblia/visual/Unicolor.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Geometrico.h"
#include "biblia/visual/VisualExcecao.h"

using namespace std;

namespace biblia {
  namespace visual {
	namespace imagem2d {

		/**
		 * Representa uma imagem
		 * que tem um determinado tamanho e
		 * pode ter uma transpar�ncia qualquer.
		 * <p>
		 * Esta imagem � capaz de colar outra
		 * imagem nela mesma e (talvez) desenhar
		 * um ou mais objetos {@link
		 * biblia::visual::Geometrico geometricos}.
		 * <p>
		 * � poss�vel tamb�m executar a opera��o mais
		 * b�sica de uma imagem, que � ler e escrever um pixel
		 * em uma determinada posi��o da imagem, que
		 * inicia em (0, 0) e vai at� o tamanho definida
		 * em {@link biblia::visual::Dimensionavel}.
		 * <p>
		 * Sua transpar�ncia � definida pela heran�a
		 * da interface Unicolor; <i>as demais cores
		 * s�o totalmente ignoradas</i>.
		 */
		class Imagem: public Dimensionavel,
					  public Unicolor,
					  public Objeto
		{
			protected:
				Imagem::Imagem(
						const Tamanho&,
						const int transparencia = 0);

			public:
				virtual Imagem::~Imagem() {};

				/**
				 * Cola uma outra imagem nesta.
				 */
				virtual Imagem& Imagem::cola(
						const Imagem& origem,
						Ponto aonde,
						Ponto deOnde = Ponto(0, 0),
						Tamanho = Tamanho(0, 0)) = 0;

				/**
				 * Desenha um objeto {@link
				 * biblia::visual::Geometrico} na
				 * imagem.
				 *
				 * @throws GeometricoNaoSuportadoExcecao
				 *           � invocada quando a implenta��o
				 *           desta classe n�o conhece o
				 *           objeto {@link
				 *           biblia::visual::Geometrico}
				 *           para poder desenh�-lo.
				 */
				virtual Imagem& Imagem::desenha(
						const Geometrico&) = 0;

				/**
				 * Indica se esta classe sabe
				 * desenhar um {@link
				 * biblia::visual::Geometrico}.
				 */
				virtual bool Imagem::sabeDesenhar(
						const Geometrico&) const = 0;

				/**
				 * Coloca um pixel numa determinada posi��o.
				 */
				virtual Imagem& Imagem::pixel(
						const Ponto&, const Cor&) = 0;

				/**
				 * L� um pixel duma determinada posi��o.
				 */
				virtual const Cor& Imagem::pixel(
						const Ponto&) const = 0;

				/**
				 * Define que uma determinada cor
				 * � transparente, i. e, n�o ser�
				 * renderizada junto com as demais.
				 *
				 * @throws CorNaoSuportadaVisualExcecao
				 *           � invocada se esta cor n�o pode
				 *           ser transparente. Dependendo da
				 *           implementa��o desta classe a cor
				 *           pode ser inv�lida.
				 *
				 * @throws LimiteExcedidoVisualExcecao
				 *           � invocada quando o n�mero m�ximo
				 *           de cores transparentes foi atingido.
				 *           Algumas implementa��es podem suportar
				 *           apenas uma cor.
				 *
				 * @see #tornaOpaca(const Cor&)
				 * @see #invisiveis()
				 */
				virtual Imagem& Imagem::tornaInvisivel(const Cor&) = 0;

				/**
				 * Determina que uma determinada cor
				 * deixa de ser transparente.
				 *
				 * @see tornaInvisivel(const Cor&)
				 * @see #invisiveis()
				 */
				virtual Imagem& Imagem::tornaOpaca(const Cor&) = 0;

				/**
				 * Retorna as cores que est�o definidas
				 * como transparentes, i. e., que n�o
				 * ser�o exibidas.
				 *
				 * @see #tornaInvisivel(const Cor&)
				 */
				virtual const std::deque<Cor>&
						Imagem::invisiveis() const = 0;

				/**
				 * Faz uma c�pia de uma determinada
				 * imagem nesta imagem.
				 */
				virtual Imagem& Imagem
						::operator=(const Imagem&) = 0;

				/**
				 * Verifica se esta imagem � igual
				 * a outra.<p>Deve ser reimplementada
				 * preferencialmente pois utiliza um
				 * m�todo n�o otimizado para comparar
				 * as imagens (pixel a pixel).
				 */
				virtual bool Imagem
						::operator==(const Imagem&) const;

				/**
				 * Verifica se esta imagem � diferente
				 * de outra.
				 *
				 * @see #operator==(const Imagem&) const
				 */
				virtual bool Imagem
						::operator!=(const Imagem& i) const
				{ return !((*this) == i); }
		};
	}
  }
}

#endif // !defined(AFX_IMAGEM_H__8175BE2A_64B8_464F_B8F6_DE5EF31858A8__INCLUDED_)
