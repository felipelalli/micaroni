/*
 * $RCSfile: GeradorDeEventosComponenteInterno.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(GeradorDeEventosComponenteInterno_h)
#define GeradorDeEventosComponenteInterno_h

#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Semelhante ao GeradorDeEventosEspecial
		 * porém é "pai" de um conjunto de classes com
		 * instruções para os componentes internos
		 * atuais da bíblia, como executáveis,
		 * temporizadores e animações.
		 * 
		 * Pode ser relativo somente Estados
		 * que não são genéricos.
		 */
		class GeradorDeEventosComponenteInterno
				:public GeradorDeEventos
		{

		};
	  }
	}
  }
}

#endif /* GeradorDeEventosComponenteInterno_h */
