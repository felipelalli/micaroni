/*
 * $RCSfile: CronometroAllegro.h,v $
 * $Date: 2004/02/18 17:59:38 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CRONOMETROALLEGRO_H__278F547F_929B_4DE6_808C_F6A737F60BE4__INCLUDED_)
#define AFX_CRONOMETROALLEGRO_H__278F547F_929B_4DE6_808C_F6A737F60BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/allegro/TempoGlobalAllegro.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/unidades/Milissegundo.h"

using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace mais {
    namespace allegro {
		/**
		 * Ele usa um TempoGlobalAllegro est�tico
		 * de um milissegundo.
		 *
		 * @deprecated Evite usar esta classe!
		 *			   Por utilizar um TempoGlobalAllegro
		 *			   est�tico, voc� pode "perder o controle"
		 *             sobre os tempos globais que est�o
		 *             funcionando. Use somente para "quebrar um galho"
		 *             quando precisar rapidamente de
		 *             um cron�metro funcionante.
		 *
		 * @see biblia::tempo::Cronometro
		 */
		class CronometroAllegro: public Cronometro {
			private:
				static TempoGlobalAllegro CronometroAllegro::pGlobal;

			public:
				CronometroAllegro::CronometroAllegro();
				virtual CronometroAllegro::~CronometroAllegro();
		};
    }
  }
}

#endif // !defined(AFX_CRONOMETROALLEGRO_H__278F547F_929B_4DE6_808C_F6A737F60BE4__INCLUDED_)
