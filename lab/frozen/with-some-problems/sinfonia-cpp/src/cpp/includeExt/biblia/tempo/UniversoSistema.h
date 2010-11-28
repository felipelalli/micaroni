/*
 * $RCSfile: UniversoSistema.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_UNIVERSOSISTEMA_H__0D0FA1D0_F865_4F20_A888_3907C8D2E72B__INCLUDED_)
#define AFX_UNIVERSOSISTEMA_H__0D0FA1D0_F865_4F20_A888_3907C8D2E72B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <time.h>
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/unidades/MilionesimoDeSegundo.h"

using namespace biblia::tempo::unidades;

namespace biblia {
  namespace tempo {

	class UniversoSistema: public UniversoDeTempo {

		public:
			UniversoSistema::UniversoSistema(){};
			virtual UniversoSistema::~UniversoSistema(){};

			// UniversoDeTempo:
			virtual Momento UniversoSistema::agora() const;

			virtual const UnidadeDeTempo&
					UniversoSistema::cadaPasso() const;

			virtual bool UniversoSistema::mesmoUniversoDeTempo(
					const UniversoDeTempo&) const;
	};
  }
}

#endif // !defined(AFX_UNIVERSOSISTEMA_H__0D0FA1D0_F865_4F20_A888_3907C8D2E72B__INCLUDED_)
