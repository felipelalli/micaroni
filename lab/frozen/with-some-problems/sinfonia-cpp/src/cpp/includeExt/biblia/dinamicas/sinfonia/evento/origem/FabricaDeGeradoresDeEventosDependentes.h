/*
 * $RCSfile: FabricaDeGeradoresDeEventosDependentes.h,v $
 * $Date: 2005/03/03 03:32:33 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(FabricaDeGeradoresDeEventosDependentes_h)
#define FabricaDeGeradoresDeEventosDependentes_h

#include "biblia/basico/Fabrica.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/evento/GeradorDeEventosDependente.h"

using namespace biblia::basico;
using namespace biblia::util::instrucoes;
using namespace biblia::dinamicas::sinfonia::evento;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
	  namespace evento {
	    namespace origem {
			class FabricaDeGeradoresDeEventosDependentes
					:public Fabrica
			{

			};
		}
	  }
	}
  }
}

#endif /* FabricaDeGeradoresDeEventosDependentes_h */
