/*
 * $RCSfile: RedeCliente.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef REDE_CLIENTE_SW
#define REDE_CLIENTE_SW


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/io/rede/Rede.h"
#include "biblia/io/rede/ComunicadorRede.h"
using namespace biblia::io::rede;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/Cronometro.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/rede/interfaces/interfacesCliente/InterCliBaseRede.h"
using namespace biblia::io::rede::interfaces::interfacesCliente;

namespace biblia{
	namespace io{
		namespace rede{

			class RedeCliente:  public Rede,
							    public Executavel,
								public ComunicadorRede{

				private:

					InterCliBaseRede* pInterfaceBaseRede;

					bool pConnected;

					Thread* pMinhaThread;

					bool pTerminar;
					bool pTerminou;

					Cronometro pCronometro;

					Semaforo* pSemaComm;

					bool RedeCliente::pConectar();
					void RedeCliente::pAbrirSocket();
					void RedeCliente::pFecharSocket();

				public:
					RedeCliente::RedeCliente(
									UniversoDeTempo& universo,
									const char* ip        = "localhost",
									unsigned int porta    = 80,
									ChaveSeguranca* chave = NULL);

					virtual RedeCliente::~RedeCliente();

					Executavel& RedeCliente::executa();

					void RedeCliente::terminar();
					bool RedeCliente::terminou();

					bool RedeCliente::conectado();

					int RedeCliente::makeComm(char* buffer,int tamanho);
			};
		}
	}
}

#endif
