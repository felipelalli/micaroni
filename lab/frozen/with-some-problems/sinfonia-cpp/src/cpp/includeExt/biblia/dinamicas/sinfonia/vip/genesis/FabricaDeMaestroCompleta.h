/*
 * $RCSfile: FabricaDeMaestroCompleta.h,v $
 * $Date: 2005/03/03 03:32:37 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeMaestroCompleta_h)
#define FabricaDeMaestroCompleta_h

#include "biblia/dinamicas/sinfonia/vip/maestro/FabricaDeMaestro.h"
using namespace biblia::dinamicas::sinfonia::vip::maestro;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace genesis {
			/**
			 * Usa quem precisar usar para criar um Maestro.
			 */
			class FabricaDeMaestroCompleta: public FabricaDeMaestro {

			};
		}
	  }
	}
  }
}

#endif /* FabricaDeMaestroCompleta_h */
