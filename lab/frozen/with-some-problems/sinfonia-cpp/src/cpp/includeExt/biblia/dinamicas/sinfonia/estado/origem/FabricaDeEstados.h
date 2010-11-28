/*
 * $RCSfile: FabricaDeEstados.h,v $
 * $Date: 2005/03/03 03:32:26 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeEstados_h)
#define FabricaDeEstados_h

#include "biblia/basico/Fabrica.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::estado;
using namespace biblia::armazenamento::volatil::carcacas::composto;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
      namespace estado {
	    namespace origem {
			class FabricaDeEstados: public Fabrica {
				private:
					ConhecedorDeCompostos*
							FabricaDeEstados
								::pConhecedorDeCompostos;
			};
		}
	  }
	}
  }
}

#endif /* FabricaDeEstados_h */
