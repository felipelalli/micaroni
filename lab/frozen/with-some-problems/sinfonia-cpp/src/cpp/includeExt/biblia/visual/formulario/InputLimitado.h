/*
 * $RCSfile: InputLimitado.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_INPUTLIMITADO_H__F567F06B_9382_4A70_BB41_1B7E225E8AD6__INCLUDED_)
#define AFX_INPUTLIMITADO_H__F567F06B_9382_4A70_BB41_1B7E225E8AD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <deque>
#include <string>
#include "biblia/visual/formulario/Input.h"

using namespace std;
using namespace biblia::visual::fonte;

namespace biblia {
  namespace visual {
    namespace formulario {

		class InputLimitado: public Input {
			private:
				std::string InputLimitado::pAceitos;
				int InputLimitado::pCaractereAtual;
				int InputLimitado::pPosicaoNaString;
				int InputLimitado::pQuantosCaracteres;
				std::string InputLimitado::pResultado;

			protected:
				virtual InputLimitado& InputLimitado::arrumaResultado();
				virtual InputLimitado& InputLimitado::atualizaResultado();

			public:
				InputLimitado::InputLimitado();
				virtual InputLimitado::~InputLimitado();
				virtual InputLimitado& InputLimitado::aceitos(const std::string&);
				virtual const std::string& InputLimitado::aceitos() const;
				virtual const int& InputLimitado::quantosCaracteres() const;
				virtual const int InputLimitado::posicaoNoResultado() const;
				virtual InputLimitado& InputLimitado::quantosCaracteres(int);
				virtual const std::string& InputLimitado::resultado() const;
				virtual InputLimitado& InputLimitado::proximoCaractere();
				virtual InputLimitado& InputLimitado::caractereAnterior();
				virtual InputLimitado& InputLimitado::aumentaCaractere();
				virtual InputLimitado& InputLimitado::diminuiCaractere();
		};
	}
  }
}

#endif // !defined(AFX_INPUTLIMITADO_H__F567F06B_9382_4A70_BB41_1B7E225E8AD6__INCLUDED_)
