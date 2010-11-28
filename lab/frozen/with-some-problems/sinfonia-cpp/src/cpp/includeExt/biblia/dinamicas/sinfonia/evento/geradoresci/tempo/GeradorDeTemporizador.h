/*
 * $RCSfile: GeradorDeTemporizador.h,v $
 * $Date: 2005/03/03 03:32:31 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(GeradorDeTemporizador_h)
#define GeradorDeTemporizador_h

#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventosComponenteInterno.h"
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
	    namespace geradoresci {
	      namespace tempo {
			class GeradorDeTemporizador
					:public GeradorDeEventosComponenteInterno
			{

			};
		  }
		}
	  }
	}
  }
}

#endif /* GeradorDeTemporizador_h */
