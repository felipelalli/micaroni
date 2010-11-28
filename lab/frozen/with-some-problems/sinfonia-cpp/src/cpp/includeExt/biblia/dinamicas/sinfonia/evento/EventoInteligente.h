/*
 * $RCSfile: EventoInteligente.h,v $
 * $Date: 2005/03/03 03:32:28 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * É um Evento "mais aprimorado". Sabe, além das seguintes
		 * definições, também apenas manter um Evento final constante.
		 * 
		 * É capaz de, baseado em outros estados (dinamicamente), gerar
		 * novos resultados.
		 * 
		 * É capaz também de aplicar uma operação a um estado. (+, -,
		 * adiciona, divide etc.)
		 * 
		 * É conhecedor dos tipos primitivos e inclusive da Lista.
		 * 
		 * Gera dinamicamente o "estado final"
		 * 
		 * (FIXME: repensar nesta documentação)
		 */
		class EventoInteligente: public Evento {

		};
	  }
	}
  }
}

#endif /* EventoInteligente_h */
