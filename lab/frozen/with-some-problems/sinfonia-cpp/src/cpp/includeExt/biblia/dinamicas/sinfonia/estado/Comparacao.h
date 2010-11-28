/*
 * $RCSfile: Comparacao.h,v $
 * $Date: 2005/03/03 03:32:25 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * � relativo � compara��o entre dois Estados.
		 * 
		 * <i>nota: � tamb�m composi��o de uma
		 * Condi��o (vide pacote condicao).</i>
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
