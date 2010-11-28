/*
 * $RCSfile: Animacao.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.5 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ANIMACAO_H__2A53CA31_7FE4_4B61_97CB_B2E60B0ECF30__INCLUDED_)
#define AFX_ANIMACAO_H__2A53CA31_7FE4_4B61_97CB_B2E60B0ECF30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/ExecutavelOtimizado.h"
using namespace biblia::fluxo;

namespace biblia {
  namespace visual {
 	namespace animacao {

		/**
		 * Representa uma anima��o qualquer, de qualquer
		 * coisa, n�o necessariamente visual apesar de
		 * estar neste pacote (biblia::visual); nem t�o pouco
		 * de quadros.
		 * <p>
		 * � um {@link biblia::fluxo::ExecutavelOtimizado}
		 * pois uma anima��o 'atrasada' pode ter otimiza��es
		 * especiais para, por exemplo, pular direto para
		 * a parte certa.
		 */
		class Animacao: public ExecutavelOtimizado {
			private:
				bool Animacao::pSentidoInverso;
				bool Animacao::pEmLoop;
				bool Animacao::pVaiEVolta;

			protected:
				Animacao::Animacao(bool emLoop,
								   bool vaiEVolta,
								   bool sentidoInverso);

			public:
				virtual Animacao::~Animacao() {};
				virtual Animacao& Animacao::reinicia() = 0;

				virtual Animacao& Animacao::inverteSentido();
				virtual Animacao& Animacao::sentidoInverso(bool sim);
				virtual Animacao& Animacao::emLoop(bool sim);
				virtual Animacao& Animacao::vaiEVolta(bool sim);

				virtual bool Animacao::sentidoInverso() const;
				virtual bool Animacao::emLoop() const;
				virtual bool Animacao::vaiEVolta() const;

				virtual bool Animacao::inicio() const = 0;
				virtual bool Animacao::fim() const = 0;

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& Animacao
						::executa(int quantasVezes) = 0;
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAO_H__2A53CA31_7FE4_4B61_97CB_B2E60B0ECF30__INCLUDED_)
