/*
 * $RCSfile: Display.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace display{

			class Display : public Objeto{

				protected:
					Display::Display(){};

				public:
					virtual Display::~Display(){};

					virtual void Display::escrever(double numero) = 0;
			};
		}
	}
}

#endif