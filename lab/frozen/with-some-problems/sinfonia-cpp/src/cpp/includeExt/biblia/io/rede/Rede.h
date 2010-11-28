/*
 * $RCSfile: Rede.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef REDE_SW_H
#define REDE_SW_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/SecureMessage.h"
using namespace biblia::seguranca;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/util/Debug.h"
using namespace biblia::util;


#include <time.h>
#include <stdlib.h>

#ifdef WIN32
	#include <winsock.h>
#else
	#include <signal.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <stdio.h>
	#include <sys/un.h>
	#include <unistd.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
#endif

namespace biblia{
	namespace io{
		namespace rede{

		static int qtsConexoes = 0;
		static Semaforo pSema (1);

		}
	}
}




#define SLEEP_POOLING              1000 //Intevalo de tempo esperando pelo cliente para checar o servidor
#define SLEEP_SINCRONIZACAO         500 //Intevalo de tempo entre uma verificacao de sincronizacao e outro
#define PERIODO_MAX_SINCRONIZACAO 10000 //Periodo maximo em que a maquina fica tentando sincronizar

#define BUFFER_SIZE      500  // Tamanho maximo de pacotes recebimento
#define TIMEOUT_RECEIVE 10000 // Limite de espera de um recv 1 segundo (nao deve ser mais baixo que isso)
#define TIMEOUT_CONEXAO 1000  // Limite de tempo espernado uma conexao

#define TIMEOUT_FALHA_REDE 60 //Tempo limite para indicar para o resto do programa que esta em falha de rede


namespace biblia{
	namespace io{
		namespace rede{

			class Rede: public Objeto {

				private:
					static void Rede::pBrokenPipe(int);

				protected:

					int  pPorta;
					char pIP[200];
					int  pSocket;
					ChaveSeguranca* pChaveSeguranca;

					char pMsgErro [200];

					Rede::Rede(ChaveSeguranca* chaveSeguranca);
					Rede::Rede(const char* ip,int porta, ChaveSeguranca* chaveSeguranca);

					virtual int Rede::enviar(char* buffer, int tamanho);
					virtual int Rede::receber(char* buffer, int tamanho);

					bool Rede::deuErro(int result);


					static long	Rede::pVezes;

					static void Rede::inicializar();
					static void Rede::terminar();

					static int Rede::comparaIP(const char* ip1, const char* ip2);

				public:
					virtual Rede::~Rede();
					static bool Rede::mesmoIP(const char* ip1,const char* ip2);
			};
		}
	}
}

#endif
