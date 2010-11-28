/*
 * $RCSfile: ComposicaoDeCondicao.h,v $
 * $Date: 2005/03/03 03:32:23 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ComposicaoDeCondicao_h)
#define ComposicaoDeCondicao_h

#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"
#include "biblia/dinamicas/sinfonia/condicao/Ligacao.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		class ComposicaoDeCondicao: public Condicao {
			private:
				Condicao* ComposicaoDeCondicao::pPrimeiraCondicao;
				Condicao* ComposicaoDeCondicao::pSegundaCondicao;
				Ligacao* ComposicaoDeCondicao::pEOuOu;
		};
	  }
	}
  }
}

#endif /* ComposicaoDeCondicao_h */
