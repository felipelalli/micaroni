/*
 * $RCSfile: RegistroDeEventos.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(RegistroDeEventos_h)
#define RegistroDeEventos_h

#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Registra um Evento de alguma forma.
		 */
		class RegistroDeEventos: public Objeto {
			public:
				virtual RegistroDeEventos& RegistroDeEventos
						::registra(Evento&);
		};
	  }
	}
  }
}

#endif /* RegistroDeEventos_h */
