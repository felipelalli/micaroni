/*
 * $RCSfile: FabricaDeMaquinasDeEstados.h,v $
 * $Date: 2005/03/03 03:32:39 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeMaquinasDeEstados_h)
#define FabricaDeMaquinasDeEstados_h

#include "biblia/basico/Fabrica.h"
#include "biblia/basico/Objeto.h"
#include "biblia/dinamicas/sinfonia/concretizador/Concretizador.h"
#include "biblia/dinamicas/sinfonia/evento/MediadorDeEstados.h"
#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventos.h"
#include "biblia/dinamicas/sinfonia/vip/maquinadeestados/MaquinaDeEstados.h"

using namespace biblia::basico;
using namespace biblia::dinamicas::sinfonia::concretizador;
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
	    namespace maquinadeestados {
			class FabricaDeMaquinasDeEstados
					:public Fabrica,
					 public Objeto
			{
				public:
					virtual Objeto*
							FabricaDeMaquinasDeEstados
								::gera();
			};
		}
	  }
	}
  }
}

#endif /* FabricaDeMaquinasDeEstados_h */
