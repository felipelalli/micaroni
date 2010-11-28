/*
 * $RCSfile: Dicionario.h,v $
 * $Date: 2003/11/24 19:38:32 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Dicionario_h)
#define Dicionario_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {
	  namespace carcacas {

		/**
		 * � um MapaHash que usa
		 * um Objeto* para o valor.
		 */
		typedef MapaHash<Objeto*> Dicionario;
	  }
	}
  }
}

// ver em biblia/doc/rascunhos/c�digos-lixo.txt

#endif /* Dicionario_h */
