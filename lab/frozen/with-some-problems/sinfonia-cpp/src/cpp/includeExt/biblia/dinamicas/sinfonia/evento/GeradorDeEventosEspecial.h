/*
 * $RCSfile: GeradorDeEventosEspecial.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * Cont�m l�gica espec�fica do software para a gera��o de Eventos.
		 * 
		 * Pode ser relativo somente Estados que n�o s�o gen�ricos.
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
