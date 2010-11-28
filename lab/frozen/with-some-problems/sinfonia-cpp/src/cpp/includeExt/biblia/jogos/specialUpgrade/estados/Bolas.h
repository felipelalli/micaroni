/*
 * $RCSfile: Bolas.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOLAS_H__AFE1F180_D70F_43AE_A7E9_6A4421CC3EEE__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOLAS_H__AFE1F180_D70F_43AE_A7E9_6A4421CC3EEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;


namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Bolas: public Objeto {
			private:
				Intervalo Bolas::pTempoFilada;
				bool Bolas::pFilada;
				Intervalo Bolas::pLancamento;
				double Bolas::pVelocidade;
				Intervalo Bolas::pDeGiro;

				bool pLancando;
				int pLancadas;

			public:
				Bolas::Bolas(const Intervalo tempoMaximoDeFilada,
							 const Intervalo lancamento,
							 const Intervalo deGiro,
							 double velocidade  = 1.0);

				virtual Bolas::~Bolas();

				virtual Intervalo Bolas
						::intervaloDeLancamento() const;

				virtual Intervalo Bolas
						::intervaloMaximoFilada() const;

				virtual Intervalo Bolas
						::intervaloDeGiro() const;

				virtual Bolas& Bolas::velocidade(double);
				virtual const double& Bolas::velocidade() const;

				virtual Bolas& Bolas::fila();
				virtual Bolas& Bolas::desfila();
				virtual const bool& Bolas::filado() const;

				virtual Bolas& Bolas::iniciaLancamento();
				virtual Bolas& Bolas::finalizaLancamento();

				virtual bool Bolas::lancando() const;

				virtual Bolas& Bolas::lancaUma();
				virtual int Bolas::lancadas() const;

				virtual Bolas& Bolas::zerar();
		};
	  }
	}
  }
}
#endif // !defined(AFX_BOLAS_H__AFE1F180_D70F_43AE_A7E9_6A4421CC3EEE__INCLUDED_)
