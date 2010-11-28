/*
 * $RCSfile: SelecaoImagem.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_SELECAOIMAGEM_H__A25ACB8D_777D_4396_BEF7_0627D82D87CB__INCLUDED_)
#define AFX_SELECAOIMAGEM_H__A25ACB8D_777D_4396_BEF7_0627D82D87CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Selecao.h"
#include "biblia/visual/formulario/Label.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class SelecaoImagem: public Selecao {
			private:
				LabelComponente SelecaoImagem::pFace;
				LabelComponente SelecaoImagem::pFacePressionada;
				LabelComponente SelecaoImagem::pFaceDesabilitada;

			public:
				SelecaoImagem::SelecaoImagem();
				virtual SelecaoImagem::~SelecaoImagem();

				virtual LabelComponente& SelecaoImagem::face();
				virtual const LabelComponente& SelecaoImagem::face() const;
				virtual LabelComponente& SelecaoImagem::facePressionada();
				virtual const LabelComponente& SelecaoImagem::facePressionada() const;
				virtual LabelComponente& SelecaoImagem::faceDesabilitada();
				virtual const LabelComponente& SelecaoImagem::faceDesabilitada() const;
		};
	}
  }
}

#endif // !defined(AFX_SELECAOIMAGEM_H__A25ACB8D_777D_4396_BEF7_0627D82D87CB__INCLUDED_)
