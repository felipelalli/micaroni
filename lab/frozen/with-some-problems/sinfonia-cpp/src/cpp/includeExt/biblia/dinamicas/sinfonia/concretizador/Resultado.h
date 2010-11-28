/*
 * $RCSfile: Resultado.h,v $
 * $Date: 2005/03/03 03:32:23 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Resultado_h)
#define Resultado_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/realizador/Realizador.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;
using namespace biblia::dinamicas::sinfonia::realizador;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace concretizador {
		class Resultado: public Objeto {
			private:
				ConjuntoDeInstrucoes* Resultado::pInstrucoes;
				Realizador* Resultado::pAssociadoA;
		};
	  }
	}
  }
}

#endif /* Resultado_h */
