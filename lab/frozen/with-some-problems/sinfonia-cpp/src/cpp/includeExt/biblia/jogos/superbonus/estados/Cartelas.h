/*
 * $RCSfile: Cartelas.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_)
#define AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_

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

		class Cartelas: public Objeto {
			private:
				Intervalo Cartelas::pGiro;
				Intervalo Cartelas::pFaltaUm;
				bool Cartelas::pGirando;
				int Cartelas::pUltimoPremio;

			public:
				Cartelas::Cartelas(const Intervalo giro,
								   const Intervalo faltaUm);

				virtual Cartelas::~Cartelas();

				virtual Cartelas& Cartelas::gira();
				virtual Cartelas& Cartelas::parouDeGirar();
				virtual bool Cartelas::girando() const;
				virtual int Cartelas::ultimoPremio() const;
				virtual Cartelas& Cartelas::ultimoPremio(int premio);
				virtual const Intervalo& Cartelas::intervaloDeGiro() const;
				virtual const Intervalo& Cartelas::intervaloDeFaltaUm() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_CARTELAS_H__4D899E09_7F1C_449A_B854_86E544D3E451__INCLUDED_)
