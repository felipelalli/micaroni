/*
 * $RCSfile: GeradorDeEventosDependente.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(GeradorDeEventosDependente_h)
#define GeradorDeEventosDependente_h

#include <deque>
#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"
#include "biblia/dinamicas/sinfonia/evento/Regra.h"

using namespace std;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
		/**
		 * É relativo a um único Estado e é responsável por gerar Eventos a
		 * partir de uma determinada Situação. É um GeradorDeEventos
		 * genérico e não precisa ser reescrito a cada novo software. Seu
		 * comportamento depende apenas da Situação. A idéia é que, entre
		 * os GeradoresDeEventos, haja o maior número de
		 * GeradoresDeEventosDependetes possível.
		 *
		 * Pode ser relativo somente Estados que são genéricos.
		 */
		class GeradorDeEventosDependente: public GeradorDeEventos {
			private:
				std::deque<Regra*> GeradorDeEventosDependente::pRegras;
		};
	  }
	}
  }
}

#endif /* GeradorDeEventosDependente_h */
