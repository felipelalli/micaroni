/*
 * $RCSfile: FabricaDeGeradoresTemporizadores.h,v $
 * $Date: 2005/03/03 03:32:31 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeGeradoresTemporizadores_h)
#define FabricaDeGeradoresTemporizadores_h

#include "biblia/dinamicas/sinfonia/evento/geradoresci/FabricaDeGeradoresDeEventosComponenteInterno.h"
#include "biblia/dinamicas/sinfonia/evento/geradoresci/tempo/GeradorDeTemporizador.h"

using namespace biblia::dinamicas::sinfonia::evento::geradoresci;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
	    namespace geradoresci {
	      namespace tempo {
			class FabricaDeGeradoresTemporizadores
				:public FabricaDeGeradoresDeEventosComponenteInterno
			{

			};
		  }
		}
	  }
	}
  }
}

#endif /* FabricaDeGeradoresTemporizadores_h */
