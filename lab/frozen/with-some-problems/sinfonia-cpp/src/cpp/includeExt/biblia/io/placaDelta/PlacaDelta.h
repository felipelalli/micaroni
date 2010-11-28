#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef PLACA_DELTA_H
#define PLACA_DELTA_H
				


#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;

#include "biblia/io/serial/Com.h"
using namespace biblia::io::serial;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/UniversoDeTempo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/noteiro/LeitorNotas.h"
using namespace biblia::io::noteiro;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
using namespace biblia::armazenamento::volatil::primitivos;





#define QTS_BOTOES_PLACA_DELTA 20

#define INTERVALO_PISCADA_PADRAO 500


namespace biblia{

	namespace io{

		namespace placadelta{

			class PlacaDelta: public LeitorNotas{

				private:
					bool pEstadoBotoes   [QTS_BOTOES_PLACA_DELTA];
					int pEstadoLampadas [QTS_BOTOES_PLACA_DELTA];

					Thread* pThread;
					bool pTerminar;
					bool pTerminou;
					Semaforo pSema;

					bool pAceso;
					
					int  PlacaDelta::pQtsReais (int canal);

					Com pCom;

					Cronometro pCronometroPiscada;
					Intervalo pIntervaloPiscada;

					void PlacaDelta::pHabilitar(){};

				public:
					PlacaDelta::PlacaDelta(UniversoDeTempo& universoDeTempo);
					PlacaDelta::~PlacaDelta();
					
					bool PlacaDelta::acenderLampada (int lampada);
					bool PlacaDelta::apagarLampada (int lampada);					
					bool PlacaDelta::piscarLampada (int lampada);
					int  PlacaDelta::getEstadoLampada (int lampada);
					bool PlacaDelta::getEstadoBotao (int botao);
					bool PlacaDelta::escreverDisplay (double valor);
					bool PlacaDelta::ligarMonitor (bool ligar);

					bool PlacaDelta::pulsarContador (int contador, int vezes);
					
					void PlacaDelta::limparBotoes ();

					Executavel& PlacaDelta::executa ();

					void PlacaDelta::desligar();
					void PlacaDelta::ligar(const char* porta);
					void PlacaDelta::habilitarNotas (int notas){};

					enum Contador{
						ENTRADA_PLACA_DELTA=1,
						SAIDA_PLACA_DELTA=2
					};
					
					enum EstadoLampada{
						APAGADO=1,
						ACESO=2,
						PISCANDO=3
					};
			};

		}
	}
}

#endif