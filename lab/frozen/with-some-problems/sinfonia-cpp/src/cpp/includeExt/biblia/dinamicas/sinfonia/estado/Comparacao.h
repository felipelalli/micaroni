/*
 * $RCSfile: Comparacao.h,v $
 * $Date: 2005/03/03 03:32:25 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Comparacao_h)
#define Comparacao_h

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
      namespace estado {
		/**
		 * É relativo à comparação entre dois Estados.
		 * 
		 * <i>nota: É também composição de uma
		 * Condição (vide pacote condicao).</i>
		 */
		class Comparacao: public Objeto {
			public:
				virtual const bool mesma(
						const Comparacao& outra) const;
		};
	  }
	}
  }
}

#endif /* Comparacao_h */
