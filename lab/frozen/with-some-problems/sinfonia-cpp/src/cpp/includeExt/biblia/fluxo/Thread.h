/*
 * $RCSfile: Thread.h,v $
 * $Date: 2005/03/31 23:41:43 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef Thread_SW_H
#define Thread_SW_H

#ifdef WIN32
	#include <windows.h>
	#include <winbase.h>
#else
	#include <pthread.h>
	#include <unistd.h>
#endif

#include <deque>
#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/tempo/Intervalo.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
  namespace fluxo {
	class ThreadExcecao: public Excecao {
		public:
			ThreadExcecao(const string& msg) {
				(*this) << msg;
			}
	};

#ifndef WIN32
	void* myThread(void* arg);
#else
	DWORD WINAPI myThread(void* arg);
#endif

	/**
	 * Quebra o fluxo de execução em dois,
	 * apoiado em um {@link biblia::fluxo::Executavel}.
	 *
	 * @see biblia::fluxo::Executavel
	 */
	class Thread: public Objeto {
#ifndef WIN32
		friend void* myThread(void* arg);
#else
		friend DWORD WINAPI myThread(void* arg);
#endif

		private:
			Executavel& Thread::pExecutavel;
			std::string pNomeThread;
			deque<bool> pAcabou;
			int pQuantasThreads;
			ThreadExcecao* pExcecaoLancada;

#ifdef WIN32
			DWORD pThreadID;
			HANDLE pHThread;
#else
			pthread_t pThreadID;
#endif
		public:
			/**
			 * Executa em Thread e retorna 0 se
			 * foi executado com sucesso ou o código
			 * do erro (> 0) caso tenha ocorrido algum erro.
			 */
			int Thread::start();
			static void Thread::sleep(const Intervalo&);
			static void Thread::sleep(const int& milissegundos);

			/**
			 * Se o nome for omitido, ele pega o typeid(...).name()
			 * do executável passado.
			 */
			Thread::Thread(Executavel&, const string& nome = "_");
			virtual Thread::~Thread();

			virtual Executavel& Thread::executavel() const;

			/**
			 * Retorna o número de threads em execução baseado
			 * nesta instância.
			 */
			virtual const int& quantasThreads() const;

			/**
			 * Se alguma exceção é lançada em thread, esta é
			 * lançada nesta função. Chame sempre esta função
			 * num loop caso queira que a exceção da thread
			 * seja lançado no fluxo principal.
			 *
			 * @throws ThreadExcecao
			 */
			virtual const Thread& monitoraExcecao() const;

			// Objeto:
			string emString() const;
	};
  }
}

#endif





