/*
 * $RCSfile: FabricaDeGeradoresAnimacao.h,v $
 * $Date: 2005/03/03 03:32:32 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeGeradoresAnimacao_h)
#define FabricaDeGeradoresAnimacao_h

#include "biblia/dinamicas/sinfonia/evento/geradoresci/FabricaDeGeradoresDeEventosComponenteInterno.h"
#include "biblia/dinamicas/sinfonia/evento/geradoresci/visual2d/GeradorBaseadoEmAnimacao.h"

using namespace biblia::dinamicas::sinfonia::evento::geradoresci;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
	    namespace geradoresci {
	      namespace visual2d {
			class FabricaDeGeradoresAnimacao
					:public FabricaDeGeradoresDeEventosComponenteInterno
			{

			};
		  }
		}
	  }
	}
  }
}

#endif /* FabricaDeGeradoresAnimacao_h */
