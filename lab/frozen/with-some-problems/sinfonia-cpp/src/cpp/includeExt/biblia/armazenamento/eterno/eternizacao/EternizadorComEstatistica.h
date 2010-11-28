/*
 * $RCSfile: EternizadorComEstatistica.h,v $
 * $Date: 2004/02/18 17:59:38 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ETERNIZADORCOMESTATISTICA_H__8793AD30_3903_488A_978A_D86FB5CFCE54__INCLUDED_)
#define AFX_ETERNIZADORCOMESTATISTICA_H__8793AD30_3903_488A_978A_D86FB5CFCE54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/armazenamento/eterno/eternizacao/EternizadorDePacotes.h"

using namespace biblia::tempo;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace eternizacao {
		/**
		 * Guarda as estatísticas de gasto de tempo
		 * de sincronização e da eternização dos dados.
		 */
		class EternizadorComEstatistica: public EternizadorDePacotes {
			private:
				EternizadorDePacotes& EternizadorComEstatistica::pEternizador;
				UniversoDeTempo& EternizadorComEstatistica::pUniversoDeTempo;
				Cronometro EternizadorComEstatistica::pTempoTotalDeEternizacao;
				Cronometro EternizadorComEstatistica::pTempoTotalDeSincronizacao;
				int EternizadorComEstatistica::pVezesQueFoiEternizado;
				int EternizadorComEstatistica::pVezesQueFoiSincronizado;

			public:
				EternizadorComEstatistica
						::EternizadorComEstatistica(
							EternizadorDePacotes& queSeraMedido,
							UniversoDeTempo& paraMedir);

				virtual EternizadorComEstatistica::~EternizadorComEstatistica();

				virtual const Intervalo	EternizadorComEstatistica
						::tempoTotalDeEternizacao() const;

				virtual const Intervalo	EternizadorComEstatistica
						::tempoTotalDeSincronizacao() const;

				virtual const int& EternizadorComEstatistica
						::quantasVezesEternizado() const
				{
					return this->pVezesQueFoiEternizado;
				}

				virtual const int& EternizadorComEstatistica
						::quantasVezesSincronizado() const
				{
					return this->pVezesQueFoiSincronizado;
				}

				// EternizadorDePacotes:
				virtual const Caixa& EternizadorComEstatistica::caixa() const;

				inline virtual EternizadorDePacotes&
						EternizadorComEstatistica
							::eterniza(const Caixa&,
								       const bool& forcar = false,
									   const bool& verificaSeMudou
											= true);

				virtual EternizadorDePacotes&
						EternizadorComEstatistica
							::apagaDiferenca(
								const Caixa& todaACaixa);

				virtual const bool EternizadorComEstatistica
						::estaDessincronizado(
							const Identificacao&
							qualPacote) const;

				virtual const bool EternizadorComEstatistica
						::estaDessincronizado() const;

				inline virtual EternizadorDePacotes&
						EternizadorComEstatistica
							::sincroniza(const Identificacao&
										 qualPacote);

				virtual EternizadorDePacotes& EternizadorComEstatistica
						::sincronizaTudo();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ETERNIZADORCOMESTATISTICA_H__8793AD30_3903_488A_978A_D86FB5CFCE54__INCLUDED_)
