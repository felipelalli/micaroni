/*
 * $RCSfile: GeradorDeEventos.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(GeradorDeEventos_h)
#define GeradorDeEventos_h

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::dinamicas::sinfonia::estado;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Gera eventos descart�veis.
		 */
		class GeradorDeEventos
				:public Objeto,
				 public Executavel
		{
			public:
				GeradorDeEventos& GeradorDeEventos
						::esperaAteQueHajaEvento();
		};
	  }
	}
  }
}

#endif /* GeradorDeEventos_h */
