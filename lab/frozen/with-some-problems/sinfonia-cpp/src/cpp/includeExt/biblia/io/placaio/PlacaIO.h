/*
 * $RCSfile: PlacaIO.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef CPlacaIO_H
#define CPlacaIO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


#ifndef WIN32
	#define END_DISPOSITIVO "/dev/fs8e8s"
#else
	#define END_DISPOSITIVO NULL
#endif

#ifndef COMUNICACAO_OK
	#define SEM_COMUNICACAO_EQUIPAMENTO 2
	#define COMUNICACAO_OK              3
#endif

#define NUM_PLACAS 2
#define NUM_SAIDAS 8


namespace biblia{

	namespace io{

		namespace placaio{

			class PlacaIO:public Objeto {

				private:
					int pStatus;
					unsigned char pVetOut [NUM_PLACAS];
					unsigned char pVetIn  [NUM_PLACAS];
					Semaforo* pSema;
					int pPlaca;

					void PlacaIO::escrever();

				public:
					PlacaIO::PlacaIO();
					PlacaIO::~PlacaIO();

					void PlacaIO::onSinal  (int placa,int saida);//Seta em um (liga) o sinal correspondente na placa
					void PlacaIO::offSinal (int placa,int saida);//Seta em zero (desliga) o sinal correspondente na placa
					bool PlacaIO::getSinal (int placa,int saida);//Retorna o sinal (de saida) correspondente na placa
					void PlacaIO::sendSinal(int placa,int saida);//Liga e Desliga o sinal correspondente na placa

					unsigned char PlacaIO::verSinal (int placa);//Retorna o estado de entrada da placa

					int PlacaIO::getStatus() const {
						return this->pStatus;
					}
			};
		}
	}
}

#endif
