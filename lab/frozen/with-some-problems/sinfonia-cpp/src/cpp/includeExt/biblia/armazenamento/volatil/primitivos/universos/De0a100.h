/*
 * $RCSfile: De0a100.h,v $
 * $Date: 2003/11/07 22:55:12 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(De0a100_h)
#define De0a100_h

#include "biblia/armazenamento/volatil/primitivos/universos/RelativoLimitado.h"
#include "biblia/armazenamento/volatil/primitivos/Relativo.h"

using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
	  namespace primitivos {
	    namespace universos {
			class De0a100: public RelativoLimitado<0, 100> {
				public:
					De0a100::De0a100();
			};
		}
	  }
	}
  }
}

#endif /* De0a100_h */
