/*
 * $RCSfile: EternizadorDePacotesQueNaoEterniza.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ETERNIZADORDEPACOTESQUENAOETERNIZA_H__27103920_17A3_4AC0_8F11_ACBF9DBA61EB__INCLUDED_)
#define AFX_ETERNIZADORDEPACOTESQUENAOETERNIZA_H__27103920_17A3_4AC0_8F11_ACBF9DBA61EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/eterno/eternizacao/EternizadorDePacotes.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace eternizacao {
		/**
 		 * Parece bizarro a existência de um
		 * "eternizador de pacotes que não eterniza",
		 * porém sua função é semelhante à da classe
		 * biblia::io::texto::BuracoNegro. É uma
		 * implementação que "não faz nada". É útil
		 * para informações que realmente não devem
		 * ou não necessitam ser eternizadas.
		 * <p>
		 * Essa classe possuirá uma Caixa, assim
		 * como qualquer EternizadorDePacotes possui.
		 */
		class EternizadorDePacotesQueNaoEterniza
				:public EternizadorDePacotes
		{
			public:
				EternizadorDePacotesQueNaoEterniza
						::EternizadorDePacotesQueNaoEterniza();

				EternizadorDePacotesQueNaoEterniza
						::EternizadorDePacotesQueNaoEterniza(
							const Caixa& caixaInicial);

				virtual EternizadorDePacotesQueNaoEterniza
						::~EternizadorDePacotesQueNaoEterniza();

				// EternizadorDePacotes:
				virtual EternizadorDePacotes&
						EternizadorDePacotesQueNaoEterniza
							::eterniza(const Caixa&,
								       const bool& forcar = false,
									   const bool& verificaSeMudou = true);

				virtual EternizadorDePacotes&
						EternizadorDePacotesQueNaoEterniza
							::apagaDiferenca(const Caixa& todaACaixa);

				virtual const bool EternizadorDePacotesQueNaoEterniza
						::estaDessincronizado(
							const Identificacao&
							qualPacote) const;

				virtual const bool EternizadorDePacotesQueNaoEterniza
						::estaDessincronizado() const;

				virtual EternizadorDePacotes&
						EternizadorDePacotesQueNaoEterniza
							::sincroniza(const Identificacao&
										 qualPacote);

				virtual EternizadorDePacotes&
						EternizadorDePacotesQueNaoEterniza
							::sincronizaTudo();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ETERNIZADORDEPACOTESQUENAOETERNIZA_H__27103920_17A3_4AC0_8F11_ACBF9DBA61EB__INCLUDED_)
