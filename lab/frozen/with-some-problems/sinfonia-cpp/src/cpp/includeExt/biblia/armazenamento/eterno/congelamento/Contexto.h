/*
 * $RCSfile: Contexto.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Contexto_h)
#define Contexto_h

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		/**
		 * Universal/Rede/Local
		 * 
		 * volatil/eterno
		 */
		class Contexto: public Objeto {

		};
	  }
	}
  }
}

#endif /* Contexto_h */
