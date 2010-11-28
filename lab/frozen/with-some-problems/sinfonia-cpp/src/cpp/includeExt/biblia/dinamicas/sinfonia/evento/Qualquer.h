/*
 * $RCSfile: Qualquer.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Qualquer_h)
#define Qualquer_h

#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Contém uma identificação *constante* que o identifica como um
		 * Evento qualquer. --- usado para comparações, não faria sentido
		 * ser "lançado" por um gerador de eventos.
		 * <p>
		 * É um Evento Especial assim como o Evento Sempre.
		 */
		class Qualquer: public Evento {

		};
	  }
	}
  }
}

#endif /* Qualquer_h */
