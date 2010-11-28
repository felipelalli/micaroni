/*
 * $RCSfile: PlacaDePremios.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_)
#define AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		class PlacaDePremios: public Objeto {
			private:
				int PlacaDePremios::pMaiorPremio[4];
				int PlacaDePremios::pMaiorPremioDeTodos;
				Intervalo PlacaDePremios::pIntervaloDePisque;

			public:
				PlacaDePremios::PlacaDePremios(
						const Intervalo intervaloDePisque);

				virtual PlacaDePremios::~PlacaDePremios();

				virtual PlacaDePremios& PlacaDePremios
						::deuPremio(int qualPremio,
									int qualCartela);

				virtual const int& PlacaDePremios
						::premioAceso(int cartela) const;

				virtual const int& PlacaDePremios
						::maiorPremio() const;

				virtual PlacaDePremios& PlacaDePremios::zera();

				virtual const Intervalo& PlacaDePremios
						::intervaloDePisque() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_)
