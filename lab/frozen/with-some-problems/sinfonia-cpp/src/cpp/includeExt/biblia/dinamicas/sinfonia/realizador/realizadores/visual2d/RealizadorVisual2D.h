/*
 * $RCSfile: RealizadorVisual2D.h,v $
 * $Date: 2005/03/03 03:32:35 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(RealizadorVisual2D_h)
#define RealizadorVisual2D_h

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
	      namespace visual2d {
			/**
			 * Entende um conjunto de instruções específico.
			 */
			class RealizadorVisual2D
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

#endif /* RealizadorVisual2D_h */
