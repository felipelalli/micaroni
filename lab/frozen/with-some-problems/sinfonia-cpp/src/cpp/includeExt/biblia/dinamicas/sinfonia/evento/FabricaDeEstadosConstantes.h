/*
 * $RCSfile: FabricaDeEstadosConstantes.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeEstadosConstantes_h)
#define FabricaDeEstadosConstantes_h

#include "biblia/dinamicas/sinfonia/estado/Estado.h"
#include "biblia/dinamicas/sinfonia/estado/Congelador.h"
#include "biblia/dinamicas/sinfonia/estado/origem/FabricaDeEstados.h"

using namespace biblia::dinamicas::sinfonia::estado;
using namespace biblia::dinamicas::sinfonia::estado::origem;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		class FabricaDeEstadosConstantes
				:public FabricaDeEstados
		{
			public:
				Congelador* FabricaDeEstadosConstantes
						::pCongelador;
		};
	  }
	}
  }
}

#endif /* FabricaDeEstadosConstantes_h */
