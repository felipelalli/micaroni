/*
 * $RCSfile: TransportadorDeEvento.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TransportadorDeEvento_h)
#define TransportadorDeEvento_h

#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Transporta um evento pra algum lugar.
		 */
		class TransportadorDeEvento: public Interface {
			public:
				virtual TransportadorDeEvento& TransportadorDeEvento
						::envia(Evento&) = 0;
		};
	  }
	}
  }
}

#endif /* TransportadorDeEvento_h */
