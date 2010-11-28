/*
 * $RCSfile: Compartimento.h,v $
 * $Date: 2004/02/17 18:21:35 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Compartimento_h)
#define Compartimento_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/eterno/eternizacao/EternizadorDePacotes.h"
#include "biblia/armazenamento/eterno/congelamento/Caracteristicas.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::eterno::eternizacao;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		class Compartimento: public Objeto {
			private:
				Identificacao Compartimento::pId;

				EternizadorDePacotes* Compartimento
						::pEternizadorDePacotes;

				Caracteristicas* Compartimento
						::pCaracteristicas;
		};
	  }
	}
  }
}

#endif /* Compartimento_h */
