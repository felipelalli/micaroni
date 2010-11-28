/*
 * $RCSfile: Evento2.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * Um Evento representa a mudan�a de
		 * um Estado para outro.
		 * 
		 * Sua identifica��o � em rela��o ao seu
		 * "comportamento" pr�prio, i. e., pode
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
