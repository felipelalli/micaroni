/*
 * $RCSfile: HardwareClockTicks.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_HardwareClockTicks_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
#define AFX_HardwareClockTicks_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_

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

		/**
		 * Um segundo contém 1.193.181
		 * <i>hardware clock ticks</i>.
		 */
		class HardwareClockTicks
				:public UnidadeDeTempo
		{
			public:
				HardwareClockTicks::HardwareClockTicks();
				virtual HardwareClockTicks
						::~HardwareClockTicks();
		};
	}
  }
}

#endif // !defined(AFX_HardwareClockTicks_H__0E2F523A_D46E_4248_8110_F530B83B8BD4__INCLUDED_)
