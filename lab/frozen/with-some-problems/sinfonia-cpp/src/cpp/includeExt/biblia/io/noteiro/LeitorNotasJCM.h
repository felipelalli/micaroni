/*
 * $RCSfile: LeitorNotasJCM.h,v $
 * $Date: 2004/05/31 04:06:31 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef CLEITORNOTASJCM_H_SW
#define CLEITORNOTASJCM_H_SW

#include "biblia/io/noteiro/LeitorNotas.h"
using namespace biblia::io::noteiro;

#include "biblia/io/noteiro/util/CRC16JCM.h"
#include "biblia/io/noteiro/util/CRC16Smiles.h"
using namespace biblia::io::noteiro::util;

namespace biblia{

	namespace io{

		namespace noteiro{

			class LeitorNotasJCM : public LeitorNotas {

				private:
					int pNota;
					int pNotasHabilitadas;

					void LeitorNotasJCM::pCriarCom(const char* porta);
					void LeitorNotasJCM::pDestruirCom();

					void LeitorNotasJCM::pInicializar ();
					void LeitorNotasJCM::pVerBuffer (BYTE* buffer);
					int  LeitorNotasJCM::pQtsReais (int canal);

					bool LeitorNotasJCM::makeComm (BYTE* buffer, BYTE command, BYTE* data, int tamanhoData);					

					void LeitorNotasJCM::pHabilitar();

				public:
					LeitorNotasJCM::LeitorNotasJCM (UniversoDeTempo& universoDeTempo,const char* porta);
					LeitorNotasJCM::~LeitorNotasJCM ();

					Executavel& LeitorNotasJCM::executa ();					

					void LeitorNotasJCM::ligar(const char* porta);
					void LeitorNotasJCM::desligar();
					void LeitorNotasJCM::habilitarNotas (int notas);

				private:

					enum Constantes{

						  /*******MENSAGENS DO CONTROLE**********/

						  //STATUS************
						  CONTROL_STATUS=0x11,

						  //RESPONSE TO [VEND VALID]
						  CONTROL_ACK   =0x50,

						  //OPERATION COMMAND*************
						  CONTROL_RESET				=0x40,
						  CONTROL_STACK1			=0x41,
						  CONTROL_STACK2			=0x42,
						  CONTROL_RETURN			=0x43,
						  CONTROL_HOLD				=0x44,
						  CONTROL_WAIT				=0x45,
						  CONTROL_PROGRAM_SIGNATURE =0xDC,

						  //SET COMMAND****************
						  CONTROL_SET_ENABLE     =0xC0,
						  CONTROL_SET_SECURITY   =0xC1,
						  CONTROL_SET_INHIBIT    =0xC3,
						  CONTROL_SET_DIRECTION  =0xC4,
						  CONTROL_SET_OPTIONAL   =0xC5,
						  CONTROL_SET_BARCODE    =0XC6,
						  CONTROL_SET_BAR_INHIBIT=0xC7,

						  //GET COMMAND********************
						  CONTROL_GET_ENABLE         =0x80,
						  CONTROL_GET_SECURITY       =0x81,
						  CONTROL_GET_INHIBIT        =0x83,
						  CONTROL_GET_DIRECTION      =0x84,
						  CONTROL_GET_OPTIONAL       =0x85,
						  CONTROL_GET_VERSION        =0x88,
						  CONTROL_GET_BOOT_VERSION   =0x89,
						  CONTROL_CURRENCY_ASSIGNMENT=0x8A,



						  /**********MENSAGENS DO ACCEPTOR*************/

						  //STATUS-NORMAL**********************
						  ACCEPTOR_ENABLE                =0x11,
						  ACCEPTOR_ACCEPTING             =0x12,
						  ACCEPTOR_ESCROW                =0x13,
						  ACCEPTOR_STAKING               =0x14,
						  ACCEPTOR_VEND_VALID            =0x15,
						  ACCEPTOR_STACKED               =0x16,
						  ACCEPTOR_REJECTING             =0x17,
						  ACCEPTOR_RETURNING             =0x18,
						  ACCEPTOR_HOLDING               =0x19,
						  ACCEPTOR_DISABLE               =0x1A,
						  ACCEPTOR_INITIALIZING          =0x1B,
						  //STATUS-POWER-UP********************
						  ACCEPTOR_POWER_UP              =0x40,
						  ACCEPTOR_POWER_UP_BILL_ACCEPTOR=0x41,
						  ACCEPTOR_POWER_UP_BILL_STACKER =0x42,
						  //STATUS-ERROR***********************
						  ACCEPTOR_STACKER_FULL          =0x43,
						  ACCEPTOR_STACKER_OPEN          =0x44,
						  ACCEPTOR_JAM_ACCEPTOR          =0x45,
						  ACCEPTOR_JAM_STACKER           =0x46,
						  ACCEPTOR_PAUSE                 =0x47,
						  ACCEPTOR_CHEATED               =0x48,
						  ACCEPTOR_FAILURE               =0x49,
						  ACCEPTOR_COMMUNICATION_ERROR   =0x4A,

						  //RESPONSE TO OPERATION COMMAND
						  ACCEPTOR_ACK    =0x50,
						  ACCEPTOR_INVALID=0x4B,

						  //RESPONSE TO SET COMMAND***
						  ACCEPTOR_SET_ENABLE      =0xC0,
						  ACCEPTOR_SET_SECURITY    =0xC1,
						  ACCEPTOR_SET_INHIBIT     =0xC3,
						  ACCEPTOR_SET_DIRECTION   =0xC4,
						  ACCEPTOR_SET_OPTIONAL    =0xC5,
						  ACCEPTOR_SET_BARCODE     =0XC6,
						  ACCEPTOR_SET_BAR_INHIBIT=0xC7,

						  //RESPONSE TO GET COMMAND******
						  ACCEPTOR_GET_ENABLE      =0x80,
						  ACCEPTOR_GET_SECURITY    =0x81,
						  ACCEPTOR_GET_INHIBIT     =0x83,
						  ACCEPTOR_GET_DIRECTION   =0x84,
						  ACCEPTOR_GET_OPTIONAL    =0x85,
						  ACCEPTOR_GET_VERSION     =0x88,
						  ACCEPTOR_GET_BOOT_VERSION=0x89,

						  VAZIO=0x00
					};
					Constantes pStatusRequest;
			};
		}
	}
}
#endif
