/**
 * $RCSfile: CondicaoImpl.h,v $
 * $Date: 2005/02/24 00:41:28 $
 * $Revision: 1.4 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONDICAOIMPL_H__E5BDC843_9538_4510_8551_236BF14659A7__INCLUDED_)
#define AFX_CONDICAOIMPL_H__E5BDC843_9538_4510_8551_236BF14659A7__INCLUDED_

#include "biblia/dinamicas/sinfonia/Condicao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * É uma Condição implementada, ou seja,
	 * carrega consigo um boleano que pode ser definido
	 * como verdadeiro ou falso.
	 * <p>
	 * <i>Obs.: Esta classe poderia se chamar "Boleana",
	 * por isso existe um typedef dela como "Boleana"</i>
	 */
	class CondicaoImpl: public Condicao {
		private:
			bool pB;

		public:
			CondicaoImpl(bool b):pB(b) {}
			virtual ~CondicaoImpl() {}

			// Condicao:
			virtual bool verdadeira() const {
				return this->pB;
			}

			// Copiavel:
			virtual Objeto* geraCopia() const {
				return new CondicaoImpl(*this);
			}

			virtual Copiavel& copiaEmSi(const Copiavel& alheio) {
				const CondicaoImpl& ci = dynamic_cast<const CondicaoImpl&>(alheio);
				this->pB = ci.pB;
				return *this;
			}
	};

	/**
	 * Apelido para uma CondicaoImpl.
	 *
	 * @see CondicaoImpl
	 */
	typedef CondicaoImpl Boleana;
  }
 }
}

#endif // !defined(AFX_CONDICAOIMPL_H__E5BDC843_9538_4510_8551_236BF14659A7__INCLUDED_)
