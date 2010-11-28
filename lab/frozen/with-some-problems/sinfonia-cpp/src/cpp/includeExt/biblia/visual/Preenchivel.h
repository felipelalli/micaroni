/*
 * $RCSfile: Preenchivel.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PREENCHIVEL_H__07E7280B_1153_421F_8C8C_8BE7CEE74836__INCLUDED_)
#define AFX_PREENCHIVEL_H__07E7280B_1153_421F_8C8C_8BE7CEE74836__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

	/**
	 * Deriva desta {@link biblia::basico::Interface}
	 * todo aquele que pode estar preenchido.
	 */
	class Preenchivel: public Interface {
		private:
			bool Preenchivel::pPreenchido;

		protected:
			Preenchivel::Preenchivel(const bool& preenchido);
			Preenchivel::Preenchivel(const Preenchivel&);

		public:
			virtual Preenchivel::~Preenchivel();
			virtual const bool& Preenchivel::preenchido() const;
			virtual Preenchivel& Preenchivel::preenchido(bool sim);
	};
  }
}

#endif // !defined(AFX_PREENCHIVEL_H__07E7280B_1153_421F_8C8C_8BE7CEE74836__INCLUDED_)
