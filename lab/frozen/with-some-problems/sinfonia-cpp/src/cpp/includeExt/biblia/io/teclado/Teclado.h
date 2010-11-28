/*
 * $RCSfile: Teclado.h,v $
 * $Date: 2003/11/22 19:07:44 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef TECLADO_H
#define TECLADO_H

#ifndef WIN32
	#include <termios.h>
#else
	#include <conio.h>
#endif

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace teclado{


			class Teclado : public Objeto{

				public:
					Teclado::Teclado();
					Teclado::~Teclado();
					int Teclado::pressionouTecla();
					int Teclado::teclaPressionada();
					int Teclado::teclaPressionadaAllegro();

				private:

#ifndef WIN32
					struct termios initial_settings, new_settings;
					int peek_character;
#endif
			};
		}
	}
}

#endif
