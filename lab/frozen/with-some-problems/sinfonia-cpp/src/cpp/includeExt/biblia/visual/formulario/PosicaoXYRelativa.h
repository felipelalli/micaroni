/*
 * $RCSfile: PosicaoXYRelativa.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_)
#define AFX_POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/visual/Posicionado.h"
#include "biblia/visual/formulario/Componente.h"

using namespace biblia::visual;

namespace biblia {
  namespace visual {
    namespace formulario {
		class Componente;

		class PosicaoXYRelativa: public Posicionado, public Objeto {
			private:
				const Componente* PosicaoXYRelativa::pComponente;
				Ponto PosicaoXYRelativa::pPonto;

			protected:
				const Componente& PosicaoXYRelativa::componente() const;

			public:
				PosicaoXYRelativa::PosicaoXYRelativa();
				virtual PosicaoXYRelativa::~PosicaoXYRelativa();

				virtual PosicaoXYRelativa& PosicaoXYRelativa
						::componente(const Componente&);

				virtual const Ponto& PosicaoXYRelativa
						::posicaoRelativa() const;

				virtual PosicaoXYRelativa& PosicaoXYRelativa
						::posicaoRelativa(const Ponto&);

				// Posicionado:
				virtual const Ponto& PosicaoXYRelativa
						::posicao() const;
		};
	}
  }
}

#endif // !defined(AFX_POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_)
