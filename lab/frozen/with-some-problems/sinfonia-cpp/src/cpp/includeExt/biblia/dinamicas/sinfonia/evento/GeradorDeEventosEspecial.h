/*
 * $RCSfile: GeradorDeEventosEspecial.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(GeradorDeEventosEspecial_h)
#define GeradorDeEventosEspecial_h

#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * Contém lógica específica do software para a geração de Eventos.
		 * 
		 * Pode ser relativo somente Estados que não são genéricos.
		 */
		class GeradorDeEventosEspecial
				:public GeradorDeEventos
		{

		};
	  }
	}
  }
}

#endif /* GeradorDeEventosEspecial_h */
