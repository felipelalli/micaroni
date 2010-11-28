/*
 * $RCSfile: SaidaNoDebug.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_SAIDANODEBUG_H__252AB971_35D2_4BE4_B3E8_822DA27DE1C2__INCLUDED_)
#define AFX_SAIDANODEBUG_H__252AB971_35D2_4BE4_B3E8_822DA27DE1C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/util/Debug.h"

using namespace biblia::io::texto;
using namespace biblia::util;

namespace biblia {
  namespace io {
    namespace disco {

		class SaidaNoDebug: public FluxoDeTexto {
			private:
				enum NivelErro SaidaNoDebug::pNivel;

			public:
				SaidaNoDebug::SaidaNoDebug(enum NivelErro = INFO);
				virtual SaidaNoDebug::~SaidaNoDebug();

				// FluxoDeTexto:
				virtual Executavel& SaidaNoDebug::executa();
		};
	}
  }
}

#endif // !defined(AFX_SAIDANODEBUG_H__252AB971_35D2_4BE4_B3E8_822DA27DE1C2__INCLUDED_)
