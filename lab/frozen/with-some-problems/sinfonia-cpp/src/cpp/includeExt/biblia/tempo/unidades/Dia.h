/*
 * $RCSfile: Dia.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_Dia_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
#define AFX_Dia_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/tempo/UnidadeDeTempo.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::tempo;

namespace biblia {
  namespace tempo {
  	namespace unidades {

		class Dia
				:public UnidadeDeTempo
		{
			public:
				Dia::Dia();
				virtual Dia::~Dia();
		};
	}
  }
}

#endif // !defined(AFX_Dia_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
