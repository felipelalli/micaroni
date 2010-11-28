/*
 * $RCSfile: SmileyHardwareLayer.h,v $
 * $Date: 2003/10/28 23:45:27 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef SMILEY_HARDWARE_LAYER_H
#define SMILEY_HARDWARE_LAYER_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/io/serial/Com.h"
using namespace biblia::io::serial;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

				class SmileyHardwareLayer : public Objeto {

					private:
						Semaforo pSemaCom;
						Com* pCom;
						char pPorta [30];

						void SmileyHardwareLayer::pAbrirPorta();
						void SmileyHardwareLayer::pFecharPorta();

						enum Constantes{
							TAMANHO_MAX_BUFFER_SMILES = 255
						};

					protected:
						SmileyHardwareLayer::SmileyHardwareLayer (const char* porta);						

						bool SmileyHardwareLayer::writeComm(BYTE* buffer, int tamanho);
						bool SmileyHardwareLayer::readComm(BYTE* buffer, int qtsBytes);

						bool SmileyHardwareLayer::hardwareLayerOk();

					public:
						virtual SmileyHardwareLayer::~SmileyHardwareLayer ();
						
						void SmileyHardwareLayer::mudarPorta (const char* porta);
						const char* SmileyHardwareLayer::getPorta();
				};
			}
		}
	}
}

#endif