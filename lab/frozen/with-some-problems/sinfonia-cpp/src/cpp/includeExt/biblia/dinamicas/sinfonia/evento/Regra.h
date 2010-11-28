/*
 * $RCSfile: Regra.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Regra_h)
#define Regra_h

#include <deque>
#include "biblia/dinamicas/sinfonia/evento/EventoInteligente.h"
#include "biblia/dinamicas/sinfonia/evento/Situacao.h"

using namespace std;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Associa uma Situação a um ou mais Eventos.
		 */
		class Regra {
			private:
				EventoInteligente* pLancarQuaisEventos;
				Situacao* pQuando;
		};
	  }
	}
  }
}

#endif /* Regra_h */
