/*
 * $RCSfile: CriadouroDeCondicoesWizard.h,v $
 * $Date: 2005/03/03 03:32:25 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CriadouroDeCondicoesWizard_h)
#define CriadouroDeCondicoesWizard_h

#include "biblia/util/Wizard.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/condicao/CondicaoIdentificada.h"
#include "biblia/dinamicas/sinfonia/condicao/origem/CriadouroDeCondicoes.h"

using namespace biblia::util;
using namespace biblia::util::instrucoes;
using namespace biblia::dinamicas::sinfonia::condicao;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
  	  namespace condicao {
        namespace origem {
			class CriadouroDeCondicoesWizard: public Wizard {
				private:
					CriadouroDeCondicoes* CriadouroDeCondicoesWizard
							::pCriadouroDeCondicoes;
			};
		}
	  }
	}
  }
}

#endif /* CriadouroDeCondicoesWizard_h */
