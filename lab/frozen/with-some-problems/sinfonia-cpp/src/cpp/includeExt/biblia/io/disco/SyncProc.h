/*
 * $RCSfile: SyncProc.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SYNC_PROC_H
#define SYNC_PROC_H

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/disco/ArquivoBasico.h"

namespace biblia{

	namespace io{

		namespace disco{

			class SyncProc : public Executavel{

				private:
					Semaforo* pSemaforo;
					Thread* pMinhaThread;

				public:
					SyncProc::SyncProc();
					SyncProc::~SyncProc();
					void SyncProc::sync();
					Executavel& SyncProc::executa ();
			};

		}
	}
}

#endif