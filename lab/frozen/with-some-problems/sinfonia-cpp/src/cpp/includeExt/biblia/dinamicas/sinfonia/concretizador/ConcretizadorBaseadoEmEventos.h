/*
 * $RCSfile: ConcretizadorBaseadoEmEventos.h,v $
 * $Date: 2005/03/03 03:32:22 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConcretizadorBaseadoEmEventos_h)
#define ConcretizadorBaseadoEmEventos_h

#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/concretizador/Concretizador.h"

using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace concretizador {
		/**
		 * Cont�m um conjunto de Geradores de Eventos predefinidos e
		 * imut�veis, i.e., uma vez definidos no in�cio, o n�mero de
		 * Geradores e seus respectivos comportamentos permanecer�o os
		 * mesmos.
		 */
		class ConcretizadorBaseadoEmEventos: public Concretizador {
			public:
				/**
				 * Apenas empilha os eventos para serem
				 * consumidos no Executar.
				 */
				ConcretizadorBaseadoEmEventos&
						ConcretizadorBaseadoEmEventos
							::aconteceu(const Evento& evento);
		};
	  }
	}
  }
}

#endif /* ConcretizadorBaseadoEmEventos_h */
