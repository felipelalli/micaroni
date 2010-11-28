/*
 * $RCSfile: Grupo.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_GRUPO_H__5A12AB6D_47CF_4BE2_A654_4A59A7A1202C__INCLUDED_)
#define AFX_GRUPO_H__5A12AB6D_47CF_4BE2_A654_4A59A7A1202C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Grupo: public Componente {
			public:
				Grupo::Grupo();
				virtual Grupo::~Grupo();
		};
	}
  }
}

#endif // !defined(AFX_GRUPO_H__5A12AB6D_47CF_4BE2_A654_4A59A7A1202C__INCLUDED_)
