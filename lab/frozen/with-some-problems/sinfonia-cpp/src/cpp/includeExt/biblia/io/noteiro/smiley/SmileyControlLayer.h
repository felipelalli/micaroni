/*
 * $RCSfile: SmileyControlLayer.h,v $
 * $Date: 2004/06/16 00:31:24 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SMILEY_CONTROL_LAYER_H
#define SMILEY_CONTROL_LAYER_H

#include "biblia/io/noteiro/smiley/ComandosSmiley.h"
#include "biblia/io/noteiro/smiley/EventosSmiley.h"
#include "biblia/io/noteiro/smiley/SmileyTransportLayer.h"
#include "biblia/io/noteiro/smiley/InformacoesSmiley.h"
using namespace biblia::io::noteiro::smiley;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;


namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

				class SmileyControlLayer :	public SmileyTransportLayer,
											public InformacoesSmiley,
											public Executavel{

					private:
						
						Thread* pThread;
						bool pTerminar;
						bool pTerminou;

						Semaforo pSemaEventos;
						biblia::armazenamento::volatil::Lista pLstEventos;
						void SmileyControlLayer::pAdicionaEvento(EventoID* evento);

						Semaforo pSemaComandos;
						biblia::armazenamento::volatil::Lista pLstComandos;
						bool      SmileyControlLayer::pHaComando();
						EventoID* SmileyControlLayer::pConsomeComando();

						BYTE pBuffer [200];
						
						void SmileyControlLayer::pExecutaComando(EventoID* comando);
						bool SmileyControlLayer::pExecutouComando();

						bool pComunicacaoOk;
						bool pReset;

						void SmileyControlLayer::pInicia();

						enum Constantes{

							/**********MENSAGENS DO CONTROLADOR*************/
							//GENERAL COMMAND
							CONTROL_RESET           = 0x01,
							CONTROL_PROTOCOL_VERSION= 0x06,
							CONTROL_POLL            = 0x07,
							CONTROL_GET_SERIAL      = 0x0C,
							CONTROL_SYNC            = 0x11,
							CONTROL_DISABLE         = 0x09,
							CONTROL_ENABLE          = 0x0A,
							CONTROL_FIRMWARE        = 0x0B,
							CONTROL_MANU_EXTENSION  = 0x30,
							//BANKNOTE VALIDATOR COMMANDS
							CONTROL_INHIBITS        = 0x02,
							CONTROL_DISPLAY_ON      = 0x03,
							CONTROL_DISPLAY_OFF     = 0x04,
							CONTROL_SET_UP_REQUEST  = 0x05,
							CONTROL_REJECT          = 0x08,
							CONTROL_UNIT_DATA       = 0x0D,
							CONTROL_CHANNEL_VALUE   = 0x0E,
							CONTROL_CHANNEL_SECURITY= 0x0F,
							CONTROL_CHANNEL_RE_TEACH= 0x10,
							CONTROL_LAST_REJECT_CODE= 0x17,
							CONTROL_HOLD            = 0x18,

							/**********MENSAGENS DO ACCEPTOR*************/
							//GENERAL COMMAND RESPONSES
							ACCEPTOR_OK             = 0xF0,
							ACCEPTOR_NOT_KNOWN      = 0xF2,
							ACCEPTOR_WRONG_PARAM    = 0xF3,
							ACCEPTOR_PARAM_OUT_RANGE= 0xF4,
							ACCEPTOR_CANNOT_PROCESS = 0xF5,
							ACCEPTOR_SOFT_ERROR     = 0xF6,
							ACCEPTOR_FAIL           = 0xF8,
							//RESPONSE TO POLLS
							ACCEPTOR_SLAVE_RESET = 0xF1,
							ACCEPTOR_READ        = 0xEF,
							ACCEPTOR_CREDIT      = 0xEE,
							ACCEPTOR_REJECTING   = 0xED,
							ACCEPTOR_REJECTED    = 0xEC,
							ACCEPTOR_STACKING    = 0xCC,
							ACCEPTOR_STACKED     = 0xEB,
							ACCEPTOR_SAFE_JAM    = 0xEA,
							ACCEPTOR_UNSAFE_JAM  = 0xE9,
							ACCEPTOR_DISABLED    = 0xE8,
							ACCEPTOR_FRAUD_ATTEMP= 0xE6,
							ACCEPTOR_STACKER_FULL= 0xE7
						};						
						

					public:
						SmileyControlLayer::SmileyControlLayer(const char* porta);
						virtual SmileyControlLayer::~SmileyControlLayer();

						Executavel& SmileyControlLayer::executa ();

						bool SmileyControlLayer::haEvento();
						EventoID* SmileyControlLayer::consomeEvento();

						void SmileyControlLayer::adicionaComando(EventoID* comando);

						//COMANDOS GENERICOS
						bool SmileyControlLayer::reset();						
						bool SmileyControlLayer::poll(); //Eventos recebidos sao colocados na lista de eventos
						bool SmileyControlLayer::getSerialNumber();
						bool SmileyControlLayer::sync();
						bool SmileyControlLayer::disable();
						bool SmileyControlLayer::enable();

						//COMANDOS ESPECIFICOS LEITOR DE NOTAS
						bool SmileyControlLayer::setInhibits (int canais);
						bool SmileyControlLayer::displayOn();
						bool SmileyControlLayer::displayOff();
						bool SmileyControlLayer::setUpRequest();
						bool SmileyControlLayer::reject();
						bool SmileyControlLayer::unitData();
						bool SmileyControlLayer::channelValueData();
						bool SmileyControlLayer::channelSecurityData();
						bool SmileyControlLayer::channelReTeachDAta();
						bool SmileyControlLayer::lastRejectCode();
						bool SmileyControlLayer::hold();

						bool SmileyControlLayer::controlLayerOk();

				};
			}
		}
	}
}

#endif