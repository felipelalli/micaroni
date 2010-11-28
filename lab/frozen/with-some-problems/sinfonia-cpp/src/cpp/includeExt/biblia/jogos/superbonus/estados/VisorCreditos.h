/*
 * $RCSfile: VisorCreditos.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VISORCREDITOS_H__45C34C9B_E84B_4118_8019_267630D8652A__INCLUDED_)
#define AFX_VISORCREDITOS_H__45C34C9B_E84B_4118_8019_267630D8652A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		class VisorCreditos: public Objeto {
			private:
				Intervalo VisorCreditos::pIntervaloDeIncrementacao;
				double VisorCreditos::pVelocidade;
				int VisorCreditos::pValorFinal;
				int VisorCreditos::pValorAtual;
				bool VisorCreditos::pCreditosInsuficientes;

			public:
				VisorCreditos::VisorCreditos(
						const Intervalo intervaloDeIncrementacao,
						double velocidade = 1.0);

				virtual VisorCreditos::~VisorCreditos();

				virtual Intervalo VisorCreditos
						::intervaloDeIncrementacao() const;

				virtual VisorCreditos& VisorCreditos
						::velocidade(double qual);

				virtual const int& VisorCreditos
						::valorFinal() const;

				virtual const int& VisorCreditos
						::valorAtual() const;

				virtual VisorCreditos& VisorCreditos
						::valorFinal(int valor);

				virtual VisorCreditos& VisorCreditos
						::normaliza();

				virtual bool VisorCreditos
						::normal() const;

				virtual VisorCreditos& VisorCreditos
						::creditosInsuficientes();

				virtual bool VisorCreditos
						::consomeCreditosInsuficientes();

				virtual VisorCreditos& VisorCreditos
						::incrementaValorAtual(int quanto = 1);

				virtual VisorCreditos& VisorCreditos
						::decrementaValorAtual(int quanto = 1)
				{
					return this->incrementaValorAtual(-quanto);
				}
		};
	  }
	}
  }
}

#endif // !defined(AFX_VISORCREDITOS_H__45C34C9B_E84B_4118_8019_267630D8652A__INCLUDED_)
