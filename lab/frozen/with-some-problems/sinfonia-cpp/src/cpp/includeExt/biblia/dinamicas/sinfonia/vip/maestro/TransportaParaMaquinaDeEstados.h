/*
 * $RCSfile: TransportaParaMaquinaDeEstados.h,v $
 * $Date: 2005/03/03 03:32:38 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TransportaParaMaquinaDeEstados_h)
#define TransportaParaMaquinaDeEstados_h

#include "biblia/dinamicas/sinfonia/evento/TransportadorDeEvento.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/vip/maquinadeestados/MaquinaDeEstados.h"

using namespace biblia::dinamicas::sinfonia::evento;
using namespace biblia::dinamicas::sinfonia::vip::maquinadeestados;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace maestro {
			class TransportaParaMaquinaDeEstados
					:public TransportadorDeEvento
			{
				private:
					MaquinaDeEstados*
							TransportaParaMaquinaDeEstados
								::pMaquinaDeEstados;

				public:
					virtual TransportadorDeEvento&
							TransportaParaMaquinaDeEstados
								::envia(Evento&);
			};
		}
	  }
	}
  }
}

#endif /* TransportaParaMaquinaDeEstados_h */
