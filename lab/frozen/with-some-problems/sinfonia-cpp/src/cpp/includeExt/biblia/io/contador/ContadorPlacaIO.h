/*
 * $RCSfile: ContadorPlacaIO.h,v $
 * $Date: 2003/11/25 02:18:14 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef CONTADOR_PLACAIO_H
#define CONTADOR_PLACAIO_H


#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;



#include "biblia/armazenamento/eterno/Contador.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;


#define PLACA_CONTADOR   2

#define CONTADOR_APOSTADO_IO 5
#define CONTADOR_GANHO_IO    6


#define MAX_CONTADOR 999999


namespace biblia{

	namespace io{

		namespace contador{

			class ContadorPlacaIO:	public Contador,
									public Executavel{

				private:				

					Thread* pMinhaThread;
					bool pTerminar;
					bool pTerminou;

					PlacaIO* pPlacaIO;
				

				public:
					ContadorPlacaIO::ContadorPlacaIO(PlacaIO* placaIO);
					ContadorPlacaIO::~ContadorPlacaIO();


					Executavel& ContadorPlacaIO::executa();
			};
		}
	}
}

#endif
