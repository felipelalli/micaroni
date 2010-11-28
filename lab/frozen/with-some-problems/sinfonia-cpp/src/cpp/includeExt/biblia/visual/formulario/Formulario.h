/*
 * $RCSfile: Formulario.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FORMULARIO_H__92F498DA_F214_4406_817E_3FCDEA3554D4__INCLUDED_)
#define AFX_FORMULARIO_H__92F498DA_F214_4406_817E_3FCDEA3554D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/formulario/Paginas.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Formulario: public Componente {
			private:
				Componente* Formulario::pComponenteAtual;
				bool Formulario::pDeveFocalizarProximo;

			protected:
				virtual Formulario& Formulario
						::focalizaProximo(Componente&,
								bool praTras = false, int nivel = 0);

			public:
				Formulario::Formulario();
				virtual Formulario::~Formulario();

				virtual Componente& Formulario::componenteAtual();
				virtual const Componente& Formulario::componenteAtual() const;
				virtual Formulario& Formulario::focaliza(Componente&);
				virtual Formulario& Formulario::proximo();
				virtual Formulario& Formulario::anterior();
		};
	}
  }
}

#endif // !defined(AFX_FORMULARIO_H__92F498DA_F214_4406_817E_3FCDEA3554D4__INCLUDED_)
