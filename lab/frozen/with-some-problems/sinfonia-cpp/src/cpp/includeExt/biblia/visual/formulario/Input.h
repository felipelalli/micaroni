/*
 * $RCSfile: Input.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_INPUT_H__0FFAAD0D_BC0E_4E11_817C_17A064DD6998__INCLUDED_)
#define AFX_INPUT_H__0FFAAD0D_BC0E_4E11_817C_17A064DD6998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/ComponenteExecutavel.h"
#include "biblia/visual/fonte/Texto.h"

using namespace biblia::visual::fonte;

namespace biblia {
  namespace visual {
    namespace formulario {

		class Input: public ComponenteExecutavel {
			private:
				Texto Input::pTexto;

			public:
				Input::Input();
				virtual Input::~Input();

				virtual Input& Input::texto(const Texto&);
				virtual const Texto& Input::texto() const;
		};
	}
  }
}

#endif // !defined(AFX_INPUT_H__0FFAAD0D_BC0E_4E11_817C_17A064DD6998__INCLUDED_)
