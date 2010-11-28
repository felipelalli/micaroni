/*
 * $RCSfile: VariavelEterna.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_VARIAVELETERNA_H__017F9B00_9C1F_466A_A5C7_2705574E2767__INCLUDED_)
#define AFX_VARIAVELETERNA_H__017F9B00_9C1F_466A_A5C7_2705574E2767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/fluxo/Executavel.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::fluxo;

namespace biblia {
  namespace armazenamento{
    namespace eterno {
		/**
		 * Representa uma variável que existe eternamente.
		 * Ao ser 'executado' se garante que esse
		 * valor existirá 'para sempre'.
		 */
		template<class Tipo> class VariavelEterna
				:public Executavel, public Objeto
		{
			private:
				std::string pID;

			protected:
				VariavelEterna<Tipo>(std::string id):pID(id){}
				const std::string& id() const {
					return this->pID;
				}

			public:
				virtual ~VariavelEterna<Tipo>() {}

				virtual const bool mesma(
						const VariavelEterna& ve)
				{
					return !ve.id().compare(this->id());
				}

				/**
				 * Retorna o conteúdo.
				 */
				virtual const Tipo& valor() const = 0;

				/**
				 * Retorna o conteúdo para ser modificado.
				 */
				virtual Tipo& pegaValorPraMudar() = 0;

				/**
				 * É necessário que o Tipo tenha o operador !=
				 */
				virtual VariavelEterna<Tipo>&
						muda(const Tipo&) = 0;

				/**
				 * Restaura o último valor desde que
				 * essa VariavelEterna foi 'executada'.
				 */
				virtual VariavelEterna<Tipo>& restaura() {
					return *this;
				}

				/**
				 * Salva o último valor.
				 */
				virtual VariavelEterna<Tipo>& salva() {
					return *this;
				}

				/**
				 * Destrói essa variável eterna.
				 */
				virtual VariavelEterna<Tipo>& destroi() = 0;

				// Executavel:
				/**
				 * Salva o último valor.
				 */
				virtual Executavel& executa() {
					this->salva();
					return *this;
				}
		};
	}
  }
}

#endif // !defined(AFX_VARIAVELETERNA_H__017F9B00_9C1F_466A_A5C7_2705574E2767__INCLUDED_)
