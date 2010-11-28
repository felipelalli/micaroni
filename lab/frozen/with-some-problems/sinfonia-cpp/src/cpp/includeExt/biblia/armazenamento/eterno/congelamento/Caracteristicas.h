/*
 * $RCSfile: Caracteristicas.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Caracteristicas_h)
#define Caracteristicas_h

#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/eterno/congelamento/Velocidade.h"
#include "biblia/armazenamento/eterno/congelamento/Contexto.h"
#include "biblia/armazenamento/eterno/congelamento/Seguranca.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		class Caracteristicas: public Objeto {
			private:
				bool Caracteristicas::pSomenteLeitura;
				Velocidade Caracteristicas::pVelocidade;
				Contexto Caracteristicas::pContexto;
				Seguranca Caracteristicas::pSeguranca;

			public:
				virtual const bool& Caracteristicas
						::somenteLeitura() const;
		};
	  }
	}
  }
}

#endif /* Caracteristicas_h */
