/*
 * $RCSfile: Com.h,v $
 * $Date: 2004/07/01 15:10:38 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef BIBLIA_COM_H
#define BIBLIA_COM_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef WIN32 //PARA WINDOWS
	#include <windows.h>
	#include <winbase.h>

#else		 //PARA LINUX
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
#endif


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


#define BYTE unsigned char

#define SEM_COMUNICACAO_PORTA       1
#define SEM_COMUNICACAO_EQUIPAMENTO 2
#define COMUNICACAO_OK              3

#ifdef WIN32
#define PORTA_COM1 "COM1"
#define PORTA_COM2 "COM2"
#define PORTA_COM3 "COM3"
#define PORTA_COM4 "COM4"
#else
#define PORTA_COM1 "/dev/ttyS0"
#define PORTA_COM2 "/dev/ttyS1"
#define PORTA_COM3 "/dev/ttyS2"
#define PORTA_COM4 "/dev/ttyS3"
#endif

namespace biblia{

	namespace io{

		namespace serial{

			class Com:public Objeto {

				private:

					int pStatus;

					Semaforo pSemaforo;

					#ifdef WIN32 //PARA WINDOWS
						HANDLE pCom;

					#else		 //PARA LINUX
						int pCom;
						struct termios pOldio;
					#endif

				public:
					Com::Com (const char* com);
					Com::Com (const char* com,int taxaTrans, int dataBits, int stopBits, char paridade, long timeout);
					Com::~Com();
					bool Com::readCCom(BYTE* buffer, unsigned long qtsBytes);
					bool Com::writeCCom(BYTE* buffer, unsigned long qtsBytes);

					int Com::getStatus() const;

					static char* Com::showHexa (BYTE* buffer, int tamanho);
			};
		}
	}
}

#endif
