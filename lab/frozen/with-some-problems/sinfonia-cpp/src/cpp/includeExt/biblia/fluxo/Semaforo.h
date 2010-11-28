/*
 * $RCSfile: Semaforo.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef Semaforo_SW_H
#define Semaforo_SW_H

#include "biblia/util/Debug.h"

#ifdef WIN32
	#include <windows.h>
	#include <winbase.h>
#else
	#include <semaphore.h>
	//#include <sys/sem.h>
	//#include <sys/types.h>
	//#include <sys/ipc.h>
	////#include <pthread.h> mutex

#endif

#ifdef WIN32
#define MAX_SEMAFOROS 500
#endif

namespace biblia {
  namespace fluxo {

	/**
	 * Implementa um semáforo mutex.
	 */
	class Semaforo {

		private:

	#ifdef WIN32
			HANDLE pSemaforo;
	#else
			sem_t pSemaforo;
			//pthread_mutex_t work_mutex;

	#endif

		public:
			Semaforo::Semaforo(int valorInicial);
			Semaforo::~Semaforo();

			bool Semaforo::esperar(bool block = true);
			void Semaforo::liberar();
	};
  }
}

#endif
