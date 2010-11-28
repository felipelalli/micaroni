/*
 * $RCSfile: InstrucaoSonora.h,v $
 * $Date: 2005/03/03 03:32:34 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(InstrucaoSonora_h)
#define InstrucaoSonora_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/realizador/realizadores/sonoro/AparelhoDeSom.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace realizador {
	    namespace realizadores {
	      namespace sonoro {
			/**
			 * Para a cria��o das instru��es espec�ficas do AparelhoDeSom.
			 */
			class InstrucaoSonora: public Objeto {
				private:
					ConjuntoDeInstrucoes* InstrucaoSonora
							::pConjuntoDeInstrucoesString;
			};
		  }
		}
	  }
	}
  }
}

#endif /* InstrucaoSonora_h */
