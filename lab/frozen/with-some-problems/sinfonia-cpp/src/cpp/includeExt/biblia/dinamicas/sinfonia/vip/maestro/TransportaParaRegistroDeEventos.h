/*
 * $RCSfile: TransportaParaRegistroDeEventos.h,v $
 * $Date: 2005/03/03 03:32:39 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TransportaParaRegistroDeEventos_h)
#define TransportaParaRegistroDeEventos_h

#include "biblia/dinamicas/sinfonia/evento/TransportadorDeEvento.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/evento/RegistroDeEventos.h"

using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace maestro {
			class TransportaParaRegistroDeEventos
					:public TransportadorDeEvento
			{
				private:
					RegistroDeEventos*
							TransportaParaRegistroDeEventos
								::pRegistroDeEventos;
 
				private:
					TransportadorDeEvento&
							TransportaParaRegistroDeEventos
								::envia(Evento&);
			};
		}
	  }
	}
  }
}

#endif /* TransportaParaRegistroDeEventos_h */
