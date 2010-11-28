/*
 * $RCSfile: SaidaNoConsole.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SAIDA_NO_CONSOLE_SW_H
#define SAIDA_NO_CONSOLE_SW_H

#include <stdio.h>

#include "biblia/io/texto/FluxoDeTexto.h"
using namespace biblia::io::texto;


namespace biblia {
  namespace io {
    namespace monitor {

		class SaidaNoConsole: public FluxoDeTexto {
			public:
				SaidaNoConsole::SaidaNoConsole();
				virtual SaidaNoConsole::~SaidaNoConsole();

				// FluxoDeTexto:
				virtual Executavel& SaidaNoConsole::executa();
		};
	}
  }
}

#endif
