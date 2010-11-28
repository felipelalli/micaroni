/*
 * $RCSfile: Concretizador.h,v $
 * $Date: 2005/03/03 03:32:22 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Concretizador_h)
#define Concretizador_h

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::dinamicas::sinfonia::estado;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace concretizador {

		/**
		 * Um Concretizador tem a fun��o de, a partir de um ou mais
		 * Estados, gerar (de forma qualquer/indefinida) um resultado
		 * percept�vel ao usu�rio.
		 */
		class Concretizador: 
				public Objeto, 
				public Executavel
		{

		};
	  }
	}
  }
}

#endif /* Concretizador_h */
