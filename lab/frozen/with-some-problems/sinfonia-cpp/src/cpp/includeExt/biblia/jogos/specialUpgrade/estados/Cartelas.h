/*
 * $RCSfile: Cartelas.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Cartelas: public Objeto {
			private:

				LogicaCartelas* pCartelas;

				Intervalo Cartelas::pGiro;
				Intervalo Cartelas::pFaltaUm;
				bool Cartelas::pGirando;

			public:
				Cartelas::Cartelas(const Intervalo giro,
								   const Intervalo faltaUm);

				virtual Cartelas::~Cartelas();

				void Cartelas::setCartelas(LogicaCartelas& cartelas){
					pCartelas = (LogicaCartelas*)&cartelas;
				}

				LogicaCartelas& Cartelas::getCartelas(){
					return *this->pCartelas;
				}

				virtual Cartelas& Cartelas::gira();
				virtual Cartelas& Cartelas::parouDeGirar();
				virtual bool Cartelas::girando() const;
				virtual const Intervalo& Cartelas::intervaloDeGiro() const;
				virtual const Intervalo& Cartelas::intervaloDeFaltaUm() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_)
