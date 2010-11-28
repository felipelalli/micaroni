/*
 * $RCSfile: PosicaoRelativa.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_2POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_)
#define AFX_2POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_

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

		class PosicaoRelativa: public Posicionado, public Objeto {
			private:
				static int PosicaoRelativa::CENTRO;
				static int PosicaoRelativa::DIREITA;
				static int PosicaoRelativa::ESQUERDA;
				static int PosicaoRelativa::TOPO;
				static int PosicaoRelativa::BASE;

				const Componente* PosicaoRelativa::pComponente;
				const Componente* PosicaoRelativa::pComponenteThis;
				int PosicaoRelativa::pPosicao;

			protected:
				const Componente& PosicaoRelativa::componente() const;
				const Componente& PosicaoRelativa::componenteThis() const;

			public:
				PosicaoRelativa::PosicaoRelativa();
				virtual PosicaoRelativa::~PosicaoRelativa();

				virtual PosicaoRelativa& PosicaoRelativa
						::componente(const Componente&);

				virtual PosicaoRelativa& PosicaoRelativa
						::componenteThis(const Componente&);

				virtual PosicaoRelativa& PosicaoRelativa
						::centro(bool);

				virtual PosicaoRelativa& PosicaoRelativa
						::direita(bool);

				virtual PosicaoRelativa& PosicaoRelativa
						::esquerda(bool);

				virtual PosicaoRelativa& PosicaoRelativa
						::topo(bool);

				virtual PosicaoRelativa& PosicaoRelativa
						::base(bool);

				virtual bool PosicaoRelativa
						::centro() const;

				virtual bool PosicaoRelativa
						::direita() const;

				virtual bool PosicaoRelativa
						::esquerda() const;

				virtual bool PosicaoRelativa
						::topo() const;

				virtual bool PosicaoRelativa
						::base() const;

				// Posicionado:
				virtual const Ponto& PosicaoRelativa
						::posicao() const;
		};
	}
  }
}

#endif // !defined(AFX_2POSICAOXYRELATIVA_H__C16D83D7_5EC2_4D0E_AE71_5BECFE2643A0__INCLUDED_)
