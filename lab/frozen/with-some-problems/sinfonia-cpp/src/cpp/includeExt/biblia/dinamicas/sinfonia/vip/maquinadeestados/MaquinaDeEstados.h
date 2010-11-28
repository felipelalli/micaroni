/*
 * $RCSfile: MaquinaDeEstados.h,v $
 * $Date: 2005/03/03 03:32:40 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(MaquinaDeEstados_h)
#define MaquinaDeEstados_h

#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/evento/Evento2.h"
#include "biblia/dinamicas/sinfonia/evento/MediadorDeEstados.h"
#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"
#include "biblia/dinamicas/sinfonia/concretizador/Concretizador.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::evento;
using namespace biblia::dinamicas::sinfonia::concretizador;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
	    namespace maquinadeestados {
			/**
			 * Uma Máquina de Estados é o conjunto de um
			 * GeradorDeEventos, um Mediador de Estados
			 * (contendo os Estados) e um Concretizador.
			 * 
			 * Sua função é garantir que os Estados
			 * estão sendo modificados pelos eventos
			 * e que os resultados estão sendo gerados pelo
			 * Concretizador, unindo todos conceitualmente.
			 */
			class MaquinaDeEstados: public Objeto {
				private:
					Concretizador* MaquinaDeEstados
							::pConcretizador;

					MediadorDeEstados* MaquinaDeEstados
							::pMediadorDeEstados;

					GeradorDeEventos* MaquinaDeEstados
							::pGeradorDeEventos;

				public:
					/**
					 * Recebe um Evento e o distribui
					 * na seguinte ordem: MediadorDeEstados,
					 * GeradoresDeEventosDependentes
					 * e por último ao Concretizador.
					 */
					virtual MaquinaDeEstados&
							MaquinaDeEstados
								::recebeEvento(Evento&);
			};
		}
	  }
	}
  }
}

#endif /* MaquinaDeEstados_h */
