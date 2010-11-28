/*
 * $RCSfile: MediadorDeEstados.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(MediadorDeEstados_h)
#define MediadorDeEstados_h

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/evento/FabricaDeEstadosConstantes.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::estado;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * O MediadorDeEstado serve como um mediador ao acesso e mudanças
		 * dos Estados para que se garanta a criação (ou existência) de um
		 * Evento para a mudança do Estado.
		 */
		class MediadorDeEstados: public Objeto {
			private:
				std::deque<Estado*> MediadorDeEstados::pDetem;
				FabricaDeEstadosConstantes	*theFabricaDeEstadosConstantes;

			public:
				virtual MediadorDeEstados& MediadorDeEstados
						::modifica(Evento&);
		};
	  }
	}
  }
}

#endif /* MediadorDeEstados_h */
