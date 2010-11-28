/*
 * $RCSfile: Ciano.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_Ciano_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
#define AFX_Ciano_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Cor.h"

namespace biblia {
  namespace visual {
	namespace cores {

		class Ciano: public Cor {
			public:
				Ciano::Ciano();
				virtual Ciano::~Ciano();
		};
	}
  }
}

#endif // !defined(AFX_Ciano_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
