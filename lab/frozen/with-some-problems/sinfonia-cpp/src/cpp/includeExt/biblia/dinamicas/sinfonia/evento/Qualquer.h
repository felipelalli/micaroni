/*
 * $RCSfile: Qualquer.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * Cont�m uma identifica��o *constante* que o identifica como um
		 * Evento qualquer. --- usado para compara��es, n�o faria sentido
		 * ser "lan�ado" por um gerador de eventos.
		 * <p>
		 * � um Evento Especial assim como o Evento Sempre.
		 */
		class Qualquer: public Evento {

		};
	  }
	}
  }
}

#endif /* Qualquer_h */
