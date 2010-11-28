/*
 * $RCSfile: TransportaParaLixeira.h,v $
 * $Date: 2005/03/03 03:32:38 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TransportaParaLixeira_h)
#define TransportaParaLixeira_h

#include "biblia/util/Lixeira.h"
#include "biblia/dinamicas/sinfonia/evento/TransportadorDeEvento.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

using namespace biblia::util;
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace maestro {
			class TransportaParaLixeira: public TransportadorDeEvento {
				private:
					Lixeira* TransportaParaLixeira::pLixeira;

				public:
					virtual TransportadorDeEvento&
							TransportaParaLixeira::envia(Evento&);

			};
		}
	  }
	}
  }
}

#endif /* TransportaParaLixeira_h */
