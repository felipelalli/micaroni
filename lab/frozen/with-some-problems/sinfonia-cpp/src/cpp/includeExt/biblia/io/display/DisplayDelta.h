/*
 * $RCSfile: DisplayDelta.h,v $
 * $Date: 2004/06/01 00:32:03 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef DISPLAY_DELTA_H
#define DISPLAY_DELTA_H

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/io/display/Display.h"
using namespace biblia::io::display;


namespace biblia{

	namespace io{

		namespace display{

			class DisplayDelta : public Display,
								 public Executavel{

				private:
					PlacaDelta& pPlacaDelta;
					double pNumero;					
					Semaforo pSemaforo;
					bool pTerminar;
					bool pTerminou;
					Thread* pMinhaThread;

				public:
					DisplayDelta::DisplayDelta(PlacaDelta& placaDelta);
					DisplayDelta::~DisplayDelta();

					Executavel& DisplayDelta::executa();

					void DisplayDelta::escrever(double numero);
			};
		}
	}
}

#endif
