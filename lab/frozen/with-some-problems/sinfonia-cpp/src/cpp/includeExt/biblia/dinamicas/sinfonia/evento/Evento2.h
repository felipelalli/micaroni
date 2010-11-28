/*
 * $RCSfile: Evento2.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Evento2_h)
#define Evento2_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::estado;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Um Evento representa a mudança de
		 * um Estado para outro.
		 * 
		 * Sua identificação é em relação ao seu
		 * "comportamento" próprio, i. e., pode
		 * existir mais de um Evento para um mesmo Estado.
		 *
		 * @see EventoInteligente
		 * @see Qualquer
		 * @see Sempre
		 */
		class Evento: public Objeto {
			private:
				Estado* Evento::pEstadoFinal;
				Identificacao* Evento::pIdentificacao;
		};
	  }
	}
  }
}

#endif /* Evento2_h */
