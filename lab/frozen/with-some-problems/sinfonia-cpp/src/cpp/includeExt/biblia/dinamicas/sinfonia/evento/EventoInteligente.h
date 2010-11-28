/*
 * $RCSfile: EventoInteligente.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(EventoInteligente_h)
#define EventoInteligente_h

#include "biblia/dinamicas/sinfonia/evento/Evento2.h"

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * � um Evento "mais aprimorado". Sabe, al�m das seguintes
		 * defini��es, tamb�m apenas manter um Evento final constante.
		 * 
		 * � capaz de, baseado em outros estados (dinamicamente), gerar
		 * novos resultados.
		 * 
		 * � capaz tamb�m de aplicar uma opera��o a um estado. (+, -,
		 * adiciona, divide etc.)
		 * 
		 * � conhecedor dos tipos primitivos e inclusive da Lista.
		 * 
		 * Gera dinamicamente o "estado final"
		 * 
		 * (FIXME: repensar nesta documenta��o)
		 */
		class EventoInteligente: public Evento {

		};
	  }
	}
  }
}

#endif /* EventoInteligente_h */
