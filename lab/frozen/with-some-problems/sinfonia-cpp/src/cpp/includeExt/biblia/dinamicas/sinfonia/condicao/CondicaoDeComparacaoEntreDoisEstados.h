/*
 * $RCSfile: CondicaoDeComparacaoEntreDoisEstados.h,v $
 * $Date: 2005/03/03 03:32:23 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CondicaoDeComparacaoEntreDoisEstados_h)
#define CondicaoDeComparacaoEntreDoisEstados_h

#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"
#include "biblia/dinamicas/sinfonia/estado/Comparacao.h"
#include "biblia/dinamicas/sinfonia/estado/Estado.h"

using namespace biblia::dinamicas::sinfonia::estado;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
		/**
		 * Possui dois Estados comparados por uma Comparacao.
		 * 
		 * Algum dos Estados pode ser/estar
		 * congelado. E pode ser também dinâmico.
		 */
		class CondicaoDeComparacaoEntreDoisEstados: public Condicao {
			private:
				Comparacao* CondicaoDeComparacaoEntreDoisEstados
						::pComparacao;

				Estado* CondicaoDeComparacaoEntreDoisEstados::pPrimeiro;
				Estado* CondicaoDeComparacaoEntreDoisEstados::pSegundo;
		};
	  }
	}
  }
}

#endif /* CondicaoDeComparacaoEntreDoisEstados_h */
