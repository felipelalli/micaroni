/*
 * $RCSfile: CronometroSistema.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef CRONOMETRO_SISTEMA_H
#define CRONOMETRO_SISTEMA_H

#include <time.h>
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoSistema.h"

namespace biblia {
	namespace tempo {
		class CronometroSistema: public Cronometro {
			private:
				static UniversoSistema CronometroSistema
						::pUniversoSistema;

			public:
				CronometroSistema::CronometroSistema(
						bool pausado = false);

				virtual CronometroSistema::~CronometroSistema();
		};
	}
}
#endif
