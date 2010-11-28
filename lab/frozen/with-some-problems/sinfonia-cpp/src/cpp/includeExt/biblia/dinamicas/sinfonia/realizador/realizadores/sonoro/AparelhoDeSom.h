/*
 * $RCSfile: AparelhoDeSom.h,v $
 * $Date: 2005/03/03 03:32:34 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AparelhoDeSom_h)
#define AparelhoDeSom_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/realizador/Realizador.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;
using namespace biblia::dinamicas::sinfonia::realizador;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace realizador {
	    namespace realizadores {
	      namespace sonoro {
			/**
			 * Sabe tocar a partir de algumas instruções específicas.
			 */
			class AparelhoDeSom
				:public Realizador,
				 public Objeto
			{

			};
		  }
		}
	  }
	}
  }
}

#endif /* AparelhoDeSom_h */
