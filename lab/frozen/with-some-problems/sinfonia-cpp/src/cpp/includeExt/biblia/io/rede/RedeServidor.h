/*
 * $RCSfile: RedeServidor.h,v $
 * $Date: 2005/01/20 21:28:43 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef REDESERVIDOR_SW_H
#define REDESERVIDOR_SW_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifdef WIN32
	#include <io.h>
#endif

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>



#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/rede/Rede.h"
#include "biblia/io/rede/RequisicaoRede.h"
#include "biblia/io/rede/GerenciadorInterface.h"
#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia{

	namespace io{

		namespace rede{

			class RedeServidor : public Executavel,
								 public Rede,
								 public GerenciadorInterface
			{
				private:

					struct timeval pTimeout;
					fd_set         pConnState;
					fd_set         pConn;

					Thread* pMinhaThread;

					bool pTerminar;
					bool pTerminou;
					bool pReiniciar;
					bool pFalhaDeRede;

					biblia::armazenamento::volatil::Lista* pLstRequisicoes;

					void RedeServidor::pLimparListaRequisicoes();
					bool RedeServidor::pAtualizarConfiguracoes();
					void RedeServidor::pCriarSocket();
					void RedeServidor::pFecharSocket();

				public:

					RedeServidor::RedeServidor(
									const char* ip        = "localhost",
									unsigned int porta    = 80,
									ChaveSeguranca* chave = NULL);

					virtual RedeServidor::~RedeServidor();

					Executavel& RedeServidor::executa();

					void RedeServidor::reiniciar(
										const char* ip     = "localhost",
										unsigned int porta = 80);

					bool RedeServidor::servidorAtivo();
			};
		}
	}
}

#endif
