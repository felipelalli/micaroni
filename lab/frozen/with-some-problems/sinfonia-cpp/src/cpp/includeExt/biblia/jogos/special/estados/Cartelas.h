/*
 * $RCSfile: Cartelas.h,v $
 * $Date: 2003/07/17 23:27:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(SBS_AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_)
#define SBS_AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
using namespace biblia::jogos::bingo::logica;

namespace biblia {
  namespace jogos {
    namespace special {
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
