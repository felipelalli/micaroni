/*
 * $RCSfile: AnimacaoDeQuadros.h,v $
 * $Date: 2003/10/09 01:39:12 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ANIMACAODEQUADROS_H__320C4D75_39A8_433E_BE6D_CD1165B80753__INCLUDED_)
#define AFX_ANIMACAODEQUADROS_H__320C4D75_39A8_433E_BE6D_CD1165B80753__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/animacao/Animacao.h"

namespace biblia {
  namespace visual {
    namespace animacao {

		/**
		 * É uma {@link biblia::visual::animacao::Animacao}
		 * que tem quadros. O último quadro se dá por
		 * <code>{@link #quantosQuadros()} - 1</code>.
		 */
		class AnimacaoDeQuadros: public Animacao {
			private:
				bool AnimacaoDeQuadros::pPassaraEmTodosOsQuadros;
				int pUltimoQuadroForcado;
		
			protected:
				AnimacaoDeQuadros::AnimacaoDeQuadros(
						bool emLoop,
						bool vaiEVolta,
						bool sentidoInverso)
					:Animacao(emLoop, vaiEVolta, sentidoInverso),
					 pPassaraEmTodosOsQuadros(false),
					 pUltimoQuadroForcado(-1)
				{}

			public:
				virtual AnimacaoDeQuadros::~AnimacaoDeQuadros() {};

				/**
				 * Retorna quantos quadros essa animação possui.
				 */
				virtual unsigned int AnimacaoDeQuadros
						::quantosQuadros() const = 0;

				/**
				 * Retorna em que posição está o quadro atual.
				 */
				virtual unsigned int AnimacaoDeQuadros
						::quadroAtual() const = 0;

				/**
				 * Pula para determinado <b>quadro</b>,
				 * sendo que a animação começanda do quadro zero.
				 */
				virtual AnimacaoDeQuadros& AnimacaoDeQuadros
						::vaiPara(unsigned int quadro) = 0;

				virtual AnimacaoDeQuadros& AnimacaoDeQuadros
						::vaiParaOFim()
				{
					return this->vaiPara(this->quantosQuadros() - 1);
				}

				/**
				 * Garante que esta animação passe no
				 * mínimo em todos os quadros.
				 * <b>CUIDADO:
				 *    O tempo da animação pode ficar
				 *    totalmente diferente do esperado.
				 *    'Use esse recurso com responsabilidade.'</b>
				 *
				 * P.S.2: esta classe apenas armazena esta
				 *        informação que deve ser lida e interpretada
				 *        da forma correta pela classe que desta
				 *        deriva.
				 */
				virtual AnimacaoDeQuadros& AnimacaoDeQuadros
						::garanteQuePassaraEmTodosOsQuadros(bool s)
				{
					this->pPassaraEmTodosOsQuadros = s;
					return *this;
				}

				virtual const bool& AnimacaoDeQuadros
						::garanteQuePassaraEmTodosOsQuadros() const
				{
					return this->pPassaraEmTodosOsQuadros;
				}

				/**
				 * Força que o último quadro seja algum pré-definido.
				 * <b>CUIDADO:
				 *    'Use esse recurso com responsabilidade.'</b>
				 *
				 * P.S.2: esta classe apenas armazena esta
				 *        informação que deve ser lida e interpretada
				 *        da forma correta pela classe que desta
				 *        deriva.
				 */
				virtual AnimacaoDeQuadros& AnimacaoDeQuadros
						::forcaUltimoQuadro(int quadro)
				{
					this->pUltimoQuadroForcado = quadro;
					return *this;
				}

				virtual const int& AnimacaoDeQuadros
						::ultimoQuadroForcado() const
				{
					return this->pUltimoQuadroForcado;
				}

				// Animacao:
				virtual Animacao& AnimacaoDeQuadros::reinicia() = 0;

				virtual bool AnimacaoDeQuadros::inicio() const = 0;
				virtual bool AnimacaoDeQuadros::fim() const = 0;

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& AnimacaoDeQuadros
						::executa(int quantasVezes) = 0;
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAODEQUADROS_H__320C4D75_39A8_433E_BE6D_CD1165B80753__INCLUDED_)
