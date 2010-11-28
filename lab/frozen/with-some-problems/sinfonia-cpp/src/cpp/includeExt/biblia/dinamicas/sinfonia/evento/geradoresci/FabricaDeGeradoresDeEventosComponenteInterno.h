/*
 * $RCSfile: FabricaDeGeradoresDeEventosComponenteInterno.h,v $
 * $Date: 2005/03/03 03:32:30 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeGeradoresDeEventosComponenteInterno_h)
#define FabricaDeGeradoresDeEventosComponenteInterno_h

#include "biblia/basico/Fabrica.h"
#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventosComponenteInterno.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		namespace geradoresci {
			class FabricaDeGeradoresDeEventosComponenteInterno
					:public Fabrica
			{

			};
		}
	  }
	}
  }
}

#endif /* FabricaDeGeradoresDeEventosComponenteInterno_h */
