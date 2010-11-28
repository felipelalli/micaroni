/**
 * $RCSfile: CondicaoModificadora.h,v $
 * $Date: 2005/02/23 22:32:50 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONDICAOMODIFICADORA_H__B0BDA12B_148C_45A4_AD3E_5C85981A50AE__INCLUDED_)
#define AFX_CONDICAOMODIFICADORA_H__B0BDA12B_148C_45A4_AD3E_5C85981A50AE__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Condicao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Modifica uma Condição, aplicando um "NOT". Se
	 * ela for verdadeira, ela se torna falsa e vice-versa.
	 */
	class CondicaoModificadora: public Condicao {
		private:
			Condicao* pCondicao;

		public:
			CondicaoModificadora(const Condicao&);
			virtual ~CondicaoModificadora();

			/**
			 * Retorna o oposto do que foi
			 * passado no construtor.
			 */
			virtual bool verdadeira() const;

			// Objeto:
			virtual string emString() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);
	};
  }
 }
}

#endif // !defined(AFX_CONDICAOMODIFICADORA_H__B0BDA12B_148C_45A4_AD3E_5C85981A50AE__INCLUDED_)
