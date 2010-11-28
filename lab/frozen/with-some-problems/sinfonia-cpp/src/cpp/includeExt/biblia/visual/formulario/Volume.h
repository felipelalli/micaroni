/*
 * $RCSfile: Volume.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VOLUME_H__2F6C1E18_C6AC_41C8_A564_C3D04416EF0A__INCLUDED_)
#define AFX_VOLUME_H__2F6C1E18_C6AC_41C8_A564_C3D04416EF0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/BarraDePorcentagem.h"
#include "biblia/visual/formulario/ComponenteExecutavel.h"
#include "biblia/visual/formulario/AnimacaoComponente.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Volume: public ComponenteExecutavel {
			private:
				AnimacaoComponente Volume::pCaixinha;

			public:
				BarraDePorcentagem Volume::porcentagem;

				Volume::Volume();
				virtual Volume::~Volume();
				virtual AnimacaoComponente& Volume::animacao();
				virtual const AnimacaoComponente& Volume::animacao() const;
		};
	}
  }
}

#endif // !defined(AFX_VOLUME_H__2F6C1E18_C6AC_41C8_A564_C3D04416EF0A__INCLUDED_)
