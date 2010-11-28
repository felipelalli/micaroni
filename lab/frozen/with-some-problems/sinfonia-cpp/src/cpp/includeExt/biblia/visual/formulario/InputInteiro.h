/*
 * $RCSfile: InputInteiro.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_INPUTINTEIRO_H__DC5012FE_6D10_494A_9F00_683163623FFE__INCLUDED_)
#define AFX_INPUTINTEIRO_H__DC5012FE_6D10_494A_9F00_683163623FFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/visual/formulario/Input.h"

using namespace std;
using namespace biblia::visual::fonte;

namespace biblia {
  namespace visual {
    namespace formulario {

		class InputInteiro: public Input {
			private:
				int InputInteiro::pValor;
				int InputInteiro::pValorMaximo;
				int InputInteiro::pValorMinimo;
				int InputInteiro::pPasso;

			public:
				InputInteiro::InputInteiro();
				virtual InputInteiro::~InputInteiro();

				virtual InputInteiro& InputInteiro::proximo();
				virtual InputInteiro& InputInteiro::anterior();

				virtual InputInteiro& InputInteiro::valor(int);
				virtual InputInteiro& InputInteiro::passo(int);
				virtual InputInteiro& InputInteiro::valorMaximo(int);
				virtual InputInteiro& InputInteiro::valorMinimo(int);

				virtual const int& InputInteiro::valor() const;
				virtual const int& InputInteiro::passo() const;
				virtual const int& InputInteiro::valorMaximo() const;
				virtual const int& InputInteiro::valorMinimo() const;
		};
	}
  }
}

#endif // !defined(AFX_INPUTINTEIRO_H__DC5012FE_6D10_494A_9F00_683163623FFE__INCLUDED_)
