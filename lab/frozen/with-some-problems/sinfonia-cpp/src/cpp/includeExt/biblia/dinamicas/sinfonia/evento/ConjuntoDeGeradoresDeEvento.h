/*
 * $RCSfile: ConjuntoDeGeradoresDeEvento.h,v $
 * $Date: 2005/03/03 03:32:27 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConjuntoDeGeradoresDeEvento_h)
#define ConjuntoDeGeradoresDeEvento_h

#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Possui um ou mais Geradores de Eventos.
		 */
		class ConjuntoDeGeradoresDeEvento: public GeradorDeEventos {
			private:
				GeradorDeEventos* ConjuntoDeGeradoresDeEvento
						::pGeradorDeEventos;
		};
	  }
	}
  }
}

#endif /* ConjuntoDeGeradoresDeEvento_h */
