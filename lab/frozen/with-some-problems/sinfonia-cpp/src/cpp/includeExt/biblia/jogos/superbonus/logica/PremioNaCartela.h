/*
 * $RCSfile: PremioNaCartela.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PREMIONACARTELA_H__2CA6A6CF_CFEF_49E9_A1A4_63FDE352D0F2__INCLUDED_)
#define AFX_PREMIONACARTELA_H__2CA6A6CF_CFEF_49E9_A1A4_63FDE352D0F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/superbonus/logica/PosicaoNasCartelas.h"

using namespace biblia::basico;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {
		class PremioNaCartela: public Objeto {
			private:
				PosicaoNasCartelas PremioNaCartela::pPosicao;
				int PremioNaCartela::pPremio;

			public:
				PremioNaCartela::PremioNaCartela(
						const PosicaoNasCartelas&,
						int premio);

				virtual int PremioNaCartela::premio() const;
				virtual const PosicaoNasCartelas
						PremioNaCartela::posicao() const;

				virtual PremioNaCartela::~PremioNaCartela();
		};
	  }
	}
  }
}

#endif // !defined(AFX_PREMIONACARTELA_H__2CA6A6CF_CFEF_49E9_A1A4_63FDE352D0F2__INCLUDED_)
