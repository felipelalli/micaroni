/*
 * $RCSfile: Segundo.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_SEGUNDO_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
#define AFX_SEGUNDO_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/tempo/UnidadeDeTempo.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/UltraLong.h"

using namespace biblia::tempo;

namespace biblia {
  namespace tempo {
  	namespace unidades {

		class Segundo
				:public UnidadeDeTempo
		{
			public:
				Segundo::Segundo();
				virtual Segundo::~Segundo();
		};
	}
  }
}

#endif // !defined(AFX_SEGUNDO_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
