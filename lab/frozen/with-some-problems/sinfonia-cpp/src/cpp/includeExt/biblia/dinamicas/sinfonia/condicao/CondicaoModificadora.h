/*
 * $RCSfile: CondicaoModificadora.h,v $
 * $Date: 2005/03/03 03:32:24 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CondicaoModificadora_h)
#define CondicaoModificadora_h

#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"
#include "biblia/dinamicas/sinfonia/condicao/Ligacao.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		/**
		 * Aplica um NOT na condição.
		 */
		class CondicaoModificadora: public Condicao {
			private:
				Condicao* CondicaoModificadora::pUnica;
				const Ligacao* CondicaoModificadora::pNot;
		};
	  }
	}
  }
}

#endif /* CondicaoModificadora_h */
