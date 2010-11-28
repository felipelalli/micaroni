/*
 * $RCSfile: RequisicaoRede.h,v $
 * $Date: 2005/01/20 21:28:44 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef REQUISICAO_REDE_SW_H
#define REQUISICAO_REDE_SW_H


#include <stdio.h>
#include <stdlib.h>
#include <string>
#ifdef WIN32
#include <io.h>
#endif
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "biblia/io/rede/Rede.h"
#include "biblia/io/rede/GerenciadorInterface.h"
using namespace biblia::io::rede;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Thread.h"
using namespace biblia::fluxo;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

namespace biblia{
	namespace io{
		namespace rede{

			class RequisicaoRede :	public Rede,
									public Executavel{
				private:
					ChaveSeguranca* pChaveSeguranca;

					Thread* pMinhaThread;

					GerenciadorInterface* pInterfaces;

					bool pTerminou;
					bool pTerminar;

				public:
					RequisicaoRede::RequisicaoRede(	int cSocket = -1,
													char* ipCliente = "localhost",
													GerenciadorInterface* interfaces = NULL,
													ChaveSeguranca* chaveSeguranca   = NULL);

					virtual RequisicaoRede::~RequisicaoRede();

					Executavel& RequisicaoRede::executa();

					bool RequisicaoRede::terminou();
					void RequisicaoRede::terminar();
			};
		}
	}
}

#endif
