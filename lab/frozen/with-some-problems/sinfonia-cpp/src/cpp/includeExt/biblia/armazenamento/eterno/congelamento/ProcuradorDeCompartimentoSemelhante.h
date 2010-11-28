/*
 * $RCSfile: ProcuradorDeCompartimentoSemelhante.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_PROCURADORDECOMPARTIMENTOSEMELHANTE_H__6AADBFC7_22E6_43A7_80A5_F3CB93FF2844__INCLUDED_)
#define AFX_PROCURADORDECOMPARTIMENTOSEMELHANTE_H__6AADBFC7_22E6_43A7_80A5_F3CB93FF2844__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/basico/Excecao.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"
#include "biblia/armazenamento/eterno/congelamento/Compartimento.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::eterno::congelamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace congelamento {
		class ProcuradorDeCompartimentoSemelhante: public Interface {
			protected:
				ProcuradorDeCompartimentoSemelhante
						::ProcuradorDeCompartimentoSemelhante();

			public:
				virtual ProcuradorDeCompartimentoSemelhante::
						~ProcuradorDeCompartimentoSemelhante() {};

				/**
				 * @throws NenhumCompartimentoAdequadoExcecao
				 */
				virtual Compartimento*
						ProcuradorDeCompartimentoSemelhante
							::procura(const Caracteristicas&,
									  const Lista<Compartimento*>&)
										const = 0;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PROCURADORDECOMPARTIMENTOSEMELHANTE_H__6AADBFC7_22E6_43A7_80A5_F3CB93FF2844__INCLUDED_)
