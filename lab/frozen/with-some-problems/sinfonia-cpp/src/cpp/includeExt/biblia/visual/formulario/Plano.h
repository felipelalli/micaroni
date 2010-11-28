/*
 * $RCSfile: Plano.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PLANO_H__FE99A5EA_074C_4479_876C_E9DA2EEB9898__INCLUDED_)
#define AFX_PLANO_H__FE99A5EA_074C_4479_876C_E9DA2EEB9898__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/imagem2d/Imagem.h"

using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
    namespace formulario {

		class Plano: public Componente {
			private:
				const Imagem* Plano::pFundo;

			public:
				Plano::Plano();
				virtual Plano::~Plano();

				virtual const bool Plano::temFundo() const;
				virtual Plano& Plano::fundo(const Imagem&);
				virtual const Imagem& Plano::fundo() const;
		};
	}
  }
}

#endif // !defined(AFX_PLANO_H__FE99A5EA_074C_4479_876C_E9DA2EEB9898__INCLUDED_)
