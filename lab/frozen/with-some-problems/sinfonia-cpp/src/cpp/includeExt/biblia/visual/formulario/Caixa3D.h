/*
 * $RCSfile: Caixa3D.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CAIXA3D_H__CBB0706B_BE79_4743_AD58_F61C825542FB__INCLUDED_)
#define AFX_CAIXA3D_H__CBB0706B_BE79_4743_AD58_F61C825542FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Grupo.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Caixa3D: public Grupo {
			public:
				Caixa3D::Caixa3D();
				virtual Caixa3D::~Caixa3D();
		};
	}
  }
}

#endif // !defined(AFX_CAIXA3D_H__CBB0706B_BE79_4743_AD58_F61C825542FB__INCLUDED_)
