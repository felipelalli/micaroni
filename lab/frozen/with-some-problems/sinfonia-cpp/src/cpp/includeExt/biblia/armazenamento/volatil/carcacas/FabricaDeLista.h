/*
 * $RCSfile: FabricaDeLista.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADELISTA_H__B78DC1CF_9EEF_46E3_8A68_AF9099D9CEC0__INCLUDED_)
#define AFX_FABRICADELISTA_H__B78DC1CF_9EEF_46E3_8A68_AF9099D9CEC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"

using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
		class FabricaDeLista: public FabricaDeInformacao {
			public:
				FabricaDeLista::FabricaDeLista();
				virtual FabricaDeLista::~FabricaDeLista();

				// FabricaDeInformacao:
				virtual const bool FabricaDeLista
						::sabeGerarUm(const Tipo&) const;

				// Fabrica:
				virtual Objeto* FabricaDeLista::gera();
		};
	  }
	}
  }
}

#endif // !defined(AFX_FABRICADELISTA_H__B78DC1CF_9EEF_46E3_8A68_AF9099D9CEC0__INCLUDED_)
