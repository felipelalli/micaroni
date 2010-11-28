/*
 * $RCSfile: LeitorNotas.h,v $
 * $Date: 2004/05/17 21:10:19 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef LEITORNOTAS_H
#define LEITORNOTAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/serial/Com.h"
using namespace biblia::io::serial;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/noteiro/util/ArqLeitorNotas.h"
using namespace biblia::io::noteiro::util;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#define HABILITADO true
#define DESABILITADO false


#define TEMPO_MINIMO_ENTRE_NOTAS 3

namespace biblia{

	namespace io{

		namespace noteiro{

			class LeitorNotas:  public Objeto,
								public Executavel {

				private:
					ListaInt* pLstNotas;
					Semaforo* pSemaNotas;

				protected:
					Com*  pCom;
					int   pStatus;
					BYTE  pBuffer[255];
					BYTE  pData[255];

					Semaforo* pSemaComm;

					bool    pTerminar;
					bool    pTerminou;
					Thread* pMinhaThread;

					bool   pReiniciar;					

					char pStrError[200];

					void LeitorNotas::pAddNota (int nota);					

					bool pHabilitado;
					bool pNovaHabilitacao;
					bool pDesabilitado;
					virtual void LeitorNotas::pHabilitar()=0;

					Cronometro pCronometroNotas;
					Intervalo pIntervaloEntradaNota;

				public:

					LeitorNotas::LeitorNotas(UniversoDeTempo& universoDeTempo);
					virtual LeitorNotas::~LeitorNotas();

					int  LeitorNotas::getStatus();
					bool LeitorNotas::temNota();
					int  LeitorNotas::getNota();
					bool LeitorNotas::habilitado();
					void LeitorNotas::reiniciar ();
					const char* LeitorNotas::strError();

					void LeitorNotas::habilitar(bool estado);

					virtual Executavel& LeitorNotas::executa ()=0;
					virtual void LeitorNotas::desligar()=0;
					virtual void LeitorNotas::ligar(const char* porta)=0;
					virtual void LeitorNotas::habilitarNotas (int notas)=0;

					enum Notas{
						REAIS_1   = 0x01,
						REAIS_2   = 0x02,
						REAIS_5   = 0x04,
						REAIS_10  = 0x08,
						REAIS_20  = 0x10,
						REAIS_50  = 0x20,
						REAIS_100 = 0x40
					};
			};
		}
	}
}
#endif
