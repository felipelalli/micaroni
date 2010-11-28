/*
 * $RCSfile: Sprite.h,v $
 * $Date: 2005/01/20 21:29:32 $
 * $Revision: 1.15 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_SPRITE_H__AD2E7CF3_2AC9_48D5_84D1_F4E147E3E0C4__INCLUDED_)
#define AFX_SPRITE_H__AD2E7CF3_2AC9_48D5_84D1_F4E147E3E0C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/util/Debug.h"
#include "biblia/util/Lixeira.h"
#include "biblia/fluxo/Conclusivo.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/animacao/AnimacaoExcecao.h"
#include "biblia/visual/animacao/AnimacaoDeImagens.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace std;
using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace visual {
    namespace animacao {

		/**
		 * Implementa��o b�sica de uma {@link
		 * biblia::visual::animacao::AnimacaoDeImagens}
		 * que consiste numa lista de imagens.
		 * <p>
		 * Certamente n�o � a maneira mais otimizada de
		 * se fazer uma anima��o de imagens, por�m pode
		 * ser �til se houver uma sequ�ncia dispon�vel de
		 * {@link biblia::visual::imagem2d::Imagem imagens}.
		 */
		class Sprite: public AnimacaoDeImagens {
			private:
				std::deque<Imagem*> Sprite::pImagens;
				bool Sprite::pExcluirImagensNoFinal;

				int Sprite::pAtual;
				Tamanho Sprite::pMaiorTamanho;
				ImagemPosicionada* Sprite::pImagem;
				Lixeira Sprite::pLixeira;

			protected:
				const std::deque<Imagem*>& Sprite::imagens() const;
				Sprite& Sprite::atualizaImagemEPosicao();

			public:
				/**
				 * N�o deve ser independente se
				 * houver refer�ncias cruzadas,
				 * imagens repetidas (a mesma)
				 * ou que ser�o exclu�das em
				 * outro lugar.
				 */
				Sprite::Sprite(bool emLoop,
							   bool vaiEVolta,
							   bool sentidoInverso,
							   const Ponto,
							   bool independente);

				/**
				 * Faz a c�pia de um outro Sprite
				 * neste. As imagens n�o s�o copiadas,
				 * suas refer�ncias s�o mantidas. Prefira
				 * utilizar este construtor para economizar
				 * espa�o em mem�ria quando n�o h� necessidade
				 * de cada imagem de cada Sprite ser modificada
				 * individualmente.
				 *
				 * @see #Sprite(const Sprite&, bool copia,
				 *              FabricaDeImagens& f)
				 */
				Sprite::Sprite(const Sprite&);

				/**
				 * Copia o outro Sprite neste, copiando
				 * imagem por imagem. Prefira utilizar este
				 * quando � necess�rio modificar as imagens
				 * do Sprite independentemente em tempo de
				 * execu��o sendo que o Sprite n�o pode
				 * ser modificado. As c�pias das imagens
				 * s�o exclu�das no destrutor.
				 *
				 * @param f � necess�rio uma {@link
				 *          biblia::visual::imagem2d::FabricaDeImagens}
				 *          para que a c�pia seja poss�vel.
				 *
				 * @see #Sprite(const Sprite&)
				 */
				Sprite::Sprite(const Sprite&, bool copia,
							   FabricaDeImagens& f);

				virtual Sprite::~Sprite();
				virtual Sprite& Sprite::adiciona(Imagem*);

				/**
				 * Indica se este Sprite � independente,
				 * i. e., � respons�vel por suas pr�prias
				 * figuras e as deleta em seu destrutor.
				 */
				virtual bool Sprite::independente() const;

				/**
				 * Retorna o conclusivo da lixeira interna.
				 */
				virtual const Conclusivo& Sprite
						::progressoDeExclusao() const;

				// AnimacaoDeImagens:
				virtual const ImagemPosicionada& Sprite::imagem() const;

				// Animacao:
				virtual Animacao& Sprite::reinicia();

				virtual bool Sprite::inicio() const;
				virtual bool Sprite::fim() const;

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& Sprite
						::executa(int quantasVezes);

				// AnimacaoDeQuadros:
				virtual unsigned int Sprite
						::quantosQuadros() const;

				virtual AnimacaoDeQuadros& Sprite
						::vaiPara(unsigned int quadro);

				virtual unsigned int Sprite
						::quadroAtual() const;

				// Bidimensional:
				virtual Area Sprite
						::areaQueOcupa() const;

				// Posicionado:
				virtual Posicionado& Sprite
						::reposiciona(const Ponto&);

				// Objeto:
				virtual std::string Sprite::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_SPRITE_H__AD2E7CF3_2AC9_48D5_84D1_F4E147E3E0C4__INCLUDED_)
