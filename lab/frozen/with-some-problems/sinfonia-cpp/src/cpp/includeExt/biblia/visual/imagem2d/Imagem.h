/*
 * $RCSfile: Imagem.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.16 $
 *
 * Implementação da biblioteca Bíblia.
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
		 * pode ter uma transparência qualquer.
		 * <p>
		 * Esta imagem é capaz de colar outra
		 * imagem nela mesma e (talvez) desenhar
		 * um ou mais objetos {@link
		 * biblia::visual::Geometrico geometricos}.
		 * <p>
		 * É possível também executar a operação mais
		 * básica de uma imagem, que é ler e escrever um pixel
		 * em uma determinada posição da imagem, que
		 * inicia em (0, 0) e vai até o tamanho definida
		 * em {@link biblia::visual::Dimensionavel}.
		 * <p>
		 * Sua transparência é definida pela herança
		 * da interface Unicolor; <i>as demais cores
		 * são totalmente ignoradas</i>.
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
				 *           É invocada quando a implentação
				 *           desta classe não conhece o
				 *           objeto {@link
				 *           biblia::visual::Geometrico}
				 *           para poder desenhá-lo.
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
				 * Coloca um pixel numa determinada posição.
				 */
				virtual Imagem& Imagem::pixel(
						const Ponto&, const Cor&) = 0;

				/**
				 * Lê um pixel duma determinada posição.
				 */
				virtual const Cor& Imagem::pixel(
						const Ponto&) const = 0;

				/**
				 * Define que uma determinada cor
				 * é transparente, i. e, não será
				 * renderizada junto com as demais.
				 *
				 * @throws CorNaoSuportadaVisualExcecao
				 *           É invocada se esta cor não pode
				 *           ser transparente. Dependendo da
				 *           implementação desta classe a cor
				 *           pode ser inválida.
				 *
				 * @throws LimiteExcedidoVisualExcecao
				 *           É invocada quando o número máximo
				 *           de cores transparentes foi atingido.
				 *           Algumas implementações podem suportar
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
				 * Retorna as cores que estão definidas
				 * como transparentes, i. e., que não
				 * serão exibidas.
				 *
				 * @see #tornaInvisivel(const Cor&)
				 */
				virtual const std::deque<Cor>&
						Imagem::invisiveis() const = 0;

				/**
				 * Faz uma cópia de uma determinada
				 * imagem nesta imagem.
				 */
				virtual Imagem& Imagem
						::operator=(const Imagem&) = 0;

				/**
				 * Verifica se esta imagem é igual
				 * a outra.<p>Deve ser reimplementada
				 * preferencialmente pois utiliza um
				 * método não otimizado para comparar
				 * as imagens (pixel a pixel).
				 */
				virtual bool Imagem
						::operator==(const Imagem&) const;

				/**
				 * Verifica se esta imagem é diferente
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
