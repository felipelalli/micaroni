/*
 * $RCSfile: DistribuidorDeEventos.h,v $
 * $Date: 2005/03/03 03:32:27 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(DistribuidorDeEventos_h)
#define DistribuidorDeEventos_h

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/evento/TransportadorDeEvento.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Através de Transportadores de Eventos
		 * consome e envia os Eventos
		 * para quem necessita.
		 */
		class DistribuidorDeEventos
				:public Executavel,
				 public TransportadorDeEvento,
				 public Objeto
		{
			private:
				std::deque<TransportadorDeEvento*>
						DistribuidorDeEventos
							::pTransportadorDeEvento;

			public:
				Executavel& DistribuidorDeEventos::executa();
				TransportadorDeEvento& DistribuidorDeEventos
						::envia(Evento&);

		};
	  }
	}
  }
}

#endif /* DistribuidorDeEventos_h */
