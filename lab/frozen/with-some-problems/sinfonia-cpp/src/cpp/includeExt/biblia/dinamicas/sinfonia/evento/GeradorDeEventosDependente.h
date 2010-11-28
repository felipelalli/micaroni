/*
 * $RCSfile: GeradorDeEventosDependente.h,v $
 * $Date: 2005/03/03 03:32:29 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * � relativo a um �nico Estado e � respons�vel por gerar Eventos a
		 * partir de uma determinada Situa��o. � um GeradorDeEventos
		 * gen�rico e n�o precisa ser reescrito a cada novo software. Seu
		 * comportamento depende apenas da Situa��o. A id�ia � que, entre
		 * os GeradoresDeEventos, haja o maior n�mero de
		 * GeradoresDeEventosDependetes poss�vel.
		 *
		 * Pode ser relativo somente Estados que s�o gen�ricos.
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
