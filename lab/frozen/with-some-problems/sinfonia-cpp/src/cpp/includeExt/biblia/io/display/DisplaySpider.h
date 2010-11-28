/*
 * $RCSfile: DisplaySpider.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef DISPLAY_SPIDER_H
#define DISPLAY_SPIDER_H

#include "biblia/io/display/Display.h"
using namespace biblia::io::display;

#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/io/serial/Com.h"
using namespace biblia::io::serial;

#define SOH  0x01
#define STX  0x02
#define CRC  0x88
#define NDTX 0x04
#define ETX  0x03

#define FALHA_NO_PROTOCOLO 10


namespace biblia{

	namespace io{

		namespace display{

			class DisplaySpider :   public Display,
									public Executavel{

				private:
					Com* pCom;

					int pStatus;

					BYTE DisplaySpider::getBCC (BYTE* buffer,int bufferSize);
					void DisplaySpider::formarNumero (char* buffer,double numero);

					double pNumero;

					void DisplaySpider::pEscrever ();

					Semaforo* pSemaforo;
					Thread* pMinhaThread;

					bool pTerminar;
					bool pTerminou;

				public:
					DisplaySpider::DisplaySpider(const char* porta);
					DisplaySpider::~DisplaySpider();

					void DisplaySpider::escrever(double numero);

					Executavel& DisplaySpider::executa();
					int DisplaySpider::getStatus() const;


					void DisplaySpider::ligar(const char* porta);
					void DisplaySpider::desligar();
			};
		}
	}
}

#endif