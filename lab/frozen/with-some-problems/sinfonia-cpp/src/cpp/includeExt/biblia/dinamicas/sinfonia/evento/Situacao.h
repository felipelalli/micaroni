/*
 * $RCSfile: Situacao.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Situacao_h)
#define Situacao_h

#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/condicao/Condicao.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::condicao;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Quando tal Evento ocorrer e somente
		 * se Condicao for verdadeira.
		 * 
		 * Cuidado quando o Evento for "sempre"
		 * porque isso pode ocasionar um overhead
		 * generalizado (o processamento ir� para 100%
		 * instantantaneamente porque ele precisar�
		 * verificar *sempre*).
		 */
		class Situacao: public Objeto {
			private:
				Evento* Situacao::pQuandoOcorrer;
				Condicao* Situacao::pSomenteSe;
		};
	  }
	}
  }
}

#endif /* Situacao_h */
