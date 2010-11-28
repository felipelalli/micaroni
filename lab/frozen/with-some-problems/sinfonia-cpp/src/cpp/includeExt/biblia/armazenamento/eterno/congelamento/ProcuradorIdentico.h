/*
 * $RCSfile: ProcuradorIdentico.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_PROCURADORIDENTICO_H__92616EBA_CC0E_455C_8494_9379CA714A3F__INCLUDED_)
#define AFX_PROCURADORIDENTICO_H__92616EBA_CC0E_455C_8494_9379CA714A3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/eterno/congelamento/ProcuradorDeCompartimentoSemelhante.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		class ProcuradorIdentico: public ProcuradorDeCompartimentoSemelhante {
			public:
				ProcuradorIdentico::ProcuradorIdentico();
				virtual ProcuradorIdentico::~ProcuradorIdentico();

				// ProcuradorDeCompartimentoSemelhante:
				virtual Compartimento*
						ProcuradorIdentico
							::procura(const Caracteristicas&,
									  const Lista<Compartimento*>&)
										const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PROCURADORIDENTICO_H__92616EBA_CC0E_455C_8494_9379CA714A3F__INCLUDED_)
