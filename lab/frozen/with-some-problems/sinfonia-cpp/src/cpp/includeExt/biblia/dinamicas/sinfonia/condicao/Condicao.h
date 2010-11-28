/*
 * $RCSfile: Condicao.h,v $
 * $Date: 2005/03/03 03:32:23 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Condicao_h)
#define Condicao_h

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		/**
		 * Uma Condição pode ser verdadeira ou falsa.
		 */
		class Condicao: public Objeto {

		};
	  }
	}
  }
}

#endif /* Condicao_h */
