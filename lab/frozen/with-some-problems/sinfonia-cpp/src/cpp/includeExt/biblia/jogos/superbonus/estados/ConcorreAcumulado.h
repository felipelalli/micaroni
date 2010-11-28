/*
 * $RCSfile: ConcorreAcumulado.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CONCORREACUMULADO_H__05C0CA23_AB07_4C9A_9D3B_FBF684B00C0F__INCLUDED_)
#define AFX_CONCORREACUMULADO_H__05C0CA23_AB07_4C9A_9D3B_FBF684B00C0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		class ConcorreAcumulado: public Objeto {
			private:
				bool ConcorreAcumulado::pConcorre;

			public:
				ConcorreAcumulado::ConcorreAcumulado();
				virtual ConcorreAcumulado::~ConcorreAcumulado();

				virtual ConcorreAcumulado& ConcorreAcumulado
						::concorre(bool sim);

				virtual const bool& ConcorreAcumulado
						::concorre() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_CONCORREACUMULADO_H__05C0CA23_AB07_4C9A_9D3B_FBF684B00C0F__INCLUDED_)
