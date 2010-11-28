/*
 * $RCSfile: Instrucao2D.h,v $
 * $Date: 2005/03/03 03:32:35 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Instrucao2D_h)
#define Instrucao2D_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/realizador/realizadores/visual2d/RealizadorVisual2D.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace realizador {
	    namespace realizadores {
	      namespace visual2d {
			/**
			 * Usado para criação de comandos específicos para o
			 * RealizadorVisual2D.
			 */
			class Instrucao2D: public Objeto {
				private:
					ConjuntoDeInstrucoes* Instrucao2D
							::pConjuntoDeInstrucoesString;
			};
		  }
		}
	  }
	}
  }
}

#endif /* Instrucao2D_h */
