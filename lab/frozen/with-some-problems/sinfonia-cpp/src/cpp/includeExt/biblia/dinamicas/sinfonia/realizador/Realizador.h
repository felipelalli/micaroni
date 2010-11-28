/*
 * $RCSfile: Realizador.h,v $
 * $Date: 2005/03/03 03:32:33 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Realizador_h)
#define Realizador_h

#include "biblia/fluxo/Executavel.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"

using namespace biblia::fluxo;
using namespace biblia::util::instrucoes;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace realizador {
		/**
		 * Sabe interpretar um conjunto de instru��es espec�ficas.
		 */
		class Realizador: public Executavel {

		};
	  }
	}
  }
}

#endif /* Realizador_h */
