/*
 * $RCSfile: SmileyTransportLayer.h,v $
 * $Date: 2003/10/23 16:26:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef SMILEY_TRANSPORT_LAYER_H
#define SMILEY_TRANSPORT_LAYER_H

#include "biblia/io/noteiro/smiley/SmileyHardwareLayer.h"
using namespace biblia::io::noteiro::smiley;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/noteiro/smiley/CRC16Smiley.h"
using namespace biblia::io::noteiro::smiley;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

				class SmileyTransportLayer : public SmileyHardwareLayer {

					private:

						bool pTerminar;
						
						BYTE pSequencia;

						bool pComunicacaoOk;

						void SmileyTransportLayer::pMontarBuffer(BYTE* buffer, unsigned int& indice, int sequencia, BYTE command, BYTE* data, int tamanhoData);
						void SmileyTransportLayer::pCalcularCRC(BYTE* buffer, unsigned int& indice, int tamanhoData);
						void SmileyTransportLayer::pGerarBufferSTX(BYTE* buffer, unsigned int& indice);

					protected:

						SmileyTransportLayer::SmileyTransportLayer(const char* porta);
						
						void SmileyTransportLayer::pZerarSequencia();

						bool SmileyTransportLayer::makeComm (BYTE* buffer, BYTE command, BYTE* data, int tamanhoData);

						bool SmileyTransportLayer::transportLayerOk();

						void SmileyTransportLayer::terminarTransportLayer();

					public:
						virtual SmileyTransportLayer::~SmileyTransportLayer();

				};
			}
		}
	}
}

#endif