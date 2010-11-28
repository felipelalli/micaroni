/*
 * $RCSfile: Selecao.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_SELECAO_H__519965D5_7523_4768_B125_46C5B5BF9989__INCLUDED_)
#define AFX_SELECAO_H__519965D5_7523_4768_B125_46C5B5BF9989__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Selecao: public Componente {
			private:
				bool Selecao::pSelecionado;
				bool Selecao::pMultiplo;

			public:
				Selecao::Selecao();
				virtual Selecao::~Selecao();

				virtual Selecao& Selecao::selecionado(bool);
				virtual const bool& Selecao::selecionado() const;
				virtual Selecao& Selecao::multiplo(bool);
				virtual const bool& Selecao::multiplo() const;
		};
	}
  }
}

#endif // !defined(AFX_SELECAO_H__519965D5_7523_4768_B125_46C5B5BF9989__INCLUDED_)
