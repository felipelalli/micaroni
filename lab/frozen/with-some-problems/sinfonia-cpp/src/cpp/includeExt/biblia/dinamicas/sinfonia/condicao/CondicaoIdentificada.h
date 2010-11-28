/*
 * $RCSfile: CondicaoIdentificada.h,v $
 * $Date: 2005/03/03 03:32:24 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CondicaoIdentificada_h)
#define CondicaoIdentificada_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"

using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		class CondicaoIdentificada: public Objeto {
			private:
				Condicao* CondicaoIdentificada::pCondicao;
				Identificacao* CondicaoIdentificada::pIdentificadoPor;
		};
	  }
	}
  }
}

#endif /* CondicaoIdentificada_h */
