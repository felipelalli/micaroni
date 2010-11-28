/*
 * $RCSfile: Consequencia.h,v $
 * $Date: 2005/03/03 03:32:22 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Consequencia_h)
#define Consequencia_h

#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/evento/Situacao.h"
#include "biblia/dinamicas/sinfonia/concretizador/Resultado.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace concretizador {
		/**
		 * Agrupa uma Situação a um Resultado (Conjunto de Instruções
		 * específicas de um determinado Realizador).
		 */
		class Consequencia: public Objeto {
			private:
				Resultado* Consequencia::pResultado;
				Situacao* Consequencia::pSituacao;
		};
	  }
	}
  }
}

#endif /* Consequencia_h */
