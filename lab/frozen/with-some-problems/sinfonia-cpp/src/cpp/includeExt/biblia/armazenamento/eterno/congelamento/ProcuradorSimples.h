/*
 * $RCSfile: ProcuradorSimples.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_PROCURADORSIMPLES_H__01206E79_6A2E_4F0B_B0A7_F3FB72DD0670__INCLUDED_)
#define AFX_PROCURADORSIMPLES_H__01206E79_6A2E_4F0B_B0A7_F3FB72DD0670__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/eterno/congelamento/ProcuradorDeCompartimentoSemelhante.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		class ProcuradorSimples: public ProcuradorDeCompartimentoSemelhante {
			public:
				ProcuradorSimples::ProcuradorSimples();
				virtual ProcuradorSimples::~ProcuradorSimples();

				// ProcuradorDeCompartimentoSemelhante:
				virtual Compartimento*
						ProcuradorSimples
							::procura(const Caracteristicas&,
									  const Lista<Compartimento*>&)
										const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PROCURADORSIMPLES_H__01206E79_6A2E_4F0B_B0A7_F3FB72DD0670__INCLUDED_)
