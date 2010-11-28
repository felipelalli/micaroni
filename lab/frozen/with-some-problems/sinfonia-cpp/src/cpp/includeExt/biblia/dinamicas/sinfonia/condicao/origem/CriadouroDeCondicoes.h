/*
 * $RCSfile: CriadouroDeCondicoes.h,v $
 * $Date: 2005/03/03 03:32:24 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CriadouroDeCondicoes_h)
#define CriadouroDeCondicoes_h

#include "biblia/basico/Fabrica.h"
#include "biblia/dinamicas/sinfonia/condicao/CondicaoDeComparacaoEntreDoisEstados.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::condicao;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
        namespace origem {
			class CriadouroDeCondicoes: public Fabrica {

			};
		}
	  }
	}
  }
}

#endif /* CriadouroDeCondicoes_h */
