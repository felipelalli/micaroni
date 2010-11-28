/*
 * $RCSfile: FabricaDeMaestro.h,v $
 * $Date: 2005/03/03 03:32:38 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeMaestro_h)
#define FabricaDeMaestro_h

#include "biblia/basico/Fabrica.h"
#include "biblia/util/Lixeira.h"
#include "biblia/dinamicas/sinfonia/evento/RegistroDeEventos.h"
#include "biblia/dinamicas/sinfonia/vip/maestro/Maestro.h"
#include "biblia/dinamicas/sinfonia/vip/maquinadeestados/MaquinaDeEstados.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::dinamicas::sinfonia::evento;
using namespace biblia::dinamicas::sinfonia::vip::maquinadeestados;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace maestro {
			class FabricaDeMaestro: public Fabrica {
				protected:
					virtual Objeto* FabricaDeMaestro::gera();
			};
		}
	  }
	}
  }
}

#endif /* FabricaDeMaestro_h */
