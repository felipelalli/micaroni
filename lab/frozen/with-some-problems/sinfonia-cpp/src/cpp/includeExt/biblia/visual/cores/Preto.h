/*
 * $RCSfile: Preto.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.5 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_Preto_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
#define AFX_Preto_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Cor.h"

namespace biblia {
  namespace visual {
	namespace cores {

		class Preto: public Cor {
			public:
				Preto::Preto();
				virtual Preto::~Preto();
		};
	}
  }
}

#endif // !defined(AFX_VERMELHO_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
