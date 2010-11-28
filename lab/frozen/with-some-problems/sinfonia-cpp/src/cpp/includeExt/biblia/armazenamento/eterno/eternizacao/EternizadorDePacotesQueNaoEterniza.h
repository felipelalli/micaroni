/*
 * $RCSfile: EternizadorDePacotesQueNaoEterniza.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
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
 		 * Parece bizarro a exist�ncia de um
		 * "eternizador de pacotes que n�o eterniza",
		 * por�m sua fun��o � semelhante � da classe
		 * biblia::io::texto::BuracoNegro. � uma
		 * implementa��o que "n�o faz nada". � �til
		 * para informa��es que realmente n�o devem
		 * ou n�o necessitam ser eternizadas.
		 * <p>
		 * Essa classe possuir� uma Caixa, assim
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
