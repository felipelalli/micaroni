/*
 * $RCSfile: PlacaDePremios.h,v $
 * $Date: 2003/08/19 01:28:20 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(SBS_AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_)
#define SBS_AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <map>
using namespace std;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/jogos/bingo/logica/util/Premio.h"
using namespace biblia::jogos::bingo::logica::util;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace estados {
		class Barras: public Objeto {
			public:
				class Barra {
					private:
						bool Barra::pDeuPremio;
						int Barra::pQuantosFaltaUns;

					public:
						Barra::Barra();
						virtual const bool& Barra::premio() const;
						virtual const int& Barra::quantosFaltaUns() const;
						virtual Barra& Barra::deuPremio();
						virtual Barra& Barra::tirouPremio();
						virtual Barra& Barra::deuFaltaUm();
						virtual Barra& Barra::tirouFaltaUm();
				};

				Barras::Barras();
				virtual Barras& Barras::zera();
				virtual Barras& Barras::deuPremio(int premio);
				virtual Barras& Barras::deuFaltaUm(int premio);
				virtual Barras& Barras::tirouPremio(int premio);
				virtual Barras& Barras::tirouFaltaUm(int premio);
				virtual bool Barras::premio(int premio);
				virtual int Barras::quantosFaltaUns(int premio);

			private:
				map<int, Barra> Barras::pPremio;
		};

		class PlacaDePremios: public Objeto {
			private:
				LogicaCartelas* pCartelas;
				Intervalo PlacaDePremios::pIntervaloDePisque;
				Barras PlacaDePremios::pBarras;

			public:
				PlacaDePremios::PlacaDePremios(
						const Intervalo intervaloDePisque);

				void PlacaDePremios::setCartelas(LogicaCartelas& cartelas){
					this->pCartelas = (LogicaCartelas*)&cartelas;
				}

				virtual PlacaDePremios::~PlacaDePremios();

				virtual biblia::jogos::bingo::logica::util::Premio*
						PlacaDePremios::maiorPremio() const;

				virtual const Intervalo& PlacaDePremios
						::intervaloDePisque() const;

				virtual const LogicaCartelas& PlacaDePremios::getCartelas();

				virtual Barras& PlacaDePremios::barras();
				virtual const Barras& PlacaDePremios::barras() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PLACADEPREMIOS_H__D3F98262_73F3_4F5B_A522_3199E682067C__INCLUDED_)
