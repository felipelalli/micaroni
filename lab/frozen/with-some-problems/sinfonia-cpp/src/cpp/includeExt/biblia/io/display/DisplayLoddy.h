/*
 * $RCSfile: DisplayLoddy.h,v $
 * $Date: 2003/11/21 03:35:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef DISPLAY_LODDY_H
#define DISPLAY_LODDY_H

#include "biblia/io/display/Display.h"
using namespace biblia::io::display;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

namespace biblia{

	namespace io{

		namespace display{

			class DisplayLoddy : public Display,
								 public Executavel{

				private:
					PlacaLoddy* pPlacaLoddy;
					double pNumero;					
					Semaforo* pSemaforo;
					Thread* pMinhaThread;

				public:
					DisplayLoddy::DisplayLoddy(PlacaLoddy* placaLoddy);
					DisplayLoddy::~DisplayLoddy();

					Executavel& DisplayLoddy::executa();

					void DisplayLoddy::escrever(double numero);
			};
		}
	}
}

#endif