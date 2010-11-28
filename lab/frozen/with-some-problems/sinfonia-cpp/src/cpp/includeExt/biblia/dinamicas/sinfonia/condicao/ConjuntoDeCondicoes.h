/*
 * $RCSfile: ConjuntoDeCondicoes.h,v $
 * $Date: 2005/03/03 03:32:24 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConjuntoDeCondicoes_h)
#define ConjuntoDeCondicoes_h

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		class ConjuntoDeCondicoes: public Objeto {
			private:
				std::deque<Condicao*> ConjuntoDeCondicoes::pCondicoes;
		};
	  }
	}
  }
}

#endif /* ConjuntoDeCondicoes_h */
