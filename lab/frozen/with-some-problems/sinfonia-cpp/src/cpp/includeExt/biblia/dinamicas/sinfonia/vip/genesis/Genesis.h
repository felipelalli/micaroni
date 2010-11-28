/*
 * $RCSfile: Genesis.h,v $
 * $Date: 2005/03/03 03:32:37 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Genesis_h)
#define Genesis_h

#include "biblia/basico/Fabrica.h"
#include "biblia/dinamicas/sinfonia/vip/genesis/FabricaDeMaestroCompleta.h"

using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace genesis {
			/**
			 * � a F�brica da F�brica, onde tudo se inicia,
			 * tudo come�a, tudo se origina.
			 */
			class Genesis: public Fabrica {

			};
		}
	  }
	}
  }
}

#endif /* Genesis_h */
