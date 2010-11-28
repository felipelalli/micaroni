/*
 * $RCSfile: ConcretizadorAprendiz.h,v $
 * $Date: 2005/03/03 03:32:22 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConcretizadorAprendiz_h)
#define ConcretizadorAprendiz_h

#include <deque>
#include "biblia/fluxo/ExecutaveisEmSerie.h"
#include "biblia/dinamicas/sinfonia/realizador/Realizador.h"
#include "biblia/dinamicas/sinfonia/concretizador/ConcretizadorBaseadoEmEventos.h"
#include "biblia/dinamicas/sinfonia/concretizador/Consequencia.h"

using namespace std;
using namespace biblia::fluxo;
using namespace biblia::dinamicas::sinfonia::realizador;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace concretizador {
		class ConcretizadorAprendiz
				:public ConcretizadorBaseadoEmEventos
		{
			private:
				std::deque<ExecutaveisEmSerie*> ConcretizadorAprendiz
						::pConcretizadoresEspeciais;

				std::deque<Consequencia*> ConcretizadorAprendiz
						::pConsequencias;

				std::deque<Realizador*> ConcretizadorAprendiz
						::pRealizadores;

			public:
				/**
				 * verifica se os Estados s�o gen�ricos
				 * e verifica poss�veis
				 * inconsist�ncias.
				 */
				const bool ConcretizadorAprendiz
						::verificaSeEstaTudoOK();
		};
	  }
	}
  }
}

#endif /* ConcretizadorAprendiz_h */
