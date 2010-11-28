/**
 * $RCSfile: Lock.h,v $
 * $Date: 2005/03/24 14:03:21 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_LOCK_H__0892701D_C459_4458_9E47_D6D3D5494B0A__INCLUDED_)
#define AFX_LOCK_H__0892701D_C459_4458_9E47_D6D3D5494B0A__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/util/Debug.h>
using namespace biblia::util;

#include <biblia/fluxo/Semaforo.h>
using namespace biblia::fluxo;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace util {
	/**
	 * Serve para garantir a execução por uma thread de cada vez,
	 * equivalente à palavra-chave <b>synchronized</b> em Java.
	 * <p>
	 * Deve ser usado assim:
	 * <br><pre>
	int Classe::funcao() {
		static Semaforo s(1);
		Lock lock(s);
		int valor = 10;

		// ...
		// codigo

		return valor;
	}
	   </pre>
	 * <p>
	 * Retirado do documento "Object-Oriented Programming" encontrado em
	 * "http://www.cs.utexas.edu/users/lavender/courses/cs371/lectures/lecture-10.pdf"
	 * e copiado para "CVS/ages/doc/mais/thread/lecture-10 - Sincronização de Thread em C++.pdf".
	 */
	class Lock: public Objeto {
		private:
			Semaforo& semaforo;

		public:
			Lock(Semaforo&);
			virtual ~Lock();
	};
   }
  }
 }
}

#endif // !defined(AFX_LOCK_H__0892701D_C459_4458_9E47_D6D3D5494B0A__INCLUDED_)
