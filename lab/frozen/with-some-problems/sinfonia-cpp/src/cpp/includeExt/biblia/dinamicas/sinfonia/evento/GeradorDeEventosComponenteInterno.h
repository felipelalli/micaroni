/*
 * $RCSfile: GeradorDeEventosComponenteInterno.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * por�m � "pai" de um conjunto de classes com
		 * instru��es para os componentes internos
		 * atuais da b�blia, como execut�veis,
		 * temporizadores e anima��es.
		 * 
		 * Pode ser relativo somente Estados
		 * que n�o s�o gen�ricos.
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
