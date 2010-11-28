/*
 * $RCSfile: Amarelo.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_Amarelo_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
#define AFX_Amarelo_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Cor.h"

namespace biblia {
  namespace visual {
	namespace cores {

		class Amarelo: public Cor {
			public:
				Amarelo::Amarelo();
				virtual Amarelo::~Amarelo();
		};
	}
  }
}

#endif // !defined(AFX_Amarelo_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
